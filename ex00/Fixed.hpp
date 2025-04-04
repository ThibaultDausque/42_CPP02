/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:00:21 by tdausque          #+#    #+#             */
/*   Updated: 2025/04/02 11:14:23 by tdausque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int					_nb;
		const static int	_bits;
	
	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed&	operator=(const Fixed& x);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

