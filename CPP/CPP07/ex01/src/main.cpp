#include "iter.hpp"
#include <math.h>

int main(){
	int array[5] = {1, 2, 3, 4, 5};

	::iter(array, 5, ::print);
	std::cout << "===========================" << std::endl;
	::iter(array, 5, ::increment);
	::iter(array, 5, ::print);


	return 0;
}


