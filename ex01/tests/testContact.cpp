#include "test.h"
#include <criterion/criterion.h>

// default constructor
#define scenario1                                                                                                      \
    CYAN "\nGiven Contact c = Contact()\n\
Then c.getName() == \"\"\n\
And c.getPhone() == \"\"\n" RESET

Test(add_contacts, default_constructor, .description = scenario1) {
    Contact c = Contact();
    cr_assert_eq(c.getName(), "");
    cr_assert_eq(c.getNumber(), "");
}

// constructor with parameters
#define scenario2                                                                                                      \
    CYAN "\nGiven Contact c = Contact(\"John\", \"1234567890\")\n\
Then c.getName() == \"John\"\n\
And c.getPhone() == \"1234567890\"\n" RESET

Test(add_contacts, constructor_with_parameters, .description = scenario2) {
    Contact c = Contact("John", "1234567890");
    cr_assert_eq(c.getName(), "John");
    cr_assert_eq(c.getNumber(), "1234567890");
}

// setters and getters
#define scenario3                                                                                                      \
	CYAN "\nGiven Contact c = Contact()\n\
When c.setNameNumber(\"John\", \"1234567890\")\n\
Then c.getName() == \"John\"\n\
And c.getPhone() == \"1234567890\"\n" RESET

Test(add_contacts, setters_and_getters, .description = scenario3) {
	Contact c = Contact();
	c.setNameNumber("John", "1234567890");
	cr_assert_eq(c.getName(), "John");
	cr_assert_eq(c.getNumber(), "1234567890");
}
