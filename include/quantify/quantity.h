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
#include "unit.h"

namespace Quantify {

class Quantity
{
public:
    Quantity(Unit unit = Unit(), double value = 0);
    Quantity(const Quantity &other);        
    Quantity(Quantity &&other);
    ~Quantity() noexcept {}

    Quantity &operator=(const Quantity &other);
    Quantity &operator=(Quantity &&other);

    Quantity convertTo(const Unit &unit) const;
    int toInt() const;
    float toFloat() const;
    bool equals(const Quantity &other) const;
    bool lessThan(const Quantity &other) const;
    bool greaterThan(const Quantity &other) const;
    bool equals(double value) const;
    bool lessThan(double value) const;
    bool greaterThan(double value) const;
    Quantity add(const Quantity &other) const;
    Quantity add(double value) const;
    Quantity subtract(const Quantity &other) const;
    Quantity subtract(double value) const;
    Quantity multiplyBy(const Quantity &other) const;
    Quantity multiplyBy(double value) const;
    Quantity divideBy(const Quantity &other) const;
    Quantity divideBy(double value) const;

    bool operator==(const Quantity &other) const { return equals(other); }
    bool operator==(double value) const { return equals(value); }
    bool operator!=(const Quantity &other) const { return !equals(other); }
    bool operator!=(double value) const { return !equals(value); }
    bool operator<(const Quantity &other) const { return lessThan(other); }
    bool operator<(double value) const { return lessThan(value); }
    bool operator<=(const Quantity &other) const { return lessThan(other) || equals(other); }
    bool operator<=(double value) const { return lessThan(value) || equals(value); }
    bool operator>(const Quantity &other) const { return greaterThan(other); }
    bool operator>(double value) const { return greaterThan(value); }
    bool operator>=(const Quantity &other) const { return greaterThan(other) || equals(other); }                   
    bool operator>=(double value) const { return greaterThan(value) || equals(value); }
    friend Quantity operator+(const Quantity &left, const Quantity &right) { return left.add(right); }
    friend Quantity operator+(const Quantity &left, double right) { return left.add(right); }
    friend Quantity operator+(double left, const Quantity &right) { return right.add(left); }
    friend Quantity operator-(const Quantity &left, const Quantity &right) { return left.subtract(right); }
    friend Quantity operator-(const Quantity &left, double right) { return left.subtract(right); }
    friend Quantity operator-(double left, const Quantity &right) { return right.subtract(left); }
    friend Quantity operator*(const Quantity &left, const Quantity &right) { return left.multiplyBy(right); }
    friend Quantity operator*(const Quantity &left, double right) { return left.multiplyBy(right); }
    friend Quantity operator*(double left, const Quantity &right) { return right.multiplyBy(left); }
    friend Quantity operator/(const Quantity &left, const Quantity &right) { return left.divideBy(right); }
    friend Quantity operator/(const Quantity &left, double right) { return left.divideBy(right); }
    friend Quantity operator/(double left, const Quantity &right)
    {
        return Quantity(1.0 / right.unit, left / right.value);
    }
    friend std::ostream& operator <<(std::ostream& outputStream, const Quantity& quantity)
    {
        outputStream << quantity.getValue() << " " << quantity.getUnit();
        return outputStream;
    }

    double getValue() const;
    Unit getUnit() const;

    void setValue(double value);
    void setUnit(const Unit &value);

private:
    void copyFrom(const Quantity &other);
    void moveFrom(Quantity &other);

    double value;
    Unit unit;
};

}
