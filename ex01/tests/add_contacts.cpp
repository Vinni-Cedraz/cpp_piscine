#include <criterion/criterion.h>
#include "test.h"

#define scenario1 CYAN\
	"\nGiven 1 == 1\n \
	Then true" RESET

Test(add_contacts, test1, .description = scenario1)
{
	cr_assert(1 == 1, "1 is equal to 1");
}
