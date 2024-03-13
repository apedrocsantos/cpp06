/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:09:47 by anda-cun          #+#    #+#             */
/*   Updated: 2024/03/13 15:05:13 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Reinterpret cast - https://en.cppreference.com/w/cpp/language/reinterpret_cast
uintptr_t - unsigned integer type capable of holding a pointer to void - https://en.cppreference.com/w/cpp/types/integer
*/

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

    std::cout << "new_data->i: " << new_data->i << "\t new_data->str: " << new_data->str << "\n";
    std::cout << "data: " << &data << "\tdata.i: " << &data.i << "\tdata.str: " << &data.str << "\n";
    std::cout << "new_data: " << new_data << "\tnew_data->i: " << &new_data->i << "\tnew_data->str: " << &new_data->str << "\n";
    new_data->i = 20;
    new_data->str = "Xau";
    std::cout << "new_data->i: " << new_data->i << "\tnew_data->str: " << new_data->str << "\n";
}