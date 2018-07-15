
#include <iostream>

#include "gtest/gtest.h"
#include "qarrow.hpp"

TEST(QConnectionTest, canConnect) {
    auto foo = QConnection("localhost", 1234);
    int ok = foo.connect();
    foo.close();
    EXPECT_GE(ok, 1);
}


TEST(QConnectionTest, canQuery) {
    auto foo = QConnection("localhost", 1234);
    int ok = foo.connect();
    auto x = foo.query("select from trade");
    foo.close();
    EXPECT_FALSE(x == nullptr);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
