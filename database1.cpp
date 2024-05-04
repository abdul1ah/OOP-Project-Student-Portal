enum department{FCSE, MGS, FME, FMCE};
string departments(department x){
    if (x == FCSE)
        return "FCSE";
    else if (x == MGS)
        return "MGS";
    else if (x == FME)
        return "FME";
    else if (x == FMCE)
        return "FMCE";
}

enum gender { male, female };
string genders(gender y){
    if (y == male)
        return "MALE";
    else if (y == female)
        return "FEMALE";
    }

void Admin::addteacher()
{
    char f;
    
    string year, month, day;

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

    cout << "PLEASE INPUT THE ID OF TEACHER e.g(1/22/303/5555)   ";
    cin >> t_id;

    while (stoi(t_id) < 1 || stoi(t_id) > 9999){
        cout << "INVALID ID!" <<endl;
        cout << "RE-ENTER ID    ";
        cin >> t_id;
    }

    if (t_id.length() == 1){
        t_id = "000" + t_id;
    }
    else if (t_id.length() == 2) {
        t_id = "00" + t_id;
    }
    else{
        t_id = "0" + t_id;
    }

    t_id = year + t_id;
    
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

    cout << "PLEASE INPUT THE USER NAME OF TEACHER    ";
    cin >> tuser_name;
    cout << "PLEASE INPUT THE PASSWORD OF TEACHER    ";
    cin >> tpassword;
    cout << "PLEASE INPUT THE NUMBER OF TEACHER    ";
    cin >> t_number;
    cout << "PLEASE INPUT THE QUALIFICATION OF TEACHER    ";
    cin >> t_qualification;
    cout << "PLEASE INPUT THE CITY OF TEACHER AS ADDRESS    ";
    cin >> address;
    ofstream out("Teacher.txt", ios::app);  // Open file in append mode
    out << t_id << "," << t_firstname << "," << t_lastname << "," << departments(x) << "," << tuser_name << "," << tpassword << "," << t_date << "," << genders(y) << "," << t_number << "," << t_qualification << "," << address << endl;
    out.close();  // Remember to close the file
    cout << endl << "THE DATA OF TEACHER HAS BEEN ADDED" << endl;
    cout << "PRESS ANY KEY TO CONTINUE" << endl;
    cin>>f;
}