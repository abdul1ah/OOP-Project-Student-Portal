#ifndef USER_H
#define USER_H

#include <QString>
#include <QFile>
#include <QTextStream>
// using namespace std;
class User
{
private:
    std::string name;
    int age;
    std::string remail;
    std::string rpassword;
    std::string lemail;
    std::string lpassword;
    std::string checkusername;
    std::string checkpassword;
    int emailline;
    int nameline;
    int rpin;
    std::string batch;
    std::string faculty;
    bool checkU;
    bool checkP;

public:
    User();
    std::string  ReturnPawword();
    int Returnnameline();
    void registration(std::string name, int age, std::string remail, std::string rpassword, int rpin, std::string file,std::string batch,std::string faculty,std::string department);
    std::string login(std::string file, std::string useremail, std::string userpassword);
    std::string changepassword(std::string email,int recoverykey1,std::string newpassword12,std::string file,std::string tempfile);
    std::string deleteaccount(std::string name, std::string file, std::string tempfile);
    void PrintTeacherDetails(std::string name);
    void PrintStudentDetails(std::string name);
    void readAndStoreLines(const std::string& filepath);
    void replaceLinesAfter(std::string filename, std::string searchString, std::string replacementLine, std::string tempFilename);
    void replaceNextLine(const std::string& filepath, const std::string& targetLine, const std::string& newLine, const std::string& tempFilepath);
};

#endif // USER_H
