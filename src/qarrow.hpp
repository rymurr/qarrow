#ifndef  QARROW_H
#define QARROW_H

#include <string>
#include <utility>
#include "arrow/api.h"
#include "column.hpp"


class QConnection {
private:
    const std::string _hostname;
    const int _port;
    const std::string _username;
    const std::string _password;

    int _handle = -1;
public:
    QConnection(std::string hostname, int port) : _hostname(std::move(hostname)), _port(port), _username(""),
                                                  _password("") {}

    QConnection(std::string hostname, int port, std::string username, std::string password) : _hostname(
            std::move(hostname)), _port(port), _username(
            std::move(username)), _password(std::move(password)) {}

    int connect();
    void close();
    std::shared_ptr<arrow::Table> query(std::string query);
};


#endif