#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base* generate(){
	switch (std::rand() % 3) {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    default:
        return NULL;
    }
}

//*Use the dynamic_cast for this
void identify(Base* p){
	std::cout << "Identify by pointer" << std::endl;
	if (!p){
		std::cout << "NULL" << std::endl;
		return ;
	}
	if (dynamic_cast<A *>(p))
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Type C" << std::endl;
	else
		std::cout << "Unkown Type" << std::endl;

}

void identify(Base &p){
	std::cout << "Identify by reference" << std::endl;
	try{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Type A" << std::endl;
	}
	catch (std::exception& e) {
		try{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "Type B" << std::endl;
		}
		catch (std::exception& e){
			try{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "Type C" << std::endl;
			}
			catch(std::exception& e){
				std::cout << "Unkown Type" << std::endl;
			}
		}
	}
}


