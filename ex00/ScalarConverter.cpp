/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:20 by anda-cun          #+#    #+#             */
/*   Updated: 2024/03/13 14:57:16 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Casting operators in C++ - https://www.geeksforgeeks.org/casting-operators-in-cpp/

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &that)
{
    *this = that;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &that)
{
    if (this != &that)
        return (*this);
    return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

float ScalarConverter::toFloat(std::string &string)
{
    float nb;
    std::stringstream ss;
    
    ss << string;
    ss >> nb;
    if (std::abs(nb) == FLT_MAX)
        throw(std::out_of_range("Out of range"));
    return (nb);
}

double ScalarConverter::toDouble(std::string &string)
{
    double nb;
    std::stringstream ss;
    
    ss << string;
    ss >> nb;
    if (std::abs(nb) == DBL_MAX)
        throw(std::out_of_range("Out of range"));
    return (nb);
}

int ScalarConverter::toInt(std::string &string)
{
    int nb;
    std::stringstream ss;
    
    ss << string;
    ss >> nb;
    if (std::abs(nb) == INT_MAX)
        throw(std::out_of_range("Out of range"));
    return (nb);
}

void ScalarConverter::convert(std::string string)
{
    size_t dot_pos;
    size_t j = -1;
    int dot = 0;
    char c;
    int c2 = 0;
    int i;
    float f;
    double d;
    int a = -1;
    std::string array[] = {"-inf", "-inff", "+inf", "+inff", "nan"};

    while (++a < 5)
    {
        if (array[a] == string)
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            if (string == "-inf" || string == "-inff")
            {
                std::cout << "float: -inff\n";
                std::cout << "double: -inf\n";
            }
            if (string == "+inf" || string == "+inff")
            {
                std::cout << "float: +inff\n";
                std::cout << "double: +inf\n";
            }
            if (string == "nan" || string == "nanf")
            {
                std::cout << "float: nanf\n";
                std::cout << "double: nan\n";
            }
            return;
        }
    }
    while (string[++j])
    {
        if (string[j] == '-')
            ++j;
        if (!isdigit(string[j]))
        {
            dot_pos = string.find(".");
            if (dot_pos != std::string::npos && !dot)
                dot = 1;
            else if (dot < 2 && string.length() > 1 && !string[j + 1] && string[j] == 'f')
            {
                try
                {
                    f = toFloat(string); // float
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                    return;
                }
                c2 = 1;
                c = static_cast<char>(f);
                i = static_cast<int>(f);
                d = static_cast<double>(f);
            }
            else if (string.length() != 1)
            {
                std::cout << "Invalid value\n";
                return;
            }
            else
            {
                c2 = 1;
                c = string[0]; // char
                i = static_cast<int>(c);
                f = static_cast<float>(c);
                d = static_cast<double>(c);
            }
        }
    }
    if (j == string.length() && dot == 1)
    {
        try
        {
            d = toDouble(string); // double
        }
        catch(const std::out_of_range& e)
        {
            std::cerr << e.what() << std::endl;
            return;
        }
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    }
    else if (!c2)
    {
        try
        {
            i = toInt(string); // int
        }
        catch(const std::out_of_range& e)
        {
            std::cerr << e.what() << std::endl;
            return;
        }
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d =  static_cast<double>(i);
    }

    if (i < 0 || i > 256 || !isprint(i))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << i << "\n";
    if (d == i && d > -1000000 && d < 1000000)
    {
        std::cout << "float: " << f << ".0f\n";
        std::cout << "double: " << d << ".0\n";
        return;
    }
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << d << "\n";
    return;
}