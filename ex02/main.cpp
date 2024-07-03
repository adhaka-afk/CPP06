/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:31:51 by adhaka            #+#    #+#             */
/*   Updated: 2024/07/03 22:38:58 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate()
{
	srand(static_cast<unsigned int>(time(0)));
	int random = rand() % 3;

	switch (random)
	{
		case 0:
			std::cout << "A generated" << std::endl;
			return new A();
		case 1:
			std::cout << "B generated" << std::endl;
			return new B();
		case 2:
			std::cout << "C generated" << std::endl;
			return new C();
	}
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified (pointer) A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified (pointer) B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified (pointer) C" << std::endl;
	else
		std::cout << "Unknown (pointer)" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Identified (reference) A" << std::endl;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Identified (reference) B" << std::endl;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Identified (reference) C" << std::endl;
	}
	catch (const std::exception &e)
	{
	}
}

int main()
{
	Base *ptr = generate();
	if (ptr == NULL)
	{
		std::cerr << "Error generating a Base object." << std::endl;
		return 1;
	}
	std::cout << "Identifying type using pointer:" << std::endl;
	identify(ptr);
	std::cout << "Identifying type using reference:" << std::endl;
	identify(*ptr);
	delete ptr;

	return 0;
}
