#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
using namespace std;

class People {
private:
    string surname;
    string country;
    string gender;
    string education;
    int birthYear;
    int age;

public:
    People(); // def
    People(const People& other); // copy
    ~People(); // dest

    void input();
    void display() const;
    string getEducation() const;
    int getAge() const;
    string getGender() const;
};

void showEducatedAdults(People people[], int size, int minAge);
void removeByGender(People people[], int& size, const string& gender);
void insertAtStart(People people[], int& size, const People& person);

#endif

