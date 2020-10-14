/*Name john michael

Course 1437

Date 10/14/2020
*/
//Assignment Description:
/*
Design a class called NumDays. store  values
that represents a number of work hours
 convert it to a number of days.
 For example, 8 hours would be converted to 1 day,
 12 hours would be converted to 1.5 days,
  18 hours would be converted to 2.25 days.
  The class should have a constructor that accepts a number of hours,
as well as member functions for storing and retrieving the hours and days.
The class should also have the following overloaded operators */
#include <iostream>
#include <string>
using namespace std;
//class declaration
class NumDays {

private:
    double hours;
    double days;

public:
 //constructor
 NumDays(double h = 0) {

        hours = h;

        days = h / (8.00);
 }

    //getter functions

    double getHours() {

        return hours;
    }
    double getDays() {

        return days;
    }

    //setter functions

    void setHours(double h) {

        hours = h;

        days = h / (8.00);

    }

    void setDays(double d) {

        days = d;

        hours = d * (8.0);

    }

    //overload + operator

    double operator+ (const NumDays& right) {

        return hours + right.hours;

    }

    //overload - operator

    double operator- (const NumDays& right) {

        //check if subtraction will give negative value

        if (hours < right.hours) {

            cout << "ERROR! Cannot subtract! Now terminating!\n";

            exit(0);

        }

        return hours - right.hours;

    }

    //overload prefix ++ operator

    NumDays operator++() {

        //pre-increment hours member

        ++hours;

        //update days member

        days = hours / (8.00);

        //return modified calling object

        return *this;

    }

    //overload postfix ++ operator

    NumDays operator++(int) {

        //post-increment hours member

        hours++;

        //update days member

        days = hours / (8.0);

        //return modified calling object

        return *this;

    }

    //overload prefix -- operator

    NumDays operator--() {

        //pre-decrement hours member

        --hours;

        //update days member

        days = hours / (8.00);

        //return modified calling object

        return *this;

    }

    //overload postfix -- operator

    NumDays operator--(int) {

        //post-decrement hours member

        hours--;

        //update days member

        days = hours / (8.00);

        //return modified calling object

        return *this;

    }

};

int main()

{
    // first object

    cout << "Creating object with 12 hours...\n";

    NumDays Week1(12);

    cout << Week1.getHours() << " hours = " << Week1.getDays() << " days.\n";

    //create second object

    cout << "\nCreating object with 18 hours...\n";

    NumDays obj2(18);

    cout << obj2.getHours() << " hours = " << obj2.getDays() << " days.\n";

    //check overloaded operator

    cout << endl << "Adding hours... " << Week1 + obj2 << " hours.\n";

    //check overloaded operator -

    cout << endl << "Subtracting hours... " << obj2 - Week1 << " hours.\n\n";

    //checking the post increment operator

    cout << "Pre- and post-incrementing first object...\n";

    ++Week1;

    cout << Week1.getHours() << " hours = " << Week1.getDays() << " days.\n";

    Week1++;

    cout << Week1.getHours() << " hours = " << Week1.getDays() << " days.\n";

    //test overloaded -- operators

    cout << "\nPre- and post-decrementing second object...\n";

    --obj2;

    cout << obj2.getHours() << " hours = " << obj2.getDays() << " days.\n";

    obj2--;

    cout << obj2.getHours() << " hours = " << obj2.getDays() << " days.\n";

    return 0;

}