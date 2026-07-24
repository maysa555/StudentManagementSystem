#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

// Structure to represent a student record
struct Student {
    string id;
    string name;
    int age;
    double gpa;
};

// Function declarations
void displayMenu();
void insertStudent(vector<Student>& students);
void viewStudents(const vector<Student>& students);
void searchStudent(const vector<Student>& students);
void deleteStudent(vector<Student>& students);
void updateStudent(vector<Student>& students);
void sortStudents(vector<Student>& students);
void displayStatistics(const vector<Student>& students);
void loadFromFile(vector<Student>& students, const string& filename);
void saveToFile(const vector<Student>& students, const string& filename);
void clearInputBuffer();

const string FILE_NAME = "students.txt";

int main() {
    vector<Student> students;
    loadFromFile(students, FILE_NAME);

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice (1-8): ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); // Consume newline left in the buffer

        switch (choice) {
        case 1: insertStudent(students); break;
        case 2: viewStudents(students); break;
        case 3: searchStudent(students); break;
        case 4: deleteStudent(students); break;
        case 5: updateStudent(students); break;
        case 6: sortStudents(students); break;
        case 7: displayStatistics(students); break;
        case 8:
            cout << "Saving records and exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please select a valid option from the menu.\n";
        }
        cout << "\nPress Enter to continue...";
        cin.get();
    } while (choice != 8);

    return 0;
}

void displayMenu() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    cout << "=========================================\n";
    cout << "        STUDENT MANAGEMENT SYSTEM        \n";
    cout << "=========================================\n";
    cout << "1. Insert New Student Record\n";
    cout << "2. View All Student Records\n";
    cout << "3. Search Student Record\n";
    cout << "4. Delete Student Record\n";
    cout << "5. Update Student Information\n";
    cout << "6. Sort Students by Name\n";
    cout << "7. Display Grade/GPA Statistics\n";
    cout << "8. Save & Exit\n";
    cout << "=========================================\n";
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void insertStudent(vector<Student>& students) {
    Student newStudent;
    cout << "\n--- Insert New Student ---\n";

    // Check for ID uniqueness
    while (true) {
        cout << "Enter Student ID: ";
        getline(cin, newStudent.id);

        auto it = find_if(students.begin(), students.end(), [&](const Student& s) {
            return s.id == newStudent.id;
            });

        if (it != students.end()) {
            cout << "Error: A student with ID " << newStudent.id << " already exists. Try again.\n";
        }
        else if (newStudent.id.empty()) {
            cout << "ID cannot be empty.\n";
        }
        else {
            break;
        }
    }

    cout << "Enter Student Name: ";
    getline(cin, newStudent.name);

    while (true) {
        cout << "Enter Age: ";
        if (cin >> newStudent.age && newStudent.age > 0) break;
        cout << "Invalid age. Please enter a positive integer.\n";
        clearInputBuffer();
    }

    while (true) {
        cout << "Enter GPA (0.0 - 4.0): ";
        if (cin >> newStudent.gpa && newStudent.gpa >= 0.0 && newStudent.gpa <= 4.0) break;
        cout << "Invalid GPA. Please enter a value between 0.0 and 4.0.\n";
        clearInputBuffer();
    }
    clearInputBuffer();

    students.push_back(newStudent);
    saveToFile(students, FILE_NAME);
    cout << "\nStudent record successfully added and saved!\n";
}

void viewStudents(const vector<Student>& students) {
    cout << "\n--- All Student Records ---\n";
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }

    cout << left << setw(12) << "ID" << setw(25) << "Name" << setw(8) << "Age" << setw(6) << "GPA" << "\n";
    cout << string(51, '-') << "\n";

    for (const auto& student : students) {
        cout << left << setw(12) << student.id
            << setw(25) << student.name
            << setw(8) << student.age
            << fixed << setprecision(2) << setw(6) << student.gpa << "\n";
    }
}

void searchStudent(const vector<Student>& students) {
    cout << "\n--- Search Student ---\n";
    if (students.empty()) {
        cout << "No records available to search.\n";
        return;
    }

    cout << "1. Search by ID\n2. Search by Name\nEnter preference: ";
    int option;
    if (!(cin >> option)) {
        clearInputBuffer();
        cout << "Invalid choice.\n";
        return;
    }
    clearInputBuffer();

    bool found = false;
    if (option == 1) {
        string searchId;
        cout << "Enter ID to search: ";
        getline(cin, searchId);

        for (const auto& student : students) {
            if (student.id == searchId) {
                if (!found) {
                    cout << "\nMatch found:\n";
                    cout << left << setw(12) << "ID" << setw(25) << "Name" << setw(8) << "Age" << setw(6) << "GPA" << "\n";
                    cout << string(51, '-') << "\n";
                }
                cout << left << setw(12) << student.id << setw(25) << student.name << setw(8) << student.age << fixed << setprecision(2) << setw(6) << student.gpa << "\n";
                found = true;
                break;
            }
        }
    }
    else if (option == 2) {
        string searchName;
        cout << "Enter Name (or partial name) to search: ";
        getline(cin, searchName);

        // Case-insensitive/partial match baseline snippet
        for (const auto& student : students) {
            if (student.name.find(searchName) != string::npos) {
                if (!found) {
                    cout << "\nMatches found:\n";
                    cout << left << setw(12) << "ID" << setw(25) << "Name" << setw(8) << "Age" << setw(6) << "GPA" << "\n";
                    cout << string(51, '-') << "\n";
                }
                cout << left << setw(12) << student.id << setw(25) << student.name << setw(8) << student.age << fixed << setprecision(2) << setw(6) << student.gpa << "\n";
                found = true;
            }
        }
    }
    else {
        cout << "Invalid search criteria selection.\n";
        return;
    }

    if (!found) cout << "No matching records found.\n";
}

void deleteStudent(vector<Student>& students) {
    cout << "\n--- Delete Student Record ---\n";
    if (students.empty()) {
        cout << "No records available to delete.\n";
        return;
    }

    string deleteId;
    cout << "Enter the Student ID to delete: ";
    getline(cin, deleteId);

    auto it = find_if(students.begin(), students.end(), [&](const Student& s) {
        return s.id == deleteId;
        });

    if (it != students.end()) {
        students.erase(it);
        saveToFile(students, FILE_NAME);
        cout << "Record with ID " << deleteId << " successfully wiped out.\n";
    }
    else {
        cout << "Student ID not found.\n";
    }
}

void updateStudent(vector<Student>& students) {
    cout << "\n--- Update Student Info ---\n";
    if (students.empty()) {
        cout << "No records available to update.\n";
        return;
    }

    string updateId;
    cout << "Enter Student ID to update: ";
    getline(cin, updateId);

    auto it = find_if(students.begin(), students.end(), [&](const Student& s) {
        return s.id == updateId;
        });

    if (it != students.end()) {
        cout << "Current Info -> Name: " << it->name << " | Age: " << it->age << " | GPA: " << it->gpa << "\n\n";

        cout << "Enter New Name (Leave blank to keep current): ";
        string newName;
        getline(cin, newName);
        if (!newName.empty()) it->name = newName;

        cout << "Enter New Age (0 to keep current): ";
        int newAge;
        if (cin >> newAge && newAge > 0) {
            it->age = newAge;
        }
        clearInputBuffer();

        cout << "Enter New GPA (-1 to keep current): ";
        double newGpa;
        if (cin >> newGpa && newGpa >= 0.0 && newGpa <= 4.0) {
            it->gpa = newGpa;
        }
        clearInputBuffer();

        saveToFile(students, FILE_NAME);
        cout << "Record updated and saved successfully!\n";
    }
    else {
        cout << "Student ID not found.\n";
    }
}

void sortStudents(vector<Student>& students) {
    cout << "\n--- Sort Students by Name ---\n";
    if (students.empty()) {
        cout << "No records to sort.\n";
        return;
    }

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.name < b.name;
        });

    saveToFile(students, FILE_NAME);
    cout << "Students sorted alphabetically by name.\n";
    viewStudents(students);
}

void displayStatistics(const vector<Student>& students) {
    cout << "\n--- Performance Statistics ---\n";
    if (students.empty()) {
        cout << "No records available to calculate statistics.\n";
        return;
    }

    double totalGpa = 0;
    double highestGpa = students[0].gpa;
    double lowestGpa = students[0].gpa;
    string bestStudent = students[0].name;

    for (const auto& student : students) {
        totalGpa += student.gpa;
        if (student.gpa > highestGpa) {
            highestGpa = student.gpa;
            bestStudent = student.name;
        }
        if (student.gpa < lowestGpa) {
            lowestGpa = student.gpa;
        }
    }

    double averageGpa = totalGpa / students.size();

    cout << "Total Students Registered: " << students.size() << "\n";
    cout << "Class Average GPA:         " << fixed << setprecision(2) << averageGpa << "\n";
    cout << "Highest GPA achieved:      " << highestGpa << " (" << bestStudent << ")\n";
    cout << "Lowest GPA recorded:       " << lowestGpa << "\n";
}

void loadFromFile(vector<Student>& students, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        // File doesn't exist yet; it will be dynamically created upon insertion
        return;
    }

    Student s;
    // Uses pipe delimiter handling to manage string tracking safely across spaces
    while (getline(inFile, s.id, '|') &&
        getline(inFile, s.name, '|') &&
        (inFile >> s.age) &&
        (inFile.ignore(1, '|')) &&
        (inFile >> s.gpa)) {
        inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip line ending
        students.push_back(s);
    }
    inFile.close();
}

void saveToFile(const vector<Student>& students, const string& filename) {
    ofstream outFile(filename, ios::trunc); // Overwrites file to preserve sync matrix
    if (!outFile) {
        cout << "Error: Could not save data to filesystem.\n";
        return;
    }

    for (const auto& student : students) {
        outFile << student.id << "|"
            << student.name << "|"
            << student.age << "|"
            << student.gpa << "\n";
    }
    outFile.close();
}