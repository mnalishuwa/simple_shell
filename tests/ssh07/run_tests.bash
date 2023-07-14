#!/bin/bash

# list test scripts
test_scripts=($(ls bin*.bash))
# set checker script filename
checker_script="./checker.bash"
# set program filename
program_file="../hsh.out"
# set index/counter
i=0

# loop through scripts
for script in "${test_scripts[@]}"; do
    ((i++))
    # create output folder name
    output_file="${script%.bash}-results.txt"
    echo "Running test $i: $script"
    echo "Results file: $output_file"
    echo "executing $checker_script $program_file $script ..."
    ./checker.bash ../hsh.out "$script" > "$output_file" 2>&1
    echo "-----------------------------------------------\n"
done
echo "done"
