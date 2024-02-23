/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:20 by anda-cun          #+#    #+#             */
/*   Updated: 2024/02/23 11:01:25 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void ScalarConverter::convert(std::string string)
{
    size_t dot_pos;
    size_t j = -1;
    int dot = 0;
    char c;
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
        if (!isdigit(string[j]))
        {
            dot_pos = string.find(".");
            if (dot_pos != std::string::npos && !dot)
                dot = 1;
            else if (string[j] == 'f' && !string[j + 1])
            {
                try
            {
                f = stof(string); // float
            }
            catch(const std::out_of_range& e)
            {
                std::cerr << "Out of range\n";
                return;
            }
                c = static_cast<char>(f);
                i = static_cast<int>(stof(string));
                d = static_cast<double>(stof(string));
            }
            else if (string.length() != 1)
            {
                std::cout << "Invalid value\n";
                return;
            }
            else
            {
                c = string[0]; // char
                i = static_cast<int>(c);
                f = static_cast<float>(c);
                d = static_cast<double>(c);
            }
        }
    }
    if (j == string.length() && dot)
    {
       try
        {
            d = stod(string); // double
        }
        catch(const std::out_of_range& e)
        {
            std::cerr << "Out of range\n";
            return;
        }
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    }
    else
    {
        try
        {
            i = stoi(string); // int
        }
        catch(const std::out_of_range& e)
        {
            std::cerr << "Out of range\n";
            return;
        }
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d =  static_cast<double>(i);
    }

    if (!isprint(i))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << i << "\n";
    if (d == i && d >= -1000000 && d < 1000000)
    {
        std::cout << "float: " << f << ".0f\n";
        std::cout << "double: " << d << ".0\n";
        return;
    }
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << d << "\n";
    return;
}