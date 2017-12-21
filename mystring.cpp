/* 
 mystring.cpp
 a14_1
 Stacey Rivet Beck, 5/1/17
 Fundamentals in Programming in C++, 110B, David Lee Harden
 
 Private data member myStringArr is a char array that does not get changed
 during the program.  It points to a copy and deep copy of the object, in 
 which the copies are created to store the input data.
 
*/

#include "mystring.h"
#include <fstream>
#include <cctype>      
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

namespace cs_mystring{
   
    
    
    
    
    
    
    //needs to return length of the cstring
    unsigned long MyString :: length() const
    {
        unsigned long length = 0;
        length = strlen(myStringArray);
        return length;
    }
    
    
    
    
    
    
    
    //default constructor initializing data members
    MyString :: MyString()
    {
        myStringArray = new char[1];
        strcpy(myStringArray, "");
    }
    
    
    
    
    
    
    
    //constructor setting cstring to parameter inMyStringArr
    MyString :: MyString (const char *inMyStringArr)
    {
        myStringArray = new char[strlen(inMyStringArr) + 1];
        strcpy(myStringArray, inMyStringArr);
    }
    
    
    
    
    
    
    
    //copy constructor
    MyString :: MyString (const MyString& right)
    {
        myStringArray = new char[strlen(right.myStringArray) + 1];
        strcpy(myStringArray, right.myStringArray);
    }
    
    
    
    
    
    
    
    MyString :: ~MyString ()
    {
        delete [] myStringArray;
    }
    
    
    
    
    
    
    
    // deep copy assignment constructor
    MyString MyString :: operator = (const MyString& right)
    {   if (this != &right)
        
    {
        delete [] myStringArray;
        myStringArray = new char[strlen(right.myStringArray) + 1];
        strcpy(myStringArray, right.myStringArray);
    }
        return *this;
    }

    
    
    
    
    
    
    /* This function concantenates the right operand to the left while creating 
     enough space to hold the c-string using strlen of the left + right operand 
     + 1 and storing that as the size of new char. Strcpy copies left operand 
     into the new char result and strcat combines the right operand to the result 
     object.*/
    MyString operator + (const MyString& left, const MyString& right)
    {
        MyString result;
        
        result.myStringArray = new char[strlen(left.myStringArray)
                                        + strlen(right.myStringArray) + 1];
        
        strcpy(result.myStringArray, left.myStringArray);
        strcat(result.myStringArray, right.myStringArray);
        
        return result;
    }
    
    
    
    
    
    
    
    MyString MyString :: operator += (const MyString& right)
    {
        *this = *this + right;
        return *this;
    }
    
    
    
    
    
    
    
    
    ostream& operator << (ostream& out, const MyString& print)
    {
        out << print.myStringArray;
        return out;
    }
    
    
    
    
    
    
    
    istream& operator>>(istream& in, MyString& obj)
    {
        char temp[128];
        in >> temp;
        delete [] obj.myStringArray;
        obj.myStringArray = new char[strlen(temp) + 1];
        strcpy(obj.myStringArray, temp);
        return in;
    }
    
    
    
    
    
    
    
    /*This function passes in a stream of data as well as passes a char by value 
     into the function that temporarily creates a char array of 127 characters 
     to hold the data that is read until it reaches the delimiter defined by the 
     client program. It then copies the temp data into myStringArray object and 
     does not return a value.*/
    void MyString :: read (istream& in, char delim)
    {
        char temp[128];
        in.getline(temp, 127, delim);
        strcpy(myStringArray, temp);
    }
    
    
    
    
    
    
    
    char MyString :: operator[](int index) const
    {
        assert(index >= 0 && index < strlen(myStringArray));
        return myStringArray[index];
    }
    
    
    
    
    
    
    
    char& MyString :: operator [](int index)
    {
        assert(index >= 0 && index < strlen(myStringArray));
        return myStringArray[index];
    }
    

    
    
    
    
    
    
    
    bool operator < (const MyString& left, const MyString& right)
    {
        if (strcmp(left.myStringArray, right.myStringArray) < 0)
            return true;
        return false;
    }
    
    
    
    
    
    
    
    bool operator > (const MyString& left, const MyString& right)
    {
        if (strcmp(left.myStringArray, right.myStringArray) > 0)
            return true;
        return false;
    }
    
    
    
    
    
    
    
    bool operator <= (const MyString& left, const MyString& right)
    {
        if (strcmp(left.myStringArray, right.myStringArray) <= 0)
            return true;
        return false;
    }
    
    
    
    
    
    
    
    bool operator >= (const MyString& left, const MyString& right)
    {
        if (strcmp(left.myStringArray, right.myStringArray) >= 0)
            return true;
        return false;
    }
    
    
    
    
    
    
    
    bool operator == (const MyString& left, const MyString& right)
    {
        if (strcmp(left.myStringArray, right.myStringArray) == 0)
            return true;
        return false;
    }
    
    
    
    
    
    
    
    bool operator != (const MyString& left, const MyString& right)
    {
        if (strcmp(left.myStringArray, right.myStringArray) != 0)
            return true;
        return false;
    }
     
}


