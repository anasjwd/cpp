#pragma once

class Fixed {
	private:
		int	value;
		static const int fractional_bits_value;
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& othera);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
