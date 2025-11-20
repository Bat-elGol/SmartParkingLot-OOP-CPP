#pragma once
#define CLASSD_H
#include "ClassA.h"

class ClassD : public ClassA {
public:

    ClassD(const std::string& licensePlate, int entryTime);
    double calculateCost() const override;
    std::string toString() const override;

};
