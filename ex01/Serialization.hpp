/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:27:55 by anda-cun          #+#    #+#             */
/*   Updated: 2024/02/22 22:30:15 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>

class Serialization
{
    explicit Serialization();
    Serialization(const Serialization &that);
    Serialization &operator=(const Serialization &that);
    ~Serialization();

    public:
    static void convert(std::string string_literal);
};

#endif