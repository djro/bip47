#include <gtest/gtest.h>
#include "designated_pubkey.cpp"

int main(int arc, char* argv[]) {
    testing::InitGoogleTest(&arc, argv);
    return RUN_ALL_TESTS();
}
