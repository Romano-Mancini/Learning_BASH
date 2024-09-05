# File and Directory Information Script

This script processes a list of files and directories provided as command-line arguments. For each item, the script prints relevant information based on its type:

1. **For regular files**: 
   - Prints the file's name.
   - Prints the file's size in bytes.
   - Checks if the user has read and write permissions and prints the result.

2. **For directories**:
   - Prints the directory's name.
   - Counts and prints the number of subdirectories it contains.

## Requirements

- Bash

## Example

If you run the script with the following command:

./script.sh file1.txt directory1

And file1.txt is a regular file, while directory1 is a directory containing subdirectories, the output would be:

Name: file1.txt.
Dimension: 1024.
The user has read permissions.
The user has write permissions.
----
Name: directory1.
Number of subdirectories: 3.
----
