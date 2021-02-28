#include <iostream>

#include <gtest/gtest.h>

#include <cmp/cmp.tpp>

TEST(Test, example)
{
    struct CMP_TEST_t : Moon::Core::Component_t<CMP_TEST_t>
    {
        /* data */
    };

    EXPECT_EQ(1, CMP_TEST_t::getComponentType());
}