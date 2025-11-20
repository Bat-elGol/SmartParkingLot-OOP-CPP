#include "ClassA.h"
#include "Utility.h"
#include <algorithm>
#include <vector>
#include <iostream>

ClassA::ClassA(const std::string& licensePlate, const std::string& vehicleType, int entryTime)
    : licensePlate(licensePlate), vehicleType(vehicleType), entryTime(entryTime), exitTime(0) {}

void ClassA::setExitTime(int exitTime)
{
    this->exitTime = exitTime;
}


int ClassA::getEntryTime() const
{
    return entryTime;
}

int ClassA::getExitTime() const
{
    return exitTime;
}


void ClassA::display() const
{
    int entryHours = entryTime / 60;
    int entryMinutes = entryTime % 60;

    std::cout << "License Plate: " << licensePlate
        << ", Type: " << vehicleType
        << ", Entry Time: " << (entryHours < 10 ? "0" : "") << entryHours
        << ":" << (entryMinutes < 10 ? "0" : "") << entryMinutes;

    if (exitTime > 0)
    {
        int exitHours = exitTime / 60;
        int exitMinutes = exitTime % 60;
        std::cout << ", Exit Time: " << (exitHours < 10 ? "0" : "") << exitHours
            << ":" << (exitMinutes < 10 ? "0" : "") << exitMinutes;
    }
    else
    {
        std::cout << ", Exit Time: N/A";
    }

    std::cout << std::endl;
}


std::string ClassA::getLicensePlate() const
{
    return licensePlate;
}


ClassA::~ClassA() {}

// מימוש אופרטור +
std::vector<ClassA*>& operator+(std::vector<ClassA*>& vehicles, ClassA* vehicle)
{
    vehicles.push_back(vehicle);
    return vehicles;
}

// מימוש אופרטור -
std::vector<ClassA*>& operator-(std::vector<ClassA*>& vehicles, std::vector<ClassA*>& exitedVehicles)
{
    if (!vehicles.empty())
    {
        exitedVehicles.push_back(vehicles.back());
        vehicles.pop_back();
    }
    return vehicles;
}
