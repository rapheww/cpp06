/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:00:17 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/02 19:05:41 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int const intMin = std::numeric_limits<int>::min();
int const intMax = std::numeric_limits<int>::max();
float const floatMin = std::numeric_limits<float>::min();
float const floatMax = std::numeric_limits<float>::max();
std::string flag;

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
    char asChar = literal[0];
    int asInt = static_cast<int>(asChar);
    float asFloat = static_cast<float>(asChar);
    double asDouble = static_cast<double>(asChar);
    
    std::cout<<"char : '"<<asChar<<"'"<<std::endl;
    std::cout<<"int : "<<asInt<<std::endl;
    std::cout<<"float : "<<std::fixed<<std::setprecision(1)<<asFloat<<"f"<<std::endl;
    std::cout<<"double : "<<asDouble<<std::endl;
}

void convertInt(const std::string& literal){
    int asInt = atoi(literal.c_str());
    float asFloat = static_cast<float>(asInt);
    double asDouble = static_cast<double>(asInt);
    char asChar = static_cast<char>(asInt);

    if (displayChar(asInt))
        std::cout<<"char : '"<<asChar<<"'"<<std::endl;
    std::cout<<"int : "<<asInt<<std::endl;
    std::cout<<"float : "<<std::fixed<<std::setprecision(1)<<asFloat<<"f"<<std::endl;
    std::cout<<"double : "<<asDouble<<std::endl;
}

void convertFloat(const std::string& literal){
    float asFloat = std::atof(literal.c_str());
    char asChar = static_cast<char>(asFloat);
    int asInt = static_cast<int>(asFloat);
    double asDouble = static_cast<double>(asFloat);

   if (displayChar(asInt))
        std::cout<<"char : '"<<asChar<<"'"<<std::endl;
    std::cout<<"int : "<<asInt<<std::endl;
    if (asFloat == asInt)
        std::cout<<"float : "<<std::fixed<<std::setprecision(1)<<asFloat<<"f"<<std::endl;
    else
        std::cout<<"float : "<<asFloat<<"f"<<std::endl;
    std::cout<<"double : "<<asDouble<<std::endl;
}

void convertDouble(const std::string& literal){
    char *end;
    double asDouble = std::strtod(literal.c_str(), &end);
    float asFloat =  static_cast<float>(asDouble);
    char asChar = static_cast<char>(asFloat);
    int asInt = static_cast<int>(asFloat);

   if (displayChar(asInt))
        std::cout<<"char : '"<<asChar<<"'"<<std::endl;
    std::cout<<"int : "<<asInt<<std::endl;
    if (asFloat == asInt)
        std::cout<<"float : "<<std::fixed<<std::setprecision(1)<<asFloat<<"f"<<std::endl;
    else
        std::cout<<"float : "<<asFloat<<"f"<<std::endl;
    std::cout<<"double : "<<asDouble<<std::endl;
}

void ScalarConverter::convert(const std::string& literal){
    if (pseudoLiteralcase(literal))
        return ;
    else if(isChar(literal)){
        convertChar(literal);
    }
    else if (isInt(literal)){
        convertInt(literal);
    }
    else if (isFloat(literal))
        convertFloat(literal);
    else if (isDouble(literal)){
        convertDouble(literal);
    }
    else
        std::cout<<"Input isn't a literal type : int / char / float / double\n";
}