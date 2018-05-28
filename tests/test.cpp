
#include <iostream>

#include "gtest/gtest.h"
#include "qarrow.hpp"

TEST(QConnectionTest, canConnect) {
    auto foo = QConnection("localhost", 1234);
    int ok = foo.connect();
    foo.close();
    EXPECT_GE(ok, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
