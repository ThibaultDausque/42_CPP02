/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:23:03 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/04 18:12:27 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

class	Fixed
{
	private:
		int					_nb;
		static const int	_bits;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int nb);
		Fixed(const float ft);
		~Fixed();
		Fixed&	operator=(const Fixed& op);

		bool	operator>(const Fixed& op);
		bool	operator<(const Fixed& op);
		bool	operator>=(const Fixed& op);
		bool	operator<=(const Fixed& op);
		bool	operator==(const Fixed& op);
		bool	operator!=(const Fixed& op);

		Fixed	operator+(const Fixed& op);
		Fixed	operator-(const Fixed& op);
		Fixed	operator*(const Fixed& op);
		Fixed	operator/(const Fixed& op);

		Fixed	operator++(int); // pre-inc
		Fixed&	operator++(); //post-inc
		Fixed	operator--(int);
		Fixed&	operator--();

		static Fixed	min(Fixed& a, Fixed& b);
		static const Fixed	min(const Fixed& a, const Fixed& b);
		static Fixed	max(Fixed& a, Fixed& b);
		static const Fixed	max(const Fixed& a, const Fixed& b);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	};

	std::ostream&	operator<<(std::ostream &os, const Fixed &op);