#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}


//! NEED A BETTER WAY TO HANDLE DECIMALS
void PmergeMe::parse(char **arg){
	for (size_t i = 0; arg[i]; i++){
		for (size_t d = 0; arg[i][d]; d++){
			if(!isdigit(arg[i][d])){
				std::cout << "Not a valid list" << std::endl;
				return ;
			}
		}
		std::string str = arg[i];
		vec.push_back(static_cast<int>(atof(str.c_str())));
		deq.push_back(static_cast<int>(atof(str.c_str())));
	}

	//* START TIMER HERE
	forVector();
	//* START TIMER HERE
	
}


void PmergeMe::forVector(){
	//int haslonely = vec.size() % 2;

	for (size_t i = 0; i < vec.size() - 1; i += 2){
		if (vec[i] > vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
	}
	
	std::cout << "ORIGINAL BEFORE" << std::endl;
	for ( std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it )
        		std::cout << *it << " || ";
	std::cout << std::endl << std::endl;
	int size = vec.size();
	 for (int k = 2; k < size; k *= 2) {
        for (int i = 0; i < size; i += 2 * k) {
            int leftsubarray = i; // Start index of the left subarray
            int rightsubarry = std::min(i + k, size); // Start index of the right subarray
            int endleftsubarray = rightsubarry; // End index of the left subarray (start of right subarray)
            int endrightsubarry = std::min(i + 2 * k, size); // End index of the right subarray



            std::vector<int> merged;// Temporary deque to hold merged results

            // Merge the two subarrays
            while (leftsubarray < endleftsubarray && rightsubarry < endrightsubarry) {
				std::cout << vec[leftsubarray] << std::endl;
				std::cout << vec[rightsubarry] << std::endl;
                if (vec[leftsubarray] < vec[rightsubarry]) {
                    merged.push_back(vec[leftsubarray++]);
                } else {
                    merged.push_back(vec[rightsubarry++]);
                }
            }

            // Add any remaining elements from the left subarray
            while (leftsubarray < endleftsubarray) {
                merged.push_back(vec[leftsubarray++]);
            }

            // Add any remaining elements from the right subarray
            while (rightsubarry < endrightsubarry) {
                merged.push_back(vec[rightsubarry++]);
            }

            // Copy the merged elements back into the original deque
            std::copy(merged.begin(), merged.end(), vec.begin() + i);
			std::cout << "MERGED: ";
			for ( std::vector<int>::const_iterator it = merged.begin(); it != merged.end(); ++it )
        		std::cout << *it << " || ";
			std::cout << std::endl << "ORIGINAL: ";
			for ( std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it )
        		std::cout << *it << " || ";
			std::cout << std::endl << "END OF LOOP" << std::endl;
        }
    }


}
















const std::vector<int> *PmergeMe::getVec()const {
	return &vec;
}

std::ostream &operator<<(std::ostream &os, const PmergeMe& pm){
	 for ( std::vector<int>::const_iterator it = pm.getVec()->begin(); it != pm.getVec()->end(); ++it )
        os << *it << " || ";
    return os;
}

