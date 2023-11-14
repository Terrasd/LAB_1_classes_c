#ifndef CARMODELS_H
#define CARMODELS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class CarModels {
private:
    string name;
    int year;
    string color;
    int maxSpeed;
    string bodyType;
    double price;

    static vector<CarModels> cars;

public:
    // Конструкторы
    CarModels() : year(0), maxSpeed(0), price(0.0) {}
    CarModels(const string& n, int y, const string& c, int ms, const string& bt, double p)
        : name(n), year(y), color(c), maxSpeed(ms), bodyType(bt), price(p) {}
    CarModels(const CarModels& other)
        : name(other.name), year(other.year), color(other.color), maxSpeed(other.maxSpeed),
        bodyType(other.bodyType), price(other.price) {}

    // Методы get/set
    const string& getName() const { return name; }
    int getYear() const { return year; }
    const string& getColor() const { return color; }
    int getMaxSpeed() const { return maxSpeed; }
    const string& getBodyType() const { return bodyType; }
    double getPrice() const { return price; }

    void setName(const string& n) { name = n; }
    void setYear(int y) { year = y; }
    void setColor(const string& c) { color = c; }
    void setMaxSpeed(int ms) { maxSpeed = ms; }
    void setBodyType(const string& bt) { bodyType = bt; }
    void setPrice(double p) { price = p; }

    // Перегрузка оператора вывода для объекта класса в поток
    friend ostream& operator<<(ostream& os, const CarModels& car);

    // Перегрузка оператора ввода для объекта класса из потока
    friend istream& operator>>(istream& is, CarModels& car);

    // Статическая функция для считывания данных из файла в вектор объектов
    static vector<CarModels> readFromFile(const string& fileName);

    // Статическая функция для записи данных из вектора объектов в файл
    static void writeToFile(const vector<CarModels>& cars, const string& fileName);

    // Метод для выборки списка автомобилей определенного цвета, выпущенных после указанного года
    vector<CarModels> filterByColorAndYear(const string& color, int minYear, const vector<CarModels>& cars) const;

    // Метод для выборки списка автомобилей с указанным видом кузова
    vector<CarModels> filterByBodyType(const string& bodyType, const vector<CarModels>& cars) const;

    // Метод для выборки списка автомобилей, у которых максимальная скорость находится в указанном интервале
    vector<CarModels> filterBySpeedRange(int minSpeed, int maxSpeed, const vector<CarModels>& cars) const;
};

#endif CARMODELS_H