#pragma once

#include "session.hpp"

#include <bits/types.h>
#include <memory>
#include <string>

namespace mapper
{
    class BaseCodec
    {
    public:
        BaseCodec();
        virtual ~BaseCodec();
        virtual std::string retrieve(Buffer &buf);
        virtual void send(std::string &msg, Buffer &buf);

    private:
    };

    class LengthCodec : public BaseCodec
    {
    public:
        LengthCodec();
        virtual ~LengthCodec();
        virtual std::string retrieve(Buffer &buf);
        virtual void send(std::string &msg, Buffer &buf);

    private:
        const uint32_t header_length_;
    };
} // namespace mapper
