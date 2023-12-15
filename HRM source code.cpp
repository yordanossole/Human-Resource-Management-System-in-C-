#include <iostream>
#include <string>
#include <iomanip> // For manipulating output

using namespace std;

// Define a structure to store employee information
struct Person {
    string firstName;
    string lastName;
    int personalID;
    double salary;
    double workingHours;
    double costPerHour;
};

int main() {
    Person employees[100]; // Array to store employee data
    int employeeCount = 0; // Number of employees in the array
    int userChoice ; // Menu choice

    system("cls"); // Clear screen 'system("cls")' is for Windows but 'system("clear")'for Linux based operating systems

    do {
        cout << "*******************************************************************" << endl;
        cout << "        Welcome to Human Resource Management (HRM) Software        " << endl;
        cout << "                         Fikru MiniMart                            " << endl;
        cout << "*******************************************************************" << endl << endl;

        cout << "To perform a specific task, please choose one of the following options:" << endl << endl;
        cout << "    1. Add a new employee" << endl;
        cout << "    2. Delete employee information" << endl;
        cout << "    3. Update employee information" << endl;
        cout << "    4. Generate reports" << endl;
        cout << "    5. Search for an employee" << endl;
        cout << "    6. Quit" << endl << endl;

        while (!(cin >> userChoice)) { // Validate user input
            cout << "Please enter a valid option (1-6): ";
            cin.clear(); // Clear any error flags set in the input stream
            cin.ignore(1000, '\n'); // Ignore any remaining characters in the input buffer up to the newline character
        }

        switch (userChoice) {
            case 1: { // Add a new employee
                int i = employeeCount; // Current employee index
                char redo; // Option to add another employee

                do {
                    employeeCount++; // Increment the number of employees
                    cout << "Enter the information of the new employee" << endl;
                    cout << "First Name: ";
                    cin >> employees[i].firstName;
                    cout << "Last Name: ";
                    cin >> employees[i].lastName;

                    cout << "Working hours per week: ";
                        while (!(cin >> employees[i].workingHours)) { // Validate user input
                            cout << "Please enter a valid input.";
                            cin.clear(); // Clear any error flags set in the input stream
                            cin.ignore(1000, '\n'); // Ignore any remaining characters in the input buffer up to the newline character
                        }

                    cout << "Payment for one hour: ";
                        while (!(cin >> employees[i].costPerHour)) { // Validate user input
                            cout << "Please enter a valid input.";
                            cin.clear(); // Clear any error flags set in the input stream
                            cin.ignore(1000, '\n'); // Ignore any remaining characters in the input buffer up to the newline character
                        }

                    employees[i].personalID = 8248001 + employeeCount; // Generate a unique Personal ID
                    employees[i].salary = employees[i].workingHours * employees[i].costPerHour * 52; // Calculate annual salary

                    // Display the added employee's information
                    cout << "\nThe employee with the following information has been added to the system:" << endl;
                    cout << setw(15) << left << "First Name" << setw(15) << left << "Last Name"
                         << setw(15) << left << "Personal ID" << setw(20) << left << "Salary per year (ETB)" << endl;
                    cout << "--------------------------------------------------------------------" << endl;
                    cout << setw(15) << left << employees[i].firstName << setw(15) << left << employees[i].lastName
                         << setw(15) << left << employees[i].personalID << setw(20) << left << employees[i].salary << endl;

                    cout << "Do you want to add another employee? (y/n): ";
                    cin >> redo;
                    i++;
                } while (redo == 'y' || redo == 'Y');
                break;
            }
            case 2: { // Delete employee information
                int empId; // Employee ID to be deleted
                bool found = false; // Flag to indicate if the employee was found

                cout << "Enter the ID of the employee to remove: ";

                while (!(cin >> empId)) { // Validate user input
                    cout << "\nPlease enter a valid ID: ";
                    cin.clear(); // Clear any error flags set in the input stream
                    cin.ignore(1000, '\n'); // Ignore any remaining characters in the input buffer up to the newline character
                }

                for (int i = 0; i < employeeCount; ++i) {
                    if (employees[i].personalID == empId) { // Find the employee by Personal ID
                        for (int j = i; j < employeeCount - 1; ++j) {
                            employees[j] = employees[j + 1]; // Shift employees to fill the gap
                        }
                        found = true;
                        employees[employeeCount - 1] = Person();  // Clear the last element to remove it
                        cout << "Employee with ID " << empId << " has been removed." << endl;

                        int a = employeeCount;
                        cout << "\nThe employee list has been updated:" << endl;
                        cout << setw(15) << left << "First Name" << setw(15) << left << "Last Name"
                             << setw(15) << left << "Personal ID" << setw(20) << left << "Salary per year (ETB)" << endl;
                        cout << "--------------------------------------------------------------------" << endl;
                        for (int j = 0; j < a; j++) {
                            cout << setw(15) << left << employees[j].firstName << setw(15) << left << employees[j].lastName
                                 << setw(15) << left << employees[j].personalID << setw(20) << left << employees[j].salary << endl;
                        }
                        cout << endl;
                    }
                }

                if (!found) {
                    cout << "Sorry, there is no employee with the requested personal number.";
                    cout << endl << endl;
                }
                break;
            }
            case 3: { // Update employee information
                int empIdUpdate; // Employee ID to update
                bool found = false; // Flag to indicate if the employee was found

                cout << "Enter the ID of the employee to modify data: ";

                while (!(cin >> empIdUpdate)) { // Validate user input
                    cout << "Please enter a valid ID: ";
                    cin.clear(); // Clear any error flags set in the input stream
                    cin.ignore(1000, '\n'); // Ignore any remaining characters in the input buffer up to the newline character
                }

                for (int i = 0; i < employeeCount; ++i) {
                    if (employees[i].personalID == empIdUpdate) { // Find the employee by Personal ID
                        found = true;
                        int choice = 0; // User's update choice
                        char redo; // Option to update another field

                        do {
                            cout << endl << endl;
                            cout << "Please enter the related number of the field you would like to update" << endl;
                            cout << "1. First name" << endl;
                            cout << "2. Last name" << endl;
                            cout << "3. Working hours per week" << endl;
                            cout << "4. Payment for one hour" << endl;
                            cout << "5. Exit" << endl;
                            cout << endl;

                            cin >> choice; // User's field update choice
                            if (choice == 1) {
                                cout << "Enter the new First Name: ";
                                cin >> employees[i].firstName;
                            } else if (choice == 2) {
                                cout << "Enter the new Last Name: ";
                                cin >> employees[i].lastName;
                            } else if (choice == 3) {
                                cout << "Enter the new Working Hours per Week: ";
                                cin >> employees[i].workingHours;
                                employees[i].salary = employees[i].workingHours * employees[i].costPerHour * 52;
                            } else if (choice == 4) {
                                cout << "Enter the new Payment for One Hour: ";
                                cin >> employees[i].costPerHour;
                                employees[i].salary = employees[i].workingHours * employees[i].costPerHour * 52;
                            } else if (choice == 5) {
                                break;
                            } else {
                                cout << "Invalid option. Try again." << endl;
                            }

                            cout << "Do you want to update another field? (y/n): ";
                            cin >> redo;
                        } while (redo == 'y' || redo == 'Y');
                    }
                }

                if (!found) {
                    cout << "Sorry, there is no employee with the requested personal number.";
                    cout << endl << endl;
                }
                break;
            }
            case 4: { // Generate reports
                int sortingOption; // Report sorting option

                cout << "Please enter the related number of the field by which you would like to sort the list:" << endl;
                cout << "1. First name" << endl;
                cout << "2. Salary" << endl;

                while (!(cin >> sortingOption)) { // Validate user input
                    cout << "Please enter a number! Try again: ";
                    cin.clear(); // Clear any error flags set in the input stream
                    cin.ignore(1000, '\n'); // Ignore any remaining characters in the input buffer up to the newline character
                }

                switch (sortingOption) {
                    case 1: { // Sort by First Name
                        cout << "Sorting based on First Name" << endl;
                        for (int i = 0; i < employeeCount - 1; i++) {
                            for (int j = i + 1; j < employeeCount; j++) {
                                if (employees[i].firstName > employees[j].firstName) {
                                    Person temp = employees[i];
                                    employees[i] = employees[j];
                                    employees[j] = temp;
                                }
                            }
                        }

                        int a = employeeCount;
                        cout << "\nThe employee list has been sorted based on First Name:" << endl;
                        cout << setw(15) << left << "First Name" << setw(15) << left << "Last Name"
                             << setw(15) << left << "Personal ID" << setw(20) << left << "Salary per year (ETB)" << endl;
                        cout << "--------------------------------------------------------------------" << endl;
                        for (int j = 0; j < a; j++) {
                            cout << setw(15) << left << employees[j].firstName << setw(15) << left << employees[j].lastName
                                 << setw(15) << left << employees[j].personalID << setw(20) << left << employees[j].salary << endl;
                        }
                        break;
                    }
                    case 2: { // Sort by Salary
                        cout << "Sorting based on Salary" << endl;
                        for (int i = 0; i < employeeCount - 1; i++) {
                            for (int j = i + 1; j < employeeCount; j++) {
                                if (employees[i].salary > employees[j].salary) {
                                    Person temp = employees[i];
                                    employees[i] = employees[j];
                                    employees[j] = temp;
                                }
                            }
                        }

                        int a = employeeCount;
                        cout << "\nThe employee list has been sorted based on Salary:" << endl;
                        cout << setw(15) << left << "First Name" << setw(15) << left << "Last Name"
                             << setw(15) << left << "Personal ID" << setw(20) << left << "Salary per year (ETB)" << endl;
                        cout << "--------------------------------------------------------------------" << endl;
                        for (int j = 0; j < a; j++) {
                            cout << setw(15) << left << employees[j].firstName << setw(15) << left << employees[j].lastName
                                 << setw(15) << left << employees[j].personalID << setw(20) << left << employees[j].salary << endl;
                        }
                        break;
                    }
                    default:
                        cout << "Invalid option. Try again." << endl;
                        break;
                }
                break;
            }
            case 5: { // Search for an employee
                int searchOption; // Search choice
                char redo1; // Option to search again
                string firstname; // Employee first name for search
                double minSalary, maxSalary; // Salary range for search

                do {
                    cout << "Search is based on two different fields (1. First name, 2. Salary), please enter your choice: ";
                    while (!(cin >> searchOption)) { // Validate user input
                        cout << "Please enter a number! Try again: ";
                        cin.clear(); // Clear any error flags set in the input stream
                        cin.ignore(1000, '\n'); // Ignore any remaining characters in the input buffer up to the newline character
                    }

                    if (searchOption == 2) { // Search by salary range
                        cout << "Please define your search range for salary of employees." << endl;
                        cout << "What is the minimum salary for search (S_min)? = ";
                        while (!(cin >> minSalary)) { // Validate user input
                            cout << "Please enter a number! Try again: ";
                            cin.clear(); // Clear any error flags set in the input stream
                            cin.ignore(1000, '\n'); // Ignore any remaining characters in the input buffer up to the newline character
                        }
                        cout << "What is the maximum salary for search (S_max)? = ";
                        while (!(cin >> maxSalary)) { // Validate user input
                            cout << "Please enter a number! Try again: ";
                            cin.clear(); // Clear any error flags set in the input stream
                            cin.ignore(1000, '\n'); // Ignore any remaining characters in the input buffer up to the newline character
                        }
                        int a = employeeCount;
                        cout << "\nEmployees within the specified salary range:" << endl;
                        cout << setw(15) << left << "First Name" << setw(15) << left << "Last Name"
                             << setw(15) << left << "Personal ID" << setw(20) << left << "Salary per year (ETB)" << endl;
                        cout << "--------------------------------------------------------------------" << endl;
                        for (int j = 0; j < employeeCount; j++) {
                            if (employees[j].salary >= minSalary && employees[j].salary <= maxSalary) {
                                cout << setw(15) << left << employees[j].firstName << setw(15) << left << employees[j].lastName
                                     << setw(15) << left << employees[j].personalID << setw(20) << left << employees[j].salary << endl;
                            }
                        }
                    } else if (searchOption == 1) { // Search by first name
                        cout << "Please enter the First name of the employee: ";
                        cin >> firstname;
                        int a = employeeCount;
                        cout << "\nEmployees with the specified First name:" << endl;
                        cout << setw(15) << left << "First Name" << setw(15) << left << "Last Name"
                             << setw(15) << left << "Personal ID" << setw(20) << left << "Salary per year (ETB)" << endl;
                        cout << "--------------------------------------------------------------------" << endl;
                        for (int j = 0; j < employeeCount; j++) {
                            if (employees[j].firstName == firstname) {
                                cout << setw(15) << left << employees[j].firstName << setw(15) << left << employees[j].lastName
                                     << setw(15) << left << employees[j].personalID << setw(20) << left << employees[j].salary << endl;
                            } else {
                                cout << "The employee with the name " << firstname << " not found." << endl;
                            }
                        }
                    } else {
                        cout << "Invalid option. Try again." << endl;
                    }

                    cout << "Do you want to search for another employee? (y/n): ";
                    cin >> redo1;
                } while (redo1 == 'y' || redo1 == 'Y');
                break;
            }
            case 6: // Quit the program
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Try again." << endl;
                break;
        }

        cout << "Press any key to continue...";
        cin.ignore(); // Clear input buffer
        cin.get();    // Wait for user input
        system("cls"); // Clear screen

    } while (userChoice != 6);

    return 0;
}
