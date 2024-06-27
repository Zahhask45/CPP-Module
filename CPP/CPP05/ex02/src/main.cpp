#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {

    std::cout << "Tests with (*) at the begining should print an exception"
              << std::endl
              << std::endl;

    /* ------------------------------------ */
{
    std::cout << "TEST 1) Shrubbery Form, signable and executable" << std::endl;
    try {
        Bureaucrat bur("John", 10);
        ShrubberyForm form("Home");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;
}
    /* ------------------------------------ */
{
    std::cout << "* TEST 2) Shrubbery Form, signable but not executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 140);
        ShrubberyForm form("Home");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;
}
    /* ------------------------------------ */
{
    std::cout << "TEST 3) Robotomy Form, signable and executable" << std::endl;
    try {
        Bureaucrat bur("John", 40);
        RobotomyForm form("Chicken");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;
}
    /* ------------------------------------ */
{
    std::cout << "* TEST 4) Robotomy Form, signable but not executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 50);
        RobotomyForm form("Chicken");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;
}
    /* ------------------------------------ */
{
    std::cout << "TEST 5) Presidential Pardon Form, signable and executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 4);
        PresidentialForm form("Marvin");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;
}
    /* ------------------------------------ */
{
    std::cout
        << "* TEST 6) Presidential Pardon Form, signable but not executable"
        << std::endl;
    try {
        Bureaucrat bur("John", 20);
        PresidentialForm form("Marvin");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;
}
    /* ------------------------------------ */

    std::cout << "------------------------------------------" << std::endl;

    /* ------------------------------------ */
{
    std::cout << "TEST 7) Shrubbery Form, signable and executable" << std::endl;
    try {
        Bureaucrat bur("John", 10);
        ShrubberyForm form("Home");
        form.beSigned(bur);
        bur.executeForm(form);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;
}
    /* ------------------------------------ */
{
    std::cout << "* TEST 8) Shrubbery Form, signable but not executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 140);
        ShrubberyForm form("Home");
        form.beSigned(bur);
        bur.executeForm(form);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;
}
    /* ------------------------------------ */
{
    std::cout << "TEST 9) Robotomy Form, signable and executable" << std::endl;
    try {
        Bureaucrat bur("John", 40);
        RobotomyForm form("Chicken");
        form.beSigned(bur);
        bur.executeForm(form);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;
}
    /* ------------------------------------ */
{
    std::cout << "* TEST 10) Robotomy Form, signable but not executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 50);
        RobotomyForm form("Chicken");
        form.beSigned(bur);
        bur.executeForm(form);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;
}
    /* ------------------------------------ */
{
    std::cout << "TEST 11) Presidential Pardon Form, signable and executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 4);
        PresidentialForm form("Marvin");
        form.beSigned(bur);
        bur.executeForm(form);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;
}
    /* ------------------------------------ */
{
    std::cout
        << "* TEST 12) Presidential Pardon Form, signable but not executable"
        << std::endl;
    try {
        Bureaucrat bur("John", 20);
        PresidentialForm form("Marvin");
        form.beSigned(bur);
        bur.executeForm(form);
    } catch (std::exception &e) {
        std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
    }
    std::cout << std::endl;
}
    /* ------------------------------------ */
{
	std::cout
		<< "* TEST 13) Shrubbery Creation Form, executable but not signed"
		<< std::endl;
	try {
		ShrubberyForm form("Banana");
		Bureaucrat bur("John Doe", 5);
		bur.executeForm(form);
	} catch (std::exception &e) {
		std::cout << _RED << "Exception: " << e.what() << _END << std::endl;
	}
	std::cout << std::endl;
}
    return 0;
}
