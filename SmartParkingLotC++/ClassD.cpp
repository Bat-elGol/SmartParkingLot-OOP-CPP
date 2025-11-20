#include "ClassD.h"

ClassD::ClassD(const std::string& licensePlate, int entryTime)
    : ClassA(licensePlate, "Motorcycle", entryTime) {}

double ClassD::calculateCost() const
{
    if (exitTime > entryTime)
    {
        int parkedMinutes = exitTime - entryTime;
        double hours = parkedMinutes / 60.0;
        return hours * 1.0;
    }
    return 0.0;
}

std::string ClassD::toString() const
{
    int entryHours = entryTime / 60;
    int entryMinutes = entryTime % 60;
    int exitHours = exitTime / 60;
    int exitMinutes = exitTime % 60;

    return "ClassD: License Plate: " + licensePlate +
        ", Entry Time: " + (entryHours < 10 ? "0" : "") + std::to_string(entryHours) + ":" +
        (entryMinutes < 10 ? "0" : "") + std::to_string(entryMinutes) +
        ", Exit Time: " + (exitTime == 0 ? "N/A" : (exitHours < 10 ? "0" : "") + std::to_string(exitHours) + ":" +
            (exitMinutes < 10 ? "0" : "") + std::to_string(exitMinutes));
}
