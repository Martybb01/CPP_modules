#!/bin/bash

OUTPUT_FILE="conversion_results.txt"

# Function to run test and append result to file
run_test() {
    echo "Testing input: $1" >> $OUTPUT_FILE
    ./scalarConversion "$1" >> $OUTPUT_FILE
    echo "" >> $OUTPUT_FILE
}

# Clear previous results
> $OUTPUT_FILE

# Run tests
run_test "0"
run_test "42"
run_test "42.0f"
run_test "42.0"
run_test "-42"
run_test "42f"
run_test "-42.f"
run_test "nan"
run_test "nanf"
run_test "inf"
run_test "+inf"
run_test "-inf"
run_test "inff"
run_test "+inff"
run_test "-inff"
run_test "2147483647"  # Max int
run_test "-2147483648" # Min int
run_test "2147483648"  # Overflow int
run_test "a"
run_test "A"
run_test "hello"
run_test "3.16159"
run_test "0.0201f"
run_test "1e-5"

echo "All tests completed. Results written to $OUTPUT_FILE"
