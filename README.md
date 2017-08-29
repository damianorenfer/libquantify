# libquantify

Simple C++11 library to handle quantities and units. It is based on the International System of Units concept using the base dimensions (7) and then additional units are built on top of them.
There are some great libraries that do the same, but none of them fulfilled my needs. This library uses dynamic (run time) units where the other libs use compile time units.

Features:
- Dynamic units
- Conversion between units (of the same dimension)
- Unit composition
- Units with offsets (i.e temperature units), at the moment only conversions are available, no composition
- Should be memory safe as everything is value based, so no new nor malloc in there

Note that this is my first library, first C++11 project and first CMake project. So any suggestions or improvements are welcome :).

## Installation

Linux and MinGW users :

```sh
git clone ...
cd local_repo
mkdir build && cd build
cmake ..
make
sudo make install
```

Windows users :

Sorry I have not tested it yet, but it should not be a difficult to build and install.

## Usage

```cpp
#include <quantify/quantity.h>
#include <quantify/standardunits.h>

using namespace Quantify;

int main(int argc, char *argv[])
{
   Quantity meters(StandardUnits::LengthUnits::meter, 22.0);
   Quantity feets = meters.convertTo(StandardUnits::LengthUnits::foot); //unit conversion
   Quantity seconds(StandardUnits::TimeUnits::second, 15);

   Quantity speed = meters / seconds; // unit composition
   Quantity speedInKph = speed.convertTo(StandardUnits::SpeedUnits::kilometerPerHour);
   Quantity speedInMph = speed.convertTo(StandardUnits::SpeedUnits::milePerHour);

   return 0;
}
```

If a unit is not available in StandardUnits, just create it ;).  See src/standardunits.cpp


## Credits

- Very useful, and mostly based on : https://www.codeproject.com/Articles/611731/Working-with-Units-and-Amounts
- International System of Units Wikipedia page : https://en.wikipedia.org/wiki/International_System_of_Units

## License

This project is licensed under the MIT License - see the LICENSE file for details
