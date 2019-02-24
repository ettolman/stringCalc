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
    int num1, num2;
    char delim;
    ss >> num1 >> delim >> num2;
    int num = num1 + num2;
    return num;
    
}

TEST_CASE("stringCalc returns 0 when no strings are passed"){
    REQUIRE(stringCalc("") == 0);
}

TEST_CASE("Passing a single number returns the value"){
    REQUIRE(stringCalc("2") == 2);
    REQUIRE(stringCalc("11") == 11);
    REQUIRE(stringCalc("123") == 123);
}

TEST_CASE("Two numbers, comma delimited, returns the sum"){
    REQUIRE(stringCalc("1,2") == 3);
    REQUIRE(stringCalc("22,13") == 35);
    REQUIRE(stringCalc("115,6") == 121);
}
