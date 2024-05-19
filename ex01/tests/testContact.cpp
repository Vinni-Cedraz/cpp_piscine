#include "test.h"
#include <criterion/criterion.h>
#include <criterion/internal/preprocess.h>

// default constructor
#define scenario1                                                                                                      \
    CYAN "\nGiven Contact c = Contact()\n\
Then c.getFirstName() == \"\"\n\
And c.getPhone() == \"\"\n" RESET

Test(add_contacts, default_constructor, .description = scenario1) {
    Contact c = Contact();
    cr_assert_eq(c.getFirstName(), "");
    cr_assert_eq(c.getPhoneNumber(), "");
}

// setters and getters
#define scenario3\
	CYAN "\nGiven Contact c = Contact()\n\
When c.setFirstName(\"John\")\n\
And c.setLastName(\"Doe\")\n\
And c.setNickName(\"dilly\")\n\
And c.setPhoneNumber(\"12345678\")\n\
And c.setDarkestSecret(\"eats spagetthi with his hands\")\n\
Then c.getFirstName() == \"John\"\n\
And c.getLastName() == \"Doe\"\n\
And c.getNickName() == \"dilly\"\n\
And c.getPhoneNumber() == \"12345678\"\n\
And c.getDarkestSecret() == \"eats spagetthi with his hands\"\n" RESET

Test(add_contacts, setters_and_getters, .description = scenario3) {
	Contact c = Contact();
	c.setFirstName("John");
	c.setLastName("Doe");
	c.setNickName("dilly");
	c.setPhoneNumber("12345678");
	c.setDarkestSecret("eats spagetthi with his hands");
	cr_assert_eq(c.getFirstName(), "John");
	cr_assert_eq(c.getLastName(), "Doe");
	cr_assert_eq(c.getNickName(), "dilly");
	cr_assert_eq(c.getPhoneNumber(), "12345678");
	cr_assert_eq(c.getDarkestSecret(), "eats spagetthi with his hands");
}
