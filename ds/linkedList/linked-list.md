# 🔗 Linked List — Revision Notes

## 1. Basic Structure

A linked list consists of **nodes**.

Each node contains:

```cpp
data
next
```

Example:

```cpp
struct ListNode {
    int val;
    ListNode* next;
};
```

`next` stores the address of the next node.

The last node points to:

```cpp
nullptr
```

Example:

```text
10 → 20 → 30 → nullptr
```

---

# 2. Head

`head` points to the first node.

```text
head
 ↓
10 → 20 → 30 → nullptr
```

If:

```cpp
head == nullptr
```

the linked list is empty.

---

# 3. Traversing a Linked List

## Process Every Node

Use:

```cpp
while (curr != nullptr)
```

Example:

```cpp
ListNode* curr = head;

while (curr != nullptr) {
    cout << curr->val;
    curr = curr->next;
}
```

### 🧠 Rule to Remember

> **`curr != nullptr` → process the current node.**

This condition allows us to visit **every node**, including the last node.

---

# 4. Stop at the Last Node

Use:

```cpp
while (curr->next != nullptr)
```

Example:

```cpp
ListNode* curr = head;

while (curr->next != nullptr) {
    curr = curr->next;
}
```

When the loop stops:

```text
10 → 20 → 30 → nullptr
          ↑
         curr
```

`curr` is pointing to the **last node**.

### 🧠 Rule to Remember

> **`curr->next != nullptr` → stop at the current node when it is the last node.**

---

# 5. The Most Important Difference

```text
Need to PROCESS all nodes?
        ↓
curr != nullptr
```

```text
Need to STOP AT the last node?
        ↓
curr->next != nullptr
```

### Example

Given:

```text
10 → 20 → 30 → nullptr
```

### `curr != nullptr`

Processes:

```text
10
20
30
```

### `curr->next != nullptr`

Processes/visits:

```text
10
20
```

Then stops at:

```text
30
```

---

# 6. Moving to the Next Node

This:

```cpp
curr = curr->next;
```

means:

> Move `curr` to the next node.

Example:

```text
10 → 20 → 30
↑
curr
```

After:

```cpp
curr = curr->next;
```

```text
10 → 20 → 30
     ↑
    curr
```

---

# 7. Accessing Node Data

```cpp
curr->val
```

gets the value stored in the current node.

```cpp
curr->next
```

gets the pointer to the next node.

So:

```cpp
curr->val
```

means:

> Current node's value

and

```cpp
curr->next
```

means:

> Next node

---

# 8. Common Traversal Pattern

```cpp
ListNode* curr = head;

while (curr != nullptr) {

    // Process current node

    curr = curr->next;
}
```

### Remember

```text
Initialize
    ↓
curr = head

Process
    ↓
curr->val

Move
    ↓
curr = curr->next

Stop
    ↓
curr == nullptr
```

---

# 9. Finding the Last Node

```cpp
ListNode* curr = head;

while (curr->next != nullptr) {
    curr = curr->next;
}
```

At the end:

```text
curr → last node
```

⚠️ This assumes the list is not empty.

For an empty list:

```cpp
head == nullptr
```

`curr->next` would cause an error.

So safely:

```cpp
if (head == nullptr) {
    return;
}

ListNode* curr = head;

while (curr->next != nullptr) {
    curr = curr->next;
}
```

---

# 10. Insert at Beginning

Before:

```text
head
 ↓
20 → 30 → nullptr
```

Create new node:

```text
10
```

Set:

```cpp
newNode->next = head;
head = newNode;
```

After:

```text
head
 ↓
10 → 20 → 30 → nullptr
```

### 🧠 Pattern

```cpp
newNode->next = head;
head = newNode;
```

---

# 11. Delete the Head

Before:

```text
head
 ↓
10 → 20 → 30 → nullptr
```

Simply:

```cpp
head = head->next;
```

After:

```text
head
 ↓
20 → 30 → nullptr
```

---

# 12. Fast & Slow Pointers

Two pointers:

```cpp
slow
fast
```

Usually:

```cpp
slow = slow->next;
fast = fast->next->next;
```

### Used for:

- Finding middle of linked list
- Detecting cycles
- Finding cycle entry
- Other two-pointer linked-list problems

---

# 13. Finding Middle of Linked List

```cpp
ListNode* slow = head;
ListNode* fast = head;

while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
}
```

When the loop ends:

```text
slow → middle
```

### 🧠 Pattern

> Slow moves 1 step.  
> Fast moves 2 steps.

---

# 14. Reverse a Linked List

Three important pointers:

```cpp
prev
curr
next
```

Pattern:

```cpp
ListNode* prev = nullptr;
ListNode* curr = head;

while (curr != nullptr) {

    ListNode* next = curr->next;

    curr->next = prev;

    prev = curr;
    curr = next;
}

head = prev;
```

### 🧠 Remember the order

```text
1. Save next
       ↓
2. Reverse pointer
       ↓
3. Move prev
       ↓
4. Move curr
```

```text
next = curr->next

curr->next = prev

prev = curr

curr = next
```

---

# 15. Linked List Complexity

| Operation       | Complexity |
| --------------- | ---------: |
| Access by index |       O(n) |
| Search          |       O(n) |
| Insert at head  |       O(1) |
| Delete at head  |       O(1) |
| Insert at end\* |       O(n) |
| Delete at end\* |       O(n) |

`*` Depends on whether a tail pointer is maintained.

---

# 🧠 Quick Revision

### Traversal

```cpp
while (curr != nullptr)
```

→ Process **every node**

---

### Stop at last node

```cpp
while (curr->next != nullptr)
```

→ `curr` ends at **last node**

---

### Move forward

```cpp
curr = curr->next;
```

---

### Current value

```cpp
curr->val
```

---

### Next node

```cpp
curr->next
```

---

### Middle

```text
slow = 1 step
fast = 2 steps
```

---

### Reverse

```text
prev
curr
next
```

---

# ⭐ Linked List Mental Model

```text
             curr
               ↓
        ┌─────────────┐
        │     data    │
        │     next ───┼────→ next node
        └─────────────┘

```

Think:

> **Node = data + pointer to the next node**

And remember:

> **`curr != nullptr` → process the node**

> **`curr->next != nullptr` → stop at the last node**

> **`curr = curr->next` → move forward**
