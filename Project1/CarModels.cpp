#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "CarModels.h"
using namespace std;

ostream& operator<<(ostream& os, const CarModels& car) {
    os << car.name << " " << car.year << " " << car.color << " " << car.maxSpeed << " "
        << car.bodyType << " " << car.price;
    return os;
}

istream& operator>>(istream& is, CarModels& car) {
    is >> car.name >> car.year >> car.color >> car.maxSpeed >> car.bodyType >> car.price;
    return is;
}

vector<CarModels> CarModels::readFromFile(const string& fileName) {
    vector<CarModels> cars;
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file " << fileName << std::endl;
        return cars;  // ���������� ������ ������ � ������ ������
    }

    int numRecords;
    inputFile >> numRecords;

    cars.reserve(numRecords);  // ����������� ����� � �������, ����� �������� ������ ��������� ������

    for (int i = 0; i < numRecords; ++i) {
        CarModels car;
        inputFile >> car;
        cars.push_back(car);
    }

    inputFile.close();
    return cars;
}

void CarModels::writeToFile(const vector<CarModels>& cars, const string& fileName) {
    ofstream outputFile(fileName, ios::trunc);  // ��������� ���� ��� ������, ������� ��� �� ����

    if (!outputFile.is_open()) {
        cerr << "Error opening file " << fileName << endl;
        return;
    }

    // ���������� ������� ���������� ������� � ������ ������ �����
    outputFile << cars.size() << endl;

    // ���������� ������� � ����
    for (const auto& car : cars) {
        outputFile << car << endl;
    }

    outputFile.close();
}

vector<CarModels> CarModels::filterByColorAndYear(const string& color, int minYear, const vector<CarModels>& cars) const {
    vector<CarModels> result;
    for (const auto& car : cars) {
        if (car.getColor() == color && car.getYear() > minYear) {
            result.push_back(car);
        }
    }
    return result;
}

vector<CarModels> CarModels::filterByBodyType(const string& bodyType, const vector<CarModels>& cars) const {
    vector<CarModels> result;
    for (const auto& car : cars) {
        if (car.getBodyType() == bodyType) {
            result.push_back(car);
        }
    }
    return result;
}

vector<CarModels> CarModels::filterBySpeedRange(int minSpeed, int maxSpeed, const vector<CarModels>& cars) const {
    vector<CarModels> result;
    for (const auto& car : cars) {
        if (car.getMaxSpeed() >= minSpeed && car.getMaxSpeed() <= maxSpeed) {
            result.push_back(car);
        }
    }
    return result;
}