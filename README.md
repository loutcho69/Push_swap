*This project has been created as part of the 42 curriculum by btheveny and lobroue.*

# Push_swap

## Description

`push_swap` is a sorting project from the 42 curriculum.
Its goal is to sort a stack of integers in ascending order using only a restricted set of stack operations and a second auxiliary stack.
The main challenge is not only to sort correctly, but to do so with as few operations as possible.

This repository contains two programs:

- `push_swap`, which generates a sequence of valid operations to sort the input.
- `checker` (bonus), which reads a list of operations from standard input, applies them to the stacks, and prints `OK` if the stack is sorted correctly, or `KO` otherwise.

The project accepts integer arguments either as separate command-line values or as quoted strings containing several values.
Invalid input such as non-integer tokens, duplicates, or values outside the `int` range triggers an `Error` message on the standard error output.

A detailed explanation and justification of the selected algorithms is provided in the algorithm documentation already written in the sections below.

## Instructions

### Requirements

- A C compiler supporting the usual 42 flags
- `make`

### Compilation

Build the mandatory program:

```bash
make
```

Build the bonus program:

```bash
make bonus
```

Clean object files:

```bash
make clean
```

Remove all generated files:

```bash
make fclean
```

Rebuild everything:

```bash
make re
```

### Running `push_swap`

Basic usage:

```bash
./push_swap 2 1 3 6 5 8
```

The parser also accepts quoted input:

```bash
./push_swap "2 1 3 6 5 8"
```

This implementation also supports the following optional flags:

- `--simple` to force the simple strategy
- `--medium` to force the medium strategy
- `--complex` to force the complex strategy
- `--adaptive` to force the adaptive strategy selection
- `--bench` to print benchmark information such as disorder, chosen strategy, complexity, and operation counts

Examples:

```bash
./push_swap --complex "3 2 5 1 4"
./push_swap --adaptive --bench 3 2 5 1 4
```

### Running the bonus checker

The bonus program reads operations from standard input and verifies whether they sort the stack correctly.

Example with a pipe:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

Manual example:

```bash
./checker 2 1 0
```

Then type operations line by line, for example:

```text
sa
rra
```

Then send EOF (`Ctrl+D`).

The checker accepts all official `push_swap` operations:
`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

## Bonus

The bonus part of this project is fully implemented through the `checker` program.
It parses the same kind of input as the mandatory part, reads instructions with `get_next_line`, executes them on the stacks, handles invalid operations with a proper error message, and verifies whether the final state is correct.

This bonus was designed as a validation tool for the mandatory part, but it is also useful during development and debugging, since it allows quick testing of generated instruction sequences.

## Team Contributions

The work was divided as follows:

- `lobroue` mainly worked on the sorting algorithms.
- `btheveny` mainly worked on the parser and on the bonus part.
- Both debugged and reviewed both parts of the project whenever necessary.

## Resources

The project was documented and developed with the help of the following resources:

- The official 42 `push_swap` subject
- The existing algorithm notes and documentation already present in this README
- Medium articles and visualizers referenced in the repository for understanding chunk-based approaches and radix sort

### AI usage disclosure

AI tools were used for documentation support, wording improvements.
They were not used as a substitute for implementing, testing, or understanding the project.
All design choices, code implementation, and final validation were done by the authors.

RESSOURCES:
- https://medium.com/@ayogun/push-swap-c1f5d2d41e97 
- https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
- https://42-cursus.gitbook.io/guide/2-rank-02/push_swap
- https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81
- https://github.com/AdrianWR/push_swap
- https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
- https://www.youtube.com/watch?v=OaG81sDEpVk
- https://zestedesavoir.com/tutoriels/755/le-langage-c-1/1043_aggregats-memoire-et-fichiers/4279_structures/


# Push_swap — Algorithm Documentation

---

## Algorithms Overview

This project implements four sorting strategies selected at runtime based on a disorder metric computed from the initial stack configuration.

---

## Disorder Metric



## Indexing

Before sorting, all values are replaced by their **rank** (index from `0` to `n-1`). This normalization allows all algorithms to work on a clean integer range regardless of the actual input values, simplifying comparisons and bit operations.

---

## Strategy 1 — Simple Sort `O(n²)`

**Used when:** `disorder < 0.2` (almost sorted input)

**Technique:** Selection sort adaptation — repeatedly find the minimum remaining element and push it to B, then pull everything back to A.

**Special cases hardcoded for optimal operation counts:**
- **2 elements:** swap if out of order (`sa`)
- **3 elements:** all 6 permutations are hardcoded with the minimal operation sequence
- **4 elements:** push the minimum to B, sort the 3 remaining in A, reinsert
- **5 elements:** push the 2 smallest to B (choosing the closest to the top each time), sort the 3 remaining in A with the hardcoded 3-element sort, then reinsert the 2 from B in reverse order

For larger nearly-sorted inputs, the generic selection sort is used: for each target index from `0` to `n-1`, the algorithm rotates A (choosing `ra` or `rra` based on which is shorter) until the target is on top, then pushes it to B. Once all elements are in B, they are pulled back to A in order.

**Complexity argument:** Each element requires at most `n` rotations to be found and placed, for a total of `O(n²)` operations.

---

## Strategy 2 — Medium Sort `O(n√n)`

**Used when:** `0.2 ≤ disorder < 0.5` (moderately shuffled input)

**Technique:** Chunk-based sorting — divide the index range into `√n` chunks of size `√n`, push each chunk from A to B, then reconstruct A by always pulling the maximum from B.

**Phase 1 — Push by chunks:**

The index range `[0, n-1]` is divided into chunks of size `chunk_size = √n`. For each chunk, the algorithm scans A and pushes elements belonging to the current chunk range to B, rotating A (with `ra` or `rra` via `rotate_opti`) to find elements efficiently. Elements not in the current chunk are rotated past.

**Phase 2 — Pull in order:**

Once all elements are in B (grouped by chunk), the algorithm reconstructs A by repeatedly finding the maximum index remaining in B, rotating B to bring it to the top (choosing `rb` or `rrb` based on position relative to the midpoint), and pushing it to A with `pa`.

**Complexity argument:** Phase 1 performs `√n` chunk passes, each requiring at most `n` rotations: `O(n√n)`. Phase 2 performs `n` pulls, each requiring at most `√n/2` rotations on average: `O(n√n)`. Total: `O(n√n)`.

Turk/chunk animation : https://chunk-turk-algo.netlify.app/

---

## Strategy 3 — Complex Sort `O(n log n)`

**Used when:** `disorder ≥ 0.5` (highly shuffled input)

**Technique:** LSD Radix sort adapted for two stacks — sort bit by bit from the least significant bit (LSB) to the most significant bit (MSB).

**How it works:**

For each bit position `k` from `0` to `max_bits - 1`:
1. Iterate over all `n` elements in A exactly once
2. If the current bit of the top element is `0` → `pb` (push to B)
3. If the current bit is `1` → `ra` (rotate, keep in A)
4. After all `n` elements are processed, push everything from B back to A with `pa`

The bit is tested using: `(index & (1 << k))`

The number of passes is `max_bits = ⌊log₂(n-1)⌋ + 1`.

**Why it sorts correctly:** Radix sort is stable — elements that were in the correct relative order for previously processed bits remain in that order. By processing from LSB to MSB, each pass refines the ordering without breaking what was established before.

**Complexity argument:** `max_bits` passes × `2n` operations per pass (n pushes/rotates + n repushes) = `O(n log n)`.

**Performance:** For 500 elements, this produces approximately 4500 operations, well within the 5500 target.

Radix animation: https://radix-sort-animation.netlify.app/

---

## Strategy 4 — Adaptive Algorithm

**Default behavior** when no flag is specified, or when `--adaptive` is passed.

Selects the strategy based on the measured disorder:

| Disorder range | Strategy used | Complexity |
|---|---|---|
| `disorder < 0.2` | Simple Sort | `O(n²)` |
| `0.2 ≤ disorder < 0.5` | Medium Sort (Chunk) | `O(n√n)` |
| `disorder ≥ 0.5` | Complex Sort (Radix) | `O(n log n)` |

**Rationale for thresholds:**

- Below `0.2`, the stack is nearly sorted. A selection sort requires few rotations because target elements are already close to the top. An `O(n log n)` algorithm would perform unnecessary passes even though the stack barely needs work.
- Between `0.2` and `0.5`, moderate disorder benefits from chunk-based partitioning, which groups elements efficiently without the overhead of full bit-by-bit passes.
- Above `0.5`, the stack is sufficiently shuffled that the predictable `O(n log n)` cost of radix sort is optimal — it handles all permutations uniformly regardless of the disorder level.

---

## Space Complexity

All strategies operate in-place using only the two provided stacks (A and B). No auxiliary data structures beyond the `t_data` bookkeeping struct are allocated during sorting. Space complexity is `O(1)` additional memory beyond the input.