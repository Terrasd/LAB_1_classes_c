#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "CarModels.h"
using namespace std;

// Функция для выполнения операции сортировки
void sortCarsByYear(vector<CarModels>& cars) {
    sort(cars.begin(), cars.end(), [](const CarModels& a, const CarModels& b) {
        return a.getYear() < b.getYear();
        });
}

int showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Read data from file\n";
    cout << "2. Display cars\n";
    cout << "3. Add a new car\n";
    cout << "4. Sort cars by year\n";
    cout << "5. Write data to file\n";
    cout << "6. Filter cars by color and year\n";
    cout << "7. Filter cars by body type\n";
    cout << "8. Filter cars by speed range\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;
    return choice;
}

int main() {
    string fileName;
    cout << "Enter File Name: ";
    cin >> fileName;

    CarModels carModels;
    vector<CarModels> cars;

    bool exitProgram = false;
    while (!exitProgram) {
        int choice = showMenu();

        switch (choice) {
        case 1:  // Read data from file
            cars = CarModels::readFromFile(fileName);
            cout << "Data read from file.\n";
            break;

        case 2:  // Display cars
            for (const auto& car : cars) {
                cout << car << endl;
            }
            break;

        case 3: {  // Add a new car
            CarModels newCar;
            cout << "Enter car details(name, year, color, maxSpeed, bodyType, price):\n";
            cin >> newCar;
            cars.push_back(newCar);
            cout << "Car added.\n";
            break;
        }

        case 4:  // Sort cars by year
            sortCarsByYear(cars);
            cout << "Cars sorted by year.\n";
            break;

        case 5:  // Write data to file
            CarModels::writeToFile(cars, fileName);
            cout << "Data written to file.\n";
            break;

        case 6: {  // Filter cars by color and year
            string filterColor;
            int filterYear;
            cout << "Enter color: ";
            cin >> filterColor;
            cout << "Enter min year: ";
            cin >> filterYear;
            vector<CarModels> filteredCars = carModels.filterByColorAndYear(filterColor, filterYear, cars);
            for (const auto& car : filteredCars) {
                cout << car << endl;
            }
            break;
        }

        case 7: {  // Filter cars by body type
            string filterBodyType;
            cout << "Enter body type: ";
            cin >> filterBodyType;
            vector<CarModels> filteredCars = carModels.filterByBodyType(filterBodyType, cars);
            for (const auto& car : filteredCars) {
                cout << car << endl;
            }
            break;
        }

        case 8: {  // Filter cars by speed range
            int minSpeed, maxSpeed;
            cout << "Enter min speed: ";
            cin >> minSpeed;
            cout << "Enter max speed: ";
            cin >> maxSpeed;
            vector<CarModels> filteredCars = carModels.filterBySpeedRange(minSpeed, maxSpeed, cars);
            for (const auto& car : filteredCars) {
                cout << car << endl;
            }
            break;
        }

        case 0:  // Exit
            exitProgram = true;
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}