#include <iostream>

using namespace std;


double surfaceArea(double length, double width = 1.0, double height = 1.0) {
    return 2 * (length * width + length * height + width * height);
}

int main() {
  
    double area1 = surfaceArea(3.0, 4.0, 5.0);
    cout << "Area of surface (3, 4, 5): " << area1 << endl;

    
    double area2 = surfaceArea(3.0, 4.0);
    cout << "Area of surface (3, 4, h=1): " << area2 << endl;

    
    double area3 = surfaceArea(3.0);
    cout << "Area of surface (3, w=1, h=1): " << area3 << endl;

    return 0;
}
