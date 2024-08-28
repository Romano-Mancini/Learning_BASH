# Bash Script: Conditional File Copy

This script creates a directory (if it doesn't already exist) and copies specified files into that directory based on user confirmation.

### Usage

1. Run the script with a target directory name followed by files to potentially copy.
   - Example: `./script.sh target_directory file1.txt file2.txt`

2. The script will:
   - Check if the target directory exists; if not, it will create it.
   - For each file specified:
     - Prompt the user to confirm whether they want to copy the file into the target directory.
     - Copy the file if the user responds with `Y`.
     - Skip the file if the user responds with `N`.
     - Continue prompting until a valid response (`Y` or `N`) is given.

### How It Works

- **Directory Check:**
  - Checks if the target directory exists and is a directory. If not, it creates the directory.

- **File Processing:**
  - Iterates over the provided file arguments.
  - For each file (excluding the target directory), it prompts the user to decide whether to copy it.

- **User Interaction:**
  - Uses a loop to ensure valid user input (`Y` or `N`) before proceeding.
