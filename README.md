# C++ CLI Calculator (Intermediate Starter, No CI)

Minimal C++20 CLI calculator with a small library + app + tests.

## Build
```bash
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build
```

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