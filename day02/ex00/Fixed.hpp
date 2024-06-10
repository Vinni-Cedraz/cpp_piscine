class Fixed {
  private:
    int _value;
    static const int _fractional_bits = 8;

  public:
    // default constructor
    Fixed();
    // copy constructor
    Fixed(const Fixed &number);
    // assignement copy constructor
    Fixed &operator=(const Fixed &number);
    // destructor
    ~Fixed();
    // getter for value
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
