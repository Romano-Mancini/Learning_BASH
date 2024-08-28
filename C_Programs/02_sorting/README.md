# Concurrent File Sorting Program

This repository contains a C program that concurrently sorts integer data from multiple input files and writes the sorted data to corresponding output files using threads. The program utilizes the merge sort algorithm to perform the sorting.

## Overview

The program accepts three command-line arguments:

1. **n**: The number of threads to use.
2. **strA**: The base name for input files (e.g., `data` for files `data1.txt`, `data2.txt`, etc.).
3. **strB**: The base name for output files (e.g., `sorted` for files `sorted1.txt`, `sorted2.txt`, etc.).

The program will:
- Create `n` threads.
- Each thread reads data from its corresponding input file, sorts the data using merge sort, and writes the sorted data to its corresponding output file.

## Compilation

To compile the C program, use the following command:
gcc -Wall -g -o pgrm pgrm.c -pthread

## Usage

Run the program with the following command-line arguments:

./pgrm n strA strB

- n: Number of threads (and thus the number of input/output file pairs).
- strA: Base name for input files.
- strB: Base name for output files.

For example:

./pgrm 3 data sorted

This command will use 3 threads to process data1.txt, data2.txt, and data3.txt, writing the sorted results to sorted1.txt, sorted2.txt, and sorted3.txt.

## File Format

Each input file should have the following format:
<number_of_integers>
<integer_1>
<integer_2>
...
<integer_n>

Where:

- The first line contains the number of integers.
- The following lines contain the integers to be sorted.

## How It Works
- Thread Creation: The program creates n threads. Each thread handles one input file and its corresponding output file.
- Sorting: Each thread reads integers from its input file, sorts them using the merge sort algorithm, and writes the sorted integers to the output file.
- Merge Sort: The sorting is performed using the merge sort algorithm, which divides the data into smaller segments, sorts them, and then merges the sorted segments.

## Example

Given input files:

data1.txt:
- 5
- 102
- 99
- 34
- 234
- 25

data2.txt:
- 3
- 45
- 23
- 67

Running ./pgrm 2 data sorted will create:

sorted1.txt:
- 5
- 25
- 34
- 99
- 102
- 234

sorted2.txt:

- 3
- 23
- 45
- 67
