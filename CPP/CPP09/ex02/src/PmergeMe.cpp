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
	forDeque();
	
}

void debug(std::string text, std::vector<int> vec){
	std::cout << text << std::endl;
	for ( std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it )
        	std::cout << *it << " || ";
	std::cout << std::endl << std::endl;
}


void PmergeMe::forVector(){
	int count = 0;
	//* Make pairwise comparisons of [n/2] disjoint pairs of elements. (If n is odd, leave one element out.)
	for (size_t i = 0; i < vec.size() - 1; i += 2){
		if (vec[i] > vec[i + 1]){
			std::swap(vec[i], vec[i + 1]);
			count++;
		}
	}
	
	debug("ORIGINAL AFTER STEP 1", vec);


	//* Sort the pairs by their larger number
	for (size_t i = 3; i <= vec.size() - 1; i += 2){
		for (size_t d = 1; i < vec.size(); d += 2){
			if (d == i)
				break;
			if (vec[i] < vec[d]){
				count++;
				std::swap(vec[i - 1], vec[d - 1]);
				std::swap(vec[i], vec[d]);
			}	
		}
	}

	debug("ORIGINAL AFTER STEP 2", vec);


	//* CREATING MAIN CHAIN AND PEND
	std::vector<int> chain;
	std::vector<int> pend;

	chain.push_back(vec[0]);
	for (size_t i = 1; i <= vec.size() - 1; i += 2){
		chain.push_back(vec[i]);
		if (i > 1)
			pend.push_back(vec[i - 1]);
	}
	int haslonely = vec.size() % 2;
	if (haslonely){
		pend.push_back(vec[vec.size() - 1]);
	}

	//debug("MAIN CHAIN: ", chain);
	//debug("PEND: ", pend);




	std::vector<int> chainOriginal = chain;

	//* ADD THE PEND TO THE MAIN CHAIN
	int chainSize = chain.size();
	int pendSize = pend.size();

	for (int b = 0; b < chainSize / 2 - 1; b += 2){
		int b2 = b + 1;

		//* FIND INDEX ON CHAIN
		std::vector<int>::const_iterator it = std::find(chain.begin(), chain.end(), chainOriginal[b2 + 2]);
		int index = it - chain.begin();


		for (int a = 0; a < index; a++){
			if (pend[b2] < chain[a]){
				count++;
				chain.insert(chain.begin() + a, pend[b2]);
				break;
			}
			else if (a == index - 1 && pend[b2] > chain[a]){
				count++;
				chain.insert(chain.begin() + a + 1, pend[b2]);
				break;
			}
		}
		it = std::find(chain.begin(), chain.end(), chainOriginal[b + 2]);
		index = it - chain.begin();
		for (int a = 0; a < index; a++){
			if (pend[b] < chain[a]){
				count++;
				chain.insert(chain.begin() + a, pend[b]);
				break;
			}
			else if (a == index - 1 && pend[b] > chain[a]){
				count++;
				chain.insert(chain.begin() + a + 1, pend[b]);
				break;
			}
		}
	}

	//debug("CHAIN FIRST HALF", vec);
	


	for (int b = pendSize; b > chainSize / 2 - 1; b--){
		int b2 = b - 1;
		for (size_t a = 0; a < chain.size(); a++){
			if (pend[b2] < chain[a]){
				count++;
				chain.insert(chain.begin() + a, pend[b2]);
				break;
			}
			else if (a == chain.size() && pend[b2] > chain[a]){
				count++;
				chain.insert(chain.begin() + a + 2, pend[b2]);
			}
		}
	}

	//debug("CHAIN SECOND HALF", vec);
	//std::cout << "COUNT: " << count << std::endl;


}
















const std::vector<int> *PmergeMe::getVec()const {
	return &vec;
}

std::ostream &operator<<(std::ostream &os, const PmergeMe& pm){
	 for ( std::vector<int>::const_iterator it = pm.getVec()->begin(); it != pm.getVec()->end(); ++it )
        os << *it << " || ";
    return os;
}

