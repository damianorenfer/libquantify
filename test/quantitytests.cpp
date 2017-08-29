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
#include <quantify/standardunits.h>
#include <quantify/quantity.h>
#include <quantify/utils.h>
#include <quantify/incompatibleunitsexception.h>
#include <quantify/unitunsupportedoperationexception.h>
#include <iostream>

using namespace Quantify::StandardUnits;

namespace Quantify {
namespace Test {

class QuantityTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        oneMeter = Quantity(LengthUnits::meter, 1.0);
        oneSecond = Quantity(TimeUnits::second, 1.0);
        oneKelvin = Quantity(TemperatureUnits::kelvin, 1.0);
        oneCelsius = Quantity(TemperatureUnits::degreeCelsius, 1.0);
    }
    Quantity oneMeter;    
    Quantity oneSecond;
    Quantity oneKelvin;
    Quantity oneCelsius;
    // virtual void TearDown() {}
};

TEST_F(QuantityTest, ConvertTo)
{    
    Quantity oneFoot = oneMeter.convertTo(LengthUnits::foot);
    ASSERT_TRUE(Utils::areEqual(Utils::round(oneFoot.getValue(), 5), 3.28084));

    Quantity oneKelvinInCelsius = oneKelvin.convertTo(TemperatureUnits::degreeCelsius);
    ASSERT_TRUE(Utils::areEqual(oneKelvinInCelsius.getValue(), -272.15));

    Quantity oneKelvinInFahrenheit = oneKelvinInCelsius.convertTo(TemperatureUnits::degreeFahrenheit);
    ASSERT_TRUE(Utils::areEqual(oneKelvinInFahrenheit.getValue(), -457.87));    
}

TEST_F(QuantityTest, Equal)
{
    Quantity oneFoot(LengthUnits::foot, 1.0);
    Quantity oneFootInMeters(LengthUnits::meter, 0.3048);

    ASSERT_TRUE(oneFoot.equals(oneFootInMeters));
    ASSERT_FALSE(oneFoot.equals(oneMeter));

    bool exceptionOccured = false;
    try
    {
        oneFoot.equals(oneSecond);
    }
    catch (IncompatibleUnitsException &ex)
    {
        exceptionOccured = true;
    }

    ASSERT_TRUE(exceptionOccured);

}

TEST_F(QuantityTest, LessThan)
{
    Quantity oneFoot(LengthUnits::foot, 1.0);
    ASSERT_TRUE(oneFoot.lessThan(oneMeter));


    bool exceptionOccured = false;
    try
    {
        oneFoot.lessThan(oneSecond);
    }
    catch (IncompatibleUnitsException &ex)
    {
        exceptionOccured = true;
    }

    ASSERT_TRUE(exceptionOccured);
}

TEST_F(QuantityTest, GreaterThan)
{
    Quantity oneFoot(LengthUnits::foot, 1.0);
    ASSERT_TRUE(oneMeter.greaterThan(oneFoot));


    bool exceptionOccured = false;
    try
    {
        oneFoot.greaterThan(oneSecond);
    }
    catch (IncompatibleUnitsException &ex)
    {
        exceptionOccured = true;
    }

    ASSERT_TRUE(exceptionOccured);
}

TEST_F(QuantityTest, Add)
{
    Quantity oneFoot(LengthUnits::foot, 1.0);
    Quantity twoMeters = oneMeter.add(1.0);
    ASSERT_TRUE(Utils::areEqual(twoMeters.getValue(), 2.0));

    Quantity threeMeters = oneMeter.add(twoMeters);
    ASSERT_TRUE(Utils::areEqual(threeMeters.getValue(), 3.0));

    Quantity oneMeterAndOneFoot = oneMeter.add(oneFoot);
    ASSERT_TRUE(Utils::areEqual(oneMeterAndOneFoot.getValue(), 1.3048));

    bool exceptionOccured = false;
    try
    {
        oneMeter.add(oneSecond);
    }
    catch (IncompatibleUnitsException &ex)
    {
        exceptionOccured = true;
    }

    ASSERT_TRUE(exceptionOccured);
}

TEST_F(QuantityTest, Subtract)
{
    Quantity oneFoot(LengthUnits::foot, 1.0);
    Quantity zeroMeter = oneMeter.subtract(1.0);
    ASSERT_TRUE(Utils::areEqual(zeroMeter.getValue(), 0.0));

    Quantity oneMeterMinusOneFoot = oneMeter.subtract(oneFoot);
    ASSERT_TRUE(Utils::areEqual(oneMeterMinusOneFoot.getValue(), 0.6952));

    bool exceptionOccured = false;
    try
    {
        oneMeter.subtract(oneSecond);
    }
    catch (IncompatibleUnitsException &ex)
    {
        exceptionOccured = true;
    }

    ASSERT_TRUE(exceptionOccured);
}

TEST_F(QuantityTest, Multiply)
{        
    Quantity result = (2.0 * oneKelvin) * oneMeter;
    ASSERT_TRUE(result == 2.0);
    ASSERT_TRUE(result.getUnit().getSymbol() == "K*m");

    bool exceptionOccured = false;
    try
    {
        oneMeter.multiplyBy(oneCelsius);
    }
    catch (UnitUnsupportedOperation &ex)
    {
        exceptionOccured = true;
    }

    ASSERT_TRUE(exceptionOccured);
}

TEST_F(QuantityTest, Divide)
{
    Quantity result = oneKelvin / (2.0 * oneMeter);
    ASSERT_TRUE(result == 0.5);
    ASSERT_TRUE(result.getUnit().getSymbol() == "K/m");

    bool exceptionOccured = false;
    try
    {
        oneMeter.divideBy(oneCelsius);
    }
    catch (UnitUnsupportedOperation &ex)
    {
        exceptionOccured = true;
    }

    ASSERT_TRUE(exceptionOccured);
}

TEST_F(QuantityTest, ToInt)
{
    Quantity meters = 1.49 * oneMeter;
    int result = meters.toInt();
    int expected = 1;

    ASSERT_TRUE(result == expected);

    Quantity meters2 = 1.50 * oneMeter;
    int result2 = meters2.toInt();
    int expected2 = 2;

    ASSERT_TRUE(result2 == expected2);
}

}
}
