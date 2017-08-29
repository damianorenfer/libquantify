/*
 * MIT License
 *
 * Copyright (c) 2017 Damiano Renfer
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <gtest/gtest.h>
#include <quantify/dimensions.h>

namespace Quantify {
namespace Test {

class DimensionsTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        d1 = Dimensions(1, 2, 3);
        d2 = Dimensions(1, 2, 3);
        d3 = Dimensions(4, 5, 6);
    }

    // virtual void TearDown() {}

    Dimensions d1;
    Dimensions d2;
    Dimensions d3;
};

TEST_F(DimensionsTest, Equal)
{
    ASSERT_TRUE(d1 == d2);
    ASSERT_FALSE(d2 == d3);
}

TEST_F(DimensionsTest, Multiply)
{
    Dimensions result = d1 * d2;
    Dimensions expected(2, 4, 6);

    ASSERT_TRUE(result.equals(expected));
}

TEST_F(DimensionsTest, Divide)
{
    Dimensions result1 = d1 / d2;
    Dimensions expected1(0, 0, 0);

    ASSERT_TRUE(result1.equals(expected1));

    Dimensions result2 = d1 / d3;
    Dimensions expected2(-3, -3, -3);

    ASSERT_TRUE(result2.equals(expected2));
}

TEST_F(DimensionsTest, Power)
{

    Dimensions result1 = d1.power(2);
    Dimensions expected1(2, 4, 6);

    ASSERT_TRUE(result1.equals(expected1));

    Dimensions result2 = d3.power(5);
    Dimensions expected2(20, 25, 30);

    ASSERT_TRUE(result2.equals(expected2));
}

}
}
