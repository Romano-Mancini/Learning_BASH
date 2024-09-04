## File Manipulator

### Description
This script is a Bash script that processes a text file. It performs the following tasks:

1. **Argument Validation**: The script checks if exactly one argument (the filename) is passed. If there are too few or too many arguments, it exits with an appropriate message and code.
2. **File Copying**: It creates a copy of the provided file with the same name but with an `.xyz` extension.
3. **Line Modification**: The script reads the original file line by line, prefixes each line with the number of words in that line, and writes these modified lines to a temporary file.
4. **Sorting**: The modified lines are sorted based on the number of words at the beginning of each line.
5. **Appending Line Count**: The total number of lines is appended to the end of the original file.
6. **Final Output**: The original file is overwritten with the sorted content and the appended line count.

### Exit Codes
- **1**: Not enough arguments provided.
- **2**: Too many arguments provided.
- **0**: Script executed successfully.

### Notes
- The script modifies the original file, so ensure you have backups if necessary.
- The temporary file used during processing is stored in the `/tmp` directory and is named uniquely using the process ID.

