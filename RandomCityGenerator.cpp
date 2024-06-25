#include "pch.h"
#include "RandomCityGenerator.h"
#include <algorithm>
#include <random>
#include <string> 

RandomCityGenerator::RandomCityGenerator() {}

RandomCityGenerator::~RandomCityGenerator() {}



std::vector<std::string> RandomCityGenerator::RandomCities(std::vector<std::string>& strings) {

    // shuffle the list of city 
    std::random_device rd;
    std::default_random_engine g(rd());
    std::shuffle(strings.begin(), strings.end(), g);
    
    for (size_t i = strings.size() - 1; i > 0; --i)
    {
        std::uniform_int_distribution<size_t> dist(0, i);
        size_t j = dist(g);
        std::swap(strings[i], strings[j]);
    }

    return strings;
}

