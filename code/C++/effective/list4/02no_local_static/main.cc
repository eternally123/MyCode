#include "Directory.hh"
#include "filesystem.hh"

#include <iostream>
using namespace std;

extern Directory d;
int main()
{
    // d.print();
}

/**
 * 这个例子还没搞明白，依据effective来编写的。
 * 只是在用extern和static时遇到问题没想到如何利用这两个关键字构造出书中描述的错误场景
 * 书中描述的全局static变量暂时搁置。
 * 但是全局变量的初始化在no_local文件夹中
 **/
