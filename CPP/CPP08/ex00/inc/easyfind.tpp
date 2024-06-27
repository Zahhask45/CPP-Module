#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

#ifndef EASYFIND_HPP
#error "You must include easyfind.hpp before easyfind.tpp"
#endif


template<typename T>
void easyfind(T &container, int &target){
	typename T::iterator i = std::find(container.begin(), container.end(), target);
    if (i == container.end())
        throw std::exception();
    std::cout << "Found " << target << " at index " << std::distance(container.begin(), i) << std::endl;
}


#endif
