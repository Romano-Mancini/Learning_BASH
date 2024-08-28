# Binary Number Generator

This repository contains a C program that generates and prints all binary numbers of `n` bits. The program utilizes process forking to create multiple processes that compute and display the binary numbers.

## Overview

The provided C program generates binary numbers by forking processes. Each process represents a bit position in the binary numbers. The main process waits for all child processes to complete before printing the results.

## Requirements

- A Unix-like operating system with a C compiler (e.g., `gcc`).
- Basic knowledge of process management in Unix/Linux.

## Compilation

To compile the C program, use the following command:
`gcc -Wall -g -o binary_generator.exe binary_generator.c`

## Usage

Run the compiled program with an integer argument representing the number of bits:

./binary_generator <number_of_bits>

Replace <number_of_bits> with the desired number of bits for the binary numbers. 

For example:

./binary_generator 3

This command will generate and print all 3-bit binary numbers.

## Example

For n = 3, the output will be:

000
001
010
011
100
101
110
111
