#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    /* initialize random seed: */
    srand(time(NULL));

    Base *one = generate();
    Base *two = generate();
    Base *three = generate();
    Base *four = generate();

    identify(one);
    identify(*one);
    identify(two);
    identify(*two);
    identify(three);
    identify(*three);
    identify(four);
    identify(*four);

    Base *five = NULL;

    identify(five);
    identify(*five);

    delete one;
    delete two;
    delete three;
    delete four;

    return 0;
}
