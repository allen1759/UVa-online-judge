#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int calDay(const int initSize, const long long int day)
{
    int finalSize = sqrt(2*day)-5;
    finalSize = max(finalSize, initSize);
    long long int currDay = initSize+finalSize;
    currDay *= finalSize-initSize+1;
    currDay /= 2;
    while( currDay < day ) {
        finalSize++;
        currDay = initSize+finalSize;
        currDay *= (finalSize-initSize+1);
        currDay /= 2;
    }
    return finalSize;
}
int main()
{
    int initSize;
    long long int day;
    while( cin >> initSize >> day ) {
        cout << calDay(initSize, day) << endl;
    }

    return 0;
}
