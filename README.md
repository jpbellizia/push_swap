*This project has been created as part of the 42 curriculum by vneves-c, jpaulo-p.*

# push_swap

> Because Swap_push doesn't feel as natural.

## Description

`push_swap` sorts a list of integers using **two stacks** (`a` and `b`) and a limited
instruction set (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).
The program prints to standard output the **smallest possible sequence** of operations
that sorts stack `a` in ascending order.

What makes this version of the project special is that the binary embeds **four
distinct sorting strategies**, selectable at runtime, and an adaptive mode that
measures how *disordered* the input is before choosing how to sort it:

| Flag         | Strategy                     | Complexity (in generated ops) |
| ------------ | ---------------------------- | ----------------------------- |
| `--simple`   | Selection sort by minimum    | O(n²)                         |
| `--medium`   | Chunk sort (√n chunks)       | O(n·√n)                       |
| `--complex`  | LSD binary radix sort        | O(n·log n)                    |
| `--adaptive` | Disorder-based dispatcher    | Depends on measured disorder  |

`--adaptive` is the default when no flag is given.

<!-- TODO: adjust the table above if the implemented algorithms change. -->

## Instructions

### Requirements

- Linux (tested on campus machines) with `cc` and `make`
- Our `libft`, copied into `./libft/` (built automatically by this Makefile)

### Compilation

```bash
make            # builds ./push_swap
make bonus      # builds ./checker
make clean      # removes objects
make fclean     # removes objects and binaries
make re         # full rebuild
```

### Usage

```bash
# Default (adaptive) strategy
./push_swap 2 1 3 6 5 8

# Force a specific strategy
./push_swap --simple 5 4 3 2 1
./push_swap --complex 4 67 3 87 23

# Count operations
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l

# Verify the output with the provided checker
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG

# Benchmark mode: metrics go to stderr, operations stay on stdout
shuf -i 0-9999 -n 500 > args.txt
./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
cat bench.txt
```

Errors (non-integers, values outside `int` range, duplicates) print `Error` on
standard error. With no parameters, the program prints nothing and returns the prompt.

## Algorithms and justification

<!--
TODO before submission: this section was drafted at design time. Re-read it after
implementation, make sure every claim matches the final code, and rewrite anything
you would not be comfortable defending line by line.
-->

### Value normalization (ranks)

Right after parsing, every value is replaced (conceptually) by its **rank**: the
smallest value becomes `0`, the next one `1`, ..., up to `n-1`. Sorting the ranks
requires exactly the same operation sequence as sorting the original values, because
all our decisions depend only on relative order — which the transformation preserves.

Why we do it:
- Radix sort works on non-negative integers only; ranks remove negatives for free.
- Ranks cap the number of radix passes at ⌈log₂ n⌉ (9 passes for 500 numbers)
  instead of up to 31 passes for raw `int` values.
- Chunk boundaries become trivial: chunk *i* is simply the rank interval
  `[i·n/k, (i+1)·n/k)`.

The O(n²) double loop that computes ranks runs in C and costs **zero** push_swap
operations — and the subject's complexity model counts generated operations only.

### Disorder metric

Disorder is the fraction of **inverted pairs** (a bigger number appearing before a
smaller one) over all possible pairs, giving a number in `[0, 1]` — `0` for a sorted
stack, `1` for a reversed one. It is computed with the exact pseudocode from the
subject, **before any move**, and reported by `--bench` as a percentage with two
decimals.

### `--simple` — Selection sort by minimum, O(n²)

Find the position of the smallest element still in `a`, rotate it to the top through
the shortest direction (`ra` or `rra`), push it to `b`; repeat, then push everything
back with `pa`. Since elements enter `b` in ascending order, they come back to `a`
sorted with the smallest on top.

- **Ops upper bound:** each of the n extractions costs at most n/2 rotations + 1
  push, plus n final `pa` → O(n²).
- **Space:** the two stacks plus O(1) auxiliary variables → O(n).
- **Why this one:** it is the most natural fit for the stack model (one reusable
  primitive: "locate and rotate to top") and easy to reason about during defense.

### `--medium` — Chunk sort, O(n·√n)

Split the rank range into k = ⌈√n⌉ chunks. Phase 1: push chunks to `b` from the
smallest chunk up — if the top of `a` belongs to the current chunk, `pb` (with an
extra `rb` when the value sits in the lower half of the chunk, keeping big values
near the top of `b`); otherwise `ra`. Phase 2: repeatedly rotate the maximum of `b`
to its top through the shortest direction and `pa`.

- **Ops upper bound:** phase 1 scans `a` once per chunk → O(n·√n); phase 2
  extractions stay cheap because each chunk keeps its larger elements near the top
  of `b`, giving O(√n) amortized rotations per element → O(n·√n) overall.
- **Space:** O(n) for the stacks, O(1) extra.
- **Why this one:** it reuses the selection primitive from `--simple` and only adds
  a bucketing pre-pass, so it is the smallest step up in code complexity.

### `--complex` — LSD binary radix sort, O(n·log n)

For each bit from the least significant to bit ⌈log₂ n⌉−1 of the **rank**: scan the
whole stack `a`; if the current bit of the top element is `0`, `pb`, otherwise `ra`.
After the scan, `pa` everything back and move to the next bit.

- **Ops upper bound:** each of the ⌈log₂ n⌉ passes costs n scan operations plus at
  most n `pa` → ≤ 2n·⌈log₂ n⌉ = O(n·log n).
- **Space:** O(n) for the stacks, O(1) extra.
- **Why this one:** no comparisons, no recursion, no pivot handling — by far the
  simplest correct O(n·log n) strategy in the two-stack model, and its operation
  count is fully deterministic.

### `--adaptive` — Disorder-based dispatcher (default)

The adaptive strategy measures the disorder of the initial stack and delegates to
the internal method whose cost profile fits that regime, using the thresholds fixed
by the subject:

| Regime  | Condition              | Internal method            | Bound     |
| ------- | ---------------------- | -------------------------- | --------- |
| Low     | disorder < 0.2         | Selection-based insertion  | O(n²)     |
| Medium  | 0.2 ≤ disorder < 0.5   | Chunk sort                 | O(n·√n)   |
| High    | disorder ≥ 0.5         | LSD binary radix sort      | O(n·log n)|

**Threshold rationale:** the thresholds are mandated by the subject, and they match
the algorithms' behavior well. A nearly sorted stack (low disorder) has few
inversions, so a quadratic method that only moves misplaced elements performs very
few actual operations despite its worst-case class. A moderately shuffled stack
benefits from chunking, which exploits partial order. A heavily shuffled stack has
no structure to exploit, so the deterministic radix bound is the safest choice.

**Complexity argument:** each regime delegates to a method whose upper bound (proved
in the sections above) is exactly the bound required for that regime, so the
adaptive strategy satisfies the per-regime targets by construction. Space stays O(n)
in every regime.

<!-- TODO: if the low-disorder path ends up being plain selection sort instead of a
smarter insertion, update the table and rationale accordingly. -->

### Small inputs

Inputs of size ≤ 5 are handled by hardcoded optimal-ish routines (`sort_small`)
regardless of the selected strategy flag, since asymptotic classes are meaningless
at that scale. <!-- TODO: confirm this design choice. -->

## Benchmark results

<!-- TODO: fill with real numbers before submission (averages over ≥ 10 runs). -->

| Input size | Strategy     | Avg ops | Target (pass / good / excellent) |
| ---------- | ------------ | ------- | -------------------------------- |
| 100        | `--adaptive` | TODO    | 2000 / 1500 / 700                |
| 500        | `--adaptive` | TODO    | 12000 / 8000 / 5500              |

Reproduce with `./tools/benchmark.sh` (see the script for options).

## Team and contributions

<!-- TODO: replace with real logins and keep this honest and specific —
     the subject requires the README to clearly document both learners'
     contributions, and both must be able to defend any part of the code. -->

| Learner     | Main contributions                                        |
| ----------- | --------------------------------------------------------- |
| `<vneves-c>`  | TODO (e.g., parsing, ops, simple/medium strategies, ...)  |
| `<jpaulo-p>`  | TODO (e.g., radix, adaptive, bench mode, checker, ...)    |

Both learners reviewed each other's code and can explain every part of the project.

## Resources

- Donald E. Knuth, *The Art of Computer Programming, Vol. 3: Sorting and Searching*
- Cormen, Leiserson, Rivest, Stein, *Introduction to Algorithms* (chapters on
  sorting and lower bounds)
- Wikipedia: [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm),
  [Radix sort](https://en.wikipedia.org/wiki/Radix_sort),
  [Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))
- `man` pages: `read(2)`, `write(2)`, `malloc(3)`, `free(3)`, `exit(3)`

### How AI was used

<!-- TODO: keep this section truthful and up to date as the project evolves —
     it is required by the subject. Suggested honest starting point below. -->

AI (Anthropic's Claude) was used for:
- Discussing which algorithm families best fit each required complexity class and
  the trade-offs between them (no algorithm code was generated).
- Generating the initial project skeleton: this `README.md` draft, the `Makefile`.

All C code was written, reviewed, and understood by the authors. AI-drafted
documentation was reviewed and edited by both learners.
