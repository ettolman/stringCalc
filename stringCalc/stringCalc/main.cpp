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
    
    int num1;
    int num2 = 0;
    char delim;
    std::string restOfStr;
    std::stringstream numString;
    
    numString << numbers;
    numString >> num1 >> delim >> num2;
    
    int numTotal = num1 + num2;
    
    return numTotal;
    
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

TEST_CASE("Two numbers, newline delimited, returns the sum"){
    REQUIRE(stringCalc("1\n2") == 3);
}
