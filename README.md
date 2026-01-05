# C++ CLI Calculator (Intermediate Starter, No CI)

Minimal C++20 CLI calculator with a small library + app + tests.

## Build
```bash
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build
```
## Batch Mode

You can run the program in batch mode using an input file.

Example:

```bash
python main.py --input data/sample.txt


The **sample input** does **not** go in the README.  
It goes in a **separate file**:

📁 `data/sample.txt`

```txt
add 2 3
sub 10 4
mul 6 7
div 20 5
sqrt 16
add 1.5 2.5
mul -3 4

## Run
```bash
./build/calc_app add 2 3
./build/calc_app pow 2 8
./build/calc_app sqrt 9
```
Env flags:
- `CALC_PRECISION=4` sets output precision
- `CALC_VERBOSE=1` enables trace logs
- `CALC_INPUT=<file>` (future batch mode hook)

## Test
```bash
ctest --test-dir build --output-on-failure
```