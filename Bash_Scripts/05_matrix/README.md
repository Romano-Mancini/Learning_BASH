# Bash Script: Number Sequence Generator

This script generates a sequence of numbers from `0` to `p`, where `p` is calculated as `(n1 * n2) - 1`. The script prints each number and adds a newline every time the number is divisible by `n2`.

### Usage

1. Run the script with two optional command-line arguments, `n1` and `n2`.
   - Example: `./script.sh 4 5`
2. If command-line arguments are not provided, the script will prompt you to input `n1` and `n2` manually.
3. The script will output a sequence of numbers from `0` to `p` (where `p = (n1 * n2) - 1`), with each line containing numbers that are divisible by `n2`.

### How It Works

- Checks if at least two arguments are provided. If not, it prompts for `n1` and `n2`.
- Calculates `p` as `(n1 * n2) - 1`.
- Iterates from `0` to `p`, printing each number and adding a newline every `n2` numbers.
