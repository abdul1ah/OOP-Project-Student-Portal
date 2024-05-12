#include "user.h"
#include "qdebug.h"
#include <globalvariables.h>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
User::User() {
    checkU = false;
    checkP = false;
    lpassword = "";
}

string User::login(string file, string useremail, string userpassword)
{
    ifstream readfile(file);
    int line_number = 0;
    while (getline(readfile, checkusername))
    {
        if (useremail == checkusername)
        {
            checkU = true;
            break;
        }
        line_number++;
    }
    emailline = line_number;
    line_number++;
    int currentline = 0;
    readfile.seekg(0, ios::beg);
    if (checkU)
    {
        while (getline(readfile, checkpassword))
        {
            if (currentline == line_number)
            {
                if (userpassword == checkpassword)
                {
                    checkP = true;
                    // createrpassword = userpassword;
                }

            }
            currentline++;
        }
    }
    readfile.clear();
    readfile.seekg(0, ios::beg);
    line_number = line_number - 2;
    nameline = line_number;
    // lineofusername = nameline;
    currentline = 1;
    string cname;
    while (getline(readfile, cname))
    {
        if (currentline == line_number)
        {
            globalname = cname;
        }

        currentline++;
    }
    if ((checkU) && (checkP))
    {
        this->lpassword = userpassword;
        return "Login Successful!!";
    }

    else if (!checkU)
    {
        return "User Not Found!!";
    }
    else
    {
        return "Invalid Password!!";
    }
}
string User:: ReturnPawword(){
    return lpassword;
}
int User::Returnnameline(){
    return nameline;
}
void User::registration(std::string name, int age, std::string remail, std::string rpassword, int rpin, std::string file,std::string batch,std::string faculty,std::string department)
{
    this->name = name;
    this->age = age;
    this->remail = remail;
    this->rpassword = rpassword;
    this->rpin = rpin;
    this->batch = batch;
    this->faculty = faculty;
    string dep;
    dep = department;
    ofstream userdata(file, std::ios::app);
    if (!userdata)
    {
        cout << "Error: Could not open file for writing." <<endl;
        return;
    }

    userdata << this->name <<endl;
    userdata << this->age <<endl;
    userdata << this->remail <<endl;
    userdata << this->rpassword <<endl;
    userdata << this->rpin <<endl;
    if (file == "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Student Data.txt")
    {
        userdata << this->batch <<endl;
        userdata << this->faculty <<endl;
        userdata << dep<<endl;
        ofstream maths("C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Maths.txt",ios::app);
        maths<<"&"+name<<endl;
        maths<<0<<endl;
        maths<<0<<endl;

        ofstream physics("C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Physics.txt",ios::app);
        physics<<"&"+name<<endl;
        physics<<0<<endl;
        physics<<0<<endl;

        ofstream stats("C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Stats.txt",ios::app);
        stats<<"&"+name<<endl;
        stats<<0<<endl;
        stats<<0<<endl;

        ofstream cs("C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Computer.txt",ios::app);
        cs<<"&"+name<<endl;
        cs<<0<<endl;
        cs<<0<<endl;

        maths.close();
        physics.close();
        cs.close();
        stats.close();
    }
    else{
        userdata << this->faculty <<endl;
        userdata << dep<<endl;
    }


    userdata.close();



}/*
string User::changepassword(string email, int recoverykey1, string newpassword12, string file, string tempfile) {
    string Srpin;
    string newpassword;
    this->lemail = email;
    this->rpin = recoverykey1;
    Srpin = to_string(rpin);
    ifstream readfile(file);
    int recoverykey = 0;
    while (getline(readfile, this->checkusername)) {
        if (lemail == this->checkusername) {
            this->checkU = true;
            break;
        }
        recoverykey++;
    }
    readfile.seekg(0, ios::beg);
    recoverykey = recoverykey + 2;
    for (int i = 0; i <= recoverykey; i++) {
        getline(readfile, this->checkpassword);
        if (i == recoverykey) {
            if (Srpin == this->checkpassword) {
                this->checkP = true;
                break;
            }
        }
    }

    ofstream temp(tempfile);
    readfile.seekg(0, ios::beg);
    if (!this->checkU) {
        return "No User Found";
    }
    if (!this->checkP) {
        return "Recovery Key Invalid!";
    }

    if ((this->checkU) && (this->checkP)) {

        newpassword = newpassword12;
        recoverykey = recoverykey;
        int cline = 0;
        string line;
        ifstream readfile(file);
        while (getline(readfile, line)) {
            cline++;
            if (cline == recoverykey) {
                temp << newpassword << endl;
            }
            else
                temp << line << endl;
        }
    }
    readfile.close();
    temp.close();
    const char *ofile = file.c_str();
    const char *tfile = tempfile.c_str();
    remove(ofile);
    rename(tfile, ofile);
    return "Password Successfully Changed!!";
}*/

std::string User::deleteaccount(std::string name, std::string file, std::string tempfile) {
    std::ifstream readfile(file);
    std::ofstream temp(tempfile);

    int lineNumber = 0;
    std::string line;
    while (std::getline(readfile, line)) {
        lineNumber++;
        if (line == name) {
            readfile.close();
            break;
        }
        else{
            return "Student Not Found";
        }
    }

    int deletestarting, deleteending;
    if (file == "C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Student Data.txt") {
        deletestarting = lineNumber;
        deleteending = lineNumber + 7;
    } else {
        deletestarting = lineNumber;
        deleteending = lineNumber + 6;
    }

    int lineNumber1 = 1;
    readfile.open(file);
    while (std::getline(readfile, line)) {
        if (!(lineNumber1 >= deletestarting && lineNumber1 <= deleteending)) {
            temp << line << endl;
        }
        lineNumber1++;
    }

    readfile.close();
    temp.close();

    const char *oFile = file.c_str();
    const char *tFile = tempfile.c_str();
    std::remove(oFile);
    std::rename(tFile, oFile);

    return "Account Successfully Deleted!!";
}


void User::PrintTeacherDetails(std::string name) {
    std::ifstream file("C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Teacher Data.txt");
    if (!file.is_open()) {
        std::cout << "Error: Unable to open file." << std::endl;
        return;
    }

    std::string line;
    bool found = false;
    while (getline(file, line)) {
        if (line == name) {
            found = true;
            qDebug() << "Name : " << line;
            for (int i = 0; i < 6; ++i) {
                if (getline(file, line)) {
                    if (i == 0) {
                        globalage = line;
                    } else if (i == 1) {
                        globalemail = line;
                    } else if (i == 2) {
                        globalpassword = line;
                    } else if (i == 3) {
                        globalcnic = line;
                    } else if (i == 4) {
                        globaltfaculty = line;
                    } else if (i == 5) {
                        globaltdepartment = line;
                    }
                } else {
                    std::cout << "Error: End of file reached prematurely." << std::endl;
                    return;
                }
            }
            break;
        }
    }
    if (!found) {
        qDebug() << "No Record Found.";
    }
    file.close();
}


void User::PrintStudentDetails(std::string name) {
    std::ifstream file("C:\\Users\\DELL\\OneDrive\\Desktop\\LMS\\Student Data.txt");
    if (!file.is_open()) {
        std::cout << "Error: Unable to open file." << std::endl;
        return;
    }

    std::string line;
    bool found = false;
    while (getline(file, line)) {
        if (line == name) {
            found = true;
            qDebug() << "Name : " << line;
            for (int i = 0; i < 7; ++i) {
                if (getline(file, line)) {
                    if (i == 0) {
                        globalage = line;
                    } else if (i == 1) {
                        globalemail = line;
                    } else if (i == 2) {
                        globalpassword = line;
                    } else if (i == 3) {
                        globalregno = line;
                    } else if (i == 4) {
                        globalbatch = line;
                    } else if (i == 5) {
                        globaltfaculty = line;
                    } else if (i == 6) {
                        globaltdepartment = line;
                    }
                } else {
                    std::cout << "Error: End of file." << std::endl;
                    file.close();
                    return;
                }
            }
            file.close();
            break;
        }
    }
    if (!found) {
        qDebug() << "No Record Found.";
    }
}



void User::readAndStoreLines(const std::string& filepath) {
    // std::string lines[150];
    std::ifstream file(filepath);
    std::string line;
    int i = 0;
    while (std::getline(file, line) && i < 150) {
        if (!line.empty() && line[0] == '&') {
            lines[i] = line.substr(1);
            i++;
        }
    }
    arraysize = i;
}

void User::replaceNextLine(const std::string& filepath, const std::string& targetLine, const std::string& newLine, const std::string& tempFilepath) {
    std::ifstream inFile(filepath);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file " << filepath << std::endl;
        return;
    }

    std::ofstream outFile(tempFilepath);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create temporary file" << std::endl;
        inFile.close();
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(inFile, line)) {
        if (found) {
            outFile << newLine << std::endl;
            found = false;
        }
        else if (line == "&"+targetLine) {
            found = true;
            outFile << line << std::endl;
        }
        else {
            outFile << line << std::endl;
        }
    }

    inFile.close();
    outFile.close();

    if (std::remove(filepath.c_str()) != 0) {
        std::cerr << "Error: Unable to remove file " << filepath << std::endl;
    }
    else if (std::rename(tempFilepath.c_str(), filepath.c_str()) != 0) {
        std::cerr << "Error: Unable to rename file" << std::endl;
    }
}








// void User::replaceLinesAfter(string filename, string searchString, string replacementLine, string tempFilename) {
//     ifstream inputFile(filename);
//     if (!inputFile) {
//         cerr << "Error opening file: " << filename << endl;
//         return;
//     }

//     string line;
//     ofstream tempFile(tempFilename);
//     bool replaceNextLine = false;
//     while (getline(inputFile, line)) {
//         if (replaceNextLine) {
//             tempFile << replacementLine << endl;
//             replaceNextLine = false;
//         } else {
//             tempFile << line << endl;
//         }
//         if (line.find("&" + searchString) != string::npos) {
//             replaceNextLine = true;
//         }
//     }
//     inputFile.close();
//     tempFile.close();

//     remove(filename.c_str());
//     rename(tempFilename.c_str(), filename.c_str());

//     cout << "Replacement completed successfully." << endl;
// }





void User::replaceLinesAfter(string filename, string searchString, string replacementLine, string tempFilename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    bool foundSearchString = false;
    ofstream tempFile(tempFilename);
    while (getline(inputFile, line)) {
        if (!foundSearchString && line == '&' + searchString) {
            tempFile << line << endl;
            string tempstr;
            getline(inputFile, tempstr);
                tempFile << tempstr << endl;
            string skipLine;
                getline(inputFile, skipLine);
                tempFile << replacementLine << endl;  // Write the replacement line
            foundSearchString = true;  // Set foundSearchString to true
        } else {
            tempFile << line << endl;
        }
    }
    inputFile.close();
    tempFile.close();

    if (!foundSearchString) {
        cerr << "Search string not found in the file." << endl;
        remove(tempFilename.c_str());
        return;
    }

    remove(filename.c_str());
    rename(tempFilename.c_str(), filename.c_str());

    cout << "Replacement completed successfully." << endl;
}











// void User::replaceLinesAfter(string filename, string searchString, string replacementLine, string tempFilename) {
//     ifstream inputFile(filename);
//     if (!inputFile) {
//         cerr << "Error opening file: " << filename << endl;
//         return;
//     }

//     string line;
//     bool foundSearchString = false;
//     ofstream tempFile(tempFilename);
//     while (getline(inputFile, line)) {
//         if (!foundSearchString && line == '&' + searchString) {
//             tempFile << line << endl;  // Write the line containing the searchString
//             tempFile << replacementLine << endl;  // Write the replacement line
//             foundSearchString = true;  // Set foundSearchString to true
//         } else {
//             tempFile << line << endl;
//         }
//     }
//     inputFile.close();
//     tempFile.close();

//     if (!foundSearchString) {
//         cerr << "Search string not found in the file." << endl;
//         remove(tempFilename.c_str());
//         return;
//     }

//     remove(filename.c_str());
//     rename(tempFilename.c_str(), filename.c_str());

//     cout << "Replacement completed successfully." << endl;
// }
