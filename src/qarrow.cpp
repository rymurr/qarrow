#include <iostream>
#include "qarrow.hpp"
#include "k.h"
#include "column_types.hpp"
#include "utils.hpp"


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

std::shared_ptr<arrow::Table> QConnection::query(std::string query) {
    K kobj = k(this->_handle, query.c_str(), (K)0);
    if (kobj->t == 98) {
        //todo process keyed table
        K keys = ((K*)(kobj->k)->G0)[0];
        K values = ((K*)(kobj->k)->G0)[1];
        int colNumber = keys->n;
        int rowNumber = ((K*)((values)->G0))[0]->n;

        arrow::MemoryPool* pool = arrow::default_memory_pool();

        std::vector<std::shared_ptr<arrow::Field>> schema_vector;
        std::vector<std::shared_ptr<arrow::Array>> data_vector;
        for (int i=0;i<colNumber;i++) {

            char *name = ((char **) ((keys)->G0))[i];
            K obj = ((K*)((values)->G0))[i];
            std::shared_ptr<ColumnBase> builder = getBuilder(pool, name, rowNumber, &obj);
            schema_vector.push_back(builder->getField());
            data_vector.push_back(builder->getColumn());
        }


        auto schema = std::make_shared<arrow::Schema>(schema_vector);

        return arrow::Table::Make(schema, data_vector);
    }

    return nullptr;
}
