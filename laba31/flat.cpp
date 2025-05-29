#include "flat.h"
#include <iostream>
using namespace std;

Flat::Flat() : address(""), floor(0), rooms(2), area(55.0) {}

Flat::Flat(string addr, int fl) : address(addr), floor(fl), rooms(2), area(55.0) {}

Flat::Flat(const Flat& other) {
    address = other.address;
    floor = other.floor;
    rooms = other.rooms;
    area = other.area;
}

Flat::~Flat() {
    cout << "Flat at " << address << " destroyed.\n";
}

void Flat::input() {
    cout << "Enter address: ";
    getline(cin >> ws, address);
    cout << "Enter floor: ";
    cin >> floor;
    cout << "Enter rooms: ";
    cin >> rooms;
    cout << "Enter area: ";
    cin >> area;
}

void Flat::display() const {
    cout << "Address: " << address
         << ", Floor: " << floor
         << ", Rooms: " << rooms
         << ", Area: " << area << " sq.m\n";
}

int Flat::getRooms() const { return rooms; }
double Flat::getArea() const { return area; }
int Flat::getFloor() const { return floor; }

void showFlatsByRooms(Flat flats[], int size, int roomCount) {
    cout << "\nFlats with " << roomCount << " rooms:\n";
    for (int i = 0; i < size; ++i)
        if (flats[i].getRooms() == roomCount)
            flats[i].display();
}

void showFlatsByAreaAndFloor(Flat flats[], int size, double maxArea, int floorMin, int floorMax) {
    cout << "\nFlats with area <= " << maxArea << " and floor in range [" << floorMin << ", " << floorMax << "]:\n";
    for (int i = 0; i < size; ++i)
        if (flats[i].getArea() <= maxArea && flats[i].getFloor() >= floorMin && flats[i].getFloor() <= floorMax)
            flats[i].display();
}

void insertAtStart(Flat flats[], int& size, const Flat& f) {
    for (int i = size; i > 0; --i)
        flats[i] = flats[i - 1];
    flats[0] = f;
    ++size;
}
