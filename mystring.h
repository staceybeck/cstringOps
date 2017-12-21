/*
 mystring.h
 a14_1

 Stacey Rivet Beck, 5/1/17
 Fundamentals in Programming C++, 110B, David Lee Harden
 
 This class MyString is able to read in a file of c-strings and strings
 and print to the console.  It is capable of comparing c-strings as well
 as concantenate a stream of string data. 
  
 Public Member Prototypes (Pre/Post Condition comments):
 
 unsigned long length() const ;
 pre:
 post: set length of object myStringArray to zero then updates
 the length using strlen based on objects current holding value.
 
 MyString ();
 pre: --
 post: initializes the pointer value to a null string, valid c-string.
 
 MyString (const char *inMyStringArr);
 pre: *inMyStringArr points back to data member with c-string
 post: inMyStringArr copies c-strings to myStringArray data member 
 
 MyString (const MyString& right);
 pre:
 post: right object passes cstring by value to local copy myStringArray,
 does not change value.
 
 ~MyString ();
 pre:
 post: deallocates memory that myStringArray points to.
 
 MyString operator = (const MyString& right);
 pre:
 post: creates a new object copy and then returns *this (the object)
 
 MyString operator += (const MyString& right);
 pre:
 post: passes by value through object and adds to the current
 cstring copied in *this object.
 
 friend MyString operator + (const MyString& left,
 const MyString& right);
 pre:
 post: concantenates right operand to left and returns new string
 
 friend std::istream& operator>>(std::istream& in, MyString& obj);
 pre:
 post: reads in stream of cstrings and allocates new memory for 
 the right amount of space to be copied into myStringArray object
 
 friend std::ostream& operator << (std::ostream& out,
 const MyString& print);
 pre:
 post: prints object data copied from myStringArray
 
 void read (std::istream& in, char delim);
 pre:
 post: passes in char by value while reading cstring data from file
 and stops at the char value which is a delimiter and copies that into
 myStringArray object. 
 
 char operator[](int index) const;
 pre: assert will be true if cstring is still being looped and data
 being read into array.
 post: assert will be false and terminate by returning the cstring
 value once the length of the cstring has been read and null terminator
 detected.
 
 char& operator [](int index);
 pre: assert will be true if cstring is still being looped and data
 being read into array up to length of data.
 post: assert will be false and terminate by returning the cstring
 reference once the length of the cstring has been read and null 
 terminator detected.
 
 friend bool operator < (const MyString& left,
 const MyString& right);
 pre: compares value of left operand to right
 post: if value of left operand is less than right, returns true, else false
 
 friend bool operator <= (const MyString& left,
 const MyString& right);
 pre: compares value of left operand to right
 post: if value of left operand is less than or equal to right, 
 returns true, else false
 
 friend bool operator > (const MyString& left,
 const MyString& right);
 pre: compares value of left operand to right
 post: if value of left operand is greater than right,
 returns true, else false
 
 friend bool operator >= (const MyString& left,
 const MyString& right);
 pre: compares value of left operand to right
 post: if value of left operand is greater than or equal to right,
 returns true, else false
 
 friend bool operator == (const MyString& left,
 const MyString& right);
 pre: compares value of left operand to right
 post: if value of left operand is equal to right, returns true, else false
 
 friend bool operator != (const MyString& left,
 const MyString& right);
 pre: compares value of left operand to right
 post: if value of left operand is not equal to right, 
 returns true, else false

*/
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

namespace cs_mystring
{
    
    class MyString
    {
    public:
        unsigned long length() const ;
        MyString ();
        MyString (const char *inMyStringArr);
        MyString (const MyString& right);
        ~MyString ();
        MyString operator = (const MyString& right);
        MyString operator += (const MyString& right);
        friend std::istream& operator>>(std::istream& in, MyString& obj);
        friend std::ostream& operator << (std::ostream& out,
                                          const MyString& print);
        void read (std::istream& in, char delim);
        char operator[](int index) const;
        char& operator [](int index);
        friend bool operator < (const MyString& left,
                                const MyString& right);
        friend bool operator <= (const MyString& left,
                                 const MyString& right);
        friend bool operator > (const MyString& left,
                                const MyString& right);
        friend bool operator >= (const MyString& left,
                                 const MyString& right);
        friend bool operator == (const MyString& left,
                                 const MyString& right);
        friend bool operator != (const MyString& left,
                                 const MyString& right);
        friend MyString operator + (const MyString& left,
                                    const MyString& right);
    private:
        char *myStringArray;
    };
    
}
#endif

/*
 ----- Testing basic String creation & printing
 string [0] = Wow
 string [1] = C++ is neat!
 string [2] =
 string [3] = a-z
 
 ----- Now reading MyStrings from file
 
 ----- first, word by word
 Read string = The
 Read string = first
 Read string = time
 Read string = we
 Read string = will
 Read string = read
 Read string = individual
 Read string = words,
 Read string = next
 Read string = we
 Read string = read
 Read string = whole
 Read string = lines
 
 ----- now, line by line
 Read string = The  first  time  we  will
 Read string =     read individual words, next
 Read string = we read whole lines
 
 ----- Testing access to characters (using const)
 Whole string is abcdefghijklmnopqsrtuvwxyz
 now char by char: abcdefghijklmnopqsrtuvwxyz
 ----- Testing access to characters (using non-const)
 Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ
 
 ----- Testing relational operators between MyStrings
 Comparing app to apple
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
 Comparing apple to
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
 Comparing  to Banana
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
 Comparing Banana to Banana
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false
 
 ----- Testing relations between MyStrings and char *
 Comparing he to hello
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
 Comparing why to wackity
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
 
 ----- Testing concatentation on MyStrings
 outrageous + milk = outrageousmilk
 milk +  = milk
 + cow = cow
 cow + bell = cowbell
 
 ----- Testing concatentation between MyString and char *
 abcde + XYZ = abcdeXYZ
 XYZ + abcde = XYZabcde
 
 ----- Testing shorthand concat/assign on MyStrings
 who += what = whowhatandwhowhat
 what += WHEN = whatWHENandwhatWHEN
 WHEN += Where = WHENWhereandWHENWhere
 Where += why = WherewhyandWherewhy
 
 ----- Testing shorthand concat/assign using char *
 I love  += programming = I love programming
 
 ----- Testing copy constructor and operator= on MyStrings
 original is cake, copy is fake
 original is cake, copy is fake
 after self assignment, copy is Copy Cat
 Testing pass & return MyStrings by value and ref
 after calling Append, sum is BinkyBoo
 val is winky
 after assign,  val is BinkyBoo
 Program ended with exit code: 0
 */
