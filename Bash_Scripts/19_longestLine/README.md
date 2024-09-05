# Count Non-Space Lines and Longest Line Length

This Bash script, `count_lines_and_longest_nonspace_line.sh`, analyzes a text file and provides two key statistics:

- **Number of Lines (excluding empty lines):** This counts lines that contain at least one non-space character, ensuring a more accurate representation of content-bearing lines.
- **Length of the Longest Line:** This determines the maximum length of any line in the file, considering only non-space characters.

## Instructions:

1. Save the script as `count_lines_and_longest_nonspace_line.sh`.
2. Make the script executable using `chmod +x count_lines_and_longest_nonspace_line.sh`.

## Usage:

* **With filename argument:**
  ```bash
  ./script.sh file.txt
  ```
* **Without filename argument (user input)**: The script will prompt you to enter the filename.

## Output:

The script will print the calculated line count and longest line length to the console.

## Example:

If your file (file.txt) contains lines like:

- This is a line
- Another line
- No spaces here

The output would be:

* Number of lines (excluding empty lines): 3
* Length of the longest line: 13


