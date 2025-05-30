#include "easyfind.hpp"

int main() {
    int val1 = 13;
    int val2 = 50;

    std::vector<int> vect1;

    vect1.push_back(34);
    vect1.push_back(23);
    vect1.push_back(13);
    vect1.push_back(49);

    try {
        easyfind(vect1, val1);
        easyfind(vect1, val2);
    } catch (std::exception &e) {
        std::cout << "Value not found in vector" << std::endl;
    }

    std::list<int> lst;

    lst.push_back(34);
    lst.push_back(23);
    lst.push_back(13);
    lst.push_back(49);

    try {
        easyfind(lst, val1);
        easyfind(lst, val2);
    } catch (std::exception &e) {
        std::cout << "Value not found in list" << std::endl;
    }

    return (0);
}


