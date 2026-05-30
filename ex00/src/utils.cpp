/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:41:06 by rchaumei          #+#    #+#             */
/*   Updated: 2026/05/30 13:42:53 by rchaumei         ###   ########.fr       */
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