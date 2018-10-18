#ifndef OPERATION_H
#define OPERATION_H
#include "config.h"
#include <QDebug>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/pointer.h>
#include <QCryptographicHash>
#include <QDate>
#include "salary.h"
#include "user.h"
#include <vector>

#define BUF_SIZE 65536

enum ErrNo {
    OK, NETWORK_ERR, NAME_PASS_ERR, INFO_ERR
};

using namespace rapidjson;

extern ErrNo login(const QString &name, const QString &pass);

extern ErrNo query_salary(const QDate &start, const QDate &end, const QString &id, std::vector<Salary> &result);

#endif // OPERATION_H
