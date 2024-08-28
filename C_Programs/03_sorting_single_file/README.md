# Concurrent File Sorting and Merging Program

This C program concurrently sorts integer data from multiple input files using threads and merges the sorted sequences into a single ordered sequence, which is then written to a single output file.

## Overview

The program takes three command-line arguments:

1. **n**: The number of input and output files (i.e., the number of threads).
2. **strA**: The base name for input files (e.g., `data` for files named `data1.txt`, `data2.txt`, etc.).
3. **strB**: The name of the output file where the final sorted sequence will be written.

## Compilation

To compile the program, use:
gcc -o pgrm pgrm.c -pthread

## Usage

Run the program with the following command-line arguments:

./pgrm n strA strB

- n: Number of input/output file pairs and threads.
- strA: Base name for input files.
- strB: Name of the output file.

Example:

./pgrm 3 data sorted.txt

This will process the input files data1.txt, data2.txt, and data3.txt, sort the contents of each file, merge all sorted sequences, and write the final sorted sequence to sorted.txt.

## File Format

Each input file should contain a list of integers, one per line.

Example data1.txt:

- 5
- 34
- 99
- 25
- 102
- 234

## How It Works

1.  Thread Creation: The program creates n threads. Each thread reads and sorts integers from its corresponding input file but does not write to an output file.
2.  Sorting: Each thread sorts the integers using merge sort.
3.  Merging: After all threads complete, the main thread merges the sorted data from all input files into a single sorted sequence.
4.  Output: The final sorted sequence is written to the specified output file.

## Example

Given input files:

data1.txt:
- 5
- 34
- 99
- 25
- 102
- 234

data2.txt:

- 5
- 12
- 67
- 45
- 89
- 23

Running ./pgrm 2 data sorted.txt will result in the following file:
sorted.txt:

- 5
- 5
- 12
- 23
- 25
- 34
- 45
- 67
- 89
- 99
- 102
- 234
