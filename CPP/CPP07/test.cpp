#include <iostream>

//* Uses more memory, more dangerous and returning a copy
template<typename T>
T max(T x, T y){ return (x>=y ? x : y);} 

//* Uses less memory if you use address, but still more dangerous and it still returns a copy
template<typename T>
T max(T & x, T & y){ return (x>=y ? x : y);}



//* Uses less memory if you use address and the const is better to be faster and safer and also returns a const to use less memory
template<typename T>
T const & max(T const & x, T const & y){ return (x>=y ? x : y);}