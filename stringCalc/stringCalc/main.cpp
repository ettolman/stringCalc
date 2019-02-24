//
//  main.cpp
//  stringCalc
//
//  Created by Erin Tolman on 2/24/19.
//  Copyright © 2019 Erin Tolman. All rights reserved.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <sstream>

int stringCalc(std::string numbers){
    if(numbers.length() == 0){
        return 0;
    }
    
    std::stringstream ss;
    ss << numbers;
    int num;
    ss >> num;
    return num;
    
}

TEST_CASE("stringCalc returns 0 when no strings are passed"){
    REQUIRE(stringCalc("") == 0);
}

TEST_CASE("Passing a single number returns the value"){
    REQUIRE(stringCalc("2") == 2);
}
