/***************************************************************************************************
**      2020-03-31  HDBConfig 数据库配置(:/sql/dbconfig.json)
***************************************************************************************************/

#ifndef HDBCONFIG_H
#define HDBCONFIG_H

#include "HControlGlobal.h"
#include "HeCore/HSingleton3.h"
#include "HeFile/HFileGlobal.h"
#include <QtCore/QStringList>

HE_CORE_USE_NAMESPACE

HE_FILE_BEGIN_NAMESPACE
class HJson;
HE_FILE_END_NAMESPACE
HE_FILE_USE_NAMESPACE

HE_CONTROL_BEGIN_NAMESPACE

class HDBConfig
{
    H_SINGLETON3(HDBConfig)

private:
    explicit HDBConfig();
    virtual ~HDBConfig();

public:
    QString type() const;               // 数据库的类型, 如 QPSQL, QSQLITE, QMYSQL
    QString name() const;               // 数据库名
    QString hostName() const;           // 数据库主机的 IP
    QString username() const;           // 登录数据库的用户名
    QString password() const;           // 登录数据库的密码
    QString testOnBorrowSql() const;    // 验证连接的 SQL
    int  port() const;                  // 数据库的端口号
    int  maxWaitTime() const;           // 线程获取连接最大等待时间
    int  maxConnectionCount() const;    // 最大连接数
    int  waitInterval() const;          // 等待间隔
    bool isTestOnBorrow() const;        // 是否验证连接
    bool isDebug() const;               // 是否打印出执行的 SQL 语句和参数
    QStringList sqlFiles() const;       // SQL 语句文件, 可以是多个

public:
    bool setConigFile(const QString &fileName);

private:
    HJson *_json;
};

HE_CONTROL_END_NAMESPACE

#endif // HDBCONFIG_H