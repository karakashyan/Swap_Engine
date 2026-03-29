*This project has been created as part of the 42 curriculum by ekarakas, arptadev.*

# PUSH_SWAP

## Description

push_swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a limited set of operations, producing the smallest possible sequence of moves.

The program reads a list of integers as arguments, then outputs to stdout the ordered sequence of push_swap operations that sorts stack `a` in ascending order (smallest at the top). An optional strategy flag lets you force a specific algorithm, and an optional `--bench` flag prints performance metrics to stderr.

Both contributors — **ekarakas** and **arptadev** — wrote all code collaboratively together, pairing on every part of the project from parsing to sorting algorithms.

The project also makes use of our own **Libft** library (located in the `Libft/` folder), which we wrote previously as part of the 42 curriculum. It provides standard C utility functions such as `ft_split`, `ft_strdup`, `ft_strjoin`, `ft_strncmp`, `ft_isdigit`, `ft_putnbr_fd`, `ft_strlen`, `ft_calloc`, and `get_next_line`, all of which are used throughout this project.

---

## Instructions

### Compilation

```bash
make        # builds push_swap
make bonus  # builds checker (bonus)
make clean  # removes object files
make fclean # removes object files and binaries
make re     # fclean + make
```

### Execution

```bash
# Basic usage — outputs the operation sequence to stdout
./push_swap 5 3 8 1 2

# Force a specific strategy
./push_swap --simple  5 3 8 1 2
./push_swap --medium  5 3 8 1 2
./push_swap --complex 5 3 8 1 2
./push_swap --adaptive 5 3 8 1 2   # default if no flag given

# Enable benchmark output (printed to stderr)
./push_swap --bench 5 3 8 1 2
./push_swap --bench --complex 5 3 8 1 2

# Verify correctness with the bonus checker
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG

# Large input test
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l
```

### Error cases

The program prints `Error` to stderr and exits on:
- Non-integer arguments
- Integers outside the 32-bit signed range
- Duplicate values
- Empty or whitespace-only arguments
- More than one strategy flag provided
- Unknown `--` flags

```bash
./push_swap 1 two 3        # Error
./push_swap 1 2 2          # Error
./push_swap --simple --complex 1 2 3   # Error
```

---

## Usage Examples

```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
ra
ra
pa
pa
pa

$ ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l
13

$ ./push_swap --bench --complex 5 3 8 1 2
[bench] disorder: 60.00%
[bench] strategy: Complex / O(n log n)
[bench] total_ops: 18
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 4
[bench] ra: 3 rb: 0 rr: 0 rra: 6 rrb: 0 rrr: 0
```

---

## Algorithms

### Disorder Metric

Before any sorting, the program computes a **disorder score** between `0.0` and `1.0`. It counts all pairs `(i, j)` where `i < j` but `a[i] > a[j]` (inversions), divided by the total number of pairs. A score of `0` means already sorted; `1` means fully reversed.

This metric is used exclusively by the adaptive strategy to pick the best algorithm at runtime.

---

### Simple — Insertion Sort — O(n²)

**What it does:** Repeatedly finds the minimum of stack `a`, rotates it to the top, and pushes it to stack `b`. After reducing stack `a` to 3 elements, it sorts those 3 with a dedicated `sort_three` routine, then pushes everything back from `b` to `a`.

**Why O(n²):** For each of the `n` elements, finding and rotating the minimum costs up to `n` operations, giving `n × n` in the worst case.

**When we use it:**
- Forced via `--simple`
- Inside `adaptive_sort` when disorder < 0.2 (nearly sorted input)
- Inside `adaptive_sort` for any input of size ≤ 10 (overhead of heavier algorithms not worth it)

**Justification:** For nearly sorted or very small inputs, the constant factors of more complex algorithms outweigh their asymptotic advantage. Insertion sort shines here because few rotations are needed when elements are close to their target positions.

---

### Medium — Chunk Sort — O(n√n)

**What it does:** Normalizes stack `a` (assigns rank indices 0 to n−1), then divides the index range into chunks of size √n (≈12 for n≤100, ≈35 for n≤500). Each chunk is pushed to stack `b` in order; within each push, a light `sb` is applied if the new top of `b` is locally out of order. Once all chunks are in `b`, elements are pulled back to `a` one by one by always finding the current maximum of `b` and rotating it to the top.

**Why O(n√n):** There are √n chunks; processing each chunk scans at most n elements to push it, giving √n × n = n√n pushes. The pull-back phase also costs O(n√n) total rotations.

**When we use it:**
- Forced via `--medium`
- Inside `adaptive_sort` when 0.2 ≤ disorder < 0.5

**Justification:** Chunk sort strikes a balance between the simplicity of insertion sort and the overhead of radix sort. For moderately disordered inputs, the chunking strategy reduces unnecessary rotations significantly compared to O(n²) without requiring index normalization on every step like radix.

---

### Complex — Radix Sort (LSD) — O(n log n)

**What it does:** Normalizes stack `a` to rank indices 0 to n−1, then processes bits from least significant to most significant. On each bit pass, elements whose current bit is `0` are pushed to `b`; elements with bit `1` stay in `a` via `ra`. After each pass, all elements are pushed back from `b` to `a`. This repeats for `log₂(n)` bits.

**Why O(n log n):** Each of the `log₂(n)` bit passes touches all `n` elements exactly once, for a total of `n log₂(n)` operations.

**When we use it:**
- Forced via `--complex`
- Inside `adaptive_sort` when disorder ≥ 0.5 (highly disordered input)

**Justification:** For large, highly shuffled inputs, radix sort's predictable linear-per-pass behaviour avoids the worst-case blowup of insertion sort. The normalization step is cheap (O(n²) but done once), and the bit-level passes are extremely regular with no comparisons needed during sorting.

---

### Adaptive — Disorder-Driven Strategy Selection

**What it does:** Measures disorder before sorting, then delegates to one of the three strategies above based on thresholds:

| Disorder range | Strategy used | Complexity |
|---|---|---|
| < 0.2 | Insertion sort | O(n²) |
| 0.2 – 0.5 | Chunk sort | O(n√n) |
| ≥ 0.5 | Radix sort | O(n log n) |
| size ≤ 10 | Insertion sort | O(n²) |

**Threshold rationale:**
- `0.2`: at low disorder, insertion sort needs very few moves because most elements are already near their position. The O(n²) bound rarely manifests in practice.
- `0.5`: at medium disorder, chunk sort's structured push/pull is more operation-efficient than radix sort's overhead of normalization + multiple full passes.
- Above `0.5` the input is sufficiently scrambled that radix sort's guaranteed O(n log n) beats both alternatives.

**When we use it:**
- Forced via `--adaptive`
- Default behaviour when no strategy flag is provided

---

## Performance Targets

| Input size | Pass (< ops) | Good (< ops) | Excellent (< ops) |
|---|---|---|---|
| 100 numbers | 2000 | 1500 | 700 |
| 500 numbers | 12000 | 8000 | 5500 |

---

## Resources

### Algorithm references
- Donald Knuth, *The Art of Computer Programming*, Vol. 3 — Sorting and Searching
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Insertion Sort — Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)
- [Visualgo — Sorting Visualizations](https://visualgo.net/en/sorting)

### Tools
- [push_swap visualizer by o-reo](https://github.com/o-reo/push_swap_visualizer) — used to visually verify operation sequences during development

### AI usage

We used Claude (claude.ai) at several points during this project:

We asked Claude to help us draft this README in accordance with the subject requirements.

In all cases we reviewed, tested, and understood every suggestion before incorporating it. No algorithm logic was generated by AI — all sorting strategies were designed and implemented by us.
