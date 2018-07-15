//
// Created by ryan on 14/07/18.
//

#include "column_types.hpp"


Time64Column::Time64Column(K *column, char *name, arrow::MemoryPool *pool, int rowNums)
        : ColumnBase(column, name) {
    arrow::Time64Builder builder(getDataType(), pool);
    K col = *column;
    arrow::Status s;
    for(int j=0;j<rowNums;j++) {
        int val = ((int*)((col)->G0))[j];

        s = builder.Append(val);
        if (!s.ok()) {
            break;
        }
    }
    if (s.ok()) {
        std::shared_ptr<arrow::Array> array;
        _s = builder.Finish(&array);
        _column = array;
    } else {
        _s = s;
    }
}


DoubleColumn::DoubleColumn(K *column, char *name, arrow::MemoryPool *pool, int numRows) : ColumnBase(column, name) {

    arrow::DoubleBuilder builder(getDataType(), pool);
    K col = *column;
    arrow::Status s;
    for(int j=0;j<numRows;j++) {
        double val = ((double*)((col)->G0))[j];

        s = builder.Append(val);
        if (!s.ok()) {
            break;
        }
    }
    if (s.ok()) {
        std::shared_ptr<arrow::Array> array;
        _s = builder.Finish(&array);
        _column = array;
    } else {
        _s = s;
    }
}

SymbolColumn::SymbolColumn(K *column, char *name, arrow::MemoryPool *pool, int numRows) : ColumnBase(column, name) {

    arrow::StringDictionaryBuilder builder(getDataType(), pool);
    K col = *column;
    arrow::Status s;
    for(int j=0;j<numRows;j++) {
        char* val = ((char**)((col)->G0))[j];

        s = builder.Append(val);
        if (!s.ok()) {
            break;
        }
    }
    if (s.ok()) {
        std::shared_ptr<arrow::Array> array;
        _s = builder.Finish(&array);
        _column = array;
    } else {
        _s = s;
    }
}


Int32Column::Int32Column(K *column, char *name, arrow::MemoryPool *pool, int numRows) : ColumnBase(column, name) {

    arrow::Int32Builder builder(getDataType(), pool);
    K col = *column;
    arrow::Status s;
    for(int j=0;j<numRows;j++) {
        int val = ((int*)((col)->G0))[j];

        s = builder.Append(val);
        if (!s.ok()) {
            break;
        }
    }
    if (s.ok()) {
        std::shared_ptr<arrow::Array> array;
        _s = builder.Finish(&array);
        _column = array;
    } else {
        _s = s;
    }
}
