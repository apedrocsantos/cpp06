/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:27:55 by anda-cun          #+#    #+#             */
/*   Updated: 2024/02/22 17:17:10 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    explicit ScalarConverter();
    ScalarConverter(const ScalarConverter &that);
    ScalarConverter &operator=(const ScalarConverter &that);
    ~ScalarConverter();

    public:
    static void convert(std::string string_literal);
};

#endif