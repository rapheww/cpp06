/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:41:06 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/05 14:30:10 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
    if (asInt > 255 || asInt < 0){
        std::cout<<"char : impossible"<<std::endl; return 0;
    }
    if (asInt < 32 || asInt > 127){
        std::cout<<"char : non displayable"<<std::endl; return 0;
    }
    return 1;
}

int isInt(std::string str){
    if (str.rfind('-') != 0 && str.rfind('-') != std::string::npos)
        return 0;
    if (!(str.find_first_not_of("-0123456789") == std::string::npos))
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
    char *endptr;
    
    if (str[str.size() - 1] != 'f')
        return 0;
    if (str.find('.') == std::string::npos)
        return 0;
    if (!isdigit(str[str.find('.') + 1]))
        return 0;
    std::strtof(str.c_str(), &endptr);
    if (endptr == str.c_str() || *endptr != 'f' || *(endptr + 1) != '\0')
        return 0;
    return 1;
}

int isDouble(std::string str){
    char *endptr;
    
    if (str.find('.') != std::string::npos && !isdigit(str[str.find('.') + 1]))
        return 0;
    std::strtod(str.c_str(), &endptr);
    if (endptr == str.c_str() || *endptr != '\0')
        return 0;
    return 1;
}