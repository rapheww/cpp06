/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 13:41:41 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/02 19:04:28 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

int pseudoLiteralcase(const std::string& literal);
int isInt(std::string str);
int isChar(std::string str);
int isDouble(std::string str);
int isFloat(std::string str);
int displayChar(int asInt);