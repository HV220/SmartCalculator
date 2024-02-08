## Introduction

SmartCalculator is a comprehensive calculator application that provides a wide range of mathematical computations, including basic arithmetic, advanced functions, and a dedicated credit calculator for annuity and differentiated payments. This document outlines the main features, installation requirements, and commands to build and maintain the application.

## Main Features

The calculator offers a variety of functions:

- Basic Arithmetic Operations:
  - Addition
  - Subtraction
  - Multiplication
  - Division

- Advanced Mathematical Functions:
  - Exponentiation
  - Modulus (Remainder of Division)
  - Unary Plus
  - Unary Minus
  - Cosine, Sine, Tangent
  - Arccosine, Arcsine, Arctangent
  - Square Root
  - Natural Logarithm (ln)
  - Common Logarithm (log)

- Credit Calculator:
  - Annuity Payments
  - Differentiated Payments

## Installation Requirements

### For Linux:

Update your package list:

sudo apt-get update


Install necessary Qt packages:

`sudo apt-get install qt5-qmake qtbase5-dev qtbase5-dev-tools libqt5svg5-dev libqt5webenginewidgets5 libqt5webchannel5-dev qtwebengine5-dev`


### For macOS:

- Install Qt Creator using the official Qt website or Homebrew.

## Installation

To install SmartCalc v2.0, run the Makefile at the root of the project:

`make install`


## Testing

To run tests, use the following command:

`make tests`


## Code Style Check

To check the code style, enter the following command:

`make check`


## Test Report

To generate a test report, enter the following command:

`make gcov_report`


## Distribution

To create an archive of the project, enter the following command:

`make dist`


## Uninstallation

To uninstall the program, enter the following command:

`make uninstall`


## Cleanup

To clean up unnecessary files, enter the following command:

`make clean`


## Usage

After installation, SmartCalc v2.0 can be launched from the command line or through a GUI shortcut, depending on your system configuration.

## Contributing

Contributions to SmartCalc v2.0 are welcome. Please fork the repository, make your changes, and submit a pull request for review.

https://github.com/HV220/SmartCalculator/assets/96989018/93fe65a7-a68a-4c95-b4ab-efd8fd6899cc
