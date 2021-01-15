#pragma once
#include "server.hpp"
#include "session.hpp"
#include "codec.hpp"

#include <memory>
#include <string>

namespace mapper
{
    class MapperServer
    {
    public:
        MapperServer();
        ~MapperServer();
        void onMsgCallback(TcpSession &s, std::string &msg);

    private:
        // TcpServer server_;
    };
} // namespace mapper

namespace mapper
{
    MapperServer::MapperServer()
    {
    }
    MapperServer::~MapperServer()
    {
    }

    void MapperServer::onMsgCallback(TcpSession &s, std::string &msg)
    {
        // todo.........................
        /*
            报文处理。。。。。。。
        */
    }
} // namespace mapper