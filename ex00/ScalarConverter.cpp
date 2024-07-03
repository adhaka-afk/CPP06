/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:28:36 by adhaka            #+#    #+#             */
/*   Updated: 2024/07/03 04:22:36 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::displayChar(double val)
{
	if (std::isnan(val) || std::isinf(val) || val < std::numeric_limits<char>::min() || val > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << std::endl;
	}
	else if (!std::isprint(static_cast<char>(val)))
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	}
}

void ScalarConverter::displayInt(double val)
{
	if (std::isnan(val) || std::isinf(val) || val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	}
}

void ScalarConverter::displayFloat(double val)
{
	if (val == std::numeric_limits<float>::infinity())
	{
		std::cout << "float: +inff" << std::endl;
	}
	else if (val == -std::numeric_limits<float>::infinity())
	{
		std::cout << "float: -inff" << std::endl;
	}
	else if (std::isnan(val))
	{
		std::cout << "float: nanf" << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(val) << "f" << std::endl;
	}
}

void ScalarConverter::displayDouble(double val)
{
	if (val == std::numeric_limits<double>::infinity())
	{
		std::cout << "double: +inf" << std::endl;
	}
	else if (val == -std::numeric_limits<double>::infinity())
	{
		std::cout << "double: -inf" << std::endl;
	}
	else if (std::isnan(val))
	{
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1) << "double: " << val << std::endl;
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	double val;
	char *endPtr = NULL;

	if (literal.length() == 1 && std::isalpha(literal[0]))
	{
		val = static_cast<double>(literal[0]);
	}
	else
	{
		val = std::strtod(literal.c_str(), &endPtr);
		if (endPtr == literal.c_str() || (*endPtr != '\0' && *endPtr != 'f') || endPtr != literal.c_str() + literal.size())
		{
			std::cout << "Invalid input." << std::endl;
			return;
		}
	}

	displayChar(val);
	displayInt(val);
	displayFloat(val);
	displayDouble(val);

	std::cout << "Conversion completed successfully." << std::endl;
}
