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

enum ErrNo {
    OK, NETWORK_ERR, NAME_PASS_ERR, INFO_ERR
};

using namespace rapidjson;

extern ErrNo login(const QString &name, const QString &pass);

#endif // OPERATION_H
