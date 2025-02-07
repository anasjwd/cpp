#pragma once
#include <ostream>

class Fixed {
	private:
		int	value;
		static const int fractional_bits_value; // always 8
	public:
		Fixed(void);
		Fixed(const int ivalue);
		Fixed(const float fvalue);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& othera);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed &fixed);
