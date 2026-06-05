/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 12:59:56 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/05 14:32:11 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cout<<"Program takes only 1 parameter\n"; return 0;
    }
    if (av[1] && av[1][0] == '\0'){
        std::cout<<"Input isn't a literal type : int / char / float / double\n"; return 0;
    }
    ScalarConverter::convert(av[1]);    
    return 0;
}