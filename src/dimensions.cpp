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

#include <quantify/dimensions.h>
#include <cstring>

namespace Quantify {

Dimensions::Dimensions(char length, char mass, char time, char electricCurrent, char thermodynamicTemperature, char amountOfSubstance, char luminousIntensity)
{
    setLength(length);
    setMass(mass);
    setTime(time);
    setElectricCurrent(electricCurrent);
    setThermodynamicTemperature(thermodynamicTemperature);
    setAmountOfSubstance(amountOfSubstance);
    setLuminousIntensity(luminousIntensity);
}

Dimensions::Dimensions(const Dimensions &other)
{
    copyFrom(other);
}

Dimensions::Dimensions(Dimensions &&other)
{
    moveFrom(other);
}

Dimensions &Dimensions::operator=(const Dimensions &other)
{
    if(this != &other)
    {
        copyFrom(other);
    }

    return *this;
}

Dimensions &Dimensions::operator=(Dimensions &&other)
{
    if(this != &other)
    {
        moveFrom(other);
    }

    return *this;
}

char Dimensions::getLength() const
{
    return dimensions[QUANTIFY_DIMENSIONS_LENGTH_ID];
}

char Dimensions::getMass() const
{
    return dimensions[QUANTIFY_DIMENSIONS_MASS_ID];
}

char Dimensions::getTime() const
{
    return dimensions[QUANTIFY_DIMENSIONS_TIME_ID];
}

char Dimensions::getElectricCurrent() const
{
    return dimensions[QUANTIFY_DIMENSIONS_ELECTRIC_CURRENT_ID];
}

char Dimensions::getThermodynamicTemperature() const
{
    return dimensions[QUANTIFY_DIMENSIONS_THERMODYNAMIC_TEMPERATURE_ID];
}

char Dimensions::getAmountOfSubstance() const
{
    return dimensions[QUANTIFY_DIMENSIONS_AMOUNT_OF_SUBSTANCE_ID];
}

char Dimensions::getLuminousIntensity() const
{
   return dimensions[QUANTIFY_DIMENSIONS_LUMINOUS_INTENSITY_ID];
}

void Dimensions::setLength(char value)
{
    dimensions[QUANTIFY_DIMENSIONS_LENGTH_ID] = value;
}

void Dimensions::setMass(char value)
{
    dimensions[QUANTIFY_DIMENSIONS_MASS_ID] = value;
}

void Dimensions::setTime(char value)
{
    dimensions[QUANTIFY_DIMENSIONS_TIME_ID] = value;
}

void Dimensions::setElectricCurrent(char value)
{
    dimensions[QUANTIFY_DIMENSIONS_ELECTRIC_CURRENT_ID] = value;
}

void Dimensions::setThermodynamicTemperature(char value)
{
    dimensions[QUANTIFY_DIMENSIONS_THERMODYNAMIC_TEMPERATURE_ID] = value;
}

void Dimensions::setAmountOfSubstance(char value)
{
    dimensions[QUANTIFY_DIMENSIONS_AMOUNT_OF_SUBSTANCE_ID] = value;
}

void Dimensions::setLuminousIntensity(char value)
{
    dimensions[QUANTIFY_DIMENSIONS_LUMINOUS_INTENSITY_ID] = value;
}

bool Dimensions::equals(const Dimensions &other) const
{
    return memcmp(&dimensions, &(other.dimensions), QUANTIFY_DIMENSIONS_COUNT) == 0;
}

Dimensions Dimensions::multiplyBy(const Dimensions &other) const
{
    Dimensions result = *this;

    for(int i=0; i<QUANTIFY_DIMENSIONS_COUNT; ++i)
        result.dimensions[i] += other.dimensions[i];

    return result;
}

Dimensions Dimensions::divideBy(const Dimensions &other) const
{
    Dimensions result = *this;

    for(int i=0; i<QUANTIFY_DIMENSIONS_COUNT; ++i)
        result.dimensions[i] -= other.dimensions[i];

    return result;
}

Dimensions Dimensions::power(int power) const
{
    Dimensions result = *this;

    for(int i=0; i<QUANTIFY_DIMENSIONS_COUNT; ++i)
        result.dimensions[i] *= power;

    return result;
}

void Dimensions::copyFrom(const Dimensions &other)
{
    setLength(other.getLength());
    setMass(other.getMass());
    setTime(other.getTime());
    setElectricCurrent(other.getElectricCurrent());
    setThermodynamicTemperature(other.getThermodynamicTemperature());
    setAmountOfSubstance(other.getAmountOfSubstance());
    setLuminousIntensity(other.getLuminousIntensity());
}

void Dimensions::moveFrom(Dimensions &other)
{
    setLength(other.getLength());
    setMass(other.getMass());
    setTime(other.getTime());
    setElectricCurrent(other.getElectricCurrent());
    setThermodynamicTemperature(other.getThermodynamicTemperature());
    setAmountOfSubstance(other.getAmountOfSubstance());
    setLuminousIntensity(other.getLuminousIntensity());

    memset(other.dimensions, 0, QUANTIFY_DIMENSIONS_COUNT);
}

}
