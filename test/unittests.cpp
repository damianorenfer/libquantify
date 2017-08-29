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
#include <quantify/unit.h>
#include <quantify/unitunsupportedoperationexception.h>

namespace Quantify {
namespace Test {

class UnitTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        meter = Unit("meter", "m", Dimensions(1));
        feet = Unit("feet", "ft", Dimensions(1), 0.3048);
        kelvin = Unit("Kelvin", "K", Dimensions(0, 0, 0, 0, 1));
        celsius = Unit("degree Celius", "°C", Dimensions(0, 0, 0, 0, 1), 1.0, -273.15);
        second = Unit("second", "s", Dimensions(0, 0, 1));
        kilogram = Unit("kilogram", "kg", Dimensions(0, 1));
    }

    // virtual void TearDown() {}
    Unit meter;
    Unit feet;
    Unit kelvin;
    Unit celsius;
    Unit second;
    Unit kilogram;
};

TEST_F(UnitTest, Equal)
{
    ASSERT_FALSE(meter.equals(feet));

    Unit squareMeter1 = Unit("Square meter", "m^2", Dimensions(2));
    Unit squareMeter2 = meter * meter;

    ASSERT_TRUE(squareMeter1.equals(squareMeter2));
    ASSERT_FALSE(squareMeter1.equals(meter));
}

TEST_F(UnitTest, IsCompatible)
{
    ASSERT_TRUE(meter.isCompatibleTo(feet));
    ASSERT_FALSE(meter.isCompatibleTo(kelvin));
    ASSERT_TRUE(kelvin.isCompatibleTo(celsius));
}

TEST_F(UnitTest, Power)
{
    Unit expected1 = Unit("meter^4", "m^4", Dimensions(4));
    Unit result1 = meter.power(4);

    ASSERT_TRUE(expected1.equals(result1));
    ASSERT_STREQ(expected1.getSymbol().c_str(), result1.getSymbol().c_str());
    ASSERT_STREQ(expected1.getName().c_str(), result1.getName().c_str());

    bool exceptionOccurred = false;
    try
    {
        Unit celsius2 = celsius.power(2);
    }
    catch (UnitUnsupportedOperationException &ex)
    {
        exceptionOccurred = true;
    }

    ASSERT_TRUE(exceptionOccurred);
}

TEST_F(UnitTest, Multiply)
{
    Unit expected1 = Unit("meter*meter", "m*m", Dimensions(2));
    Unit result1 = meter * meter;

    ASSERT_TRUE(expected1.equals(result1));
    ASSERT_STREQ(expected1.getSymbol().c_str(), result1.getSymbol().c_str());
    ASSERT_STREQ(expected1.getName().c_str(), result1.getName().c_str());

    // Newton
    Unit expected2 = Unit("Newton", "N", Dimensions(1, 1, -1));
    Unit result2 = (kilogram * meter) / second;

    ASSERT_TRUE(expected2.equals(result2));

    bool exceptionOccurred = false;

    try
    {
        Unit celsius2 = celsius.multiplyBy(kelvin);
    }
    catch (UnitUnsupportedOperationException &ex)
    {
        exceptionOccurred = true;
    }

    ASSERT_TRUE(exceptionOccurred);
}

TEST_F(UnitTest, Divide)
{
    Unit expected1 = Unit("meter/second", "m/s", Dimensions(1, 0, -1));
    Unit result1 = meter / second;

    ASSERT_TRUE(expected1.equals(result1));
    ASSERT_STREQ(expected1.getSymbol().c_str(), result1.getSymbol().c_str());
    ASSERT_STREQ(expected1.getName().c_str(), result1.getName().c_str());

    bool exceptionOccurred = false;

    try
    {
        Unit celsius2 = celsius.divideBy(3.0);
    }
    catch (UnitUnsupportedOperationException &ex)
    {
        exceptionOccurred = true;
    }

    ASSERT_TRUE(exceptionOccurred);
}

TEST_F(UnitTest, Add)
{
    Unit expected1 = Unit("degree Celsius", "°C", Dimensions(0, 0, 0, 0, 1), 1.0, 273.15);
    Unit result1 = kelvin + 273.15;

    ASSERT_TRUE(expected1.equals(result1));
}

TEST_F(UnitTest, Subtract)
{
    Unit expected1 = Unit("Kelvin", "K", Dimensions(0, 0, 0, 0, 1));
    Unit result1 = celsius - 273.15;

    ASSERT_TRUE(expected1.equals(result1));
}

}
}
