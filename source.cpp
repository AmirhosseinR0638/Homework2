#include <iostream>
#include <iomanip>
#include "header.h"

using namespace std;
HealthProfile::HealthProfile(int cYear, string fName, string lName, char uGender, int yearOfBirth, int monthOfBirth, int dayOfBirth, float height, float weight)
{
    setCurrentYear(cYear);
    setFirstName(fName);
    setLastName(lName);
    setGender(uGender);
    setYearOfBirth(yearOfBirth);
    setMonthOfBirth(monthOfBirth);
    setDayOfBirth(dayOfBirth);
    setWeight(weight);
    setHeight(height);
}
void HealthProfile::setCurrentYear(int cYear)
{
    if (cYear <= 1402)
    {
        currentYear = cYear;
    }
    else
    {
        currentYear = 1402;
    }
}
int HealthProfile::getCurrentYear() const
{
    return currentYear;
}
void HealthProfile::setFirstName(string fName)
{
    if (fName.size() >= 3 && fName.size() <= 14)
    {
        firstName = fName;
    }
    else
    {
        firstName = "INVALID";
    }
}
string HealthProfile::getFirstName() const
{
    return firstName;
}
void HealthProfile::setLastName(string lName)
{
    if (lName.size() >= 4 && lName.size() <= 21)
    {
        lastName = lName;
    }
    else
    {
        lastName = "INVALID";
    }
}
string HealthProfile::getLastName() const
{
    return lastName;
}
void HealthProfile::setGender(char uGender)
{
    if (uGender == 'M' || uGender == 'm' || uGender == 'F' || uGender == 'f')
    {
        gender = uGender;
    }
    else
    {
        gender = 'I';
    }
}
string HealthProfile::getGender() const
{
    if (gender == 'M' || gender == 'm')
    {
        return "Male";
    }
    else if (gender == 'F' || gender == 'f')
    {
        return "Female";
    }
    else
    {
        return "Invalid";
    }
}
void HealthProfile::setYearOfBirth(int yBirth)
{
    if (yBirth >= 1300)
    {
        yearOfBirth = yBirth;
        HealthProfile::ageCalculator(currentYear, yBirth);
    }
    else
    {
        yearOfBirth = 1360;
        HealthProfile::ageCalculator(currentYear, yBirth);
    }
}
int HealthProfile::getYearOfBirth() const
{
    return yearOfBirth;
}
void HealthProfile::setMonthOfBirth(int mBirth)
{
    if (mBirth <= 12 && mBirth >= 1)
    {
        monthOfBirth = mBirth;
    }
    else
    {
        monthOfBirth = -1;
    }
}
int HealthProfile::getMonthOfBirth() const
{
    return monthOfBirth;
}
void HealthProfile::setDayOfBirth(int dBirth)
{
    if (monthOfBirth >= 1 && monthOfBirth <= 6)
    {
        if (dBirth >= 1 && dBirth <= 31)
        {
            dayOfBirth = dBirth;
        }
        else
        {
            dayOfBirth = -1;
        }
    }
    else if (monthOfBirth >= 7 && monthOfBirth <= 11)
    {
        if (dBirth >= 1 && dBirth <= 30)
        {
            dayOfBirth = dBirth;
        }
        else
        {
            dayOfBirth = -1;
        }
    }
    else if (monthOfBirth == 12)
    {
        if (dBirth >= 1 && dBirth <= 29)
        {
            dayOfBirth = dBirth;
        }
        else
        {
            dayOfBirth = -1;
        }
    }
    else
    {
        dayOfBirth = -1;
    }
}
int HealthProfile::getDayOfBirth() const
{
    return dayOfBirth;
}
void HealthProfile::setWeight(float Weight)
{
    if (Weight > 0)
    {
        weight = Weight;
    }
    else
    {
        weight = 30;
    }
}
float HealthProfile::getWeight() const
{
    return weight;
}
void HealthProfile::setHeight(float Height)
{
    if (Height > 0)
    {
        height = Height;
    }
    else
    {
        height = 60;
    }
}
float HealthProfile::getHeight() const
{
    return height;
}
int HealthProfile::ageCalculator(int curentYear, int birthYear)
{
    int result = curentYear - birthYear;
    HealthProfile::MHRCalculator(result);
    return result;
}
float HealthProfile::BMICalculator(float weight, float height)
{
    return weight * 703 / (height * height);
}
int MHRresult = 0;
int HealthProfile::MHRCalculator(int Age)
{
    MHRresult = 220 - Age;
    return MHRresult;
}
void HealthProfile::showInformations()
{
    getCurrentYear();
    cout << "#HEALTH PROFILE OF PATIENT#" << endl;
    cout << "Patient's firstName: " << getFirstName() << endl;
    cout << "Patient's lastName: " << getLastName() << endl;
    cout << "Patient's gender: " << getGender() << endl;
    cout << "Patient's weight: " << getWeight() << " lbs" << endl;
    cout << "Patient's height: " << getHeight() << " in" << endl;
    cout << "Patient's birth date: " << getYearOfBirth() << '/' << getMonthOfBirth() << '/' << getDayOfBirth() << endl;
    int userAge = getCurrentYear() - getYearOfBirth();
    cout << "Patient's age: " << userAge << " years old" << endl;
    float BMIresult = BMICalculator(weight, height);
    cout << "BMI of Patient: " << setprecision(4) << BMIresult << " KG/m^2; ";
    if (BMIresult <= 18.5)
    {
        cout << "Patient is UNDERWEIGHT" << endl;
    }
    else if (BMIresult > 18.5 && BMIresult < 25)
    {
        cout << "Patient is NORMAL" << endl;
    }
    else if (BMIresult >= 25 && BMIresult < 30)
    {
        cout << "Patient is OVERWEIGHT" << endl;
    }
    else
    {
        cout << "Patient is OBESE" << endl;
    }
    cout << "Maximum Heartbeat Rate of patient: " << MHRCalculator(userAge) << " bpm" << endl;
    cout << "Target Heartbeat Rate of patient: Between " << static_cast<int>(MHRresult * .50) << " bpm and " << static_cast<int>(MHRresult * .85) << " bpm";
}