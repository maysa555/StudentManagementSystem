# Student Management System (C++)

A console-based Student Management System developed in modern C++. This project demonstrates core object-oriented programming and data management concepts through a simple and user-friendly command-line interface (CLI).

The application allows users to efficiently manage student records with persistent file storage and common record management operations.

---

## Features

- **Persistent Storage:** Automatically saves and loads student records from `students.txt`.
- **CRUD Operations:** Create, view, update, and delete student records.
- **Search Functionality:** Search students by ID or by name.
- **Sorting:** Sort students alphabetically by name.
- **Statistics:** Display useful class statistics, including:
  - Total number of students
  - Average GPA
  - Highest GPA
  - Lowest GPA
- **Input Validation:** Prevents invalid console input and improves program stability.

---

## C++ Concepts Demonstrated

- Structures (`struct`)
- Standard Template Library (`std::vector`)
- File handling (`std::fstream`)
- String streams (`std::stringstream`)
- Algorithms (`std::sort`, `std::find_if`)
- Lambda expressions
- Input validation
- Modular programming using functions

---

## Project Files

```
StudentManagementSystem.cpp
StudentManagementSystem.slnx
StudentManagementSystem.vcxproj
students.txt
README.md
```

---

## Requirements

- C++11 or later
- Microsoft Visual Studio 2022 (recommended)

or

- GCC / Clang supporting C++11+

---

## Building the Project

### Visual Studio

1. Clone the repository:

```bash
git clone https://github.com/maysa555/StudentManagementSystem.git
```

2. Open `StudentManagementSystem.slnx` in Visual Studio.

3. Build the solution (**Ctrl + Shift + B**).

4. Run the program (**Ctrl + F5**).

---

### Using g++

Compile from the command line:

```bash
g++ -std=c++11 StudentManagementSystem.cpp -o StudentManagementSystem
```

Run:

**Windows**

```bash
StudentManagementSystem.exe
```

**Linux / macOS**

```bash
./StudentManagementSystem
```

---

## Future Improvements

- Password-protected administrator login
- Export student records to CSV
- GPA letter grade calculation
- Course enrollment management
- Graphical User Interface (GUI)
- Database support (SQLite or MySQL)

---

## Author

**Maysa Esmaeilzadeh**

GitHub: https://github.com/maysa555
