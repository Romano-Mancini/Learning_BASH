# Bash Script: String Length Calculator

This script prompts the user to input a string and calculates its length. It counts the number of characters in the string, excluding the newline character added when the user presses Enter.

### Usage

1. Run the script in a terminal.
2. Enter the string when prompted.
3. The script will display the length of the string.

### How It Works

- Prompts for a string input.
- Calculates the number of characters in the string using `wc -c`.
- Subtracts 1 to remove the newline character from the count.
- Displays the length of the string.
