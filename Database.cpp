#include "Database.hpp"

//--------------------General Class Functions--------------------

string General::departments(department x){
        if (x == FCSE)
            return "FCSE";
        else if (x == MGS)
            return "MGS";
        else if (x == FME)
            return "FME";
        else if (x == FMCE)
            return "FMCE";
    }
string General::genders(gender y){
        if (y == male)
            return "MALE";
        else if (y == female)
            return "FEMALE";
    }
void General::setSubject(Marks student[], int totalSubjects ){
    for (int i = 0; i < totalSubjects; i++)
    {
        cout << "PLEASE INPUT THE NAME OF SUBJECT    ";
        cin >> student[i].s_subject;
    }
}
string General::getSubject(Marks student[], int totalSubjects) {
    string marks;
    for (int i = 0; i < totalSubjects; i++) {
        marks = marks + student[i].s_subject + ",";
    }
    return marks;
}

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
    Date = year + "/" + month + "/" + day;

    cout << "PLEASE INPUT THE ID OF TEACHER e.g(503)   ";
    cin >> ID;

    while (stoi(ID) < 1 || stoi(ID) > 9999){
        cout << "INVALID ID!" <<endl;
        cout << "RE-ENTER ID    ";
        cin >> ID;
    }

    if (ID.length() == 1){
        ID = "00" + ID;
    }
    else if (ID.length() == 2) {
        ID = "0" + ID;
    }

    ID = year + ID;

    cout << "INPUT SECTION OF TEACHER    ";
    cin >> section;
    
    cout << "PLEASE INPUT THE FIRST NAME OF TEACHER    ";
    cin >> FirstName;
    cout << "PLEASE INPUT THE LAST NAME OF TEACHER    ";
    cin >> LastName;

    cout << "PLEASE INPUT THE DEPARTMENT OF TEACHER; 1:FCSE|2:MGS|3:FME|4:FMCE    ";
    cin >> Department;
    
    while (stoi(Department) < 1 || stoi(Department) > 4 ){
        cout << "INVALID CHOICE!" <<endl;
        cout << "RE-ENETER DEPARTMENT    ";
        cin >> Department;
    }
    department x;
    if (Department == "1") {
        x = FCSE;
    }
    else if (Department == "2") {
        x = MGS;
    }
    else if (Department == "3") {
        x = FME;
    }
    else if (Department == "4") {
        x = FMCE;
    } 

    cout << "PLEASE INPUT THE SUBJECT OF TEACHER    ";
    cin >> subject;

    cout << "PLEASE SELECT THE GENDER OF TEACHER; 1:MALE|2:FEMALE    ";
    cin >> Gender;
    while (stoi(Gender) < 1 || stoi(Gender) > 2){
        cout << "INVALID CHOICE!" <<endl;
        cout << "RE-ENETER GENDER    ";
        cin >> Gender;
    }
    
    gender y;
    if (Gender == "1"){
        y = male;
    }
    else if (Gender == "2"){
        y = female;
    }

    cout << "TEACHERS USERNAME GENERATED   " << endl;
    UserName = "t" + ID + "@giki.edu.pk" ;
    cout << "TEACHERS PASSWORD GENERATED    " << endl;
    Password = year + month + day;

    cout << "PLEASE INPUT THE NUMBER OF TEACHER    ";
    cin >> Number;
    cout << "PLEASE INPUT THE QUALIFICATION OF TEACHER    ";
    cin >> Qualification;
    cout << "PLEASE INPUT THE CITY OF TEACHER AS ADDRESS    ";
    cin >> address;
    ofstream out("Teacher.txt", ios::app);  // Open file in append mode
    out << ID << "," << section << "," << FirstName << "," << LastName << "," << departments(x) << "," <<subject << "," << UserName << "," << Password << "," << Date << "," << genders(y) << "," << Number << "," << Qualification << "," << address << endl;
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
    Date = year + "/" + month + "/" + day;

    cout << "PLEASE INPUT THE ID OF STUDENT E.G(595)   ";
    cin >> ID;
    
    while (stoi(ID) < 1 || stoi(ID) > 999) 
    {
        cout << "INVALID ID!" <<endl;
        cout << "RE-ENTER ID   ";
        cin >> ID;
    }
    if (ID.length() == 1 ){
        ID = "00" + ID;
    }
    else if (ID.length() == 2){
        ID = "0" + ID;
    }
    ID = year + ID;

    cout << "PLEASE INPUT SECTION OF STUDENT    ";
    cin >> section;
    
    cout << "PLEASE INPUT THE FIRST NAME OF STUDENT    ";
    cin >> FirstName;
    cout << "PLEASE INPUT THE LAST NAME OF STUDENT    ";
    cin >> LastName;

    cout << "PLEASE INPUT THE DEPARTMENT OF TEACHER; 1:FCSE|2:MGS|3:FME|4:FMCE    ";
    cin >> Department;
    
    while (stoi(Department) < 1 || stoi(Department) > 4 ){
        cout << "INVALID CHOICE!" <<endl;
        cout << "RE-ENETER DEPARTMENT    ";
        cin >>Department;
    }
    department x;
    if (Department == "1") {
        x = FCSE;
    }
    else if (Department == "2") {
        x = MGS;
    }
    else if (Department == "3") {
        x = FME;
    }
    else if (Department == "4") {
        x = FMCE;
    }

    cout << "PLEASE SELECT THE GENDER OF TEACHER; 1:MALE|2:FEMALE    ";
    cin >> Gender;
    while (stoi(Gender) < 1 || stoi(Gender) > 2){
        cout << "INVALID CHOICE!" <<endl;
        cout << "RE-ENETER GENDER    ";
        cin >> Gender;
    }
    
    gender y;
    if (Gender == "1"){
        y = male;
    }
    else if (Gender == "2"){
        y = female;
    }

    cout << "STUDENT USERNAME GENERATED    " << endl;
    UserName = "u" + ID + "@giki.edu,pk";
    cout << "STUDENT PASSWORD GENERATED   " << endl;
    Password = year + month + day;

    cout << "PLEASE INPUT THE PHONE NUMBER OF STUDENT    ";
    cin >> Number;
    cout << "PLEASE INPUT THE CITY OF STUDENT AS ADDRESS    ";
    cin >> address;
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
            Qualification = "Alevels";
            break;
        case 2:
            Qualification = "FSC";
            break;
        case 3:
            Qualification = "Private";
            break;
    }

    int no_of_subjects;
    cout << "PLEASE INPUT NUMBER OF SUBJECTS    ";
    cin >> no_of_subjects;

    General::Marks student[no_of_subjects];

    setSubject(student, no_of_subjects);

    // Open file in append mode
    ofstream out1("Student.txt", ios::app);  
    ofstream out2("student_data.txt", ios::app);
    out1 << ID << "," << section << "," << FirstName << "," << LastName << "," << departments(x) << "," << UserName << "," << Password << "," << Date <<  ","  << genders(y) << "," << Number << "," << address << "," << fee << "," << Qualification << "," << getSubject(student, no_of_subjects) << endl;
    out2 << ID << "," << section << "," << getSubject(student, no_of_subjects) << endl;
    out1.close();
    out2.close();
    cout << endl << "THE DATA OF STUDENT HAS BEEN ADDED" << endl;
    cout << "PRESS ANY KEY TO CONTINUE" << endl;
    cin>>f;
}

void Admin::editstudent()
{
    char f;
    ifstream file("Student.txt");
    ofstream file1("TEMP1.txt");
    ofstream file2("TEMP2.txt");
    
    if (!file.is_open() || !file1.is_open() || !file2.is_open())
    {
        cout << "Error opening file1!\n";
        return;
    }

    string firstName, lastName, sid, dept, user, pass, date, gender, phone, address, fee, quali, marks, ssection;
    string fname, lname, id;
    /*if (cin.fail()) {
        cin.clear(); cin.ignore();
    }*/
    cout << "PlEASE INPUT ID OF STUDENT    ";
    cin >> id;
    cout << "PLEASE INPUT THE FIRST NAME OF STUDENT TO EDIT INFO:    ";
    cin >> fname;
    cout << "PLEASE INPUT THE LAST NAME OF STUDENT TO EDIT INFO:    ";
    cin >> lname;

    bool found = false;
    while (getline(file, sid, ','))
    {
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
        getline(file, marks, '\n');

        if (fname == firstName && lname == lastName && id == sid)
        {
            found = true;
    
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
            Date = year + "/" + month + "/" + day;

            cout << "PLEASE INPUT THE ID OF STUDENT E.G(595)   ";
            cin >> ID;

            while (stoi(ID) < 1 || stoi(ID) > 999) 
            {
                cout << "INVALID ID!" <<endl;
                cout << "RE-ENTER ID   ";
                cin >> ID;
            }
            if (ID.length() == 1 ){
                ID = "00" + ID;
            }
            else if (ID.length() == 2){
                ID = "0" + ID;
            }
            ID = year + ID;

            cout << "PLEASE INPUT THE SECTION OF STUDENT    ";
            cin >> this->section;

            cout << "PLEASE INPUT THE FIRST NAME OF STUDENT    ";
            cin >> FirstName;
            cout << "PLEASE INPUT THE LAST NAME OF STUDENT    ";
            cin >> LastName;

            cout << "PLEASE INPUT THE DEPARTMENT OF STUDENT; 1:FCSE|2:MGS|3:FME|4:FMCE    ";
            cin >> Department;

            while (stoi(Department) < 1 || stoi(Department) > 4 ){
                cout << "INVALID CHOICE!" <<endl;
                cout << "RE-ENETER DEPARTMENT    ";
                cin >>Department;
            }
            department x;
            if (Department == "1") {
                x = FCSE;
            }
            else if (Department == "2") {
                x = MGS;
            }
            else if (Department == "3") {
                x = FME;
            }
            else if (Department == "4") {
                x = FMCE;
            }

            cout << "PLEASE SELECT THE GENDER OF STUDENT; 1:MALE|2:FEMALE    ";
            cin >> Gender;
            while (stoi(Gender) < 1 || stoi(Gender) > 2){
                cout << "INVALID CHOICE!" <<endl;
                cout << "RE-ENETER GENDER    ";
                cin >> Gender;
            }

            enum gender y;
            if (Gender == "1"){
                y = male;
            }
            else if (Gender == "2"){
                y = female;
            }

            cout << "STUDENT USERNAME GENERATED    " << endl;
            UserName = "u" + ID + "@giki.edu.pk";
            cout << "STUDENT PASSWORD GENERATED   " << endl;
            Password = year + month + day;

            cout << "PLEASE INPUT THE PHONE NUMBER OF STUDENT    ";
            cin >> Number;
            cout << "PLEASE INPUT THE CITY OF STUDENT AS ADDRESS    ";
            cin >> this->address;
            cout << "PLEASE INPUT THE FEE STATUS OF STUDENT    ";
            cin >> this->fee;

            int choice;

            cout << "Enter 1 for Alevels, 2 for FSC, or 3 for Private: ";
            cin >> choice;

            while (choice < 1 || choice > 3) {
                cout << "Invalid choice. Please enter 1, 2, or 3: ";
                cin >> choice;
            }

            switch (choice) {
                case 1:
                    Qualification = "Alevels";
                    break;
                case 2:
                    Qualification = "FSC";
                    break;
                case 3:
                    Qualification = "Private";
                    break;
            }

            int no_of_subjects;
            cout << "PLEASE INPUT NUMBER OF SUBJECTS    ";
            cin >> no_of_subjects;

            General::Marks student[no_of_subjects];

            setSubject(student, no_of_subjects);
            string updsted_marks = getSubject(student, no_of_subjects);
             
            file1 << ID << "," << this->section << "," << FirstName << "," << LastName << "," << departments(x) << "," << UserName << "," << Password << "," << Date << "," << genders(y) << "," << Number << "," << this->address << "," << this->fee << "," << Qualification << "," << getSubject(student, no_of_subjects) << endl;
            file2 << ID << "," << this->section << "," << updsted_marks << endl;
            
        }
        else {
            file1 << sid << "," << section << "," << firstName << "," << lastName << "," << dept << "," << user << "," << pass << "," << date << "," << gender << "," << phone << "," << address << "," << fee << "," << quali << "," << marks << endl;
            file2 << sid << "," << section << "," << marks << endl;
            
        }
    }
    file.close();
    file2.close();
    if (found == false)
    {
        cout << "THE ENTERED ID, FIRST NAME OR LAST NAME DID NOT MATCH TO ANY DATA" << endl;
        remove("TEMP1.txt");
        remove("TEMP2.txt");
        
    }
    else {
        remove("Student.txt");
        
        remove("studenID.txt");
        rename("TEMP1.txt", "Student.txt");
        rename("TEMP2.txt", "student_data.txt");
        
        cout << endl << "THE DATA OF STUDENT HAS BEEN EDITED" << endl;
    }
    cout << "PRESS ANY KEY TO CONTINUE " << endl;
    cin>>f;
}
void Admin::editteacher()
{
    char f;
    fstream file3("Teacher.txt", ios::in);
    fstream file4("TEMP.txt", ios::out);
    if (!file3.is_open())
    {
        cout << "Error opening file1!\n";
        return;
    }
    if (!file4.is_open())
    {
        cout << "Error opening file2!\n";
        return;
    }

    string firstName, lastName, id, dept, user, pass, date, gender, phone, address, quali, section, subject;
    string fname, lname;
    if (cin.fail()) {
        cin.clear(); cin.ignore();
    }
    cout << "PLEASE INPUT THE ID OF TEACHER    "; 
    cin >> ID;
    cout << "PLEASE INPUT THE FIRST NAME OF TEACHER TO EDIT INFO:    ";
    cin >> fname;
    cout << "PLEASE INPUT THE LAST NAME OF TEACHER TO EDIT INFO:    ";
    cin >> lname;

    bool found = false;
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

        if (fname == firstName && lname == lastName && ID == id)
        {
            found = true;

            string year, month, day;
            cout << "PLEASE ENTER THE REGISTRATION DATE OF TEACHER    " << endl;
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
            Date = year + "/" + month + "/" + day;

            cout << "PLEASE INPUT THE ID OF TEACHER e.g(503)    ";
            cin >> ID;

            while (stoi(ID) < 1 || stoi(ID) > 9999){
                cout << "INVALID ID!" <<endl;
                cout << "RE-ENTER ID    ";
                cin >> ID;
            }

            if (ID.length() == 1){
                ID = "00" + ID;
            }
            else if (ID.length() == 2) {
                ID = "0" + ID;
            }
           
            ID = year + ID;
            cout << "PLEASE INPUT SECTION OF TEACHER    ";
            cin >> this->section;

            cout << "PLEASE INPUT THE FIRST NAME OF TEACHER    ";
            cin >> FirstName;
            cout << "PLEASE INPUT THE LAST NAME OF TEACHER    ";
            cin >> LastName;

            cout << "PLEASE INPUT THE DEPARTMENT OF TEACHER; 1:FCSE|2:MGS|3:FME|4:FMCE    ";
            cin >> Department;

            while (stoi(Department) < 1 || stoi(Department) > 4 ){
                cout << "INVALID CHOICE!" <<endl;
                cout << "RE-ENETER DEPARTMENT    ";
                cin >> Department;
            }
            department x;
            if (Department == "1") {
                x = FCSE;
            }
            else if (Department == "2") {
                x = MGS;
            }
            else if (Department == "3") {
                x = FME;
            }
            else if (Department == "4") {
                x = FMCE;
            }

            cout << "PLEASE INPUT THE SUBJECT OF TEACHER    ";
            cin >> this->subject;

            cout << "PLEASE SELECT THE GENDER OF TEACHER; 1:MALE|2:FEMALE    ";
            cin >> Gender;
            while (stoi(Gender) < 1 || stoi(Gender) > 2){
                cout << "INVALID CHOICE!" <<endl;
                cout << "RE-ENETER GENDER    ";
                cin >> Gender;
            }

            enum gender y;
            if (Gender == "1"){
                y = male;
            }
            else if (Gender == "2"){
                y = female;
            }

            cout << "STUDENT USERNAME GENERATED    " << endl;
            UserName = "t" + ID + "@giki.edu.pk";
            cout << "STUDENT PASSWORD GENERATED   " << endl;
            Password = year + month + day;

            cout << "PLEASE INPUT THE NUMBER OF TEACHER    ";
            cin >> Number;
            cout << "PLEASE INPUT THE QUALIFICATION OF TEACHER    ";
            cin >> Qualification;
            cout << "PLEASE INPUT THE CITY OF TEACHER AS ADDRESS    ";
            cin >> this->address;

            file4 << ID << "," << this->section << "," << FirstName << "," << LastName << "," << departments(x) << "," << this->subject << "," << UserName << "," << Password << "," << Date << "," << genders(y) << "," << Number << "," << Qualification << "," << this->address << endl;
        }
        else {
            file4 << id << "," << section << "," << firstName << "," << lastName << "," << dept << "," << subject <<"," << user << "," << pass << "," << date << "," << gender << "," << phone << "," << quali << "," << address << "," << endl;
        }
    }
    file3.close();
    file4.close();
    if (found == false)
    {
        cout << "THE ENTERED ID FIRST NAME OR LAST NAME DID NOT MATCH TO ANY DATA" << endl;
        remove("TEMP.txt");
    }
    else {
        remove("Teacher.txt");
        rename("TEMP.txt", "Teacher.txt");
        cout << endl << "THE DATA OF TEACHER HAS BEEN EDITED" << endl;
    }
    cout << "PRESS ANY KEY TO CONTINUE " << endl;
    cin>>f;
}
void Admin::viewstudent()
{
    char f;
    fstream file("Student.txt", ios::in);
    if (!file.is_open()) { cout << "Error!\n"; }

    string firstName, lastName, id, dept, user, pass, date, gender, phone, address, fee, quali, marks, section;

    cout << endl << "TOTAL RECORDS OF STUDENTS FOUND: " << endl;
    while (getline(file, id, ','))
    {   
        getline(file, section, ',');
        getline(file, firstName, ',');
        getline(file, lastName, ',');
        getline(file, dept, ',');
        getline(file, id, ',');
        getline(file, user, ',');
        getline(file, pass, ',');
        getline(file, date, ',');
        getline(file, gender, ',');
        getline(file, phone, ',');
        getline(file, address, ',');
        getline(file, fee, ',');
        getline(file, quali, ',');
        getline(file, marks);

        cout << "ID#    " << id << endl;
        cout << "SECTION    " << section << endl;
        cout << "FIRST NAME:    " << firstName << endl;
        cout << "LAST NAME:    " << lastName << endl;
        cout << "DEPARTMENT:    " << dept << endl;
        cout << "USER NAME:    " << user << endl;
        cout << "PASSWORD:    " << pass << endl;
        cout << "REGISTERATION DATE:    " << date << endl;
        cout << "GENDER:    " << gender << endl;
        cout << "PHONE #    " << phone << endl;
        cout << "ADDRESS:    " << address << endl;
        cout << "FEE:    " << fee << endl;
        cout << "QUALIFICATION:    " << quali << endl;
        cout << "MARKS:    " << marks << endl << endl;
    }

    file.close();
    cout << "PRESS ANY KEY TO CONTINUE " << endl;
    cin>>f;
}
void Admin::viewteacher()
{
    char f;
    fstream file("Teacher.txt", ios::in);
    if (!file.is_open()) { cout << "Error!\n"; }

    string firstName, lastName, id, dept, user, pass, date, gender, phone, quali, address, section, subject;

    cout << endl << "TOTAL RECORDS OF TEACHERS FOUND: " << endl;
    while (getline(file, id, ',')) {

        getline(file, section, ',');
        getline(file, firstName, ',');
        getline(file, lastName, ',');
        getline(file, dept, ',');
        getline(file, subject, ',');
        getline(file, user, ',');
        getline(file, pass, ',');
        getline(file, date, ',');
        getline(file, gender, ',');
        getline(file, phone, ',');
        getline(file, quali, ',');
        getline(file, address);

        cout << "FIRST NAME:    " << firstName << endl;
        cout << "LAST NAME:    " << lastName << endl;
        cout << "ID#    " << id << endl;
        cout << "SECTION    " << section << endl;
        cout << "DEPARTMENT:    " << dept << endl;
        cout << "SUBJECT:    " << subject << endl;
        cout << "USER NAME:    " << user << endl;
        cout << "PASSWORD:    " << pass << endl;
        cout << "REGISTERATION DATE:    " << date << endl;
        cout << "GENDER:    " << gender << endl;
        cout << "PHONE #    " << phone << endl;
        cout << "QUALIFICATION:    " << quali << endl;
        cout << "ADDRESS:    " << address << endl << endl;

    }

    file.close();
    cout << "PRESS ANY KEY TO CONTINUE " << endl;
    cin>>f;
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
