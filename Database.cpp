//--------------------Student Class Functions--------------------

void Student::sign_in_student() {
    char f;
    ifstream file("Student.txt");
    if (!file.is_open()) {
        cout << "Error! Unable to open file.\n";
        return;
    }

    string firstName, lastName, id, dept, user, pass, date, gender, phone, address, fee, quali, subject, section;
    string inputp, inputu;
    int tries = 0;

     cout << "PLEASE INPUT YOUR USERNAME: ";
    cin >> inputu;
    cout << "PLEASE INPUT YOUR PASSWORD: ";
    cin >> inputp;

    while (tries < 4) {
        bool found = false;
        file.clear();
        file.seekg(0);

        while (getline(file, id, ',')) {
            getline(file, section, ',');
            getline(file, firstName, ',');
            getline(file, lastName, ',');
            getline(file, dept, ',');
            getline(file, user, ',');
            getline(file, pass, ',');
            getline(file, date, ',');
            getline(file, gender, ',');
            getline(file, phone, ',');
            getline(file, address, ',');
            getline(file, fee, ',');
            getline(file, quali, ',');
            getline(file, subject);

            if (user == inputu && pass == inputp) {
                found = true;
                cout << "THE USERNAME AND PASSWORD ARE CORRECT" << endl;
                cout << "YOU CAN PROCEED" << endl;
                cout << "PRESS ANY KEY TO CONTINUE" << endl;
                cin>>f;

                // Call the appropriate functions to view attendance, marks, grades, registered courses, or fee status
                // based on the user's input
                char j = 'y';
                while (j != 8) {
                    system("clear");
                    system("Color B5");
                    cout << endl << "1.    PRESS 1 TO VIEW ATTENDANCE" << endl;
                    cout << "2.    PRESS 2 TO VIEW MARKS" << endl;
                    cout << "3.    PRESS BACKSPACE <------ TO EXIT STUDENT MODULE" << endl;
                    cin>>j;

                    if (j == '1')
                    {
                        view_attendance();
                    }
                    else if (j == '2')
                    {
                        view_marks();
                    }
                    else if (j != 8)
                    {
                        cout << endl << "PLEASE PRESS VALID NUMBER" << endl;
                    }
                }
                return;
            }
        }

        if (!found) {
            cout << "USERNAME OR PASSWORD IS INCORRECT, TRY AGAIN! " << 3-tries << " TRIES REMAINING" << endl;
            cout << "PLEASE INPUT RENTER: " << endl;
            cin >> inputu;
            cin >> inputp;
            tries++;
        }
    }

    cout << endl << "YOU HAVE EXCEEDED THE NUMBER OF TRIES, PLEASE TRY AGAIN LATER" << endl;
    sleep(5);
    return;
}
void Student::view_attendance() {
    string regNumber, section, subject, date, attendanceStatus, regNumberFromFile;
    cout << "Enter your registration number: ";
    cin >> regNumber;

    ifstream file("student_marks.txt");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    bool found = false;
    while (file >> subject >> section >> regNumberFromFile >> date >> attendanceStatus) {
        if (regNumber == regNumberFromFile) {
            cout << "Subject: " << subject << ", Section: " << section << ", Date: " << date << ", Attendance: " << attendanceStatus << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No attendance records found for registration number: " << regNumber << endl;
    }
    sleep(4);

    file.close();
}
void Student::view_marks()
{
    string regNumber, section, subject, date, attendanceStatus, regNumberFromFile;
    cout << "Enter your registration number: ";
    cin >> regNumber;

    ifstream file("attendance.txt");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    bool found = false;
    while (file >> subject >> section >> regNumberFromFile >> date >> attendanceStatus) {
        if (regNumber == regNumberFromFile) {
            cout << "Subject: " << subject << ", Section: " << section << ", Date: " << date << ", Attendance: " << attendanceStatus << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No attendance records found for registration number: " << regNumber << endl;
    }
    sleep(4);

    file.close();
}
