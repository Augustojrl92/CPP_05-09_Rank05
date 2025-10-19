/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:11:29 by aurodrig          #+#    #+#             */
/*   Updated: 2025/07/16 20:01:56 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {

    Data original;
    original.number = 42;
    original.text = "Hello world";

    std::cout << "Original address    : " << &original << std::endl;

    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized value    : " << raw << std::endl;

    Data* recovered = Serializer::deserialize(raw);
    std::cout << "Recovered address   : " << recovered << std::endl;
    
    std::cout << "Recovered.number    : " << recovered->number << std::endl;
    std::cout << "Recovered.text      : " << recovered->text << std::endl;

    return 0;
}

