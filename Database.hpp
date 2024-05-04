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
};