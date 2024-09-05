# README

## Script Description

`prog.sh` is a Bash script that processes a file containing lines of alphabetic characters. The script performs the following transformations on the file's content:

- Lines with an **even number of words** are converted to **uppercase**.
- Lines with an **odd number of words** are converted to **lowercase**.

## Prerequisites

- The script requires a file as input that contains alphabetic characters.
- Bash shell environment.

## Usage

Run the script with the following command:

```bash
./prog.sh <filename>
```

## Example

Given a file named file.txt with the following content:

```css
Nel mezzo del
Cammin di
Nostra vita mi ritrovai per una
Selva oscura
```

Running the script:

```bash
./prog.sh file.txt
```

Produces the following output:

```css
nel mezzo del
CAMMIN DI
NOSTRA VITA MI RITROVAI PER UNA
SELVA OSCURA
```
