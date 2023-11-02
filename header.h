#include <iostream>
using namespace std;

#ifndef HEALTHPROFILE_H
#define HEALTHPROFILE_H

class HealthProfile
{
private:
    string firstName, lastName;
    char gender;
    int currentYear, yearOfBirth, monthOfBirth, dayOfBirth;
    float height, weight;

public:
    HealthProfile(int cYear, string fName, string lName, char uGender, int yearOfBirth, int monthOfBirth, int dayOfBirth, float height, float weight);
    void setCurrentYear(int year);
    int getCurrentYear() const;
    void setFirstName(string fName);
    string getFirstName() const;
    void setLastName(string lName);
    string getLastName() const;
    void setGender(char uGender);
    string getGender() const;
    void setYearOfBirth(int yBirth);
    int getYearOfBirth() const;
    void setMonthOfBirth(int mBirth);
    int getMonthOfBirth() const;
    void setDayOfBirth(int dBirth);
    int getDayOfBirth() const;
    void setWeight(float Weight);
    float getWeight() const;
    void setHeight(float Height);
    float getHeight() const;
    int ageCalculator(int currentYear, int birthYear);
    float BMICalculator(float Weight, float Height);
    int MHRCalculator(int Age);
    string THRCalculator(int MHR);
    void showInformations();
};

#endif