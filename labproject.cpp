#include <iostream>
#include <string>
using namespace std;

int main() {
    // Program details for three programs
    string program1Name = "BSCS";
    short program1TotalSeats = 2;
    short program1SeatsAvailable = 2;
    float program1MinMarks = 60.0;
    short program1AcceptedStudents = 0;

    string program2Name = "BSAI";
    short program2TotalSeats = 3;
    short program2SeatsAvailable = 3;
    float program2MinMarks = 65.0;
    short program2AcceptedStudents = 0;

    string program3Name = "BSDS";
    short program3TotalSeats = 4;
    short program3SeatsAvailable = 4;
    float program3MinMarks = 70.0;
    short program3AcceptedStudents = 0;

    int choice; 
    string username = "admin";
    string password = "admin123";
    string enteredUsername, enteredPassword;

    // Start the main loop
    while (true) {
        // Display welcome message and options
        cout << "\nWelcome to the University Admission System\n";
        cout << "1. Admin Login\n";
        cout << "2. Apply as Student\n";
        cout << "3. Exit\n";
        cout << "Select an option: ";
        cin >> choice; 

        if (choice == 1) {
            // Admin login
            cout << "Enter admin username: ";
            cin >> enteredUsername;
            cout << "Enter admin password: ";
            cin >> enteredPassword;

            if (enteredUsername == username && enteredPassword == password) {
                cout << "Login successful!\n";
                int option;
                // Admin menu 
                cout << "\nAdmin Dashboard:\n";
                cout << "1. View Program Details\n";
                cout << "2. Add New Program\n";
                cout << "3. Logout\n";
                cout << "Select option: ";
                cin >> option; 

                if (option == 1) {
                    // Display program information
                    cout << "\nProgram: " << program1Name 
                         << ", Total Seats: " << program1TotalSeats 
                         << ", Available Seats: " << program1SeatsAvailable 
                         << ", Minimum Marks: " << program1MinMarks << "%" 
                         << ", Accepted Students: " << program1AcceptedStudents << endl; 

                    cout << "Program: " << program2Name 
                         << ", Total Seats: " << program2TotalSeats 
                         << ", Available Seats: " << program2SeatsAvailable 
                         << ", Minimum Marks: " << program2MinMarks << "%" 
                         << ", Accepted Students: " << program2AcceptedStudents << endl; 

                    cout << "Program: " << program3Name 
                         << ", Total Seats: " << program3TotalSeats 
                         << ", Available Seats: " << program3SeatsAvailable 
                         << ", Minimum Marks: " << program3MinMarks << "%" 
                         << ", Accepted Students: " << program3AcceptedStudents << endl; 
                } else if (option == 2) {
                    // Add new program (this part is just a placeholder in this example)
                    cout << "New program addition is not implemented in this example.\n";
                } else if (option == 3) {
                    cout << "Logging out...\n";
                    break;  // Break the loop to exit the admin section
                } else {
                    cout << "Invalid option. Please try again.\n";
                }
            } else {
                cout << "Invalid login credentials!\n";
            }
        } else if (choice == 2) {
            // Student application process
            string name, email, phoneNumber, cnic;
            short marks, totalMarks = 500; 

            cout << "\nEnter your full name: ";
            cin >> name;
            cout << "Enter your email: ";
            cin >> email; 
            cout << "Enter your phone number: ";
            cin >> phoneNumber; 
            cout << "Enter your CNIC: ";
            cin >> cnic;
            cout << "Enter your marks (out of " << totalMarks << "): ";
            cin >> marks; 

            // Calculate percentage
            float percentage = (marks / float(totalMarks)) * 100;
            cout << "Your percentage is: " << percentage << "%" << endl;

            // Select program preference
            int programChoice;
            cout << "Select a program to apply for:\n";
            cout << "1. " << program1Name << endl;
            cout << "2. " << program2Name << endl;
            cout << "3. " << program3Name << endl;
            cout << "Enter your choice (1/2/3): ";
            cin >> programChoice;

            bool accepted = false;
            // Apply for selected program
            if (programChoice == 1) {
                if (percentage >= program1MinMarks && program1SeatsAvailable > 0) {
                    program1SeatsAvailable--;
                    program1AcceptedStudents++;
                    accepted = true;
                    cout << "Congratulations! You have been accepted into the " << program1Name << " program.\n";
                } else {
                    cout << "Sorry, you cannot apply to " << program1Name << ". ";
                    if (percentage < program1MinMarks) {
                        cout << "Your marks are not enough.\n";
                    } else {
                        cout << "No seats available.\n";
                    }
                }
            } else if (programChoice == 2) {
                if (percentage >= program2MinMarks && program2SeatsAvailable > 0) {
                    program2SeatsAvailable--;
                    program2AcceptedStudents++;
                    accepted = true;
                    cout << "Congratulations! You have been accepted into the " << program2Name << " program.\n";
                } else {
                    cout << "Sorry, you cannot apply to " << program2Name << ". ";
                    if (percentage < program2MinMarks) {
                        cout << "Your marks are not enough.\n";
                    } else {
                        cout << "No seats available.\n";
                    }
                }
            } else if (programChoice == 3) {
                if (percentage >= program3MinMarks && program3SeatsAvailable > 0) {
                    program3SeatsAvailable--;
                    program3AcceptedStudents++;
                    accepted = true;
                    cout << "Congratulations! You have been accepted into the " << program3Name << " program.\n";
                } else {
                    cout << "Sorry, you cannot apply to " << program3Name << ". ";
                    if (percentage < program3MinMarks) {
                        cout << "Your marks are not enough.\n";
                    } else {
                        cout << "No seats available.\n";
                    }
                }
            } else {
                cout << "Invalid program selection.\n";
            }

            if (accepted) {
                cout << "Unfortunately, your application was not successful.\n";
            }
        } else if (choice == 3) {
            cout << "Exiting the program...\n";
            break;  // Exit the program by breaking out of the loop
        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }
    return 0;
}
