#include <iostream>

class Fixed {
  private:
    int _value;
    static const int _fractional_bits = 8;

  public:
    // default constructor
    Fixed();
    // copy constructor
    Fixed(const Fixed &number);
    // A constructor that takes a const int as a parameter, converts it to the corresponding fixed-point value. The
    // _fractional_bits is initialized to 8
    Fixed(const int);
    // A constructor that takes a const float as a paraqmeter, converts it to the corresponding fixed-point value and
    // initializes _fractional_bits to 8;
    Fixed(const float);
    // assignement copy constructor
    Fixed &operator=(const Fixed &number);
    // destructor
    ~Fixed();

    // getters and setters:
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // other methods:

    // Converts the fixed-point value to a floating-point value.
    float toFloat(void) const;
    // Converts the fixed-point value to an int value.
    int toInt(void) const;
    // An overload of the << operator that inserts a float representation of the fixed-point number into the output
    // stream object passed as a parameter.
    void operator<<(std::ostream out);
};

std::ostream &operator<<(std::ostream &outstream, const Fixed &fixed);
