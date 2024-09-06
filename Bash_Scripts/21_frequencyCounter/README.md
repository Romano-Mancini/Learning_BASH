# Word Frequency Counter

This script counts the absolute frequency of all strings contained in a given ASCII text file. Each word in the file is counted, and its frequency is printed on the standard output.

## How It Works

The script reads an input file containing an indefinite number of rows and strings. It counts the occurrences of each word and prints the absolute frequency of all the strings in the file.

## Example

### Input File (`input.txt`):
hello world hello bash scripting bash scripting world


### Running the Script:
```bash
./script.sh input.txt
```

### Output:

* 2 - hello
* 2 - world
* 2 - bash
* 2 - scripting

## Script Explanation

1. The script reads a text file either provided as an argument or entered by the user.
2. It uses an associative array to keep track of each word's count.
3. The frequency of each word is printed in the format: count - word.
