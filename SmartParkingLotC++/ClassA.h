#pragma once
#define CLASSA_H
#include <string>
#include <iostream>
#include <vector>


class ClassA {
protected:
    std::string licensePlate;
    std::string vehicleType;
    int entryTime;
    int exitTime;

public:
    ClassA(const std::string& licensePlate, const std::string& vehicleType, int entryTime);

    virtual double calculateCost() const = 0;
    virtual std::string toString() const = 0;
    void setExitTime(int exitTime);
    int getEntryTime() const;
    int getExitTime() const;
    virtual void display() const;
    std::string getLicensePlate() const;

    virtual ~ClassA();

    friend std::vector<ClassA*>& operator+(std::vector<ClassA*>& vehicles, ClassA* vehicle);
    friend std::vector<ClassA*>& operator-(std::vector<ClassA*>& vehicles, std::vector<ClassA*>& exitedVehicles);
};
