#include "Array.hpp"
#include <iostream>

int main(void) {

    {
        int *a = new int();
        std::cout << "a is: " << *a << std::endl;
        Array<int> arr(*a);
        delete a;
    }

    std::cout << "------" << std::endl;

    {
        unsigned int a = 5;
        Array<int> arr(a);

        for (unsigned int i = 0; i < a; i++) {
            arr[i] = i;
        }

        for (unsigned int i = 0; i < a; i++) {
            std::cout << arr[i] << std::endl;
        }

        std::cout << "size is " << arr.size() << std::endl;

        try {
            std::cout << "accessing index 7 will throw exception " << std::endl
                      << arr[7] << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "------" << std::endl;

    {
        std::cout << "By copy constructer" << std::endl;

        unsigned int a = 4;
        Array<int> arr1(a);
		for (unsigned int i = 0; i < a; i++) {
            arr1[i] = i;
        }
        Array<int> arr2(arr1);

        for (unsigned int i = 0; i < a; i++) {
            std::cout << arr2[i] << std::endl;
        }

        std::cout << "size is " << arr2.size() << std::endl;
    }

    std::cout << "------" << std::endl;

    {
        std::cout << "By assignment" << std::endl;

        unsigned int a = 6;
        Array<int> arr1(a);
        Array<int> arr2 = arr1;

        for (unsigned int i = 0; i < a; i++) {
            std::cout << arr2[i] << std::endl;
        }

        std::cout << "size is " << arr2.size() << std::endl;
    }

    return 0;
}
