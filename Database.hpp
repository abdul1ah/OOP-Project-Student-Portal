#pragma once

#include<iostream>
#include<string>
#include<unistd.h>
#include<fstream>
#include<sstream>

using namespace std;

// Class declaration for Admin
class Admin
{
    protected:
        string username;  // Admin username
        string password;  // Admin password

    private:
        // Teacher attributes
        string t_id;
        string t_firstname;
        string t_lastname;
        string t_department;
        string tuser_name;
        string tpassword;
        string t_date;
        string t_gender;
        string t_number;
        string t_qualification;
        string address;
            struct Marks
        {
            string s_marks;
            string s_subject;
        };

        // Student attributes
        string suser_name,spassword;
        string s_id;
        string s_firstname;
        string s_lastname;
        string s_department;
        string s_user_name;
        string s_password;
        string s_date;
        string s_gender;
        string s_number;
        string s_address;
        string fee;
        string s_qualification;
        string s_marks;
        void setMarks(Marks [], int);
        string getMarks(Marks [], int);

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