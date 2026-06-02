/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:41:06 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/02 19:03:02 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int const intMin = std::numeric_limits<int>::min();
int const intMax = std::numeric_limits<int>::max();
float const floatMin = std::numeric_limits<float>::min();
float const floatMax = std::numeric_limits<float>::max();

int pseudoLiteralcase(const std::string& literal){
    std::string pseudoLiteral[6] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};
    
    for (size_t i = 0; i < 6; i++){
        if (pseudoLiteral[i] == literal){
            if (i % 2 == 0){
                std::cout<<"char : impossible\n";
                std::cout<<"int : impossible\n";
                std::cout<<"float : "<<pseudoLiteral[i + 1]<<std::endl;
                std::cout<<"double : "<<pseudoLiteral[i]<<std::endl;
            }
            else{
                std::cout<<"char : impossible\n";
                std::cout<<"int : impossible\n";
                std::cout<<"float : "<<pseudoLiteral[i]<<std::endl;
                std::cout<<"double : "<<pseudoLiteral[i - 1]<<std::endl;
            }
            return 1;
        }
    }
    return 0;
}

int displayChar(int asInt){
    if (asInt > 255){
        std::cout<<"char : impossible"<<std::endl; return 0;
    }
    if (asInt < 32 || asInt > 127){
        std::cout<<"char : not displayable"<<std::endl; return 0;
    }
    return 1;
}

int isInt(std::string str){
    if (!(str.find_first_not_of("0123456789") == std::string::npos))
        return 0;
    if (str.size() > 11)
        return 0;
    long tester = atol(str.c_str());
    if (tester < intMin || tester > intMax)
        return 0;
    return 1;
}

int isChar(std::string str){
    if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return 1;
    return 0;
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