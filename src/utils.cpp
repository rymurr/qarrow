
#include "utils.hpp"
#include "column_types.hpp"

std::shared_ptr<arrow::DataType> getType(signed char type) {
    switch(type) {
        case(6): {
            return arrow::int32();
        }
        case(9): {
            return arrow::float64();
        }
        case(11): {
            return arrow::utf8();
        }
        case(19): {
            return arrow::time64(arrow::TimeUnit::NANO);
        }
    }
    return std::shared_ptr<arrow::DataType>();
}

std::shared_ptr<ColumnBase> getBuilder(arrow::MemoryPool* pool, char* name, int numRow, K* column) {
    int type = (*column)->t;
    switch(type) {
        case(6): {
            return std::make_shared<ColumnBase>(Int32Column(column, name, pool, numRow));
        }
        case(9): {
            return std::make_shared<ColumnBase>(DoubleColumn(column, name, pool, numRow));
        }
        case(11): {
            return std::make_shared<ColumnBase>(SymbolColumn(column, name, pool, numRow));
        }
        case(19): {
            return std::make_shared<ColumnBase>(Time64Column(column, name, pool, numRow));
        }
        default:
            return std::shared_ptr<ColumnBase>();
    }
}

void print(std::shared_ptr<arrow::Table> table) {
    std::ostream soutstream(std::cout.rdbuf());
    print(std::move(table), &soutstream);
}

void print(std::shared_ptr<arrow::Table> table, std::ostream *stream) {
    std::shared_ptr<arrow::Schema> schema = table->schema();
    arrow::PrettyPrint(*schema, arrow::PrettyPrintOptions(), stream);
    std::cout << std::endl;
    for (int i=0; i<table->num_columns();i++) {
        std::shared_ptr<arrow::Column> col = table->column(i);
        for (int j=0;j<col->data()->num_chunks();j++) {
            auto c = col->data()->chunk(j);
            arrow::PrettyPrint(*c, 4, stream);
        }
        std::cout << std::endl;
    }

}
