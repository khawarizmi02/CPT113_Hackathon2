#!/bin/bash

dir="$(dirname "$0")"  # Get the directory path of the script

file="$dir/run.txt"  # Construct the relative path to file.txt

# Read the file line by line
while IFS= read -r line
do
    # Execute each line as a command
    eval "$line"
done < "$file"

