/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:42:07 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/02 18:21:10 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <limits>
#include "utils.hpp"

class ScalarConverter{
    public:
        static void convert(const std::string& literal);
        class InvalidInput : public std::exception{
            virtual const char*  what() const throw();
        };
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& cpy);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter& source);
};