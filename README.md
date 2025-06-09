# Leetcode-2641.-Cousins-in-Binary-Tree-II

# 🌳 Replace Node Values in Binary Tree

## 📘 Problem Statement

You are given the `root` of a binary tree. Replace the value of each node in the tree as follows:

* Root node becomes `0`.
* For all other nodes, their new value is:

  > **Sum of all nodes at the same level - Sum of the node's siblings**.

---

## 🧠 Approach Explanation

### Step 1: 🌐 Level Sum Mapping

* Perform **level-order traversal** (BFS) to compute the **sum of all node values** at each level.
* Store it in a hash map: `level -> sum`.

### Step 2: 🔄 Replace Values

* Use another BFS pass.
* For each node, calculate its children's sum.
* Update each child’s value as:

  > `levelSum[level + 1] - sum of its siblings`
* Finally, set the root node's value to `0`.

---

## 🧪 Example

```
Input Tree:
       5
      / \
     2   13

Level 1 sum = 5
Level 2 sum = 2 + 13 = 15

Update children:
 2 → 15 - (2 + 13) = 0
13 → 15 - (2 + 13) = 0
Root → 0

✅ Output:
       0
      / \
     0   0
```

---

## ⏱️ Time Complexity

* **O(N)**: Every node is visited twice (once for sum, once for update)

## 💾 Space Complexity

* **O(N)**: For BFS queue and level-sum map

---

## 🧑‍💻 Author Info

**👨‍🎓 Ridham Garg**
🚀 B.Tech Computer Engineering, Thapar University, Patiala
📧 *[ridhamgarg000@gmail.com](ridhamgarg000@gmail.com)*

---

## 🌟 Built with ❤️ using level-order traversal (BFS) and smart mapping in C++!
