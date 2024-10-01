/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:28:10 by marboccu          #+#    #+#             */
/*   Updated: 2024/10/01 12:02:38 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	int choice = rand() % 3;
	switch (choice)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return new A;
	}
}

void identify(Base *p)
{
	std::cout << "Identifying pointer to " << p << std::endl << "Result: ";

	if (dynamic_cast<A *>(p))
		std::cout << "\"A\"" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "\"B\"" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "\"C\"" << std::endl;
}

void identify(Base &p)
{
	std::cout << "Identifying reference to " << &p << std::endl << "Result: ";

	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "\"A\"" << std::endl;
		(void)a;
		return;
	}
	catch(std::exception &e) {};
	
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "\"B\"" << std::endl;
		(void)b;
		return;
	}
	catch(std::exception &e) {};

	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "\"C\"" << std::endl;
		(void)c;
		return;
	}
	catch(std::exception &e) {};
}

int main(void)
{
	std::srand(std::time(NULL));
	Base *pippo = generate();
	Base *pluto = generate();

	identify(pippo);
	identify(pluto);

	identify(*pippo);
	identify(*pluto);

	delete pippo;
	delete pluto;
	return 0;
}
