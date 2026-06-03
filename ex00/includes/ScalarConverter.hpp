/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:42:07 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/03 16:38:04 by rchaumei         ###   ########.fr       */
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

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& cpy);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter& source);
};

int const intMin = std::numeric_limits<int>::min();
int const intMax = std::numeric_limits<int>::max();
float const floatMin = std::numeric_limits<float>::min();
float const floatMax = std::numeric_limits<float>::max();
double const doubleMin = std::numeric_limits<double>::min();
double const doubleMax = std::numeric_limits<double>::max();