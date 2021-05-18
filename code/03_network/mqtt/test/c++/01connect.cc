#include "mqtt/async_client.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

class callback : public virtual mqtt::callback
{
public:
    virtual void connected(const std::string &cause) { std::cout << "callback::connected()"
                                                                 << " " << cause << std::endl; }
    virtual void connection_lost(const std::string &cause) { std::cout << "callback::connection_lost()"
                                                                       << " " << cause << std::endl; }
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
    }
    catch (const mqtt::exception &exc)
    {
        std::cerr << exc.what() << std::endl;
        return 1;
    }
}