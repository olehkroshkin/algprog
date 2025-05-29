#include "people.h"
#include <iostream>
using namespace std;

People::People() : surname(""), country("Ukraine"), gender(""), education(""), birthYear(2006), age(0) {}

People::People(const People& other) {
    surname = other.surname;
    country = other.country;
    gender = other.gender;
    education = other.education;
    birthYear = other.birthYear;
    age = other.age;
}

People::~People() {
    cout << "Person " << surname << " destroyed.\n";
}

void People::input() {
    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter country: ";
    cin >> country;
    cout << "Enter gender: ";
    cin >> gender;
    cout << "Enter education: ";
    cin >> education;
    cout << "Enter birth year: ";
    cin >> birthYear;
    age = 2025 - birthYear;
}

void People::display() const {
    cout << "Surname: " << surname
         << ", Country: " << country
         << ", Gender: " << gender
         << ", Education: " << education
         << ", Birth Year: " << birthYear
         << ", Age: " << age << '\n';
}

string People::getEducation() const { return education; }
int People::getAge() const { return age; }
string People::getGender() const { return gender; }

void showEducatedAdults(People people[], int size, int minAge) {
    cout << "\nPeople with higher education and age > " << minAge << ":\n";
    for (int i = 0; i < size; ++i)
        if (people[i].getEducation() == "higher" && people[i].getAge() > minAge)
            people[i].display();
}

void removeByGender(People people[], int& size, const string& gender) {
    int j = 0;
    for (int i = 0; i < size; ++i)
        if (people[i].getGender() != gender)
            people[j++] = people[i];
    size = j;
}

void insertAtStart(People people[], int& size, const People& person) {
    for (int i = size; i > 0; --i)
        people[i] = people[i - 1];
    people[0] = person;
    ++size;
}
