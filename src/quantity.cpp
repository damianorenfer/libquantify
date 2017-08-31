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

#include <quantify/quantity.h>
#include <quantify/utils.h>

namespace Quantify {

Quantity::Quantity(Unit unit, double value) : value(value), unit(unit)
{

}

Quantity::Quantity(const Quantity &other)
{
    copyFrom(other);
}

Quantity::Quantity(Quantity &&other)
{
    moveFrom(other);
}

Quantity &Quantity::operator=(const Quantity &other)
{
    if(this != &other)
    {
        copyFrom(other);
    }

    return *this;
}

Quantity &Quantity::operator=(Quantity &&other)
{
    if(this != &other)
    {
        moveFrom(other);
    }

    return *this;
}

Quantity Quantity::convertTo(const Unit &unit) const
{
    this->unit.assertCompatibility(unit);

    return Quantity(unit, (((this->unit.getFactor() * value) + this->unit.getOffset()) - unit.getOffset()) / (unit.getFactor()));
}

int Quantity::toInt() const
{
    return ((*this) >= 0.0) ? (int) (value + 0.5) : (int) (value - 0.5);
}

float Quantity::toFloat() const
{
    return (float) value;
}

bool Quantity::equals(const Quantity &other) const
{
    if(unit == other.unit)
    {
        return equals(other.value);
    }
    else
    {
        Quantity tmp = other.convertTo(unit);
        return equals(tmp.value);
    }
}

bool Quantity::lessThan(const Quantity &other) const
{
    if(unit == other.unit)
    {
        return lessThan(other.value);
    }
    else
    {
        Quantity tmp = other.convertTo(unit);
        return lessThan(tmp.value);
    }
}

bool Quantity::greaterThan(const Quantity &other) const
{
    if(unit == other.unit)
    {
        return greaterThan(other.value);
    }
    else
    {
        Quantity tmp = other.convertTo(unit);
        return greaterThan(tmp.value);
    }
}

bool Quantity::equals(double value) const
{
    return Utils::areEqual(this->value, value);
}

bool Quantity::lessThan(double value) const
{
    return this->value < value;
}

bool Quantity::greaterThan(double value) const
{
    return this->value > value;
}

Quantity Quantity::add(const Quantity &other) const
{
    if(unit == other.unit)
    {
        return Quantity(unit, value + other.value);
    }
    else
    {
        Quantity tmp = other.convertTo(unit);
        return Quantity(unit, value + tmp.value);
    }
}

Quantity Quantity::add(double value) const
{
    return Quantity(unit, this->value + value);
}

Quantity Quantity::subtract(const Quantity &other) const
{
    if(unit == other.unit)
    {
        return Quantity(unit, value - other.value);
    }
    else
    {
        Quantity tmp = other.convertTo(unit);
        return Quantity(unit, value - tmp.value);
    }
}

Quantity Quantity::subtract(double value) const
{
    return Quantity(unit, this->value - value);
}

Quantity Quantity::multiplyBy(const Quantity &other) const
{
    return Quantity(unit * other.unit, value * other.value);
}

Quantity Quantity::multiplyBy(double value) const
{
    return Quantity(unit, this->value * value);
}

Quantity Quantity::divideBy(const Quantity &other) const
{
    return Quantity(unit / other.unit, value / other.value);
}

Quantity Quantity::divideBy(double value) const
{
    return Quantity(unit / value, this->value / value);
}

double Quantity::getValue() const
{
    return value;
}

void Quantity::setValue(double value)
{
    this->value = value;
}

Unit Quantity::getUnit() const
{
    return unit;
}

void Quantity::setUnit(const Unit &value)
{
    unit = value;
}

void Quantity::copyFrom(const Quantity &other)
{
    value = other.value;
    unit = other.unit;
}

void Quantity::moveFrom(Quantity &other)
{
    value = other.value;
    unit = std::move(other.unit);

    other.value = 0;
}

}
