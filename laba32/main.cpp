#include "employee.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int CURRENT_YEAR = 2025;

    Employee emp1;
    cout << "Object emp1 (default constructor):\n";
    emp1.display();

    Employee emp2("Shevchenko", "Accounting", 2010, 12000);
    cout << "\nObject emp2 (with parameters):\n";
    emp2.display();

    const int SIZE = 3;
    Employee employees[SIZE];

    cout << "\nEnter data for " << SIZE << " employees:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "\nEmployee " << i + 1 << ":\n";
        employees[i].input(CURRENT_YEAR);
    }

    cout << "\nEmployee data:\n";
    cout << left << setw(15) << "Surname"
         << setw(15) << "Department"
         << setw(10) << "Year"
         << setw(10) << "Salary"
         << setw(10) << "Bonus" << '\n';

    for (int i = 0; i < SIZE; ++i) {
        employees[i].display();
    }

    double avgExperience = calculateAverageExperience(employees, SIZE, CURRENT_YEAR);
    cout << "\nAverage experience: " << avgExperience << " years\n";

    sortByExperience(employees, SIZE, CURRENT_YEAR);
    cout << "\nEmployees sorted by experience:\n";
    for (int i = 0; i < SIZE; ++i) {
        employees[i].display();
    }

    return 0;
}
