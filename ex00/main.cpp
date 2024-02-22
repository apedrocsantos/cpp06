/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:29:30 by anda-cun          #+#    #+#             */
/*   Updated: 2024/02/22 18:18:05 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

int main(int ac, char **av)
{
    // float a = -std::numeric_limits<float>::infinity();
    
    if (ac > 1)
    {
        int a = std::stoi(av[1]);
        ScalarConverter::convert(av[1]);
        std::cout << "======================\n";
        std::cout << "char: " << static_cast<char>(a) << "\n";
        std::cout << "int: " << static_cast<int>(a) << "\n";
        std::cout << "float: " << static_cast<float>(a) << "\n";
        std::cout << "double: " << static_cast<double>(a) << "\n";
    }
    return (0);
}