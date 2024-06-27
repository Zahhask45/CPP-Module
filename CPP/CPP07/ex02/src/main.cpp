#include "Array.hpp"
#include <iostream>
#include <cstdlib> 

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0; //!Exception
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0; //!Exception
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

/* 
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
 */
