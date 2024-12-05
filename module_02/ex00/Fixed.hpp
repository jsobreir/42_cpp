#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {
	private:
		int	_integer;
		static const int _f_bits = 8;
	public:
		// Constructor
		Fixed() {
			std::cout << "Default Constructor called" << std::endl;
			_integer = 0;
		};
		// Copy Constructor
		Fixed(const Fixed &fixed) {
			std::cout << "Copy Constructor called" << std::endl;
			*this = fixed;
		};

		// Copy Assignment Operator
		Fixed& operator=(const Fixed &fixed) {
			std::cout << "Copy Assignment Operator called" << std::endl;
			if (this != &fixed) {
				setRawBits(fixed.getRawBits());
			}
			return *this;
		} ;
		// Destructor
		~Fixed() {
			std::cout << "Destructor called" << std::endl;
		};
		// Getter
		int getRawBits( void ) const;
		// Setter
		void setRawBits( int const raw );
} ;

#endif