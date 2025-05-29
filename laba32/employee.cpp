#include "employee.h"
#include <iostream>
#include <iomanip>
using namespace std;

Employee::Employee() : surname(""), department(""), hireYear(2000), salary(0.0), bonus(0.0) {}

Employee::Employee(string s, string d, int y, double sal)
    : surname(s), department(d), hireYear(y), salary(sal) {
    calculateBonus(2025);
}

void Employee::calculateBonus(int currentYear) {
    int experience = currentYear - hireYear;
    if (experience < 10) bonus = 0.1 * salary;
    else if (experience <= 20) bonus = 0.25 * salary;
    else bonus = 0.4 * salary;
}

void Employee::input(int currentYear) {
    cout << "Enter surname: "; cin >> surname;
    cout << "Enter department: "; cin >> department;
    cout << "Enter year of employment: "; cin >> hireYear;
    cout << "Enter salary: "; cin >> salary;
    calculateBonus(currentYear);
}

void Employee::display() const {
    cout << left << setw(15) << surname
         << setw(15) << department
         << setw(10) << hireYear
         << setw(10) << salary
         << setw(10) << bonus << '\n';
}

int Employee::getExperience(int currentYear) const {
    return currentYear - hireYear;
}

double Employee::getBonus() const {
    return bonus;
}

void Employee::setSurname(const string& s) { surname = s; }
void Employee::setDepartment(const string& d) { department = d; }
void Employee::setHireYear(int y) { hireYear = y; }
void Employee::setSalary(double sal) { salary = sal; calculateBonus(2025); }

string Employee::getSurname() const { return surname; }
string Employee::getDepartment() const { return department; }
int Employee::getHireYear() const { return hireYear; }
double Employee::getSalary() const { return salary; }

double calculateAverageExperience(Employee employees[], int size, int currentYear) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += employees[i].getExperience(currentYear);
    }
    return static_cast<double>(total) / size;
}

void sortByExperience(Employee employees[], int size, int currentYear) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (employees[j].getExperience(currentYear) > employees[j + 1].getExperience(currentYear))
                swap(employees[j], employees[j + 1]);
}
