#include "session.hpp"

namespace mapper
{
    TcpSession::TcpSession(boost::asio::ip::tcp::socket socket)
        : socket_(std::move(socket)),
          read_buffer_(),
          write_buffer_(),
          codec_ptr_(std::make_shared<BaseCodec>())
    {
        temporary_read_buffer_.reserve(1024);
        temporary_write_buffer_.reserve(1024);
    }

    TcpSession::~TcpSession()
    {
    }

    void TcpSession::start()
    {
        doRead();
    }

    void TcpSession::write(std::string &msg)
    {
        // 数据通过codec写入buffer
        codec_ptr_->send(msg, write_buffer_);
        doWrite();
    }

    void TcpSession::setonMessageCallback(std::function<void(TcpSession &s, std::string &msg)> func)
    {
        message_callback_ = func;
    }

    void TcpSession::doRead()
    {
        auto buf = boost::asio::buffer(temporary_read_buffer_);
        socket_.async_read_some(buf, std::bind(&TcpSession::readCallback, this));
    }

    void TcpSession::doWrite()
    {
        write_buffer_.retrieve(temporary_write_buffer_);
        if (0 != temporary_write_buffer_.size())
        {
            auto buf = boost::asio::buffer(temporary_write_buffer_);
            socket_.async_write_some(buf, std::bind(&TcpSession::writeCallback, this));
        }
    }

    void TcpSession::readCallback(boost::system::error_code ec,
                                  std::size_t length)
    {
        if (1024 == length)
        {
            // temporary_read_buffer_.resize(2048);
        }
        // 将数据放入buffer中
        read_buffer_.append(temporary_read_buffer_, 0, length - 1);
        temporary_read_buffer_.clear();
        // assert()

        // 读到报文后，调用处理函数处理
        std::string msg = codec_ptr_->retrieve(read_buffer_);
        if (0 != msg.size())
        {
            message_callback_(*this, msg);
        }
        // 继续读
        doRead();
    }

    void TcpSession::writeCallback(boost::system::error_code ec,
                                   std::size_t length)
    {
        write_buffer_.preAppend(temporary_write_buffer_, length, temporary_write_buffer_.size() - 1);
        temporary_write_buffer_.clear();
        doWrite();
    }

} // namespace mapper
