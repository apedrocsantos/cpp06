/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:27:55 by anda-cun          #+#    #+#             */
/*   Updated: 2024/03/13 09:31:15 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include "data.hpp"
#include <stdint.h>

class Serialization
{
    Serialization();
    Serialization(const Serialization &that);
    Serialization &operator=(const Serialization &that);
    ~Serialization();

    public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif