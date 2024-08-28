# Bash Script: User Login Count Checker

This script prompts the user to input a username and determines how many times that user is currently logged into the system.

### Usage

1. Run the script in a terminal.
2. Enter the username when prompted.
3. The script will display the number of times the user is logged in.

### How It Works

- Prompts for a username.
- Counts the number of login sessions for the specified user using `who`, `grep`, and `wc -l`.
- Displays the login count for the user.
