#include <iostream>
#include "qarrow.hpp"
#include "k.h"

int QConnection::connect() {
    std::string userpass;
    if (!this->_username.empty()) {
        userpass = this->_username + ":" + this->_password;
    }
    int retval = khpu(this->_hostname.c_str(), this->_port, userpass.c_str());
    this->_handle = retval;
    return retval; //todo check if ok, cleanup if not
}

void QConnection::close() {
    if (this->_handle > 0) {
        kclose(this->_handle);
    }
}
