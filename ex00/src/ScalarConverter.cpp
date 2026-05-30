/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:00:17 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/30 16:09:54 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
    // std::cout<<"ScalarConverter Default constructor called\n"
}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy){
    // std::cout<<"ScalarConverter Copy constructor called\n"
    (void)cpy;
}

ScalarConverter::~ScalarConverter(){
    // std::cout<<"ScalarConverter Destructor called\n"
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& source){
    // std::cout<<"ScalarConverter operator '=' called\n"
    (void)source;
    return *this;
}

void convertChar(const std::string& literal){
    int asInt;
    float asFloat;
    double asDouble;
    char asChar = literal[0];

    asInt = static_cast<int>(literal[0]);
    asFloat = static_cast<float>(asInt);
    asDouble = static_cast<double>(asInt);
    std::cout<<"char : "<<asChar<<std::endl;
    std::cout<<"int : "<<asInt<<std::endl;
    std::cout<<"float : "<<std::fixed<<std::setprecision(1)<<asFloat<<"f"<<std::endl;
    std::cout<<"double : "<<asDouble<<std::endl;
}

void convertInt(const std::string& literal){
    int asInt = atoi(literal.c_str());
    float asFloat;
    double asDouble;
    char asChar;

    asChar = static_cast<char>(asInt);
    
    if (asInt > 255)
        std::cout<<"char : impossible"<<std::endl;
    if (asInt < 32 || asInt > 127){
        std::cout<<"char : not displayable"<<std::endl;
    }
    else
        std::cout<<"char : "<<asChar<<std::endl;
    asFloat = static_cast<float>(asInt);
    asDouble = static_cast<double>(asInt);
    std::cout<<"int : "<<asInt<<std::endl;
    std::cout<<"float : "<<std::fixed<<std::setprecision(1)<<asFloat<<"f"<<std::endl;
    std::cout<<"double : "<<asDouble<<std::endl;
}

void convertFloat(const std::string& literal){
    int asInt = atoi(literal.c_str());
    float asFloat;
    double asDouble;
    char asChar;

    asChar = static_cast<char>(asInt);
    
    if (asInt > 255)
        std::cout<<"char : impossible"<<std::endl;
    if (asInt < 32 || asInt > 127){
        std::cout<<"char : not displayable"<<std::endl;
    }
    else
        std::cout<<"char : "<<asChar<<std::endl;
    asFloat = static_cast<float>(asInt);
    asDouble = static_cast<double>(asInt);
    std::cout<<"int : "<<asInt<<std::endl;
    std::cout<<"float : "<<std::fixed<<std::setprecision(1)<<asFloat<<"f"<<std::endl;
    std::cout<<"double : "<<asDouble<<std::endl;
}

int isFloat(std::string str){
    int countDot = 0;
    int countF = 0;
    
    for (size_t i = 0; i < str.size(); i++){
        if (str[i] == '.')
            countDot++;
    }
    if (countDot != 1)
        return 0;
    if (str[str.size() - 1] != 'f')
        return 0;
    for (size_t i = 0; i < str.size(); i++){
        if (str[i] == 'f')
            countF++;
    }
    if (countF != 1)
        return 0;
    if (str.find_first_not_of("0123456789.f") != std::string::npos)
        return 0;
    return 1;
}

int isDouble(std::string str){
    int countDot = 0;
    
    for (size_t i = 0; i < str.size(); i++){
        if (str[i] == '.')
            countDot++;
    }
    if (countDot != 1)
        return 0;
    if (str.find_first_not_of("0123456789.") != std::string::npos)
        return 0;
    return 1;
}

void ScalarConverter::convert(const std::string& literal){
    if (pseudoLiteralcase(literal))
        return ;
    else if(literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])){
        convertChar(literal);
    }
    else if (literal.find_first_not_of("0123456789") == std::string::npos){
        convertInt(literal);
    }
    else if (isFloat(literal)){
        std::cout<<"float\n";
    }
    else if (isDouble(literal)){
        std::cout<<"double\n";
    }
}