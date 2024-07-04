#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{
	{
		std::cout << "TEST 1 (SUBJECT TEST)" << std::endl;
		Intern	someRandomIntern;
		Form	*rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << CYN << *rrf << RESET << std::endl;

		delete rrf;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2" << std::endl;
		
		Form		*a;
		Form		*b;
		Form		*c;
		Intern		niceIntern;
		Bureaucrat	marvin("Marvin", 1);

		a = niceIntern.makeForm("shrubbery creation request", "I_LOVE");
		b = niceIntern.makeForm("robotomy request", "Marvin");
		c = niceIntern.makeForm("presidential pardon request", "Me");

		std::cout << std::endl;
		std::cout << CYN << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl;
		std::cout << RESET << std::endl;

		marvin.signForm(*a);
		marvin.signForm(*b);
		marvin.signForm(*c);

		std::cout << std::endl;
		marvin.executeForm(*a);
		std::cout << std::endl;
		marvin.executeForm(*b);
		std::cout << std::endl;
		marvin.executeForm(*c);
		std::cout << std::endl;

		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl;

		delete a;
		delete b;
		delete c;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3 (INVALID FORMS)" << std::endl;

		Form	*a;
		Form	*b;
		Form	*c;
		Intern	someRandomIntern;
		
		a = someRandomIntern.makeForm("Invalid", "");
		b = someRandomIntern.makeForm("Valid?", "");
		c = someRandomIntern.makeForm("presidential robotomy", "");
	}
}
