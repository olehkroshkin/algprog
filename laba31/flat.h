#ifndef FLAT_H
#define FLAT_H

#include <string>
using namespace std;

class Flat {
private:
    string address;
    int floor;
    int rooms;
    double area;

public:
    Flat(); // def
    Flat(string addr, int fl); // param
    Flat(const Flat& other); // copy
    ~Flat(); // dest

    void input();
    void display() const;

    int getRooms() const;
    double getArea() const;
    int getFloor() const;
};

void showFlatsByRooms(Flat flats[], int size, int roomCount);
void showFlatsByAreaAndFloor(Flat flats[], int size, double maxArea, int floorMin, int floorMax);
void insertAtStart(Flat flats[], int& size, const Flat& f);

#endif
