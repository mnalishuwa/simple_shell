#!/bin/bash

# list scripts
test_scripts=($(ls bin*.bash))
checker_script="./checker.bash"
program_file="../hsh.out"
i=0

for script in "${test_scripts[@]}"; do
    ((i++))
    # create output filename
    output_file="${script%.bash}-results.txt"
    echo "Running test $i: $script"
    echo "Results filename: $output_file"
    echo "executing $checker_script $program_file $script ..."
    ./checker.bash ../hsh.out "$script" > "$output_file" 2>&1
    echo "------------------------------------------------"
done
echo "done"
