class QMManager
{
protected:
    static QMManager instance_;
    QMManager();
    ~QMManager(){};

public:
    static QMManager *instance()
    {
        return &instance_;
    }
};

class QMSqlite
{
protected:
    static QMSqlite instance_;
    QMSqlite();
    ~QMSqlite(){};

public:
    static QMSqlite *instance()
    {
        return &instance_;
    }
    void do_something();

private:
    int num = 10;
};

QMManager QMManager::instance_;
QMSqlite QMSqlite::instance_;