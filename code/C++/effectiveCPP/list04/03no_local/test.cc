#include "test.hh"

#include <stdio.h>

QMManager::QMManager()
{
    printf("QMManager constructor\n");
    QMSqlite::instance()->do_something();
}

QMSqlite::QMSqlite()
{
    printf("QMSqlite constructor\n");
}
void QMSqlite::do_something()
{
    printf("QMSqlite do_something\n");
    printf("%d\n", num);
}

int main()
{
}

// 运行后，结果如下：可以看到，出现了错误。
/**
 * QMManager constructor
 * QMSqlite do_something
 * 0
 * QMSqlite constructor
 **/