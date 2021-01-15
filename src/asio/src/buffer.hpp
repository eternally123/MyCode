#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace mapper
{
    class Buffer
    {
        friend class Session;

    public:
        Buffer();
        virtual ~Buffer();

        int getReadableSize();
        int getWriteableSize();

        int append(std::vector<char> &vec, int begin, int end);
        int append(std::string &str);
        int appendInt32(uint32_t val);
        int preAppend(std::vector<char> &vec, int begin, int end);
        int retrieve(std::vector<char> &vec);
        std::string retrieveAsString(int size);
        std::string retrieveAsString(int begin, int end);

        void *peek();
        void *peekInt32();

    private:
        std::vector<char> buf_;
    };
} // namespace mapper
