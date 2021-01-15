#include "codec.hpp"

namespace mapper
{
    BaseCodec::BaseCodec()
    {
    }

    BaseCodec::~BaseCodec()
    {
    }

    std::string BaseCodec::retrieve(Buffer &buf)
    {
        std::string str;
        return std::move(str);
    }
    void BaseCodec::send(std::string &msg, Buffer &buf)
    {
        buf.append(msg);
    }

    LengthCodec::LengthCodec()
        : header_length_(sizeof(uint32_t))
    {
    }

    LengthCodec::~LengthCodec()
    {
    }

    std::string LengthCodec::retrieve(Buffer &buf)
    {
        std::string str;
        void *addr = buf.peekInt32();
        if (nullptr == addr)
        {
            return std::move(str);
        }

        uint32_t length = *(static_cast<uint32_t *>(addr));

        // todododododoododododododododoododododododo
        if (buf.getReadableSize() >= length + header_length_)
        {
            std::string msg = std::move(buf.retrieveAsString(length, length + header_length_));
            return std::move(msg);
        }
        else
        {
            return str;
        }
    }

    void LengthCodec::send(std::string &msg, Buffer &buf)
    {
        uint32_t body_length = static_cast<uint32_t>(msg.size());
        buf.appendInt32(boost::asio::detail::socket_ops::host_to_network_long(body_length));
        buf.append(msg);
    }

} // namespace mapper
