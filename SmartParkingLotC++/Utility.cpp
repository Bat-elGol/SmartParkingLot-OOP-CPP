#include "Utility.h"
#include "ClassB.h"
#include "ClassC.h"
#include "ClassD.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>  

void Utility::printWelcomeMessage()
{
    std::cout << "Welcome to the Smart Parking System!" << std::endl;
}

void Utility::saveToFile(const std::vector<ClassA*>& vehicles, const std::string& filename)
{
    std::ofstream outFile(filename);
    if (outFile.is_open())
    {
        for (const auto& vehicle : vehicles)
        {
            outFile << vehicle->toString() << std::endl;
        }
        outFile.close();
        std::cout << "Data successfully saved to file: " << filename << std::endl;
    }
    else
    {
        std::cerr << "Error: The file cannot be opened: " << filename << std::endl;
    }
}

void Utility::loadFromFile(std::vector<ClassA*>& vehicles, const std::string& filename, std::vector<int>& availableSpots)
{
    std::ifstream inFile(filename);
    if (inFile.is_open())
    {
        std::string line;
        while (std::getline(inFile, line))
        {
            std::istringstream iss(line);
            std::string type, licensePlate;
            std::string entryTimeStr, exitTimeStr;
            int entryTime = 0, exitTime = 0;

            if (line.find("ClassB:") != std::string::npos)
            {
                type = "Car";
            }
            else if (line.find("ClassC:") != std::string::npos)
            {
                type = "Truck";
            }
            else if (line.find("ClassD:") != std::string::npos)
            {
                type = "Motorcycle";
            }
            else
            {
                std::cerr << "Unknown vehicle type in line: " << line << std::endl;
                continue;
            }
            size_t licenseStart = line.find("License Plate: ") + 15;
            size_t entryStart = line.find("Entry Time: ") + 12;
            size_t exitStart = line.find("Exit Time: ") + 11;

            licensePlate = line.substr(licenseStart, line.find(",", licenseStart) - licenseStart);

            entryTimeStr = line.substr(entryStart, 5);
            int entryHours = std::stoi(entryTimeStr.substr(0, 2));
            int entryMinutes = std::stoi(entryTimeStr.substr(3, 2));
            entryTime = entryHours * 60 + entryMinutes;

            if (line.find("Exit Time: N/A") == std::string::npos)
            {
                exitTimeStr = line.substr(exitStart, 5);
                int exitHours = std::stoi(exitTimeStr.substr(0, 2));
                int exitMinutes = std::stoi(exitTimeStr.substr(3, 2));
                exitTime = exitHours * 60 + exitMinutes;
            }

            ClassA* vehicle = nullptr;
            if (type == "Car")
            {
                vehicle = new ClassB(licensePlate, entryTime);
                availableSpots[0]--;
            }
            else if (type == "Truck")
            {
                vehicle = new ClassC(licensePlate, entryTime);
                availableSpots[1]--;
            }
            else if (type == "Motorcycle")
            {
                vehicle = new ClassD(licensePlate, entryTime);
                availableSpots[2]--;
            }

            if (vehicle)
            {
                vehicle->setExitTime(exitTime);
                vehicles.push_back(vehicle);
            }
        }
        inFile.close();
        std::cout << "Data loaded successfully from file: " << filename << std::endl;
    }
    else
    {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
    }
}


void Utility::displayAvailableSpots(const std::vector<int>& availableSpots)
{
    std::cout << "\n=== Available Parking Spots ===" << std::endl;
    std::cout << "Cars: " << availableSpots[0] << "/10" << std::endl;
    std::cout << "Trucks: " << availableSpots[1] << "/3" << std::endl;
    std::cout << "Motorcycles: " << availableSpots[2] << "/5" << std::endl;
}

void Utility::displayExitedVehicles(const std::vector<ClassA*>& exitedVehicles)
{
    std::cout << "\n=== Exited Vehicles ===" << std::endl;
    for (const auto& vehicle : exitedVehicles)
    {
        vehicle->display();
        std::cout << "Cost Paid: " << vehicle->calculateCost() << " NIS" << std::endl;
    }
}

void Utility::saveSummaryToFile(const std::string& filename, int totalMinutes, double totalCost)
{
    std::ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << totalMinutes << std::endl;
        outFile << totalCost << std::endl;
        outFile.close();
    }
    else
    {
        std::cerr << "Error: Unable to save summary data to file." << std::endl;
    }
}

void Utility::loadSummaryFromFile(const std::string& filename, int& totalMinutes, double& totalCost)
{
    std::ifstream inFile(filename);
    if (inFile.is_open())
    {
        inFile >> totalMinutes;
        inFile >> totalCost;
        inFile.close();
    }
    else
    {
        std::cerr << "Warning: No summary data file found. Initializing to zero." << std::endl;
        totalMinutes = 0;
        totalCost = 0.0;
    }
}
