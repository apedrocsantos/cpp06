/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:27:55 by anda-cun          #+#    #+#             */
/*   Updated: 2024/03/13 14:24:50 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "ScalarConverter.hpp"
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <climits>
#include <iostream>

class ScalarConverter
{
    ScalarConverter();
    ScalarConverter(const ScalarConverter &that);
    ScalarConverter &operator=(const ScalarConverter &that);
    ~ScalarConverter();
    static float toFloat(std::string &string);
    static double toDouble(std::string &string);
    static int toInt(std::string &string);

    public:
    static void convert(std::string string_literal);
};

#endif