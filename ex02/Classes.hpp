/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:46:43 by anda-cun          #+#    #+#             */
/*   Updated: 2024/03/13 10:09:07 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
#define CLASSES_HPP

class Base
{
    public:
    virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
class D : public Base {};

#endif