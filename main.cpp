#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    string firstName, lastName;
    char gender;
    int currentYear, yearOfBirth, monthOfBirth, dayOfBirth;
    float height, weight;
    cout << "Enter patient's firstName: ";
    getline(cin, firstName);
    cout << "Enter patient's lastName: ";
    getline(cin, lastName);
    cout << "Enter patient's gender(M/F): ";
    cin >> gender;
    cout << "Enter current year: ";
    cin >> currentYear;
    cout << "Enter patient's birth year: ";
    cin >> yearOfBirth;
    cout << "Enter patient's birth month: ";
    cin >> monthOfBirth;
    cout << "Enter patient's birth day: ";
    cin >> dayOfBirth;
    cout << "Enter patient's weight(lb): ";
    cin >> weight;
    cout << "Enter patient's height(in): ";
    cin >> height;
    HealthProfile P1(currentYear, firstName, lastName, gender, yearOfBirth, monthOfBirth, dayOfBirth, height, weight);
    cout << "***********************************\n";
    P1.showInformations();
}
