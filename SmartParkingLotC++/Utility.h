#pragma once

#ifndef UTILITY_H
#define UTILITY_H
#include <vector> 
#include <ctime>
#include "ClassA.h" 


class Utility {
public:
    static void printWelcomeMessage();
    static void saveToFile(const std::vector<ClassA*>& vehicles, const std::string& filename);
    static void loadFromFile(std::vector<ClassA*>& vehicles, const std::string& filename, std::vector<int>& availableSpots);
    static void displayAvailableSpots(const std::vector<int>& availableSpots);
    static void displayExitedVehicles(const std::vector<ClassA*>& exitedVehicles);
    static void saveSummaryToFile(const std::string& filename, int totalMinutes, double totalCost);
    static void loadSummaryFromFile(const std::string& filename, int& totalMinutes, double& totalCost);

};

#endif
