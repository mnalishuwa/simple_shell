#!/bin/bash

# list scripts
test_scripts=($(ls *set*.bash))
checker_script="./checker.bash"
program_file="../hsh.out"
i=0

for script in "${test_scripts}"; do
    ((i++))
    # create output filename
    output_file="${script%.bash}-results.txt"
    # print test number and file
    echo "Running test $i: $script"
    # print results filename
    echo "Results file: $output_file"
    # print command being executed
    echo "executing $checker_script $program_file $script ..."
    # execute command
    # "$checker_script" "$program_file" "$script" > "$output_file" 2>&1
    ./checker.bash ../hsh.out "$script" > "$output_file" 2>&1
    # print separator
    echo "-------------------------------------------------------\n"
done
echo "done"
