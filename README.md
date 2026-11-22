# C++ Projects

Console projects written in C++ during my first year at the Faculty of Computers and Information, using **OOP** and **data structures** (linked lists, queues, and stacks implemented from scratch, without the STL containers).

| Project | Concepts |
|---------|----------|
| [Hospital Management System](hospital-management-system/) | Singly linked list, queue, classes, dynamic memory |
| [Chat Application](chat-application/) | Queue (FIFO), stack (LIFO), undo logic |
| [Bank Account](oop-bank-account/) | Classes, constructors, `this` pointer, encapsulation |

## Build and run

Requires a C++ compiler such as `g++` (C++11 or later).

```bash
cd hospital-management-system
g++ main.cpp -o hospital
./hospital          # on Windows: hospital.exe
```

The same steps work for the other projects (replace the folder and output name).

---

## 1. Hospital Management System

A menu-driven program that manages patient records and a waiting queue.

- **Patient records:** stored in a singly linked list. Add (duplicate IDs are rejected), display all, search by ID, update, and delete.
- **Waiting queue:** every new patient joins a queue. You can view the queue, see who is first, and serve the next patient, who is then removed from the records.
- Memory is released in the destructors of the list and the queue.

## 2. Chat Application

A small simulation of a messaging inbox.

- **Inbox:** a queue, so messages are handled in the order they were sent (FIFO).
- **Deleted messages:** a stack, so the most recently deleted message is restored first (LIFO).
- Features: send a message, show the inbox, delete the oldest message, undo a delete, show deleted messages, and show a status summary.
- The menu uses a few Unicode symbols, so run it in a terminal that supports UTF-8.

## 3. Bank Account

A single class demonstrating core OOP ideas: default and parameterized constructors, the `this` pointer, private data members, a `const` member function, and input validation for deposits and withdrawals.

---

## Author

**Youssef Ashour**: AI student at the Faculty of Computers and Information, Suez Canal University.
[LinkedIn](https://www.linkedin.com/in/youssef-m-ashour) · [GitHub](https://github.com/youssef-m-ashour)
