# ZenoE SQL

A lightweight, modular, file-based SQL engine written entirely in C. ZenoE SQL is designed to mimic core database functionalities while offering custom-built pre-made management systems — all in a menu-driven terminal interface.

---

## 📦 Features

### 🔹 Main Database Engine
- Create, access, and delete databases
- Create, modify, and sort tables
- Structured storage using text files
- Menu-driven operations with user-friendly prompts

### 🔹 Pre-Made Library Modules
ZenoE SQL includes built-in domain-specific systems:
- 📚 **Library Management**: Issue, return, and view books
- 🎟 **Ticket Management**: Search, book, and cancel train tickets
- 🎓 **Student Management**: Track attendance, marks, and fees
- 👨‍💼 **Employee Management**: Store and display employee records
- 📘 **Book Management**: Manage book data separately
- 🎬 **Movie Management**: Add and view movie details
- 🎵 **Music Management**: Handle music databases
- 🍽 **Restaurant Management**: Maintain restaurant entries
- 🏨 **Hotel Management**: Store hotel data
- 🚗 **Car Management**: Handle vehicle records

### 🔹 File-Based Storage
- Persistent data using `.txt` files
- File handling with error checking
- Custom sorting and filtering operations

---

## 🛠 Technologies Used
- Language: **C**
- Data storage: **Text files**
- Interface: **Terminal-based (CLI)**

---

## 🚀 Getting Started

### 🔧 Compilation
```bash
gcc -o zeno_sql main.c
