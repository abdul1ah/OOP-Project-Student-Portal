//--------------------Teacher Class Functions--------------------

void Teacher::signin()
{
    char f;
    bool found = false;
    ifstream file("Teacher.txt");
    if (!file.is_open()) {
        cout << "Error! Unable to open file.\n";
        return;
    }

    int tries = 0;
    
    string user, pass;

    while (tries < 4) {
        cout << "PLEASE INPUT THE USERNAME:    ";
        cin >> user;
        cout << "PLEASE INPUT THE PASSWORD:    ";
        cin >> pass;

        found = false;
        file.clear();
        file.seekg(0);

        while (getline(file, ID, ',')) {
            
            getline(file, section, ',');
            getline(file, FirstName, ',');
            getline(file, LastName, ',');
            getline(file, Department, ',');
            getline(file, subject, ',');
            getline(file, UserName, ',');
            getline(file, Password, ',');
            getline(file, Date, ',');
            getline(file, Gender, ',');
            getline(file, Number, ',');
            getline(file, Qualification, ',');
            getline(file, address);
            if (UserName == user && Password == pass) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "THE USERNAME AND PASSWORD ARE CORRECT" << endl;
            cout << "YOU CAN PROCEED" << endl;
            cout << "PRESS ANY KEY TO CONTINUE" << endl;
            cin>>f;
            file.close();

            char j = 'y';

            while (j != 8)
            {
                system("clear");
                system("Color 6F");
                cout << endl << "1.    PRESS 1 TO SET TIMETABLE" << endl;
                cout << "2.    PRESS 2 TO MARK ATTENDANCE" << endl;
                cout << "3.    PRESS 3 TO ASSIGN MARKS" << endl;
                cout << "4.    PRESS BACKSPACE <------ TO EXIT TEACHER MODULE" << endl;
                cin>>j;
                if (j == '1')
                {
                    timetable();
                }
                else if (j == '2')
                {
                    markingattendance();
                }
                else if (j == '3')
                {
                    assignmarks();
                }
                else if (j != 8)
                {
                    cout << endl << "PLEASE PRESS VALID NUMBER" << endl;
                }
            }
            return;
        } else {
            cout << "USERNAME OR PASSWORD IS INCORRECT, TRY AGAIN! " << 3-tries << " TRIES REMAINING" << endl;
            tries++;
        }
    }

    cout << endl << "YOU HAVE EXCEEDED THE NUMBER OF TRIES, PLEASE TRY AGAIN LATER" << endl;
    sleep(5);
    return;
}
void Teacher::timetable(){
char f;
    fstream file3("Teacher.txt", ios::in);
    fstream file4("course_schedule.txt", ios::app);
    if (!file3.is_open())
    {
        cout << "Error opening file1!\n";
        sleep(2000);
        return;
    }
    if (!file4.is_open())
    {
        cout << "Error opening file2!\n";
        sleep(2000);
        return;
    }

    string firstName, lastName, id, dept, user, pass, date, gender, phone, address, fee, quali, section, subject, time;
    string fname, lname;
    if (cin.fail()) {
        cin.clear(); cin.ignore();
    }
    cout << "Enter your id: ";
    cin >> ID;
    cout << "Enter your user name: ";
    cin >> UserName;
    cout << "Enter your password: ";
    cin >> Password;

    while (getline(file3, id, ','))
    {   
        getline(file3, section, ',');
        getline(file3, firstName, ',');
        getline(file3, lastName, ',');
        getline(file3, dept, ',');
        getline(file3, subject, ',');
        getline(file3, user, ',');
        getline(file3, pass, ',');
        getline(file3, date, ',');
        getline(file3, gender, ',');
        getline(file3, phone, ',');
        getline(file3, address, ',');
        getline(file3, quali);

        if(id  == ID && user == UserName && pass == Password){

            cout << "enter time in 24 hrs: (e.g 08:00-10:00)  ";
            cin >> time;
            file4 << dept << "," << subject << "," << section << "," << id << "," << time << endl;
            cout << "time table created " << endl;
            sleep(3);
            file3.close();
            file4.close();
        }
    }
    file3.close();
    file4.close();
}     
void Teacher::assignmarks(){
    char f;
    fstream file("student_data.txt", ios::in);
    fstream file3("student_marks.txt", ios::app);
    if (!file3.is_open())
    {
        cout << "Error opening file1!\n";
        sleep(2000);
        return;
    }
    if (!file.is_open())
    {
        cout << "Error opening file2!\n";
        sleep(2000);
        return;
    }

    string date, marks;
    string fname, lname, id;
    if (cin.fail()) {
        cin.clear(); cin.ignore();
    }
    cout << "Enter your section: ";
    cin >> this->section;
    cout << "Enter your subject: ";
    cin >> this->subject;

    string line;
    while (getline(file, line, '\n')){
        stringstream iss(line);
        string ID, tempSection, tempSub1, tempSub2, tempSub3, tempSub4, tempSub5;

        getline(iss, ID, ',');
        getline(iss, tempSection, ',');
        getline(iss, tempSub1, ',');
        getline(iss, tempSub2, ',');
        getline(iss, tempSub3, ',');
        getline(iss, tempSub4, ',');
        getline(iss, tempSub5, ',');

        if(this->section == tempSection && (this->subject == tempSub1 || this->subject == tempSub2 || this->subject == tempSub3 || this->subject == tempSub4 || this->subject == tempSub5)){
            cout << "Enter marks " << ID << ": ";
            cin >> marks;
            file3 << this->subject << " " << tempSection << " " << ID << " " << marks << endl;
        }
    }
    sleep(3);
    file.close();
    file3.close();
}
void Teacher::markingattendance(){
    char f;
    fstream file("student_data.txt", ios::in);
    fstream file3("attendance.txt", ios::app);
    if (!file3.is_open())
    {
        cout << "Error opening file1!\n";
        sleep(3);
        return;
    }
    if (!file.is_open())
    {
        cout << "Error opening file2!\n";
        sleep(3);
        return;
    }

    string sub1, sub2, sub3, sub4, sub5, date, section, subject, attendanceStatus;
    string fname, lname, id;
    if (cin.fail()) {
        cin.clear(); cin.ignore();
    }
    cout << "Enter your section: ";
    cin >> this->section;
    cout << "Enter your subject: ";
    cin >> this->subject;
    cout << "Enter date: (e.g 2023-11-22) ";
    cin >> date;

    string line;
    while (getline(file, line, '\n')){
        stringstream iss(line);
        string ID, tempSection, tempSub1, tempSub2, tempSub3, tempSub4, tempSub5;

        getline(iss, ID, ',');
        getline(iss, tempSection, ',');
        getline(iss, tempSub1, ',');
        getline(iss, tempSub2, ',');
        getline(iss, tempSub3, ',');
        getline(iss, tempSub4, ',');
        getline(iss, tempSub5, ',');

        if(this->section == tempSection && (this->subject == tempSub1 || this->subject == tempSub2 || this->subject == tempSub3 || this->subject == tempSub4 || this->subject == tempSub5)){
            cout << "Enter attendance status for student " << ID << " (P for present, A for absent): ";
            cin >> attendanceStatus;
            file3 << this->subject << " " << tempSection << " " << ID << " " << date << " " << attendanceStatus << endl;
        }
    }
    sleep(3);
    file.close();
    file3.close();
}

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
