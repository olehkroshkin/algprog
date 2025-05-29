#include "flat.h"
#include "people.h"
#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;

    // --- FLATS ---
    Flat flats[MAX];
    int flatCount = 3;
    flats[0] = Flat("Main St 12", 5);
    flats[1] = Flat("Green Ave 7", 2);
    flats[2] = Flat("Park Blvd 4", 1);

    Flat copyFlat = flats[1];
    insertAtStart(flats, flatCount, copyFlat);

    for (int i = 0; i < flatCount; ++i) {
        cout << "\nFlat " << i + 1 << ":\n";
        flats[i].display();
    }

    showFlatsByRooms(flats, flatCount, 2);
    showFlatsByAreaAndFloor(flats, flatCount, 40.0, 1, 3);

    // --- PEOPLE ---
    People people[MAX];
    int peopleCount;

    cout << "\nEnter number of people: ";
    cin >> peopleCount;

    for (int i = 0; i < peopleCount; ++i) {
        cout << "\nPerson " << i + 1 << ":\n";
        people[i].input();
    }

    People copied = people[0];
    insertAtStart(people, peopleCount, copied);

    cout << "\nAll People:\n";
    for (int i = 0; i < peopleCount; ++i)
        people[i].display();

    showEducatedAdults(people, peopleCount, 18);

    string genderToRemove;
    cout << "\nEnter gender to remove: ";
    cin >> genderToRemove;
    removeByGender(people, peopleCount, genderToRemove);

    cout << "\nRemaining people:\n";
    for (int i = 0; i < peopleCount; ++i)
        people[i].display();

    return 0;
}
