# Hotel Management System (C++)

A robust C++ console application designed to simulate and manage hotel room allocations, customer booking workflows, priority requests, and transaction histories. This project demonstrates core **Data Structures and Algorithms (DSA)** concepts—including Linked Lists, Circular Priority Queues, Stacks, and Binary Search Trees—implemented without external library dependencies.

---

## Table of Contents
- [Data Structures & Architecture](#data-structures--architecture)
- [Key Features](#key-features)
- [Room Categories](#room-categories)
- [Interactive Menu Operations](#interactive-menu-operations)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation & Execution](#compilation--execution)
- [Example Walkthrough](#example-walkthrough)
- [Code Structure](#code-structure)

---

## Data Structures & Architecture

The system utilizes four custom-built data structures to handle different aspects of hotel management:

| Data Structure | Implementation Class | Purpose / Role |
| :--- | :--- | :--- |
| **Singly Linked List** | `floorManagment` | Tracks real-time room inventories, dynamic statuses (`available`/`booked`), room IDs, and room types. |
| **Circular Priority Queue** | `Queue` | Manages incoming booking requests. VIP/High-priority requests are inserted at the front (head), while normal requests are enqueued at the rear[cite: 1]. |
| **Stack (LIFO)** | `Stack` | Preserves transaction history, enabling full log tracking and single-step undo functionality (popping recent records)[cite: 1]. |
| **Binary Search Tree** | `tree` | Organizes and displays the default hotel layout and room structural hierarchy[cite: 1]. |

---

## Key Features

- **Priority Queue Processing**: Handles regular and high-priority booking requests seamlessly[cite: 1].
- **Dynamic Status Updates**: Modifies room states automatically from `available` to `booked` upon processing queued requests[cite: 1].
- **Booking History Tracking**: Logs processed requests into a stack for historical viewing and step-by-step history clearing[cite: 1].
- **Floor Plan Traversal**: Supports tree traversal methods (In-order, Pre-order, Post-order) to display room layouts[cite: 1].
- **Room Search & Filter**: Enables instant search filtering across specific room types[cite: 1].

---

## Room Categories

The hotel layout supports three primary room types[cite: 1]:
- `single`
- `double`
- `suite`

---

## Interactive Menu Operations

Upon running the program, the system presents an interactive menu with the following choices[cite: 1]:

```text
------------------------- MENU -----------------------------
 ~ press 1 to display the room layout 
 ~ press 2 to add booking requests 
 ~ press 3 to display the current queue 
 ~ press 4 to process the queue 
 ~ press 5 to view booking history 
 ~ press 6 to remove the most recent booking from history 
 ~ press 7 to view hotel's default floor plan via tree 
 ~ press 8 if you want to search the rooms with specific type 
 ~ press 0 to exit 
```[cite: 1]

---

## Getting Started

### Prerequisites

To compile and run this project, you need a standard C++ compiler supporting **C++11** or higher[cite: 1]:
- GCC / G++ compiler
- Clang++ compiler
- MSVC (Visual Studio)

### Compilation & Execution

#### Command Line / Terminal (GCC):

1. **Clone the Repository:**
   ```bash
   git clone [https://github.com/minahilmehmood99/HotelManagementSystemCPP.git](https://github.com/minahilmehmood99/HotelManagementSystemC-.git)
   cd HotelManagementSystemC-
