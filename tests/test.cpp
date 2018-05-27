
#include <iostream>

#include "gtest/gtest.h"

TEST(QConnectionTest, canConnect) {
    std::cout << "hello" << std::endl;
    EXPECT_TRUE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
