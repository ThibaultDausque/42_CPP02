/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:23:03 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/04 19:55:55 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed()
{
	this->_nb = 0;
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}
Fixed::Fixed(const int nb)
{
	this->_nb = nb << _bits;
}

Fixed::Fixed(const float ft)
{
	this->_nb = roundf(ft * (1 << _bits));
}

Fixed::~Fixed()
{

}

Fixed&	Fixed::operator=(const Fixed& op)
{
	if (this != &op)
		this->_nb = op._nb;
	return (*this);
}

bool	Fixed::operator>(const Fixed& op)
{
	return (this->_nb > op._nb);
}

bool	Fixed::operator<(const Fixed& op)
{
	return (this->_nb < op._nb);
}

bool	Fixed::operator>=(const Fixed& op)
{
	return (this->_nb >= op._nb);
}

bool	Fixed::operator<=(const Fixed& op)
{
	return (this->_nb <= op._nb);
}

bool	Fixed::operator==(const Fixed& op)
{
	return (this->_nb == op._nb);
}

bool	Fixed::operator!=(const Fixed& op)
{
	return (this->_nb != op._nb);
}

Fixed Fixed::operator+(const Fixed& op)
{
	Fixed result;

	result.setRawBits(this->getRawBits() + op.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed& op)
{
	Fixed result;

	result.setRawBits(this->getRawBits() - op.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed& op)
{
	Fixed result;

	result.setRawBits(this->getRawBits() * op.getRawBits());
	return (result);
}

Fixed	Fixed::operator/(const Fixed& op)
{
	Fixed result;

	result.setRawBits(this->getRawBits() / op.getRawBits());
	return (result);
}

Fixed	Fixed::operator++(int)
{
	Fixed result;

	result = *this;
	this->_nb++;
	return (result);
}

Fixed&	Fixed::operator++()
{
	this->_nb++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed result;

	result = *this;
	this->_nb--;
	return (result);
}

Fixed&	Fixed::operator--()
{
	this->_nb--;
	return (*this);
}

Fixed	Fixed::min(Fixed& a, Fixed& b)
{
	if (a._nb < b._nb)
		return (a);
	else
		return (b);
}

const Fixed	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a._nb < b._nb)
		return (a);
	else
		return (b);
}

Fixed	Fixed::max(Fixed& a, Fixed& b)
{
	if (a._nb < b._nb)
		return (b);
	else
		return (a);
}

const Fixed	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a._nb < b._nb)
		return (b);
	else
		return (a);
}

int	Fixed::getRawBits(void) const
{
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






