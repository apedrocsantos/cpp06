/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:46:24 by anda-cun          #+#    #+#             */
/*   Updated: 2024/03/12 22:55:21 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <iostream>

Base *generate(void)
{
    int i;
    srand(time(NULL));
    i = rand() % 4;
    switch(i)
    {
        case 0:
            std::cout << "Created A class\n";
            return new A;
        case 1:
            std::cout << "Created B class\n";
            return new B;
        case 2:
        std::cout << "Created C class\n";
        return new C;
    }
    std::cout << "Created D class\n";
    return new D;
}

void identify(Base* p)
{
    std::cout << "Identifying a pointer: ";
    if (dynamic_cast<A *>(p))
        std::cout << "Type A\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "Type B\n";
    else if (dynamic_cast<C *>(p))
        std::cout << "Type C\n";
    else
        std::cout << "Couldn't find type\n";
}

void identify(Base& p)
{
    std::cout << "Identifying a reference: ";
    Base p2;
    try
    {
        p2 = dynamic_cast<A &>(p);
        std::cout << "Type A\n";
    }
    catch(...)
    {
        try
        {
            p2 = dynamic_cast<B &>(p);
            std::cout << "Type B\n";
        }
        catch(...)
        {
            try
            {
                p2 = dynamic_cast<C &>(p);
                std::cout << "Type C\n";
            }
            catch(...)
            {
                std::cout << "Couldn't find type\n";
            }
        }
    }
    
}

int main()
{
    Base *a = generate();
    Base& b = *a;
    identify(a);
    identify(b);
}