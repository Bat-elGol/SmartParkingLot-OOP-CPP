#pragma once
#define CLASSC_H
#include "ClassA.h"

class ClassC : public ClassA {
public:

    ClassC(const std::string& licensePlate, int entryTime);
    double calculateCost() const override;
    std::string toString() const override;

};
