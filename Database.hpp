#pragma once

#include<iostream>
#include<string>
#include<unistd.h>
#include<fstream>
#include<sstream>

using namespace std;

//general class
class General
{
    protected:
    struct Marks{
        string s_marks;
        string s_subject;
    };

    enum department{FCSE, MGS, FME, FMCE};
    string departments(department);

    enum gender { male, female };
    string genders(gender);
    
    void setSubject(Marks [], int);

    string getSubject(Marks [], int);

};

// Class declaration for Admin
class Admin:public General
{
protected:
    string username;  // Admin username
    string password;  // Admin password
    
    string ID;
    string FirstName;
    string LastName;
    string Department;
    string UserName;
    string Password;
    string Date;
    string Gender;
    string Number;
    string Qualification;
    string address;
    string Course;
    string Marks;
    string fee;
    string section;
    string subject;

public:
    // Function declarations for Admin operations
    void signin();       // Admin sign in
    void addteacher();    // Add teacher
    void addstudent();    // Add student
    void editstudent();   // Edit student details
    void editteacher();   // Edit teacher details
    void viewstudent();   // View all students
    void viewteacher();   // View all teachers
};

// Class declaration for Student
class Student:public Admin
{
private:
    // Student attributes
public:
    // Function declarations for Student operations
    void sign_in_student();             // Student sign in
    void view_attendance();             // View attendance
    void view_marks();                  // View marks
};

// Derived class declaration for Teacher inheriting Admin
class Teacher :public Admin
{
public:
    // Function declarations for Teacher operations
    void signin();           // Teacher sign in
    void timetable();        // View timetable
    void markingattendance();  // Mark attendance
    void assignmarks();      // Assign marks
   // Assign grades
};

