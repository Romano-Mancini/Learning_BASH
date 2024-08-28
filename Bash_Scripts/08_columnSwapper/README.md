# Bash Script: Swap Columns in File

This script reads pairs of values from a file, swaps the columns, and writes the result back to the same file.

### Usage

1. Run the script with a file containing pairs of values (two columns).
   - Example: `./script.sh data.txt`

2. The script will:
   - Read each line of the file, storing the values from the first and second columns into separate arrays.
   - Swap the columns and write the modified data back to the same file.

### How It Works

- Reads each line from the specified file, storing the first value in `vett1` and the second value in `vett2`.
- After reading all lines, it swaps the columns.
- Writes the swapped data back to the same file.

### Example

If the input file `data.txt` contains:
- 1 A
- 2 B
- 3 C

the script will modify it to:
- A 1
- B 2
- C 3
