Chunk (pre tri via divison en plusieurs groupes)
valeur d index(assigner valuer 0-100 pour les 10 plus petits etc)

RESSOURCES:
https://medium.com/@ayogun/push-swap-c1f5d2d41e97 (algo turk, mais boen pour comprendre les concepts(base des push et list circulaire))
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a


Radix animation: https://radix-sort-animation.netlify.app/

turk/chunk animation : https://chunk-turk-algo.netlify.app/

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