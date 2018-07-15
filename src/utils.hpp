#include <utility>

#ifndef QARROW_UTILS_H
#define QARROW_UTILS_H

#include "arrow/api.h"
#include "column.hpp"
#include <iostream>

std::shared_ptr<arrow::DataType> getType(signed char type);

std::shared_ptr<ColumnBase> getBuilder(arrow::MemoryPool* pool, char* name, int numRow, K* column);

void print(std::shared_ptr<arrow::Table> table, std::ostream* stream);

void print(std::shared_ptr<arrow::Table> table) ;

#endif