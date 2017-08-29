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

#include <quantify/standardunits.h>

namespace Quantify {
namespace StandardUnits {

// Length units

// metric
const Unit LengthUnits::meter("meter", "m", Dimensions(1));
const Unit LengthUnits::millimeter("millimeter", "mm", 0.001 * LengthUnits::meter);
const Unit LengthUnits::centimeter("centimeter", "cm", 0.01 * LengthUnits::meter);
const Unit LengthUnits::decimeter("decimeter", "dm", 0.1 * LengthUnits::meter);
const Unit LengthUnits::decameter("decameter", "Dm", 10.0 * LengthUnits::meter);
const Unit LengthUnits::hectometer("hectometer", "Hm", 100.0 * LengthUnits::meter);
const Unit LengthUnits::kilometer("kilometer", "km", 1000.0 * LengthUnits::meter);

// imperial units
const Unit LengthUnits::thou("thou", "th", 0.0000254 * LengthUnits::meter);
const Unit LengthUnits::inch("inch", "in", 1000.0 * LengthUnits::thou);
const Unit LengthUnits::foot("foot", "ft", 12.0 * LengthUnits::inch);
const Unit LengthUnits::yard("yard", "yd", 3.0 * LengthUnits::foot);
const Unit LengthUnits::chain("chain", "ch", 22.0 * LengthUnits::yard);
const Unit LengthUnits::furlong("furlong", "fur", 10.0 * LengthUnits::chain);
const Unit LengthUnits::mile("mile", "mi", 8.0 * LengthUnits::furlong);

const Unit LengthUnits::nauticalMile("nautical mile", "nmi", 1852.0 * LengthUnits::meter);

const Unit LengthUnits::lightYear("light-year", "ly", 9460730472580800.0 * LengthUnits::meter);

// Mass units
const Unit MassUnits::kilogram("kilogram", "kg", Dimensions(0, 1));
const Unit MassUnits::gram("gram", "g", 0.001 * MassUnits::kilogram);
const Unit MassUnits::milligram("milligram", "mg", 0.001 * MassUnits::gram);
const Unit MassUnits::ton("ton", "ton", 1000.0 * MassUnits::kilogram);

const Unit MassUnits::ounce("ounce", "oz", 28 * MassUnits::gram);
const Unit MassUnits::pound("pound", "lb", 0.5 * MassUnits::kilogram);

// Time units
const Unit TimeUnits::second("second", "s", Dimensions(0, 0, 1));
const Unit TimeUnits::microsecond("microsecond", "μs", 0.000001 * TimeUnits::second);
const Unit TimeUnits::millisecond("millisecond", "ms", 0.001 * TimeUnits::second);
const Unit TimeUnits::minute("minute", "min", 60.0 * TimeUnits::second);
const Unit TimeUnits::hour("hour", "h", 3600.0 * TimeUnits::second);
const Unit TimeUnits::day("day", "d", 24.0 * TimeUnits::hour);

// Electric units
const Unit ElectricUnits::ampere("ampere", "A", Dimensions(0, 0, 0, 1));
const Unit ElectricUnits::coulomb("coulomb", "C", TimeUnits::second * ElectricUnits::ampere);
const Unit ElectricUnits::volt("volt", "V", EnergyUnits::watt * ElectricUnits::ampere.power(-1));
const Unit ElectricUnits::ohm("ohm", "Ω", ElectricUnits::volt * ElectricUnits::ampere.power(-1));
const Unit ElectricUnits::farad("farad", "F", ElectricUnits::coulomb * ElectricUnits::volt.power(-1));

// Temperature units
const Unit TemperatureUnits::kelvin("kelvin", "K", Dimensions(0, 0, 0, 0, 1));
const Unit TemperatureUnits::degreeCelsius("degree Celsius", "°C", TemperatureUnits::kelvin + 273.15);
const Unit TemperatureUnits::degreeFahrenheit("degree Fahrenheit", "°F", ((5.0/9.0) * TemperatureUnits::kelvin) + ((5.0/9.0) * 459.67));

// Amount of substance units
const Unit AmountOfSubstanceUnits::mole("mole", "mol", Dimensions(0, 0, 0, 0, 0, 1));

// Luminous intensity units
const Unit LuminousIntensityUnits::candela("candela", "cd", Dimensions(0, 0, 0, 0, 0, 0, 1));

// Area units
const Unit AreaUnits::meter2("meter^2", "m^2", LengthUnits::meter.power(2));
const Unit AreaUnits::are("are", "are", 100.0 * AreaUnits::meter2);
const Unit AreaUnits::hectare("hectare", "ha", 10000.0 * AreaUnits::meter2);
const Unit AreaUnits::kilometer2("kilometer^2", "Km^2", LengthUnits::kilometer.power(2));
const Unit AreaUnits::inch2("inch^2", "in^2", LengthUnits::inch.power(2));

// Volume units
const Unit VolumeUnits::liter("liter", "L", LengthUnits::decimeter.power(3));
const Unit VolumeUnits::milliliter("milliliter", "mL", 0.001 * VolumeUnits::liter);
const Unit VolumeUnits::centiliter("centiliter", "cL", 0.01 * VolumeUnits::liter);
const Unit VolumeUnits::deciliter("deciliter", "dL", 0.1 * VolumeUnits::liter);
const Unit VolumeUnits::meter3("meter^3", "m^3", LengthUnits::meter.power(3));

// Speed units
const Unit SpeedUnits::meterPerSecond("meter/second", "m/s", LengthUnits::meter * TimeUnits::second.power(-1));
const Unit SpeedUnits::kilometerPerHour("kilometer/hour", "km/h", LengthUnits::kilometer * TimeUnits::hour.power(-1));
const Unit SpeedUnits::milePerHour("mile/hour", "mi/h", LengthUnits::mile * TimeUnits::hour.power(-1));
const Unit SpeedUnits::knot("knot", "kn", 1.852 * SpeedUnits::kilometerPerHour);

// Force units
const Unit ForceUnits::newton("newton", "N", LengthUnits::meter * MassUnits::kilogram * TimeUnits::second.power(-2));
const Unit ForceUnits::poundForce("pound-force", "lbf", 4.4482216152605 * ForceUnits::newton);

// Energy units
const Unit EnergyUnits::joule("joule", "J", LengthUnits::meter.power(2) * MassUnits::kilogram * TimeUnits::second.power(-2));
const Unit EnergyUnits::kilojoule("kilojoule", "kJ", 1000.0 * EnergyUnits::joule);
const Unit EnergyUnits::megajoule("megajoule", "MJ", 1000000.0 * EnergyUnits::joule);
const Unit EnergyUnits::gigajoule("gigajoule", "GJ", 1000000000.0 * EnergyUnits::joule);

const Unit EnergyUnits::watt("watt", "W", EnergyUnits::joule * TimeUnits::second.power(-1));
const Unit EnergyUnits::kilowatt("kilowatt", "kW", 1000.0 * EnergyUnits::watt);
const Unit EnergyUnits::megawatt("megawatt", "MW", 1000000.0 * EnergyUnits::watt);

const Unit EnergyUnits::wattSecond("watt-second", "Wsec", EnergyUnits::watt * TimeUnits::second);
const Unit EnergyUnits::wattHour("watt-hour", "Wh", EnergyUnits::watt * TimeUnits::hour);
const Unit EnergyUnits::kilowattHour("kilowatt-hour", "kWh", 1000.0 * EnergyUnits::wattHour);

const Unit EnergyUnits::calorie("calorie", "cal", 4.1868 * EnergyUnits::joule);
const Unit EnergyUnits::kilocalorie("kilocalorie", "kcal", 1000.0 * EnergyUnits::calorie);

const Unit EnergyUnits::horsePower("horsepower", "hp", 0.73549875 * EnergyUnits::kilowatt);

// Pressure units
const Unit PressureUnits::pascal("pascal", "Pa", ForceUnits::newton * LengthUnits::meter.power(-2));
const Unit PressureUnits::hectopascal("hectopascal", "hPa", 100.0 * PressureUnits::pascal);
const Unit PressureUnits::kilopascal("kilopascal", "KPa", 1000.0 * PressureUnits::pascal);
const Unit PressureUnits::bar("bar", "bar", 100000.0 * PressureUnits::pascal);
const Unit PressureUnits::millibar("millibar", "mbar", 0.001 * PressureUnits::bar);
const Unit PressureUnits::atmosphere("atmosphere", "atm", 101325.0 * PressureUnits::pascal);
const Unit PressureUnits::poundPerSquareInch("pound per square inch", "psi", ForceUnits::poundForce * AreaUnits::inch2.power(-1));

// Frequency units
const Unit FrequencyUnits::hertz("Hertz", "hz", TimeUnits::second.power(-1));
const Unit FrequencyUnits::megahertz("MegaHertz", "Mhz", 1000000.0 * FrequencyUnits::hertz);
const Unit FrequencyUnits::rpm("Revolutions per minute", "rpm", TimeUnits::minute.power(-1));

// Torque units
const Unit TorqueUnits::newtonMeter("newton-meter", "N*m", ForceUnits::newton * LengthUnits::meter);
const Unit TorqueUnits::poundFoot("pound-foot ", "lbf*ft", ForceUnits::poundForce * LengthUnits::foot);

}
}
