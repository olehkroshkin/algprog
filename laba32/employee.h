#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
private:
    string surname;
    string department;
    int hireYear;
    double salary;
    double bonus;

    void calculateBonus(int currentYear);

public:
    Employee();
    Employee(string s, string d, int y, double sal);

    void input(int currentYear);
    void display() const;

    int getExperience(int currentYear) const;
    double getBonus() const;

    void setSurname(const string& s);
    void setDepartment(const string& d);
    void setHireYear(int y);
    void setSalary(double sal);

    string getSurname() const;
    string getDepartment() const;
    int getHireYear() const;
    double getSalary() const;
};

double calculateAverageExperience(Employee employees[], int size, int currentYear);
void sortByExperience(Employee employees[], int size, int currentYear);

#endif
