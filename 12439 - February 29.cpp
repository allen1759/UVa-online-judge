#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> month;
void setMonth()
{
    month[ "January" ] = 1;
    month[ "February" ] = 2;
    month[ "March" ] = 3;
    month[ "April" ] = 4;
    month[ "May" ] = 5;
    month[ "June" ] = 6;
    month[ "July" ] = 7;
    month[ "August" ] = 8;
    month[ "September" ] = 9;
    month[ "October" ] = 10;
    month[ "November" ] = 11;
    month[ "December" ] = 12;
}
bool isLeap(int year)
{
    if( year % 400 == 0 ) return true;
    if( year % 100 == 0 ) return false;
    return year % 4 == 0;
}
int countLeap(int a, int b)
{
    int count = 0, x = a;
    while( x % 4 != 0 ) ++x;
    if( x <= b ) {
        count += (b-x)/4+1;
    } 

    x = a;
    while( x % 100 != 0 ) ++x;
    if( x <= b ) {
        count -= (b-x)/100+1;
    }

    x = a;
    while( x % 400 != 0 ) ++x;
    if( x <= b ) {
        count += (b-x)/400+1;
    }
    return count;
}
class Date
{
public:
    string mon;
    int day;
public:
    bool operator < (const Date &rhs) const
    {
        if( mon == rhs.mon ) return day < rhs.day;
        return month[mon] < month[rhs.mon];
    }
};
istream & operator >> (istream &is, Date &d)
{
    is >> d.mon;
    is >> d.day;
    return is;
}
//ostream & operator << (ostream &os, Date &d)
//{
//    os << d.mon << " ";
//    os << d.day << endl;
//    return os;
//}

int main()
{
    setMonth();
    int testcases;
    cin >> testcases;
    for(int test=0; test<testcases; ++test) {
        Date feb29, date; 
        feb29.mon = "February";
        feb29.day = 29;
        int front, back;
        cin >> date;
        cin.get();
        cin >> front;
        if(feb29 < date) ++front;
//        cout << date;
//        cout << (month[ feb29.mon ] < month[ date.mon ]) << endl << endl;
        cin >> date;
        cin.get();
        cin >> back;
        int count = 0;
        if(date < feb29) --back;
//        for(int i=front; i<=back; ++i) {
//            if( isLeap(i) ) ++count;
//        }
        
        cout << "Case " << test+1 << ": ";
        cout << countLeap(front, back) << endl;
    }

    return 0;
}
