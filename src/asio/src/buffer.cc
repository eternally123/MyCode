#include "buffer.hpp"

namespace mapper
{
    Buffer::Buffer()
    {
        buf_.resize(10240);
    }

    Buffer::~Buffer()
    {
    }

    int Buffer::getReadableSize()
    {
        return buf_.size();
    }

    int Buffer::getWriteableSize()
    {
        return -1;
    }

    int Buffer::append(std::vector<char> &vec, int begin, int end)
    {
        buf_.insert(buf_.end(), vec.begin() + begin, vec.begin() + end);
    }

    int Buffer::append(std::string &str)
    {
        buf_.insert(buf_.end(), str.begin(), str.end());
    }

    int Buffer::appendInt32(uint32_t val)
    {
        buf_.push_back(*((char *)(&val) + 0));
        buf_.push_back(*((char *)(&val) + 1));
        buf_.push_back(*((char *)(&val) + 2));
        buf_.push_back(*((char *)(&val) + 3));
    }

    int Buffer::preAppend(std::vector<char> &vec, int begin, int end)
    {
        buf_.insert(buf_.begin(), vec.begin() + begin, vec.begin() + end);
    }

    int Buffer::retrieve(std::vector<char> &vec)
    {
        vec.insert(vec.end(), buf_.begin(), buf_.end());
        buf_.clear();
    }

    std::string Buffer::retrieveAsString(int size)
    {
        std::string str;
        str.insert(str.end(), buf_.begin(), buf_.begin() + size);
        buf_.erase(buf_.begin(), buf_.begin() + size);
        return std::move(str);
    }

    std::string Buffer::retrieveAsString(int begin, int end)
    {
        std::string str;
        str.insert(str.end(), buf_.begin() + begin, buf_.begin() + end);
        buf_.erase(buf_.begin() + begin, buf_.begin() + end);
        return std::move(str);
    }

    void *Buffer::peek()
    {
        return (void *)buf_[0];
    }

    void *Buffer::peek()
    {
        if (buf_.size() >= 4)
        {
            return (void *)buf_[0];
        }
        return nullptr;
    }

} // namespace mapper