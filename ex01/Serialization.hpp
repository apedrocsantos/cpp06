/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:27:55 by anda-cun          #+#    #+#             */
/*   Updated: 2024/03/07 15:58:29 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include "data.hpp"

class Serialization
{
    Serialization();
    Serialization(const Serialization &that);
    Serialization &operator=(const Serialization &that);
    ~Serialization();

    public:
    static void * serialize(Data* ptr);
    static Data* deserialize(void * raw);
};

#endif