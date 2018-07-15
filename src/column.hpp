//
// Created by ryan on 14/07/18.
//

#ifndef QARROW_COLUMN_HPP
#define QARROW_COLUMN_HPP

#include "arrow/api.h"
#include "k.h"


class ColumnBase {
private:
    std::shared_ptr<arrow::Field> _field;

protected:
    std::shared_ptr<arrow::DataType> getDataType() {
        return _field->type();
    }

    std::shared_ptr<arrow::Array> _column;
    arrow::Status _s;

public:

    ColumnBase(K *column, char* name);

    std::shared_ptr<arrow::Field> getField() {
        return _field;
    };

    std::shared_ptr<arrow::Array> getColumn() {
        return _column;
    };

    bool ok() {
        return _s.ok();
    }

    arrow::Status getStatus() {
        return _s;
    }

};

#endif //QARROW_COLUMN_HPP
