/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:29:30 by anda-cun          #+#    #+#             */
/*   Updated: 2024/03/13 14:57:58 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Static cast - https://en.cppreference.com/w/cpp/language/static_cast
*/

#include "ScalarConverter.hpp"
#include <iomanip>

int main(int ac, char **av)
{
    if (ac > 1)
        ScalarConverter::convert(av[1]);
    return (0);
}