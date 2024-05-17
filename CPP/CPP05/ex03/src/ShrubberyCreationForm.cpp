#include "ShrubberyCreationForm.hpp"

ShrubberyForm::ShrubberyForm(){}
ShrubberyForm::~ShrubberyForm(){}
ShrubberyForm::ShrubberyForm(const ShrubberyForm &src):AForm(src){}
ShrubberyForm::ShrubberyForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), _target(target){}

//! NEEDS MORE TESTS
ShrubberyForm &ShrubberyForm::operator=(const ShrubberyForm &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}


//* EXCEPTIONS

const char *ShrubberyForm::GradeTooHighException::what() const throw() {
    return ("Grade too High");
}

const char *ShrubberyForm::GradeTooLowException::what() const throw() {
    return ("Grade too Low");
}


void ShrubberyForm::formAction() const{
	std::ofstream file;
	file.open((this->_target + "_shrubbery").c_str());
	 if (file.fail()) {
        std::cout << "Failed to open file" << std::endl;
        return;
    }

	if (file.is_open()){
		file << "            .        +          .      .          .\n";
		file << "     .            _        .                    .\n";
		file << "  ,              /;-._,-.____        ,-----.__\n";
		file << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n";
		file << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n";
		file << "                      ,    `./  \\:. `.   )==-'  .\n";
		file << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n";
		file << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n";
		file << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n";
		file << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n";
		file << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n";
		file << "              \\:  `  X` _| _,\\/'   .-'\n";
		file << ".               \":._:`\\____  /:'  /      .           .\n";
		file << "                    \\::.  :\\/:'  /              +\n";
		file << "   .                 `.:.  /:'  }      .\n";
		file << "           .           ):_(:;   \\           .\n";
		file << "                      /:. _/ ,  |\n";
		file << "                   . (|::.     ,`                  .\n";
		file << "     .                |::.    {\\n";
		file << "                      |::.\\  \\ `.\n";
		file << "                      |:::(\\    |\n";
		file << "              O       |:::/{ }  |                  (o\n";
		file << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n";
		file << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n";
		file << "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~\n";
	}
	file.close();
}
