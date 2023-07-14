#!/bin/bash

# create list of scripts
test_scripts=($(ls bin*.bash echo*.bash))
checker_script="./checker.bash"
program_file="../hsh.out"
i=0

for script in "${test_scripts[@]}"; do
    ((i++))
    # create output file name
    output_file="${script%.bash}-results.txt"
    echo "Running test $i: $script"
    echo "Results file: $output_file"
    echo "executing script: $checker_script $program_file $script ..."
    # ./checker.bash ../hsh.out "$script" > "$output_file" 2>&1
    "$checker_script" "$program_file" "$script" > "$output_file" 2>&1
    echo -e "\n"
done
echo "done"
