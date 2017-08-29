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

#include <quantify/unit.h>
#include <cmath>
#include <quantify/incompatibleunitsexception.h>
#include <quantify/unitunsupportedoperationexception.h>
#include <quantify/utils.h>

namespace Quantify {

Unit::Unit(std::string name, std::string symbol, Dimensions dimensions, double factor, double offset)
{
    this->dimensions = dimensions;
    this->name = name;
    this->symbol = symbol;
    this->factor = factor;
    this->offset = offset;
}

Unit::Unit(const Unit &other)
{
    copyFrom(other);
}

Unit::Unit(Unit &&other)
{
    moveFrom(other);
}

Unit &Unit::operator=(const Unit &other)
{
    if(this != &other)
    {
        copyFrom(other);
    }

    return *this;
}

Unit &Unit::operator=(Unit &&other)
{
    if(this != &other)
    {
        moveFrom(other);
    }

    return *this;
}

void Unit::assertCompatibility(const Unit &other) const
{
    if(!isCompatibleTo(other))
    {
        throw IncompatibleUnitsException(*this, other);
    }
}

void Unit::assertCanMultiply() const
{
    if(!Utils::areEqual(this->offset, 0.0))
    {
        throw UnitUnsupportedOperation(*this, "*");
    }
}

void Unit::assertCanDivide() const
{
    if(!Utils::areEqual(this->offset, 0.0))
    {
        throw UnitUnsupportedOperation(*this, "/");
    }
}

bool Unit::isCompatibleTo(const Unit &other) const
{
    return getDimensions() == other.getDimensions();
}

Unit Unit::power(int power) const
{
    assertCanMultiply();

    std::stringstream nameStream;
    nameStream << name << "^" << power;

    std::stringstream symbolStream;
    symbolStream << symbol << "^" << power;

    return Unit(nameStream.str(), symbolStream.str(), dimensions.power(power), pow(factor, (double)power));
}

bool Unit::equals(const Unit &other) const
{    
    return isCompatibleTo(other) && Utils::areEqual(factor, other.factor);
}

bool Unit::lessThan(const Unit &other) const
{    
    return isCompatibleTo(other) && (factor < other.factor);
}

bool Unit::greaterThan(const Unit &other) const
{    
    return isCompatibleTo(other) && (factor > other.factor);
}

Unit Unit::add(double value) const
{
    std::stringstream nameStream;
    nameStream << "(" << name << "+" << value << ")";

    std::stringstream symbolStream;
    symbolStream << symbol << "+" << value;

    return Unit(nameStream.str(), symbolStream.str(), dimensions, factor, offset + value);
}

Unit Unit::subtract(double value) const
{
    std::stringstream nameStream;
    nameStream << "(" << name << "-" << value << ")";

    std::stringstream symbolStream;
    symbolStream << symbol << "-" << value;

    return Unit(nameStream.str(), symbolStream.str(), dimensions, factor, offset - value);
}

Unit Unit::multiplyBy(const Unit &other) const
{
    other.assertCanMultiply();
    assertCanMultiply();

    std::stringstream nameStream;
    nameStream << name << "*" << other.name;

    std::stringstream symbolStream;
    symbolStream << symbol << "*" << other.symbol;

    return Unit(nameStream.str(), symbolStream.str(), dimensions * other.dimensions, factor * other.factor);
}

Unit Unit::multiplyBy(double value) const
{    
    assertCanMultiply();

    std::stringstream nameStream;
    nameStream << value << "*" << name;

    std::stringstream symbolStream;
    symbolStream << value << "*" << symbol;

    return Unit(nameStream.str(), symbolStream.str(), dimensions, value * factor);
}

Unit Unit::divideBy(const Unit &other) const
{
    other.assertCanDivide();
    assertCanDivide();

    std::stringstream nameStream;
    nameStream << name << "/" << other.name;

    std::stringstream symbolStream;
    symbolStream << symbol << "/" << other.symbol;

    return Unit(nameStream.str(), symbolStream.str(), dimensions / other.dimensions, factor / other.factor);
}

Unit Unit::divideBy(double value) const
{
    assertCanDivide();

    std::stringstream nameStream;
    nameStream << name << "/" << value;

    std::stringstream symbolStream;
    symbolStream << symbol << "/" << value;

    return Unit(nameStream.str(), symbolStream.str(), dimensions, factor / value);
}

std::string Unit::getName() const
{
    return name;
}

double Unit::getFactor() const
{
    return factor;
}

std::string Unit::getSymbol() const
{
    return symbol;
}

Dimensions Unit::getDimensions() const
{
    return dimensions;
}

double Unit::getOffset() const
{
    return offset;
}

void Unit::setName(const std::string &value)
{
    name = value;
}

void Unit::setSymbol(const std::string &value)
{
    symbol = value;
}

void Unit::setFactor(double value)
{
    factor = value;
}

void Unit::setDimensions(const Dimensions &value)
{
    dimensions = value;
}

void Unit::setOffset(double value)
{
    offset = value;
}

void Unit::copyFrom(const Unit &other)
{
    dimensions = other.dimensions;
    name = other.name;
    symbol = other.symbol;
    factor = other.factor;
    offset = other.offset;
}

void Unit::moveFrom(Unit &other)
{
    dimensions = std::move(other.dimensions);
    name = std::move(other.name);
    symbol = std::move(other.symbol);
    factor = other.factor;
    offset = other.offset;

    other.factor = 0;
    other.offset = 0;
}

}
