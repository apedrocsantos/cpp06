/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:18:00 by anda-cun          #+#    #+#             */
/*   Updated: 2024/03/07 15:58:17 by anda-cun         ###   ########.fr       */
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

void * Serialization::serialize(Data* ptr)
{
    return (reinterpret_cast<void *>(ptr));
}

Data* Serialization::deserialize(void * raw)
{
    return (reinterpret_cast<Data *>(raw));
}
