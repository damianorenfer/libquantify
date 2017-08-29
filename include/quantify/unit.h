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

#include <string>
#include <sstream>
#include <ostream>
#include "dimensions.h"

namespace Quantify {

class Unit
{
public:        
    Unit(std::string name = "", std::string symbol = "", Dimensions dimensions = Dimensions(), double factor = 1.0, double offset = 0.0);
    Unit(std::string name, std::string symbol, Unit baseUnit) : Unit(name, symbol, baseUnit.getDimensions(), baseUnit.getFactor(), baseUnit.getOffset()){}
    Unit(const Unit &other);
    Unit(Unit &&other);
    ~Unit() noexcept {}

    Unit &operator=(const Unit &other);
    Unit &operator=(Unit &&other);

    void assertCompatibility(const Unit &other) const;
    void assertCanMultiply() const;
    void assertCanDivide() const;
    bool isCompatibleTo(const Unit &other) const;
    Unit power(int power) const;
    bool equals(const Unit &other) const;
    bool lessThan(const Unit &other) const;
    bool greaterThan(const Unit &other) const;
    Unit add(double value) const;
    Unit subtract(double value) const;
    Unit multiplyBy(const Unit &other) const;
    Unit multiplyBy(double value) const;
    Unit divideBy(const Unit &other) const;
    Unit divideBy(double value) const;

    bool operator==(const Unit &other) const { return equals(other); }
    bool operator!=(const Unit &other) const { return !equals(other); }
    bool operator<(const Unit &other) const { return lessThan(other); }
    bool operator<=(const Unit &other) const  { return lessThan(other) || equals(other); }
    bool operator>(const Unit &other) const { return greaterThan(other); }
    bool operator>=(const Unit &other) const { return greaterThan(other) || equals(other); }
    friend Unit operator+(const Unit &left, double right) { return left.add(right); }
    friend Unit operator+(double left, const Unit &right) { return right.add(left); }
    friend Unit operator-(const Unit &left, double right) { return left.subtract(right); }
    friend Unit operator-(double left, const Unit &right) { return right.subtract(left); }
    friend Unit operator*(const Unit &left, const Unit &right) { return left.multiplyBy(right); }
    friend Unit operator*(const Unit &left, double right) { return left.multiplyBy(right); }
    friend Unit operator*(double left, const Unit &right) { return right.multiplyBy(left); }
    friend Unit operator/(const Unit &left, const Unit &right) { return left.divideBy(right); }
    friend Unit operator/(const Unit &left, double right) { return left.divideBy(right); }
    friend Unit operator/(double left, const Unit &right)
    {
        right.assertCanDivide();

        std::stringstream nameStream;
        nameStream << left << "/" << right.getName();

        std::stringstream symbolStream;
        symbolStream << left << "/" << right.getSymbol();

        return Unit(nameStream.str(), symbolStream.str(), right.getDimensions().power(-1), left / right.getFactor());
    }    
    friend std::ostream& operator <<(std::ostream& outputStream, const Unit& unit)
    {
        outputStream << unit.getSymbol();
        return outputStream;
    }

    std::string getName() const;
    std::string getSymbol() const;
    double getFactor() const;
    double getOffset() const;
    Dimensions getDimensions() const;    

    void setName(const std::string &value);
    void setSymbol(const std::string &value);
    void setFactor(double value);
    void setOffset(double value);
    void setDimensions(const Dimensions &value);        

private:
    void copyFrom(const Unit &other);
    void moveFrom(Unit &other);

    std::string name;
    std::string symbol;
    double factor;
    double offset;
    Dimensions dimensions;
};

}
