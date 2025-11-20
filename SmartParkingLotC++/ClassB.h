#pragma once 
#define CLASSB_H
#include "ClassA.h"

class ClassB : public ClassA {
public:

    ClassB(const std::string& licensePlate, int entryTime);
    double calculateCost() const override;
    std::string toString() const override;

};
