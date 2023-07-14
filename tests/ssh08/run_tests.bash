#!/bin/bash

# create a list of scripts based on the scripts in the folder
test_scripts=($(ls exit*.bash))
checker_script="./checker.bash"
program_file="../hsh.out"
i=0

# Loop through the test_scripts
for script in "${test_scripts[@]}"; do
    ((i++))
    # create a results filename
    output_file="${script%.bash}-result.txt"
    # print the test number and script file name
    echo "Running test $i: $script"
    echo "Results file: $output_file"
    echo "executing: $checker_script $program_file $script ..."
    # run script and redirect output to results file
    ./checker.bash ../hsh.out "$script" > "$output_file" 2>&1
    echo "------------------------------------"
done
echo "done"
