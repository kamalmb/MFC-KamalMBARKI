
#ifndef RANDOMCITYGENERATOR_H
#define RANDOMCITYGENERATOR_H
#pragma once
#include <afxstr.h>
#include <vector>
#include <string> 

class RandomCityGenerator
{
public:
    RandomCityGenerator();
    ~RandomCityGenerator();

    std::vector<std::string> RandomCities(std::vector<std::string>& strings);


};

#endif RANDOMCITYGENERATOR_H
