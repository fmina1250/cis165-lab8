#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double PI = 3.14159;
    int choice = 0;
    double radius = 0.0;
    double length = 0.0;
    double width = 0.0;
    double base = 0.0;
    double height = 0.0;
    double area = 0.0;

    // Menu
    cout << "Geometry Calculator" << endl;
    cout << "1. Calculate the Area of a Circle" << endl;
    cout << "2. Calculate the Area of a rectangle" << endl;
    cout << "3. Calculate the Area of a triangle" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the radius: ";
        cin >> radius;
        if (radius < 0) {
            cout << "Error: Radius cannot be negative." << endl;
            return 1;
        }
        area = PI * radius * radius;
        cout << fixed << setprecision(5);
        cout << "Area " << area << endl;
    }
    else if (choice == 2) {
        cout << "Enter the length: ";
        cin >> length;
        cout << "Enter the width: ";
        cin >> width;
        if (length < 0 || width < 0) {
            cout << "Error: Length and width cannot be negative." << endl;
            return 1;
        }
        area = length * width;
        cout << fixed << setprecision(1);
        cout << "Area " << area << endl;
    }
    else if (choice == 3) {
        cout << "Enter the base: ";
        cin >> base;
        cout << "Enter the height: ";
        cin >> height;
        if (base < 0 || height < 0) {
            cout << "Error: Base and height cannot be negative." << endl;
            return 1;
        }
        area = base * height * 0.5;
        cout << fixed << setprecision(1);
        cout << "Area " << area << endl;
    }
    else if (choice == 4) {
        return 0;
    }
    else {
        cout << "Error: Invalid choice. Please select a number between 1 and 4." << endl;
        return 1;
    }

    return 0;
}