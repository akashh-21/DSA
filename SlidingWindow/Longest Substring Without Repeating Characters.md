# 🔠 Longest Substring Without Repeating Characters

### ❓ Problem
Given a string `s`, find the length of the **longest substring** without repeating characters.

---

### 🧠 Simple & Unforgettable Explanation

We use the **sliding window** technique along with a **hash map**.

Imagine a window that slides over the string and always holds **only unique characters**.

### 🔄 Steps:
1. Initialize two pointers: `left` and `right` at 0.
2. Move `right` to expand the window.
3. If the character at `right` was seen before **inside the current window**, move `left` to skip the previous occurrence.
4. Update the character's index in the map.
5. Track the length of the current window (`right - left + 1`).
6. Keep updating the maximum length found.

---

### 🧪 Example:

**Input:** `"abcabcbb"`  
**Process:**  
- `a` → ✅  
- `ab` → ✅  
- `abc` → ✅  
- `abca` → ❌ (repeat `a`), move `left`  
- Continue until you get: `abc` → length = 3

**Output:** `3`

---

### ⏱️ Time and Space Complexity

| Complexity | Value     | Explanation                                           |
|------------|-----------|-------------------------------------------------------|
| Time       | O(n)      | Each character is visited at most twice              |
| Space      | O(k)      | `k` is the size of the charset (e.g., 26 for a-z)    |

---

### ▶️ Run the Code

```bash
g++ longest_unique_substring.cpp -o unique
./unique


Reference:
https://leetcode.com/problems/longest-substring-without-repeating-characters/
https://www.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1