/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:20 by anda-cun          #+#    #+#             */
/*   Updated: 2024/02/22 18:23:16 by anda-cun         ###   ########.fr       */
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
    size_t i = -1;
    int dot = 0;
    // char c;
    // int i;
    // float f;
    // double d;

    if (string == "-inff" || string == "+inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: " << INT_MIN << "\n";
        if (string == "-inff")
        {
            std::cout << "float: -inff\n";
            std::cout << "double: -inf\n";
        }
        else
        {
            std::cout << "float: inff\n";
            std::cout << "double: inf\n";
        }
        return;
    }
    if (string == "-inf" || string == "+inf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: " << INT_MAX << "\n";
        if (string == "-inf")
        {
            std::cout << "float: -inff\n";
            std::cout << "double: -inf\n";
        }
        else
        {
            std::cout << "float: inff\n";
            std::cout << "double: inf\n";
        }
        return;
    }
    if (string == "nan" || string == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
        return;
    }
    while (string[++i])
    {
        if (!isdigit(string[i]))
        {
            dot_pos = string.find(".");
            if (dot_pos != std::string::npos && !dot)
                dot = 1;
            else if (string[i] == 'f' && !string[i + 1])
            {
                // f = stof(string);
                if (!isprint(static_cast<char>(stof(string))))
                    std::cout << "char: Non displayable\n";
                else
                    std::cout << "char: " << static_cast<char>(stof(string)) << "\n";
                std::cout << "int: " << static_cast<int>(stof(string)) << "\n";
                std::cout << "float: " << stof(string) << "f\n";
                std::cout << "double: " << static_cast<double>(stof(string)) << "\n";
                return;// ("float");
            }
            else if (string.length() != 1)
            {
                std::cout << "Invalid value\n";
                return;
            }
            else
            {
                std::cout << "char: " << string << "\n";
                std::cout << "int: " << static_cast<int>(string[0]) << "\n";
                std::cout << "float: " << static_cast<float>(string[0]) << "f\n";
                std::cout << "double: " << static_cast<double>(string[0]) << "\n";
                return;// ("char");
            }
        }
    }
    if (dot)
    {
        if (!isprint(static_cast<char>(stod(string))))
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: " << static_cast<char>(stod(string)) << "\n";
        std::cout << "int: " << static_cast<int>(stod(string)) << "\n";
        std::cout << "float: " << static_cast<double>(stod(string)) << "f\n";
        std::cout << "double: " << stod(string) << "\n";
        return;// ("double");
    }
    if (!isprint(static_cast<char>(stod(string))))
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: " << static_cast<char>(stoi(string)) << "\n";
    std::cout << "int: " << stoi(string) << "\n";
    std::cout << "float: " << static_cast<double>(stoi(string)) << "f\n";
    std::cout << "double: " << static_cast<double>(stoi(string)) << "\n";
    return;// ("int");
}