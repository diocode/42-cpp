/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*   By: digoncal                                     +:+ +:+         +:+     */
/*   <digoncal@student.42porto.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Project:                                          #+#    #+#             */
/*   -> C++ Modules                                   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "=================== TEST #1  ====================\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	std::cout << "\n=================== TEST #2  ====================\n";
	const Animal *arr[6] = {new Dog(), new Dog(), new Dog(), new Cat(), new Cat(), new Cat()};
	for (int k = 0; k < 6; k++)
	{
		std::cout << "Animal type: " << arr[k]->getType() << std::endl;
		delete arr[k];
	}

	std::cout << "\n=================== TEST #3  ====================\n";
	Cat	*cat = new Cat();
	Cat	*copyCat = new Cat(*cat);
	Dog	*dog = new Dog();
	Dog	*copyDog = new Dog(*dog);

	std::cout << "\nCat address: " << &cat << std::endl;
	std::cout << "CopyCat address: " << &copyCat << std::endl << std::endl;
	std::cout << "\nDog address: " << &dog << std::endl;
	std::cout << "CopyDog address: " << &copyDog << std::endl << std::endl;

	delete cat;
	delete copyCat;
	delete dog;
	delete copyDog;

	return 0;
}
