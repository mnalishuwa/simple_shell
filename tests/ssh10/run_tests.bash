#!/bin/bash

# list test scripts
test_scripts=($(ls cd*.bash))
# checker script filename
checker_script="./checker.bash"
#program filename
program_file="../hsh.out"
# create index/counter
i=0

# loop through the scripts
for script in "${test_scripts[@]}"; do
    # increment counter
    ((i++))
    # create results filename
    output_file="${script%.bash}-results.txt"
    # print test number and name
    echo "Running test $i: $script"
    # print results filename
    echo "Results file: $output_file"
    # print command being executed
    echo "executing $checker_script $program_file $script ..."
    # execute test script and write result to output file
    ./checker.bash ../hsh.out "$script" > "$output_file" 2>&1
    echo "----------------------------------------------\n"
done
echo "done"
