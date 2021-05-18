#include "mqtt/async_client.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

class callback : public virtual mqtt::callback
{
public:
    virtual void connected(const std::string &cause) override { std::cout << "callback::connected()"
                                                                          << " " << cause << std::endl; }
    virtual void connection_lost(const std::string &cause) override { std::cout << "callback::connection_lost()"
                                                                                << " " << cause << std::endl; }
    // mqtt::delivery_token_ptr = std::shared<delivery_token>  delivery_token:public token
    virtual void delivery_complete(mqtt::delivery_token_ptr delivery_token_p) override
    {
        std::cout << "\ncallback::message_arrived()\n"
                  << "Topic:" << delivery_token_p->get_message()->get_topic()
                  << std::endl
                  << "Message:" << delivery_token_p->get_message()->get_payload()
                  << std::endl
                  << "Message id:" << delivery_token_p->get_message_id() << std::endl
                  << std::endl;
    }
};

class action_listener : public virtual mqtt::iaction_listener
{
public:
    virtual void on_failure(const mqtt::token &asyncActionToken)
    {
        std::cout << "listener: send failure()\n"
                  << "Message topics:" << asyncActionToken.get_topics()->size() << std::endl
                  << "Message id is:" << asyncActionToken.get_message_id() << std::endl;
    };
    virtual void on_success(const mqtt::token &asyncActionToken)
    {
        std::cout << "listener: send success()\n"
                  << "Message topics:" << asyncActionToken.get_topics()->size() << std::endl
                  << "Message id is:" << asyncActionToken.get_message_id() << std::endl;
    };
};

int main()
{
    std::string address = "tcp://localhost:1883";
    std::string client_id = "paho_cpp_async_publish";
    std::string persist_dir = "./persist";
    std::cout << "initializing for server...\n";

    mqtt::async_client client(address, client_id, persist_dir);
    callback cb; // 这里要保证cb一直存在。set_callback实际上只保存了一个callback的裸指针。delete掉会段错误
    client.set_callback(cb);

    //构造一个connops对象，设置session、will_message
    auto connOpts = mqtt::connect_options_builder()
                        .clean_session()                                    // return *this
                        .will(mqtt::message("hello", "connect_options", 1)) // return *this
                        .finalize();                                        // return connect_options
    std::cout << "construct connect_options finish\n";

    try
    {
        //1.connect
        std::cout << "\nconnecting...\n";
        mqtt::token_ptr conntok = client.connect(connOpts);
        std::cout << "waiting for connect...\n";
        conntok->wait(); //阻塞当前线程直到token关联的动作完成。
        std::cout << "finish connect...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        // 2.send message
        // std::cout << "\n\nsending message with a msgptr ......\n";
        // mqtt::message_ptr pubmsg = mqtt::make_message("topic1", "this is a message");
        // pubmsg->set_qos(1);
        // client.publish(pubmsg); //由于用的智能指针，可以多次publish一个消息
        // client.publish(pubmsg);
        // client.publish(pubmsg)->wait_for(5);
        // std::cout << "send ok\n";
        // std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        //3.send message with deliver_token_ptr
        // std::cout << "\n\nsending message\n";
        // mqtt::delivery_token_ptr pubtok;
        // std::string msg = "deliver_token_ptr message";
        // pubtok = client.publish("topic1", msg.c_str(), msg.size(), 1, false);
        // pubtok = client.publish("topic1", msg.c_str(), msg.size(), 1, false);
        // pubtok = client.publish("topic1", msg.c_str(), msg.size(), 1, false);
        // pubtok = client.publish("topic1", msg.c_str(), msg.size(), 1, false);
        // pubtok->wait_for(5);
        // std::cout << "send ok\n";

        // 4.iaction_listener ???有什么用？有什么区别？
        std::cout << "\n\nsending message\n";
        action_listener listener;
        mqtt::message_ptr pubmsg = mqtt::make_message("topic1", "listener message");
        mqtt::message_ptr pubmsg2 = mqtt::make_message("topic1", "listener message");
        mqtt::delivery_token_ptr pubtok;
        mqtt::delivery_token_ptr pubtok2;
        pubmsg->set_qos(1);
        pubmsg2->set_qos(1);
        pubtok = client.publish(pubmsg, nullptr, listener);
        pubtok2 = client.publish(pubmsg2, nullptr, listener);
        pubtok->wait_for(5);
        pubtok2->wait_for(5);
        std::cout << "send ok\n";

        //5.subscribe

        //5.disconnect
        client.disconnect()->wait();
        std::cout << "disconnect ...ok" << std::endl;
    }
    catch (const mqtt::exception &exc)
    {
        std::cerr << exc.what() << std::endl;
        return 1;
    }
}