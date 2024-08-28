# Bash Script: Display Content of C Files with "POSIX"

This script searches for all `.c` files in the current directory that contain the string "POSIX". For each matching file, it displays the file's name and its content.

### Usage

1. Run the script in a terminal.
   - Example: `./script.sh`

2. The script will:
   - Search for all `.c` files in the current directory.
   - Check if each file contains the string "POSIX".
   - Print the content of each file that includes the string "POSIX".

### How It Works

- `find . -maxdepth 1 -name "*.c"`: Finds all `.c` files in the current directory (not in subdirectories).
- `grep "POSIX" $i | wc -w`: Checks if the file contains the word "POSIX".
- `cat $i`: Displays the content of each file that contains "POSIX".
- The script prints the content of each matching file with its filename.

