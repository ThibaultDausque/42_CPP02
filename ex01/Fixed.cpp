/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:23:03 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/04 14:53:18 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_nb = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_nb = nb << _bits;
}

Fixed::Fixed(const float ft)
{
	std::cout << "Float constructor called" << std::endl;
	this->_nb = (int)roundf(ft * (1 << _bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& op)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &op)
		this->_nb = op._nb;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nb);
}

void	Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_nb / (float)(1 << this->_bits));
}

int Fixed::toInt(void) const
{
	return (this->_nb >> this->_bits);
}

std::ostream& operator<<(std::ostream &os, const Fixed &op)
{
	os << op.toFloat();
	return (os);
}






