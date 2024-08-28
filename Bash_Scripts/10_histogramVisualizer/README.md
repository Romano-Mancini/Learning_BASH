# Bash Script: Print Patterns of Asterisks

This script reads a file containing numbers and prints a pattern of asterisks for each number.

### Usage

1. Run the script with a file containing a list of numbers.
   - Example: `./script.sh numbers.txt`

2. The script will:
   - Read each number from the file.
   - For each number, print a line of asterisks (`*`) corresponding to that number.

### How It Works

- **Reading Numbers:**
  - Uses `cat` to read the file, processing each number separately.
  
- **Printing Patterns:**
  - For each number, a nested loop prints a line of asterisks, where the number of asterisks corresponds to the current number.

