/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/03/05 17:22:30 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static void	print_conversions(int *intNbr, float *floatNbr, double *doubleNbr, bool *intFlg) {
	std::stringstream c, i, f, d;

	if (!*intFlg && *intNbr < std::numeric_limits<int>::max() &&
		*intNbr > std::numeric_limits<int>::min() && (*intNbr >= 0 && *intNbr < 256))
	{
		if (std::isprint(*intNbr))
			c << "'" << char(*intNbr) << "'";
		else
			c << "Non displayable";
	}
	else
		c << "impossible";

	if (!*intFlg && *intNbr < std::numeric_limits<int>::max() &&
		*intNbr > std::numeric_limits<int>::min())
		i << *intNbr;
	else
		i << "impossible";

	f << *floatNbr;
	if (*floatNbr != std::numeric_limits<float>::infinity() &&
		*floatNbr != std::numeric_limits<float>::quiet_NaN() &&
		int(*floatNbr * 10) % 10 == 0)
		f << ".0";

	d << *doubleNbr;
	if (*doubleNbr != std::numeric_limits<float>::infinity() &&
		*doubleNbr != std::numeric_limits<float>::quiet_NaN() &&
		int(*doubleNbr * 10) % 10 == 0)
		d << ".0";

	std::cout << "char: " << c.str() << std::endl;
	std::cout << "int: " << i.str() << std::endl;
	std::cout << "float: " << f.str() << "f\n";
	std::cout << "double: " << d.str() << std::endl;
}

static void	check_exceptions(std::string literal, float *floatNbr, double *doubleNbr, bool *intFlg) {
	if (literal == "nan" || literal == "+nan" || literal == "-nan")
	{
		*floatNbr = std::numeric_limits<float>::quiet_NaN();
		*doubleNbr = std::numeric_limits<double>::quiet_NaN();
		*intFlg = true;
	}
	else if (literal == "inf" || literal == "inff" || literal == "+inf" ||
			 literal == "+inff" || literal == "-inf" || literal == "-inff")
	{
		*floatNbr = std::numeric_limits<float>::infinity();
		*doubleNbr = std::numeric_limits<double>::infinity();
		*intFlg = true;
	}
}

static void convert_int(std::string literal, int *intNbr, float *floatNbr, double *doubleNbr) {
	std::stringstream str(literal);

	str >> *intNbr;
	*floatNbr = static_cast<float>(*intNbr);
	*doubleNbr = static_cast<double>(*intNbr);
}

static void convert_float(std::string literal, int *intNbr, float *floatNbr, double *doubleNbr) {
	std::stringstream str(literal);

	str >> *floatNbr;
	*intNbr = static_cast<int>(*floatNbr);
	*doubleNbr = static_cast<double>(*floatNbr);
}

static void convert_double(std::string literal, int *intNbr, float *floatNbr, double *doubleNbr) {
	std::stringstream str(literal);

	str >> *doubleNbr;
	*intNbr = static_cast<int>(*doubleNbr);
	*floatNbr = static_cast<float>(*doubleNbr);
}

void	ScalarConverter::convert(const std::string &literal) {
	int 	intNbr = 0;
	float 	floatNbr = 0;
	double	doubleNbr = 0;
	bool	intFlg = false;

	if (literal.length() == 1 && !isdigit(literal[0])) {
		intNbr = static_cast<unsigned char>(literal[0]);
		floatNbr = static_cast<unsigned char>(literal[0]);
		doubleNbr = static_cast<unsigned char>(literal[0]);
	}

	if (literal.find_first_of('.') == literal.find_last_of('.')
		&& literal.find_first_not_of("123456789.") == std::string::npos)
		convert_double(literal, &intNbr, &floatNbr, &doubleNbr);
	else if ((literal.find_first_not_of("123456789.f") == std::string::npos &&
			  literal.find_first_of('.') == literal.find_last_of('.') && literal.find_first_of('f') == literal.length() - 1))
		convert_float(literal, &intNbr, &floatNbr, &doubleNbr);
	else if (isprint(literal[0]))
		convert_int(literal, &intNbr, &floatNbr, &doubleNbr);
	else
	{
		std::cout << "Error: Invalid conversion\n";
		return ;
	}

	check_exceptions(literal, &floatNbr, &doubleNbr, &intFlg);
	print_conversions(&intNbr, &floatNbr, &doubleNbr, &intFlg);
}
