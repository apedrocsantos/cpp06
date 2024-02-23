/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:09:47 by anda-cun          #+#    #+#             */
/*   Updated: 2024/02/23 11:42:03 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include "data.hpp"

int main()
{
    Data data;
    Data *new_data;
    data.i = 135;
    data.str = "Ola";

    uintptr_t raw = Serialization::serialize(&data);
    new_data = Serialization::deserialize(raw);

    std::cout << "i: " << new_data->i << ", str: " << new_data->str << "\n";
}