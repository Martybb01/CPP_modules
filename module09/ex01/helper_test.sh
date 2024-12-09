#!/bin/bash

OUT_FILE="RPN_results.txt"

run_test() {
    echo "Testing input: $1" >> $OUT_FILE
    ./RPN "$1" >> $OUT_FILE 2>&1
    echo "" >> $OUT_FILE
}

> $OUT_FILE

# Basic tests
run_test "3 4 +"
run_test "9 5 -"
run_test "6 2 *"
run_test "8 4 /"
run_test "9 3 / 2 *"
run_test "5"

# Complex tests
run_test "3 4 + 5 6 + *"
run_test "8 9 * 9 - 9 - 9 - 4 - 1 +"
run_test "7 7 * 7 -"
run_test "1 2 * 2 / 2 * 2 4 - +"
run_test "5 1 2 + 4 * + 3 -"

# Invalid tests
run_test "(1 + 1)"
run_test "3 4 &"
run_test "3 3 + +"
run_test "4 0 /"
run_test ""
run_test "4 5 + 6"
run_test "4 5 + abc"
run_test "4 5"
run_test "10 5 -"

echo "All tests completed. Results written to $OUT_FILE"
