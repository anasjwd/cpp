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
		Fixed&	operator=(const Fixed& othera);
		~Fixed(void);

		bool	operator>(const Fixed& toCompareWith) const;
		bool	operator<(const Fixed& toCompareWith) const;
		bool	operator>=(const Fixed& toCompareWith) const;
		bool	operator<=(const Fixed& toCompareWith) const;
		bool	operator==(const Fixed& toCompareWith) const;
		bool	operator!=(const Fixed& toCompareWith) const;

		Fixed	operator+(const Fixed& leftSide) const;
		Fixed	operator-(const Fixed& leftSide) const;
		Fixed	operator*(const Fixed& leftSide) const;
		Fixed	operator/(const Fixed& leftSide) const;

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		static const Fixed&	min(const Fixed& left, const Fixed&right);
		static Fixed&	min(Fixed& left, Fixed&right);
		static const Fixed&	max(const Fixed& left, const Fixed&right);
		static Fixed&	max(Fixed& left, Fixed&right);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed &fixed);
