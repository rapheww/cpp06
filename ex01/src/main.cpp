/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:56:54 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/03 15:34:49 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(){
    Data tester;
    uintptr_t serialize;
    Data *deserialize;
    
    tester.name = "Tester";
    tester.size = 15;
    
    std::cout<<"Data struct before :"<<std::endl;
    std::cout<<"address : "<<&tester<<"\nName : "<<tester.name<<"\n Size : "<<tester.size<<std::endl;
    serialize = Serializer::serialize(&tester);
    deserialize = Serializer::deserialize(serialize);
    if (deserialize == &tester)
        std::cout<<"Serialize and Deserialize success\n";
    else
        std::cout<<"Serialize and Deserialize failed\n";
    std::cout<<"address : "<<deserialize<<"\nName : "<<deserialize->name<<"\n Size : "<<deserialize->size<<std::endl;
    return 0;
}