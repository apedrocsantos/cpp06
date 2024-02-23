/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:18:00 by anda-cun          #+#    #+#             */
/*   Updated: 2024/02/23 11:40:12 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{

}

Serialization::Serialization(const Serialization &that)
{
    *this = that;
}

Serialization &Serialization::operator=(const Serialization &that)
{
    if (this != &that)
        *this = that;
    return (*this);
}

Serialization::~Serialization()
{

}

uintptr_t Serialization::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialization::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}
