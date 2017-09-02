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

## Patterns

### Testable Single Instance Module

Used patterns:

- **Single Instance Module** [Gre 2011, p. 28-29 + p. 194] [implementation example](https://github.com/jwgrenning/tddec-code/blob/master/code/src/HomeAutomation/LightScheduler.c) 
- [**Test Hook**](http://xunitpatterns.com/Test%20Hook.html) - The MUT (module under test) is modified to behave differently during the test.

### Testable Multi Instance Module

Used patterns:

- **Multiple Instance Module** [Gre 2011, p. 28-29 + p. 194]
- **Abstract Data Type** [Gre 2011, p. 27] - "An abstract data type is defined indirectly, only by the operations that may be performed on it (...). " [implementation example](http://www.edn.com/electronics-blogs/embedded-basics/4441661/5-simple-steps-to-create-an-abstract-data-type-in-C)

## Book references

Greening, James W.: *Test-Driven Development for Embedded C*, 1st edition, O'Reilly, 2011 (ISBN-10: 193435662X, ISBN-13: 978-1934356623)
