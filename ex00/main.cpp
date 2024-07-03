/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:28:43 by adhaka            #+#    #+#             */
/*   Updated: 2024/07/02 23:50:32 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Starting conversion for: " << argv[1] << std::endl;
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "An error occurred during conversion: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
