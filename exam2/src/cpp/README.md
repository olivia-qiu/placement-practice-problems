This directory contains the starter code for working on the practice problems.
To solve the problems, you must only edit the following files.

- **Problem 1**: `Coop.cpp`
- **Problem 2**: `SameColor.cpp`
- **Problem 3**: `AnotherTricky.cpp` (note: no starter code is included in this file; you must implement everything from scratch in this problem)

You will find additional files in this directory. **Do not** edit those files (they
are auxiliary files needed to run and test your code).

For Problems 1 and 2, we have provided a testing program that checks your
solution against some test data.  Here are instructions for compiling the
test code for each problem:

- **Problem 1**: `c++ --std=gnu++17 Coop.cpp CoopTests.cpp TestHelpers.cpp -o test1`
- **Problem 2**: `c++ --std=gnu++17 SameColor.cpp SameColorTest.cpp TestHelpers.cpp -o test2`

The command-line interface is the same for all the test programs. For
example, to run the (compiled) test code for problem 1, on a single
test file, run:

    ./test1 -t <path to test file>

e.g.

    ./test1 -t ../../test-data/1-coop/coop-001.in

To run all the tests for problem 1, run:

    ./test1 -a ../../test-data/1-coop/

For Problem 3, we have not provided any testing programs.
You are responsible for reading in
the test data from a file, and printing the correct output.
Please see the problem statement for more details.