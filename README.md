# testability-patterns-c

Testability pattern examples in C (cmake, gtest).

## Usage

setup tools

    ./setup.sh

build and run unit tests of example (here "testable single instance module")

    cd testable-single-instance-module/build
    cmake ..
    make unit_tests
    ./unit_tests

## Testable Single Instance Module

Used concepts:

- [Single Instance Module Pattern (implementation example)](https://github.com/jwgrenning/tddec-code/blob/master/code/src/HomeAutomation/LightScheduler.c)
- [Test Hook](http://xunitpatterns.com/Test%20Hook.html)
  The MUT (module under test) is modified to behave differently during the test.

## Testable Multi Instance Module

Used concepts:
- [Abstract Data Type](http://www.edn.com/electronics-blogs/embedded-basics/4441661/5-simple-steps-to-create-an-abstract-data-type-in-C)
