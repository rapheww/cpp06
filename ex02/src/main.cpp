/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:51:25 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/03 16:22:13 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <iostream>

Base::~Base() {};

Base *generate(){
    int wich = rand() % 3;
    
    switch(wich){
        case 0:
            std::cout<<"A generated\n";
            return(new A);
        case 1:
            std::cout<<"B generated\n";
            return(new B);
        case 2:
            std::cout<<"C generated\n";
            return(new C);
    }
    return NULL;
}

void identify(Base* p){
    std::cout<<"Identify with pointer\n";
    if (dynamic_cast<A*>(p) != NULL){
        std::cout<<"Object type is A\n"; return ;
    }
    if (dynamic_cast<B*>(p) != NULL){
        std::cout<<"Object type is B\n"; return ;
    }
    if (dynamic_cast<C*>(p) != NULL){
        std::cout<<"Object type is C\n"; return ;
    }
}

void identify(Base& p){
    std::cout<<"Identify with reference\n";
    try{
        A& ref = dynamic_cast<A&>(p);
        (void)ref; 
        std::cout<<"Object type is A";
        return ;
    }
    catch(const std::exception& e){}
    try{
        B& ref = dynamic_cast<B&>(p);
        (void)ref;
        std::cout<<"Object type is B";
    }
    catch(const std::exception& e){}
    try{
        C& ref = dynamic_cast<C&>(p);
        (void)ref;
        std::cout<<"Object type is C";
    }
    catch(const std::exception& e){}
}

int main(){
    Base* tester;
    
    std::srand(time(NULL));
    tester = generate();
    identify(tester);
    identify(*tester);
    delete tester;
    return 0;
}