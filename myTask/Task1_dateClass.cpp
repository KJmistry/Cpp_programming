#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#define decMonth(M) if(1 == M){M = 12; Y--;} else M--;
using namespace std;

class Date;

void storeInt (string , Date*);

class Date
{   
    int Day,Month,Year;
    friend void storeInt(string,Date*);

public:

    /*---------CONSTRUCTOR FUNCTIONALITIES---------*/
    /*
        @ Get data in string form
        @ Convert string to integer
        @ Separate Date / Month / Year
        @ Initilize Date / Month / Year variable 
    */

    Date(string enteredDate = "1/1/1")                                                              // Constructor                                                          
    {
        storeInt(enteredDate,this);
        dateValidation(Day,Month,Year);
    }
    // get & set functions for Date, Month, Year

    int getDate();
    int getMonth();
    int getYear();

    void setDate(int);
    void setMonth(int);
    void setYear(int);
    
    // Function to Print Date in String format

    void printDate();

    // Functions to perform different functionalities

    bool checkLeap(int);
    int getMonthDays(int , int);
    void dateValidation(int, int, int);
    void dayValidation(int);
    void monthValidation(int);
    void yearValidation(int);
    string createStr(int D,int M,int Y);
    string addDays(int add, int D, int M, int Y);       
    string subtractDays(int sub, int D, int M, int Y);
    string addMonths(int add, int D, int M, int Y);
    string subtractMonths(int sub, int D, int M, int Y);
    string addYear(int add, int D, int M, int Y);
    string subtractYear(int sub, int D, int M, int Y);

    /*     Operators for Adding/Subtracting Days     */

    Date* operator+(int);
    Date* operator-(int);
    void operator++(int);
    void operator--(int);

    /*     Operators for Assigning Values     */

    void operator=(Date &);
    void operator+=(int);
    void operator-=(int);
    
    /*     Operators for Comparing Two Dates     */

    bool operator==(Date &);
    bool operator>=(Date &);
    bool operator<=(Date &);
    bool operator!=(Date &);
    bool operator >(Date &);
    bool operator <(Date &);


    ~Date() {}

};

bool Date::checkLeap(int yr)                                                                              // Check for Leap year ( Returns : true/false )
{
    if((yr % 4 == 0) && (yr % 100 != 0))
        return true;

    else if(yr % 400 == 0)
        return true;

    else
        return false;
}

int Date::getMonthDays(int month, int year)                                                               // Returns Days present in perticular month (Also validate leap year)      
{
    if(month == 2)
    {
        if(checkLeap(year))
            return 29;
        else   
            return 28;
    }
    else if((month > 7 && month % 2 == 0) || (month <= 7 && month % 2 != 0))
    {
        return 31;
    }
    else
        return 30;
}

void Date::dateValidation(int D, int M, int Y)                                                            // Function to validate the entered date
{
    int limit = getMonthDays(M,Y);
    if(D > limit || D <= 0 || M <= 0 || M > 12)
    {
        cout << "Entered Date is Invalid !" << endl; 
        exit(1);
    }
    return;
}

void Date::dayValidation(int D)                                                            // Function to validate the entered date
{
    if(D > 31 || D <= 0)
    {
        cout << "Entered Day is Invalid !" << endl; 
        exit(1);
    }
    return;
}

void Date::monthValidation(int M)                                                            // Function to validate the entered date
{
    if(M > 12 || M <= 0)
    {
        cout << "Entered Month is Invalid !" << endl; 
        exit(1);
    }
    return;
}

void Date::yearValidation(int Y)                                                            // Function to validate the entered date
{
    if(Y <= 0)
    {
        cout << "Entered Year is Invalid !" << endl; 
        exit(1);
    }
    return;
}

string Date::createStr(int D,int M,int Y)                                                                 // Generates single "/" separated string of date by combining D M Y
{   
    string str;
    str.append(to_string(D));
    str.append("/");
    str.append(to_string(M));
    str.append("/");
    str.append(to_string(Y));
    return str;
}

string Date::addDays(int add, int D, int M, int Y)                                                        // function will return next date after adding days
{   
    int limit = getMonthDays(M,Y);

    while( (add+D) > limit)
    {   
        // cout << "added " << limit-D << "Days, in month " << M << endl;                                   // Debug Statement
        add -= limit - D;                                           
        if(12 == M)
        {
            M = 1;
            Y++;
        }
        else
            M++;

        limit = getMonthDays(M,Y);
        D = 0;
        // cout << "add remain" << add << endl;                                                             // Debug Statement
    }
    return createStr(D+add,M,Y);
}

string Date::subtractDays(int sub, int D, int M, int Y)                                                   // function will return next date after subtracting days
{   
    int limit = 0;
    if(sub <= D)
    {
        if(D-sub == 0)
        {   
            decMonth(M);
            return createStr(31,M,Y);
        }
        return createStr(D-sub,M,Y);
    }
    else
    {   
        sub -= D;
        D = 0;
        decMonth(M);

        limit = getMonthDays(M,Y);

        while(sub > limit)
        {   
            sub -= limit;                                           
            decMonth(M);

            limit = getMonthDays(M,Y);
        }
        if(sub == limit)
        {
            decMonth(M);

            limit = getMonthDays(M,Y);
            return createStr(limit,M,Y);
        }
        return createStr(limit-sub,M,Y);
    }
}

string Date::addMonths(int add, int D, int M, int Y)                                                      // function will return next date after adding months provided by the user 
{
    while(add != 0)
    {
        if(12 == M)
        {
            M = 1;
            Y++;
        }
        else
            M++;
        add--;
    }
    int limit = getMonthDays(M,Y);

    if(D > limit)                                                                                   // Validating if specific moth is having lesser days (28/29/30) 
        D = limit; 
    return createStr(D,M,Y);
}

string Date::subtractMonths(int sub, int D, int M, int Y)                                                 // function will return next date after subtracting months provided by the user 
{
    while(sub != 0)
    {
        decMonth(M);
        sub--;
    }
    int limit = getMonthDays(M,Y);

    if(D > limit)                                                                                   // Validating if specific moth is having lesser days (28/29/30) 
        D = limit; 
    return createStr(D,M,Y);
}

string Date::addYear(int add, int D, int M, int Y)                                                        // function will return next date after adding year provided by the user 
{
    Y += add;
    if(!checkLeap(Y) && 2 == M && D == 29)
        D = 28;
    return createStr(D,M,Y);
}

string Date::subtractYear(int sub, int D, int M, int Y)                                                   // function will return next date after subtracting year provided by the user 
{
    Y -= sub;
    if(!checkLeap(Y) && 2 == M && D == 29)
        D = 28;
    return createStr(D,M,Y);
}

void storeInt(string str, Date* ref)                                                                      // Extracts int values of D M Y from given srting : "DD/MM/YYYY"
{
    vector<int> temp;
    stringstream ss(str);

    for (int i; ss >> i;) 
    {
        temp.emplace_back(i);
        if (ss.peek() == '/')
            ss.ignore();
    }

    if(temp.size() > 3)
    {
        cout << "Enter Valid format of date !" << endl;
        exit(1);
    }

    ref->Day = temp[0];
    ref->Month = temp[1];
    ref->Year = temp[2];
    return;
}

void Date::printDate()
{   
    cout << createStr(Day,Month,Year) << endl;      
}

int Date::getDate()
{
    // cout << "Returning Day : " << Day << endl;
    return Day;
}

int Date::getMonth()
{
    // cout << "Returning Month : " << Month << endl;
    return Month;
}

int Date::getYear()
{
    // cout << "Returning Year : " << Year << endl;
    return Year;
}

void Date::setDate(int day)
{
    cout << "Setting Day : " << day << endl;
    dayValidation(day);
    Day = day;
    return;
}

void Date::setMonth(int month)
{
    cout << "Setting Month : " << month << endl;
    monthValidation(month);    
    Month = month;
    return;
}

void Date::setYear(int year)
{
    cout << "Setting Year : " << year << endl;
    yearValidation(year);
    Year = year;
    return;
}

Date* Date::operator+(int add)
{   
    Date* temp = new Date;
    string finalDate = addDays(add,Day,Month,Year);
    storeInt(finalDate,temp);
    return temp; 
}

Date* Date::operator-(int sub)
{   
    Date* temp = new Date;
    string finalDate = subtractDays(sub,Day,Month,Year);
    storeInt(finalDate,temp);
    return temp; 
}

void Date::operator++(int)
{   
    string finalDate = addDays(1,Day,Month,Year);
    storeInt(finalDate,this);
    return; 
}

void Date::operator--(int)
{   
    string finalDate = subtractDays(1,Day,Month,Year);
    storeInt(finalDate,this); 
    return;
}

void Date::operator=(Date &ref)
{
    ref.Day = Day;
    ref.Month = Month;
    ref.Year = Year;
    return;
}

void Date::operator+=(int add)
{
    string finalDate = addDays(add,Day,Month,Year);
    storeInt(finalDate,this);
    return; 
}

void Date::operator-=(int sub)
{
    string finalDate = subtractDays(sub,Day,Month,Year);
    storeInt(finalDate,this);
    return;
}

bool Date::operator==(Date &ref)
{
    if(ref.Day == Day && ref.Month == Month && ref.Year == Year)
        return true;
    return false;
}   

bool Date::operator>=(Date &ref)
{
    if(Year >= ref.Year)
        return true;
    else if(Year == ref.Year)
    {
        if(Month >= ref.Month)
            return true;
        else if(Month == ref.Month)
        {
            if(Day >= ref.Day)
                return true;
        }
    }
    return false;
}   

bool Date::operator<=(Date &ref)
{
    if(Year <= ref.Year)
        return true;
    else if(Year == ref.Year)
    {
        if(Month <= ref.Month)
            return true;
        else if(Month == ref.Month)
        {
            if(Day <= ref.Day)
                return true;
        }
    }
    return false;
}   

bool Date::operator!=(Date &ref)
{
    if(ref.Day != Day || ref.Month != Month || ref.Year != Year)
        return true;
    return false;
}   

bool Date::operator >(Date &ref)
{
    if(Year > ref.Year)
        return true;
    else if(Year == ref.Year)
    {
        if(Month > ref.Month)
            return true;
        else if(Month == ref.Month)
        {
            if(Day > ref.Day)
                return true;
        }
    }
    return false;
}   

bool Date::operator <(Date &ref)
{
    if(Year < ref.Year)
        return true;
    else if(Year == ref.Year)
    {
        if(Month < ref.Month)
            return true;
        else if(Month == ref.Month)
        {
            if(Day < ref.Day)
                return true;
        }
    }
    return false;
}   

int main()
{   
    Date* ptr1 = new Date("31/12/2024");
    Date* ptr2 = new Date("31/12/2000");
    Date* ptr3 = new Date;                              // Default Date taken as "1/1/1" 

    (*ptr1)--;                                          // Use of --
    ptr1->printDate();

    (*ptr1)++;                                          // Use of ++
    ptr1->printDate();

    ptr3 = *ptr1 + 50;                                  // Use of +
    ptr3->printDate();
    
    *ptr3 -= 50;                                        // Use of -=
    ptr3->printDate();
    
    *ptr3 += 50;                                        // Use of +=
    ptr3->printDate();

    cout << (*ptr1 == *ptr2) << endl;                   // Use of == 
    cout << (*ptr1 == *ptr1) << endl;                   // Use of == 

    cout << (*ptr1 >= *ptr2) << endl;                   // Use of >= 
    cout << (*ptr1 > *ptr2) << endl;                    // Use of > 
    
    ptr3->setDate(23);                                  // Use of set & get functions 
    ptr3->setMonth(2);
    ptr3->setYear(1999);

    cout << ptr3->getDate() << "/" << ptr3->getMonth() << "/" << ptr3->getYear() << endl;

    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}