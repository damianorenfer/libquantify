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

#pragma once

#include <ostream>

#define QUANTIFY_DIMENSIONS_COUNT 7
#define QUANTIFY_DIMENSIONS_LENGTH_ID 0
#define QUANTIFY_DIMENSIONS_MASS_ID 1
#define QUANTIFY_DIMENSIONS_TIME_ID 2
#define QUANTIFY_DIMENSIONS_ELECTRIC_CURRENT_ID 3
#define QUANTIFY_DIMENSIONS_THERMODYNAMIC_TEMPERATURE_ID 4
#define QUANTIFY_DIMENSIONS_AMOUNT_OF_SUBSTANCE_ID 5
#define QUANTIFY_DIMENSIONS_LUMINOUS_INTENSITY_ID 6

namespace Quantify {

class Dimensions
{
public:    
    Dimensions(char length = 0, char mass = 0, char time = 0, char electricCurrent = 0, char thermodynamicTemperature = 0, char amountOfSubstance = 0, char luminousIntensity = 0);
    Dimensions(const Dimensions &other);
    Dimensions(Dimensions &&other);
    ~Dimensions() noexcept {}

    Dimensions &operator=(const Dimensions &other);
    Dimensions &operator=(Dimensions &&other);

    char getLength() const;
    char getMass() const;
    char getTime() const;
    char getElectricCurrent() const;
    char getThermodynamicTemperature() const;
    char getAmountOfSubstance() const;
    char getLuminousIntensity() const;

    void setLength(char value);
    void setMass(char value);
    void setTime(char value);
    void setElectricCurrent(char value);
    void setThermodynamicTemperature(char value);
    void setAmountOfSubstance(char value);
    void setLuminousIntensity(char value);

    bool equals(const Dimensions &other) const;
    Dimensions multiplyBy(const Dimensions &other) const;
    Dimensions divideBy(const Dimensions &other) const;
    Dimensions power(int power) const;

    bool operator==(const Dimensions &other) const { return equals(other); }
    bool operator!=(const Dimensions &other) const { return !equals(other); }
    Dimensions operator*(const Dimensions &other) const { return multiplyBy(other); }
    Dimensions operator/(const Dimensions &other) const { return divideBy(other); }
    friend std::ostream& operator <<(std::ostream& outputStream, const Dimensions& dimensions)
    {
        outputStream << "[";
        for(int i=0; i<QUANTIFY_DIMENSIONS_COUNT; ++i)
        {
            outputStream << (int)dimensions.dimensions[i];
            if (i < QUANTIFY_DIMENSIONS_COUNT - 1)
                outputStream << ", ";
        }
        outputStream << "]";

        return outputStream;
    }

private:
    void copyFrom(const Dimensions &other);
    void moveFrom(Dimensions &other);

    char dimensions[QUANTIFY_DIMENSIONS_COUNT];
};

}
