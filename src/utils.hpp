#include "arrow/api.h"
#include "column.hpp"

std::shared_ptr<arrow::DataType> getType(signed char type);

std::shared_ptr<ColumnBase> getBuilder(arrow::MemoryPool* pool, char* name, int numRow, K* column);
