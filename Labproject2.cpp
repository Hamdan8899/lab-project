#include <iostream>
#include <string>
using namespace std;

int main() {
    // Program details for three departments
    string department1Name = "CS";  // Computer Science
    short department1TotalSeats = 2;
    short department1SeatsAvailable = 2;
    float department1MinMarks = 70.0;  // Increased minimum marks
    short department1AcceptedStudents = 0;

    string department2Name = "SE";  // Software Engineering
    short department2TotalSeats = 3;
    short department2SeatsAvailable = 3;
    float department2MinMarks = 75.0;  // Increased minimum marks
    short department2AcceptedStudents = 0;

    string department3Name = "DS";  // Data Science
    short department3TotalSeats = 4;
    short department3SeatsAvailable = 4;
    float department3MinMarks = 80.0;  // Increased minimum marks
    short department3AcceptedStudents = 0;

    int optionChoice; 
    string adminUsername = "admin123";
    string adminPassword = "adminpass";
    string inputUsername, inputPassword;

    // Start the main loop
    while (true) {
        // Display welcome message and options
        cout << "\nWelcome to the University Admission System\n";
        cout << "1. Admin Access\n";
        cout << "2. Register as Applicant\n";
        cout << "3. Exit System\n";
        cout << "Please select an option: ";
        cin >> optionChoice;

        if (optionChoice == 1) {
            // Admin login
            cout << "Enter admin username: ";
            cin >> inputUsername;
            cout << "Enter admin password: ";
            cin >> inputPassword;

            if (inputUsername == adminUsername && inputPassword == adminPassword) {
                cout << "Login successful!\n";
                int adminOption;
                // Admin menu 
                cout << "\nAdmin Control Panel:\n";
                cout << "1. View Department Information\n";
                cout << "2. Add New Department\n";
                cout << "3. Logout\n";
                cout << "Select an option: ";
                cin >> adminOption;

                if (adminOption == 1) {
                    // Display department details
                    cout << "\nDepartment: " << department1Name 
                         << ", Total Seats: " << department1TotalSeats 
                         << ", Available Seats: " << department1SeatsAvailable 
                         << ", Minimum Marks: " << department1MinMarks << "%" 
                         << ", Accepted Students: " << department1AcceptedStudents << endl; 

                    cout << "Department: " << department2Name 
                         << ", Total Seats: " << department2TotalSeats 
                         << ", Available Seats: " << department2SeatsAvailable 
                         << ", Minimum Marks: " << department2MinMarks << "%" 
                         << ", Accepted Students: " << department2AcceptedStudents << endl; 

                    cout << "Department: " << department3Name 
                         << ", Total Seats: " << department3TotalSeats 
                         << ", Available Seats: " << department3SeatsAvailable 
                         << ", Minimum Marks: " << department3MinMarks << "%" 
                         << ", Accepted Students: " << department3AcceptedStudents << endl; 
                } else if (adminOption == 2) {
                    // Add new department (this part is just a placeholder in this example)
                    cout << "Adding a new department is not implemented in this demo.\n";
                } else if (adminOption == 3) {
                    cout << "Logging out...\n";
                    break;  // Break the loop to exit the admin section
                } else {
                    cout << "Invalid selection. Please try again.\n";
                }
            } else {
                cout << "Incorrect login credentials!\n";
            }
        } else if (optionChoice == 2) {
            // Applicant registration process
            string applicantName, applicantEmail, applicantPhone, applicantID;
            short applicantMarks, totalMarks = 500; 

            cout << "\nEnter your full name: ";
            cin >> applicantName;
            cout << "Enter your email address: ";
            cin >> applicantEmail; 
            cout << "Enter your contact number: ";
            cin >> applicantPhone; 
            cout << "Enter your National ID: ";
            cin >> applicantID;
            cout << "Enter your marks (out of " << totalMarks << "): ";
            cin >> applicantMarks; 

            // Calculate percentage
            float applicantPercentage = (applicantMarks / float(totalMarks)) * 100;
            cout << "Your percentage is: " << applicantPercentage << "%" << endl;

            // Select department preference
            int departmentChoice;
            cout << "Select a department to apply for:\n";
            cout << "1. " << department1Name << " - Computer Science\n";
            cout << "2. " << department2Name << " - Software Engineering\n";
            cout << "3. " << department3Name << " - Data Science\n";
            cout << "Enter your choice (1/2/3): ";
            cin >> departmentChoice;

            bool isAccepted = false;
            // Apply for selected department
            if (departmentChoice == 1) {
                if (applicantPercentage >= department1MinMarks && department1SeatsAvailable > 0) {
                    department1SeatsAvailable--;
                    department1AcceptedStudents++;
                    isAccepted = true;
                    cout << "Congratulations! You have been accepted into the " << department1Name << " department.\n";
                } else {
                    cout << "Sorry, you cannot apply to " << department1Name << ". ";
                    if (applicantPercentage < department1MinMarks) {
                        cout << "Your marks are not sufficient.\n";
                    } else {
                        cout << "No seats available.\n";
                    }
                }
            } else if (departmentChoice == 2) {
                if (applicantPercentage >= department2MinMarks && department2SeatsAvailable > 0) {
                    department2SeatsAvailable--;
                    department2AcceptedStudents++;
                    isAccepted = true;
                    cout << "Congratulations! You have been accepted into the " << department2Name << " department.\n";
                } else {
                    cout << "Sorry, you cannot apply to " << department2Name << ". ";
                    if (applicantPercentage < department2MinMarks) {
                        cout << "Your marks are not sufficient.\n";
                    } else {
                        cout << "No seats available.\n";
                    }
                }
            } else if (departmentChoice == 3) {
                if (applicantPercentage >= department3MinMarks && department3SeatsAvailable > 0) {
                    department3SeatsAvailable--;
                    department3AcceptedStudents++;
                    isAccepted = true;
                    cout << "Congratulations! You have been accepted into the " << department3Name << " department.\n";
                } else {
                    cout << "Sorry, you cannot apply to " << department3Name << ". ";
                    if (applicantPercentage < department3MinMarks) {
                        cout << "Your marks are not sufficient.\n";
                    } else {
                        cout << "No seats available.\n";
                    }
                }
            } else {
                cout << "Invalid department selection.\n";
            }

            if (!isAccepted) {
                cout << "Unfortunately, your application was unsuccessful.\n";
            }
        } else if (optionChoice == 3) {
            cout << "Exiting the portal...\n";
            break;  // Exit the program by breaking out of the loop
        } else {
            cout << "Invalid selection. Please try again.\n";
        }
    }
    return 0;
}
