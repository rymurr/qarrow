//
// Created by ryan on 14/07/18.
//

#ifndef QARROW_TIME64COLUMN_HPP
#define QARROW_TIME64COLUMN_HPP

#include "k.h"
#include "arrow/api.h"
#include "column.hpp"

class Time64Column : public ColumnBase {


public:
    Time64Column(K *column, char *name, arrow::MemoryPool *pool, int numRows);

};

class DoubleColumn : public ColumnBase {

public:
    DoubleColumn(K *column, char *name, arrow::MemoryPool *pool, int numRows);

};


class SymbolColumn : public ColumnBase {

public:
    SymbolColumn(K *column, char *name, arrow::MemoryPool *pool, int numRows);

};


class Int32Column : public ColumnBase {

public:
    Int32Column(K *column, char *name, arrow::MemoryPool *pool, int numRows);

};


#endif //QARROW_TIME64COLUMN_HPP
