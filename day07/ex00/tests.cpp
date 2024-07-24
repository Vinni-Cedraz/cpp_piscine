#include "whatever.hpp"
#include <iostream>
#include <limits>

void testSubjectExamples(void) {
    std::cout << "---- SUBJECT TESTS" << std::endl << std::endl;
    int a = 2;
    int b = 3;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl << std::endl;
}

void swap_ints(int a, int b) {
    std::cout << "Pre-swap:\t";
    std::cout << "a = " << a << ", b = " << b;
    std::cout << "\t-> Max: " << ::max<int>(a, b) << " / Min: " << ::min<int>(a, b) << std::endl;

    ::swap<int>(a, b);

    std::cout << "Post-swap:\t";
    std::cout << "a = " << a << ", b = " << b;
    std::cout << "\t-> Max: " << ::max<int>(a, b) << " / Min: " << ::min<int>(a, b) << std::endl;
    std::cout << std::endl;
}

void swap_floats(float a, float b) {
    std::cout << "Pre-swap:\t";
    std::cout << "a = " << a << ", b = " << b;
    std::cout << "\t-> Max: " << ::max<float>(a, b) << " / Min: " << ::min<float>(a, b) << std::endl;

    ::swap<float>(a, b);

    std::cout << "Post-swap:\t";
    std::cout << "a = " << a << ", b = " << b;
    std::cout << "\t-> Max: " << ::max<float>(a, b) << " / Min: " << ::min<float>(a, b) << std::endl;
    std::cout << std::endl;
}

void swap_chars(char a, char b) {
    std::cout << "Pre-swap:\t";
    std::cout << "a = " << a << ", b = " << b;
    std::cout << "\t-> Max: " << ::max<char>(a, b) << " / Min: " << ::min<char>(a, b) << std::endl;

    ::swap<char>(a, b);

    std::cout << "Post-swap:\t";
    std::cout << "a = " << a << ", b = " << b;
    std::cout << "\t-> Max: " << ::max<char>(a, b) << " / Min: " << ::min<char>(a, b) << std::endl;
    std::cout << std::endl;
}

void swap_strings(std::string a, std::string b) {
    std::cout << "Pre-swap:\t";
    std::cout << "a = " << a << ", b = " << b;
    std::cout << "\t-> Max: " << ::max<std::string>(a, b) << " / Min: " << ::min<std::string>(a, b) << std::endl;

    ::swap<std::string>(a, b);

    std::cout << "Post-swap:\t";
    std::cout << "a = " << a << ", b = " << b;
    std::cout << "\t-> Max: " << ::max<std::string>(a, b) << " / Min: " << ::min<std::string>(a, b) << std::endl;
    std::cout << std::endl;
}

void testInts() {
    std::cout << "---- INT TESTS" << std::endl << std::endl;
    swap_ints(42, 0);
    swap_ints(-500, 300);
    swap_ints(42, 42);
    swap_ints(std::numeric_limits<int>::max(), std::numeric_limits<int>::min());
}

void testFloats() {
    std::cout << "---- FLOAT TESTS" << std::endl << std::endl;
    swap_floats(0.42, 42);
    swap_floats(-20.02, 500);
    swap_floats(std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
}

void testChars() {
    std::cout << "---- CHAR TESTS" << std::endl << std::endl;
    swap_chars('a', 'z');
    swap_chars('X', '~');
    swap_chars(35, 119);
}

void testStrings() {
    std::cout << "---- STRING TESTS" << std::endl << std::endl;
    swap_strings("Hello!", "World");
    swap_strings("abracadabra", "XYZ");
    swap_strings("", "Clap");
    swap_strings("...", "!!?");
}
