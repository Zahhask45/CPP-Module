#include "MutantStack.hpp"


int main() {
    {
        std::cout << "SUBJECT TESTS" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "top:" << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size:" << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        std::cout << "iterating through the stack:" << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "---------------" << std::endl;

    {
        std::cout << "TEST 1 -> Checking empty stack" << std::endl;
        MutantStack<int> mstack;

        std::cout << "Is Stack empty?" << std::endl;
        if (mstack.empty()) {
            std::cout << "is empty" << std::endl;
        } else {
            std::cout << "is not empty" << std::endl;
        }

        mstack.push(45);
        std::cout << "A number was pushed" << std::endl;

        std::cout << "Is Stack empty?" << std::endl;
        if (mstack.empty()) {
            std::cout << "is empty" << std::endl;
        } else {
            std::cout << "is not empty" << std::endl;
        }
    }

    std::cout << "---------------" << std::endl;

    {
        std::cout << "TEST 2 -> Stack size " << std::endl;
        MutantStack<int> terracota, banana;

        terracota.push(45);
        terracota.push(95);
        terracota.push(420);
        banana.push(4011);
        banana.push(0);

        std::cout << "before swap" << std::endl;

        std::cout << "size of terracota: " << terracota.size() << std::endl;
        std::cout << "size of banana: " << banana.size() << std::endl;

        std::swap(terracota, banana);
        std::cout << "after swap" << std::endl;

        std::cout << "size of terracota: " << terracota.size() << std::endl;
        std::cout << "size of banana: " << banana.size() << std::endl;
    }

    return 0;
}
