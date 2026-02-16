# Self-Balancing AVL Tree

A C++ implementation of an AVL (Adelson-Velsky and Landis) tree with automatic balancing through rotations. 

## Overview

This project implements a complete AVL tree data structure that:
- Automatically balances after insertions using single and double rotations
- Maintains balance factor of -1, 0, or 1 at every node
- Supports efficient search, insertion, and range queries
- Provides O(log n) worst-case time complexity for core operations

## Features

- **Automatic Balancing:** Self-balances through left/right rotations after every insertion
- **Height Tracking:** Each node maintains its height for efficient balance factor calculation
- **Range Queries:** Find all values within a specified key range
- **Deep Copy Support:** Implements copy constructor and assignment operator
- **Memory Management:** Custom destructor ensures no memory leaks

## How It Works

The AVL tree maintains balance by ensuring the height difference between left and right subtrees never exceeds 1:

- **Balance Factor = Left Height - Right Height**
- Valid balance factors: -1, 0, 1
- After insertion, the tree checks balance factors from bottom-up
- Performs rotations when balance factor becomes ±2

### Rotation Types

**Single Right Rotation:** Used when left-left case detected (balance factor > 1, left child balance ≥ 0)

**Single Left Rotation:** Used when right-right case detected (balance factor < -1, right child balance ≤ 0)

**Double Rotation (Left-Right):** Used when left-right case detected (balance factor > 1, left child balance < 0)

**Double Rotation (Right-Left):** Used when right-left case detected (balance factor < -1, right child balance > 0)

## Technical Implementation

- **Language:** C++
- **Key Concepts:** Self-balancing trees, tree rotations, height balancing, binary search trees
- **Time Complexity:** O(log n) for insert/search operations (guaranteed by height balancing)
- **Space Complexity:** O(n) for n nodes
- **Memory Management:** Recursive node deletion, deep copy semantics
