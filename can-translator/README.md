# can-translator
> Post processing program to convert raw data from the CAN bus into a format that can be imported into WinDarab for analysis.

## Changelog
| Release | Changes |
| --- | --- |
| ![0.1.0](http://img.shields.io/badge/v-0.1.0-yellow.svg?style=flat) | Configuration Scanning Complete |
| ![0.0.1](http://img.shields.io/badge/v-0.0.1-orange.svg?style=flat) | Repository Creation |

## Dependencies
This project requires several libraries to build properly on Linux. If you are using Windows, good luck.
- build-essential
- libqt4-dev

## Building
First, navigate to the top level directory containing the source code.

Run `qmake` and then run `make`.

This should generate an executable file called `can-translator` which, when executed, will start the program and open up the GUI.
