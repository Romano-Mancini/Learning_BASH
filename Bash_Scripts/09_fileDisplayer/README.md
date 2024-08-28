# Bash Script: Line and Word Numbering

This script prints the contents of a file, numbering each line and each word separately.

### Usage

1. Run the script with a file as an argument.
   - Example: `./script.sh file.txt`

2. The script will:
   - Print each line of the file with a line number.
   - Print each word of the file with a word number.

### How It Works

- **Line Numbering:**
  - Reads the file line by line.
  - Numbers each line and prints it in the format `line_number - line_content`.
  
- **Word Numbering:**
  - Reads the file content as words separated by whitespace.
  - Numbers each word and prints it in the format `word_number - word_content`.
