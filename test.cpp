#include <gtest/gtest.h>

TEST(NvimCMakePlugin, ReportsNonZeroValueForFailedTest) {
    ASSERT_TRUE(false);
}


TEST(NvimCMakePlugin, ReportsFailedTestCorrectly) {
    int divisor = 0;
    ASSERT_EQ(10, 100/divisor);
}
