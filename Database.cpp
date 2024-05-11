include "Database.hpp"
//--------------------Admin Class Functions--------------------
void Admin::signin() {
    char f;
    bool found = false;
    ifstream file("Admin.txt");
    if (!file.is_open()) {
        cout << "Error! Unable to open file.\n";
        return; 
    }

    int tries = 0;
    
    string user,pass;
    cout << "PLEASE INPUT THE USERNAME:    ";
    cin >> username;
    cout << "PLEASE INPUT THE PASSWORD:    ";
    cin >> password;

    while (getline(file, user, ',')) {
            getline(file, pass);

            if (username == user && password == pass) {
                found = true;
                break;
            }
        }

    while (tries < 4) {
        
        if (found) {

            cout << "THE USERNAME AND PASSWORD ARE CORRECT" << endl;
            cout << "YOU CAN PROCEED" << endl;
            cout << "PRESS ANY KEY TO CONTINUE" << endl;
            cin >> f;
            file.close();

            char j = 'y';

            while (j != 8) {

                system("clear");
                system("Color C7");
                cout << endl << "1.    PRESS 1 TO ADD TEACHER" << endl;
                cout << "2.    PRESS 2 TO ADD STUDENT" << endl;
                cout << "3.    PRESS 3 TO EDIT TEACHER" << endl;
                cout << "4.    PRESS 4 TO EDIT STUDENT" << endl;
                cout << "5.    PRESS 5 TO VIEW ALL TEACHERS" << endl;
                cout << "6.    PRESS 6 TO VIEW ALL STUDENTS" << endl;
                cout << "7.    PRESS BACKSPACE <------ TO EXIT ADMIN MODULE" << endl;
                cin>>j;

                if (j == '1')
                {
                    addteacher();
                }
                else if (j == '2')
                {
                    addstudent();
                }
                else if (j == '3')
                {
                    editteacher();
                }
                else if (j == '4')
                {
                    editstudent();
                }
                else if (j == '5')
                {
                    viewteacher();
                }
                else if (j == '6')
                {
                    viewstudent();
                }
                else if (j != 8)
                {
                    cout << endl << "PLEASE PRESS VALID NUMBER" << endl;
                }

            }
        }

        else {
            
            cout << "USERNAME OR PASSWORD IS INCORRECT, TRY AGAIN! " << 3-tries << " TRIES REMAINING" << endl;
            cout << "PLEASE INPUT THE USERNAME:    ";
            cin >> username;
            cout << "PLEASE INPUT THE PASSWORD:    ";
            cin >> password;
            file.clear();
            file.seekg(0);

            while (getline(file, user, ',')) {
                getline(file, pass);

                if (username == user && password == pass) {
                    found = true;
                    break;
                }
            }
            tries ++;
        }

        if (tries == 3 && !found){

            cout << endl << "YOU HAVE EXCEEDED THE NUMBER OF TRIES, PLEASE TRY AGAIN LATER" << endl;
            sleep(5);
            return;
        }
    } 
}

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

        while (getline(file, t_id, ',')) {
            
            getline(file, section, ',');
            getline(file, t_firstname, ',');
            getline(file, t_lastname, ',');
            getline(file, t_department, ',');
            getline(file, subject, ',');
            getline(file, t_username, ',');
            getline(file, t_password, ',');
            getline(file, t_date, ',');j
            getline(file, t_gender, ',');
            getline(file, t_number, ',');
            getline(file, t_qualification, ',');
            getline(file, address);
            if (t_username == user && t_password == pass) {
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

    string firstName, lastName, tid, dept, user, pass, date, gender, phone, address, fee, quali, section, subject, time;
    string fname, lname, id;
    if (cin.fail()) {
        cin.clear(); cin.ignore();
    }
    cout << "Enter your id: ";
    cin >> t_id;


    
    while (getline(file3, tid, ','))
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

        if(tid  == t_id){

            cout << "enter time:   ";
            cin >> time;
            file4 << dept << "," << subject << "," << section << "," << tid << "," << time << endl;
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
        string s_id, tempSection, tempSub1, tempSub2, tempSub3, tempSub4, tempSub5;

        getline(iss, s_id, ',');
        getline(iss, tempSection, ',');
        getline(iss, tempSub1, ',');
        getline(iss, tempSub2, ',');
        getline(iss, tempSub3, ',');
        getline(iss, tempSub4, ',');
        getline(iss, tempSub5, ',');

        if(this->section == tempSection && (this->subject == tempSub1 || this->subject == tempSub2 || this->subject == tempSub3 || this->subject == tempSub4 || this->subject == tempSub5)){
            cout << "Enter marks " << s_id << ": ";
            cin >> marks;
            file3 << this->subject << " " << tempSection << " " << s_id << " " << marks << endl;
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
    cout << "Enter date: ";
    cin >> date;

    string line;
    while (getline(file, line, '\n')){
        stringstream iss(line);
        string s_id, tempSection, tempSub1, tempSub2, tempSub3, tempSub4, tempSub5;

        getline(iss, s_id, ',');
        getline(iss, tempSection, ',');
        getline(iss, tempSub1, ',');
        getline(iss, tempSub2, ',');
        getline(iss, tempSub3, ',');
        getline(iss, tempSub4, ',');
        getline(iss, tempSub5, ',');

        if(this->section == tempSection && (this->subject == tempSub1 || this->subject == tempSub2 || this->subject == tempSub3 || this->subject == tempSub4 || this->subject == tempSub5)){
            cout << "Enter attendance status for student " << s_id << " (P for present, A for absent): ";
            cin >> attendanceStatus;
            file3 << this->subject << " " << tempSection << " " << s_id << " " << date << " " << attendanceStatus << endl;
        }
    }
    sleep(3);
    file.close();
    file3.close();
}
