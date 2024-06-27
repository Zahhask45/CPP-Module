#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main() {

    std::cout << "------------------------------------------" << std::endl;
	std::cout << "TEST 1) Create Robotomy Form, Sign and Execute" << std::endl << std::endl;
  
    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("robotomy", "Banana");
        if (rrf) {
            Bureaucrat bur("John Doe", 2);
            rrf->beSigned(bur);
            bur.executeForm(*rrf);
            delete rrf;
        }
    }

    /* ------------------------------------ */

    std::cout << "------------------------------------------" << std::endl;
	std::cout << "TEST 2) Create Presidential Form, Sign and Execute" << std::endl << std::endl;


    /* ------------------------------------ */

    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("pardon", "Banana");
        if (rrf) {
            Bureaucrat bur("John Doe", 2);
            rrf->beSigned(bur);
            bur.executeForm(*rrf);
            delete rrf;
        }
    }

    /* ------------------------------------ */

    std::cout << "------------------------------------------" << std::endl;
	std::cout << "TEST 3) Create Shrubbery Form, Sign and Execute" << std::endl << std::endl;

    /* ------------------------------------ */

    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("shrubbery", "Banana");
        if (rrf) {
            Bureaucrat bur("John Doe", 2);
            rrf->beSigned(bur);
            bur.executeForm(*rrf);
            delete rrf;
        }
    }

    /* ------------------------------------ */

    std::cout << "------------------------------------------" << std::endl;
	std::cout << "*TEST 4) Does not create a form, because does not exist" << std::endl << std::endl;

    /* ------------------------------------ */

    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("another", "Banana");
        if (rrf) {
            Bureaucrat bur("John Doe", 2);
            rrf->beSigned(bur);
            bur.executeForm(*rrf);
            delete rrf;
        }
    }

    return 0;
}
