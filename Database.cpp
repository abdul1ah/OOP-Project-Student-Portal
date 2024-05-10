#include "Database.hpp"
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

void Admin::addteacher()
{
    char f;
    
    string year, month, day;
    cout << "PLEASE ENTER THE REGISTRATION DATE OF TEACHER   " << endl;
    cout << "ENTER YEAR    ";
    cin >> year;
    cout << "ENTER MONTH    ";
    cin >> month;
    cout << "ENTER DAY    ";
    cin >> day;

    while (stoi(year) < 1991 || stoi(year) > 2024 || stoi(month) < 1 || stoi(month) > 12 || stoi(day) < 1 || stoi(day) > 31) {
        cout << "INVALID DATE!" <<endl;
        cout << "RE-ENTER YEAR    ";
        cin >> year;
        cout << "RE-ENTER MONTH    ";
        cin >> month;
        cout << "RE-ENTER DAY    ";
        cin >> day;
    }

    if (month.length() == 1) {
        month = "0" + month;
    }
    if (day.length() == 1) {
        day = "0" + day;
    }
    t_date = year + "/" + month + "/" + day;

    cout << "PLEASE INPUT THE ID OF TEACHER e.g(503)   ";
    cin >> t_id;

    while (stoi(t_id) < 1 || stoi(t_id) > 9999){
        cout << "INVALID ID!" <<endl;
        cout << "RE-ENTER ID    ";
        cin >> t_id;
    }

    if (t_id.length() == 1){
        t_id = "00" + t_id;
    }
    else if (t_id.length() == 2) {
        t_id = "0" + t_id;
    }

    t_id = year + t_id;

    cout << "INPUT SECTION OF TEACHER    ";
    cin >> section;
    
    cout << "PLEASE INPUT THE FIRST NAME OF TEACHER    ";
    cin >> t_firstname;
    cout << "PLEASE INPUT THE LAST NAME OF TEACHER    ";
    cin >> t_lastname;

    cout << "PLEASE INPUT THE DEPARTMENT OF TEACHER; 1:FCSE|2:MGS|3:FME|4:FMCE    ";
    cin >> t_department;
    
    while (stoi(t_department) < 1 || stoi(t_department) > 4 ){
        cout << "INVALID CHOICE!" <<endl;
        cout << "RE-ENETER DEPARTMENT    ";
        cin >> t_department;
    }
    department x;
    if (t_department == "1") {
        x = FCSE;
    }
    else if (t_department == "2") {
        x = MGS;
    }
    else if (t_department == "3") {
        x = FME;
    }
    else if (t_department == "4") {
        x = FMCE;
    } 

    cout << "PLEASE INPUT THE SUBJECT OF TEACHER    ";
    cin >> subject;

    cout << "PLEASE SELECT THE GENDER OF TEACHER; 1:MALE|2:FEMALE    ";
    cin >> t_gender;
    while (stoi(t_gender) < 1 || stoi(t_gender) > 2){
        cout << "INVALID CHOICE!" <<endl;
        cout << "RE-ENETER GENDER    ";
        cin >> t_gender;
    }
    
    gender y;
    if (t_gender == "1"){
        y = male;
    }
    else if (t_gender == "2"){
        y = female;
    }

    cout << "TEACHERS USERNAME GENERATED   " << endl;
    t_username = "t" + t_id + "@giki.edu.pk" ;
    cout << "TEACHERS PASSWORD GENERATED    " << endl;
    t_password = year + month + day;

    cout << "PLEASE INPUT THE NUMBER OF TEACHER    ";
    cin >> t_number;
    cout << "PLEASE INPUT THE QUALIFICATION OF TEACHER    ";
    cin >> t_qualification;
    cout << "PLEASE INPUT THE CITY OF TEACHER AS ADDRESS    ";
    cin >> address;
    ofstream out("Teacher.txt", ios::app);  // Open file in append mode
    out << t_id << "," << section << "," << t_firstname << "," << t_lastname << "," << departments(x) << "," <<subject << "," << t_username << "," << t_password << "," << t_date << "," << genders(y) << "," << t_number << "," << t_qualification << "," << address << endl;
    out.close();  // Remember to close the file
    cout << endl << "THE DATA OF TEACHER HAS BEEN ADDED" << endl;
    cout << "PRESS ANY KEY TO CONTINUE" << endl;
    cin>>f;
}
void Admin::addstudent()
{
    char f;
    
    string year, month, day;
    cout << "PLEASE INPUT THE REGISTRATION DATE OF STUDENT" << endl;
    cout << "ENTER YEAR    ";
    cin >> year;
    cout << "ENTER MONTH    ";
    cin >> month;
    cout << "ENTER DAY    ";
    cin >> day;

    while (stoi(year) < 1991 || stoi(year) > 2024 || stoi(month) < 1 || stoi(month) > 12 || stoi(day) < 1 || stoi(day) > 31) {
        cout << "INVALID DATE!" <<endl;
        cout << "RE-ENTER YEAR    ";
        cin >> year;
        cout << "RE-ENTER MONTH    ";
        cin >> month;
        cout << "RE-ENTER DAY    ";
        cin >> day;
    }

    if (month.length() == 1) {
        month = "0" + month;
    }
    if (day.length() == 1) {
        day = "0" + day;
    }
    s_date = year + "/" + month + "/" + day;

    cout << "PLEASE INPUT THE ID OF STUDENT E.G(595)   ";
    cin >> s_id;
    
    while (stoi(s_id) < 1 || stoi(s_id) > 999) 
    {
        cout << "INVALID ID!" <<endl;
        cout << "RE-ENTER ID   ";
        cin >> s_id;
    }
    if (s_id.length() == 1 ){
        s_id = "00" + s_id;
    }
    else if (s_id.length() == 2){
        s_id = "0" + s_id;
    }
    s_id = year + s_id;

    cout << "PLEASE INPUT SECTION OF STUDENT    ";
    cin >> section;
    
    cout << "PLEASE INPUT THE FIRST NAME OF STUDENT    ";
    cin >> s_firstname;
    cout << "PLEASE INPUT THE LAST NAME OF STUDENT    ";
    cin >> s_lastname;

    cout << "PLEASE INPUT THE DEPARTMENT OF TEACHER; 1:FCSE|2:MGS|3:FME|4:FMCE    ";
    cin >> s_department;
    
    while (stoi(s_department) < 1 || stoi(s_department) > 4 ){
        cout << "INVALID CHOICE!" <<endl;
        cout << "RE-ENETER DEPARTMENT    ";
        cin >>s_department;
    }
    department x;
    if (s_department == "1") {
        x = FCSE;
    }
    else if (s_department == "2") {
        x = MGS;
    }
    else if (s_department == "3") {
        x = FME;
    }
    else if (s_department == "4") {
        x = FMCE;
    }

    cout << "PLEASE SELECT THE GENDER OF TEACHER; 1:MALE|2:FEMALE    ";
    cin >> s_gender;
    while (stoi(s_gender) < 1 || stoi(s_gender) > 2){
        cout << "INVALID CHOICE!" <<endl;
        cout << "RE-ENETER GENDER    ";
        cin >> s_gender;
    }
    
    gender y;
    if (s_gender == "1"){
        y = male;
    }
    else if (s_gender == "2"){
        y = female;
    }

    cout << "STUDENT USERNAME GENERATED    " << endl;
    s_user_name = "u" + s_id + "@giki.edu,pk";
    cout << "STUDENT PASSWORD GENERATED   " << endl;
    s_password = year + month + day;

    cout << "PLEASE INPUT THE PHONE NUMBER OF STUDENT    ";
    cin >> s_number;
    cout << "PLEASE INPUT THE CITY OF STUDENT AS ADDRESS    ";
    cin >> s_address;
    cout << "PLEASE INPUT THE FEE STATUS OF STUDENT    ";
    cin >> fee;

    int choice;

    cout << "Enter 1 for Alevels, 2 for FSC, or 3 for Private: ";
    cin >> choice;

    while (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please enter 1, 2, or 3: ";
        cin >> choice;
    }

    switch (choice) {
        case 1:
            s_qualification = "Alevels";
            break;
        case 2:
            s_qualification = "FSC";
            break;
        case 3:
            s_qualification = "Private";
            break;
    }

    int no_of_subjects;
    cout << "PLEASE INPUT NUMBER OF SUBJECTS    ";
    cin >> no_of_subjects;

    General::Marks student[no_of_subjects];

    setSubject(student, no_of_subjects);

    // Open file in append mode
    ofstream out1("Student.txt", ios::app);  
    ofstream out2("student_marks.txt", ios::app);
    ofstream out3("student_data.txt", ios::app);
    out1 << s_id << "," << section << "," << s_firstname << "," << s_lastname << "," << departments(x) << "," << s_user_name << "," << s_password << "," << s_date <<  ","  << genders(y) << "," << s_number << "," << s_address << "," << fee << "," << s_qualification << "," << getSubject(student, no_of_subjects) << endl;
    out2 << getSubject(student, no_of_subjects) << endl;
    out3 << s_id << "," << section << "," << getSubject(student, no_of_subjects) << endl;
    out1.close();
    out2.close();
    out3.close();
    cout << endl << "THE DATA OF STUDENT HAS BEEN ADDED" << endl;
    cout << "PRESS ANY KEY TO CONTINUE" << endl;
    cin>>f;
}
}