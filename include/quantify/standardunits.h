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

#include "unit.h"

namespace Quantify {
namespace StandardUnits {

class LengthUnits
{
public:
    // Metric units
    static const Unit meter;
    static const Unit millimeter;
    static const Unit centimeter;
    static const Unit decimeter;
    static const Unit decameter;
    static const Unit hectometer;
    static const Unit kilometer;

    //Imperial units
    static const Unit thou;
    static const Unit inch;
    static const Unit foot;
    static const Unit yard;
    static const Unit chain;
    static const Unit furlong;
    static const Unit mile;

    static const Unit nauticalMile;

    static const Unit lightYear;
};

class MassUnits
{
public:
    static const Unit kilogram;
    static const Unit gram;
    static const Unit milligram;
    static const Unit ton;

    static const Unit ounce;
    static const Unit pound;
};

class TimeUnits
{
public:
    static const Unit second;
    static const Unit microsecond;
    static const Unit millisecond;
    static const Unit minute;
    static const Unit hour;
    static const Unit day;
};

class ElectricUnits
{
public:
    static const Unit ampere;
    static const Unit coulomb;
    static const Unit volt;
    static const Unit ohm;
    static const Unit farad;
};

class TemperatureUnits
{
public:
    static const Unit kelvin;
    static const Unit degreeCelsius;
    static const Unit degreeFahrenheit;
};

class AmountOfSubstanceUnits
{
public:
    static const Unit mole;
};

class LuminousIntensityUnits
{
public:
    static const Unit candela;
};

class AreaUnits
{
public:
    static const Unit meter2;
    static const Unit are;
    static const Unit hectare;
    static const Unit kilometer2;

    static const Unit inch2;
};


class VolumeUnits
{
public:
    static const Unit liter;
    static const Unit milliliter;
    static const Unit centiliter;
    static const Unit deciliter;
    static const Unit meter3;
};

class SpeedUnits
{
public:
    static const Unit meterPerSecond;
    static const Unit kilometerPerHour;
    static const Unit milePerHour;
    static const Unit knot;
};

class ForceUnits
{
public:
    static const Unit newton;
    static const Unit poundForce;
};

class EnergyUnits
{
public:
    static const Unit joule;
    static const Unit kilojoule;
    static const Unit megajoule;
    static const Unit gigajoule;

    static const Unit watt;
    static const Unit kilowatt;
    static const Unit megawatt;

    static const Unit wattSecond;
    static const Unit wattHour;
    static const Unit kilowattHour;

    static const Unit calorie;
    static const Unit kilocalorie;

    static const Unit horsePower;
};

class PressureUnits
{
public:
    static const Unit pascal;
    static const Unit hectopascal;
    static const Unit kilopascal;
    static const Unit bar;
    static const Unit millibar;
    static const Unit atmosphere;
    static const Unit poundPerSquareInch;
};


class FrequencyUnits
{
public:
    static const Unit hertz;
    static const Unit megahertz;
    static const Unit rpm;
};

class TorqueUnits
{
public:
    static const Unit newtonMeter;
    static const Unit poundFoot;
};

}
}
