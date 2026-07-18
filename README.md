# Student Management System (C++)

A robust, console-based Student Management System built using modern C++. This application serves as a practical implementation of fundamental and intermediate software engineering concepts, focusing on object blueprints, memory management, and persistent data storage.

Designed for educational environments, the system allows administrators to seamlessly handle student records through a clean Command Line Interface (CLI).

## 🚀 Features

*   **Persistent Storage:** Automatically saves and loads student records to a local text file (`students.txt`) using customized file serialization.
*   **CRUD Operations:** Full capability to **C**reate, **R**ead, **U**pdate, and **D**elete student data.
*   **Advanced Search:** Query student records instantaneously by either a unique ID or by a partial name match.
*   **Data Manipulation:** Sort student directories alphabetically by name.
*   **Performance Analytics:** Real-time generation of class statistics, including total headcount, average GPA, and highest/lowest achieving students.
*   **Input Validation:** Robust error handling preventing program crashes from faulty console inputs (e.g., entering letters into integer inputs).

## 🛠️ Core Concepts Demonstrated

*   **Custom Data Structures (`struct`):** Bundling heterogeneous variables (Strings, Integers, Doubles) into cohesive data units.
*   **Dynamic Memory Management:** Utilizing STL vectors (`std::vector`) to handle arrays that scale seamlessly during runtime.
*   **File I/O Streams (`fstream`):** Implementing custom string parsing using character delimiters (`|`) to safely serialize and deserialize data across sessions.
*   **Lambda Expressions & Algorithms:** Leveraging C++ `<algorithm>` headers (`std::sort`, `std::find_if`) alongside modern lambdas for fast execution loops.

## 📦 Getting Started

### Prerequisites
*   A C++ compiler supporting **C++11** or higher (GCC, Clang, or MSVC).

### Compilation & Setup
Clone the repository and compile the source file using your terminal:

```bash
# Clone the repository
git clone [https://github.com/YOUR_USERNAME/student-management-system.git](https://github.com/YOUR_USERNAME/student-management-system.git)
cd student-management-system

# Compile the source code
g++ -std=c++11 main.cpp -o StudentSystem

# Run the application
./StudentSystem
