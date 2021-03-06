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

#include <exception>
#include <sstream>
#include "unit.h"
#include "utils.h"

namespace Quantify {

class UnitUnsupportedOperationException : public std::exception
{
public:

    UnitUnsupportedOperationException(const Unit &unit, const char *operation) : unit(unit), operation(operation)
    {
        std::stringstream ss;
        ss << "Unit \"" << unit.getSymbol() << "\" does not support operation \"" << operation << "\".";
        if(!Utils::areEqual(unit.getOffset(), 0))
        {
            ss << " Hint : units with an offset different from 0 do not support multiplication nor division.";
        }

        message = std::move(ss.str());
    }

    virtual const char* what() const throw()
    {        
        return message.c_str();
    }

private:    
    const Unit &unit;
    const char *operation;
    std::string message;
};

}
