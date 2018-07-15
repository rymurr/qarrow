//
// Created by ryan on 15/07/18.
//

#include "utils.hpp"
#include "column.hpp"

ColumnBase::ColumnBase(K *column, char *name) {
    K firstObj = column[0];
    auto type = getType(firstObj->t);
    _field = arrow::field(name, type);
}
