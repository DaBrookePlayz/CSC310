# A1_P1

## Purpose

Splay tree

## Task 5:

### How does splaying affect the balance of the tree in the long term (e.g., across multiple operations)? How does this affect the amortized running time of O(log n)

When we splay, it reorganizes the elements to create a self-balancing orderly binary tree. Splaying also keeps the amortized cost of time at O(log(n)) because the elements that are more frequently accessed will be closer to the top, this reducing operation time.