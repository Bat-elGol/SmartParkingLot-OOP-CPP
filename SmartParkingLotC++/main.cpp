#include "Utility.h"
#include "ClassB.h"
#include "ClassC.h"
#include "ClassD.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

void displayMenu();
int getCurrentTimeInMinutes();

void displayMenu()
{
    std::cout << "\n==== MENU ====\n";
    std::cout << "1. Vehicle Entry\n";
    std::cout << "2. Vehicle Exit (Display Exited Vehicles + Parking fee)\n";
    std::cout << "3. Display Parking Status\n";
    std::cout << "4. Save Parking Status to File\n";
    std::cout << "5. Load Parking Status from File\n";
    std::cout << "6. Save and Exit\n";
    std::cout << "Enter your choice: ";
}

int getCurrentTimeInMinutes()
{
    std::time_t now = std::time(nullptr);
    std::tm localTime;
    localtime_s(&localTime, &now);
    return localTime.tm_hour * 60 + localTime.tm_min;
}

int main()
{
    Utility::printWelcomeMessage();

    std::vector<ClassA*> vehicles;
    std::vector<ClassA*> exitedVehicles;
    std::vector<int> availableSpots = { 10, 3, 5 };
    std::string filename = "parking_data.txt";
    bool running = true;

    int totalParkingMinutes = 0;
    double totalParkingCost = 0.0;

    Utility::loadSummaryFromFile("summary_data.txt", totalParkingMinutes, totalParkingCost);
    while (running) {
        displayMenu();
        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter vehicle type (1 for Car, 2 for Truck, 3 for Motorcycle): ";
            int type;
            std::cin >> type;

            if (type < 1 || type > 3 || availableSpots[static_cast<std::size_t>(type - 1)] <= 0)
            {
                std::cout << "No parking spots available or invalid vehicle type.\n";
                break;
            }

            std::cout << "Enter license plate: ";
            std::string licensePlate;
            std::cin >> licensePlate;

            int entryTime = getCurrentTimeInMinutes();
            if (type == 1)
                vehicles.push_back(new ClassB(licensePlate, entryTime));
            else if (type == 2)
                vehicles.push_back(new ClassC(licensePlate, entryTime));
            else if (type == 3)
                vehicles.push_back(new ClassD(licensePlate, entryTime));

            availableSpots[static_cast<std::size_t>(type - 1)]--;
            break;
        }
        case 2:
        {
            std::cout << "Enter license plate of vehicle to exit: ";
            std::string licensePlate;
            std::cin >> licensePlate;

            int exitTime = getCurrentTimeInMinutes();

            auto it = std::find_if(vehicles.begin(), vehicles.end(), [&licensePlate](ClassA* vehicle)
                {
                return vehicle->getLicensePlate() == licensePlate;
                });

            if (it != vehicles.end())
            {
                (*it)->setExitTime(exitTime);

                if (dynamic_cast<ClassB*>(*it))
                {
                    availableSpots[0]++;
                }
                else if (dynamic_cast<ClassC*>(*it))
                {
                    availableSpots[1]++;
                }
                else if (dynamic_cast<ClassD*>(*it))
                {
                    availableSpots[2]++;
                }

                totalParkingMinutes += (*it)->getExitTime() - (*it)->getEntryTime();
                totalParkingCost += (*it)->calculateCost();

                exitedVehicles.push_back(*it);
                vehicles.erase(it);
                std::cout << "Vehicle exited.\n";
            }
            else
            {
                std::cout << "Vehicle not found.\n";
            }
            Utility::displayExitedVehicles(exitedVehicles);
            break;
        }
        case 3:
        {
            std::cout << "\n=== Parking Status ===\n";
            for (const auto& vehicle : vehicles)
            {
                vehicle->display();
                std::cout << "Cost: " << vehicle->calculateCost() << " NIS\n";
            }
            Utility::displayAvailableSpots(availableSpots);
            std::cout << "\n=== Summary of parking time and total cost of vehicle departure ===\n";
            std::cout << "Total Parking Time: " << totalParkingMinutes / 60 << " hours and " << totalParkingMinutes % 60 << " minutes\n";
            std::cout << "Total Parking Cost: " << totalParkingCost << " NIS\n";
            break;
        }
        case 4:
            Utility::saveToFile(vehicles, filename);
            break;
        case 5:
            Utility::loadFromFile(vehicles, filename, availableSpots);
            break;
        case 6:
            Utility::saveToFile(vehicles, filename);
            Utility::saveSummaryToFile("summary_data.txt", totalParkingMinutes, totalParkingCost);
            running = false;
            break;
        default:
            std::cout << "Invalid choice.\n";
        }
    }

    for (auto& vehicle : vehicles)
    {
        delete vehicle;
    }
    for (auto& vehicle : exitedVehicles)
    {
        delete vehicle;
    }

    return 0;
}
