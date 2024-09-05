# File Parser

This BASH script processes a text file, replacing specific strings and padding each line with a user-defined character sequence.

## Functionality:

* Reads a text file from `fileIn`.
* Creates a copy of the processed file named `fileOut`.
* Replaces all occurrences of `str1` with `str2` within the text.
* Pads each line in the output file with `N` repetitions of `str3` at the beginning and end, separated by a space.

## Input Parameters:

* `script.sh`: Name of the script itself.
* `fileIn`: Path to the input text file.
* `str1`: String to be replaced.
* `str2`: Replacement string.
* `N`: Number of repetitions to pad each line with `str3`.
* `str3`: String used for padding.

## Error Handling:

* Verifies if all six parameters are provided.
* Handles potential issues like missing files or invalid input.

## Usage:

```bash
./script.sh fileIn str1 str2 N str3 fileOut
```

## Example

```bash
./script.sh input.txt "find" "replace" 3 "-" output.txt
```

This example replaces all instances of "find" with "replace" in input.txt, adds three hyphens ("-") at the beginning and end of each line, and saves the result in output.txt.

## Note:

Ensure the script (script.sh) has execute permissions using chmod +x script.sh.
 
## Additional Information:

The script utilizes temporary files for efficient processing.
This script assumes that none of the input strings (str1, str2, and str3) contain whitespace characters.
