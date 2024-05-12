#include "Database.hpp"
//#include "Database.cpp"
#include "Untitled-1.cpp"
int main()
{
    char i=0;
    while (i != 27)
    {
        system("clear");
        
        cout << endl << endl << "\t\tLEARNING MANAGEMENT SYSTEM" << endl;
        cout << endl << "1.    PRESS 1 TO LOGIN AS ADMIN" << endl;
        cout << "2.    PRESS 2 TO LOGIN AS TEACHER" << endl;
        cout << "3.    PRESS 3 TO LOGIN AS STUDENT" << endl;
        cout << "5.    PRESS Esc TO END PROGRAM" << endl;
        cin>>i;
        if (i == '1')
        {
            Admin aobj;
            aobj.signin();
        }
        else if (i == '2')
        {
            Teacher tobj;
            tobj.signin();
        }
        else if (i == '3')
        {
            Student sobj;
            sobj.sign_in_student();
        }
        else if (i != 27)
        {
            system("clear");
            cout << endl << "PLEASE PRESS A VALID NUMBER" << endl;
        }
    }
    return 0;
}


