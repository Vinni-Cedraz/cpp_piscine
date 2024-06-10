class FixedPointNumber {
  private:
    int _value;
    static const int _fractional_bits = 8;

  public:
    // default constructor
    FixedPointNumber();
    // copy constructor
    FixedPointNumber(const FixedPointNumber &number);
    // assignement copy constructor
    FixedPointNumber &operator=(const FixedPointNumber &number);
    // destructor
    ~FixedPointNumber();
    // getter for value
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
