#!/bin/bash

# create test scripts list
test_scripts=($(ls bin*.bash empty*.bash ls*.bash))
checker_script="./checker.bash"
program_file="../hsh.out"
i=0

# iterate and execute scripts and write output to txt files
for script in "${test_scripts[@]}"; do
    ((i++))
    # create results file
    output_file="${script%.bash}-results.txt"
    echo "Running test $i: $script"
    echo "Results file: $output_file"
    echo "executing: $checker_script $program_file $script ..."
    # run script and redirect output to results file
    ./checker.bash ../hsh.out "$script" > "$output_file" 2>&1
    echo "----------------------------------------------------"
    echo -e "\n"
done
echo "done"
