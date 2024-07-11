#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &src){*this = src;}
PmergeMe::PmergeMe(char **arg){parse(arg);}
PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs){
	if (this != &rhs) {
        this->vec = rhs.vec;
        this->deq = rhs.deq;
    }
    return *this;
}




void debug(std::string text, std::vector<int> vec){
	std::cout << text << std::endl;
	for ( std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it )
        	std::cout << *it << " || ";
	std::cout << std::endl << std::endl;
}
void debug(std::string text, std::deque<int> deq){
	std::cout << text << std::endl;
	for ( std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it )
        	std::cout << *it << " || ";
	std::cout << std::endl << std::endl;
}

void PmergeMe::isSorted(){
	for (size_t i = 0; i < vec.size() - 1; i++){
		if (vec[i] > vec[i + 1]){
			std::cout << "ERROR ERROR ERROR ERROR ERROR ERROR ERROR ON VECTOR" << std::endl;
			break;
		}
	}
	for (size_t i = 0; i < deq.size() - 1; i++){
		if (deq[i] > deq[i + 1]){
			std::cout << "ERROR ERROR ERROR ERROR ERROR ERROR ERROR ON DEQUE" << std::endl;
			break;
		}
	}
	
}

void printvec(std::string text, std::vector<int> vec){
	std::cout << text;
	for ( std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it )
        	std::cout << *it << " ";
	std::cout << std::endl;
}

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

	//* CHECK IF IT HAS DUPLICATES (FOR MY CODE IS ERROR, IF YOU WANT TO PERMIT JUST CHANGE DOWN IN THE FUNCTION FOR THE VECTOR AND DEQUE)
	for (size_t i = 0; i < vec.size() - 1; i++){
		for (size_t d = i + 1; d < vec.size(); d++){
			if(vec[i] == vec[d]){
				std::cout << "No Duplicates, please(per favore)" << std::endl;
				return;
			}
		}
	}
	

	//* START TIMER HERE
	printvec("Before: ", vec);
	clock_t fight = clock();
	forVector();
	clock_t finishHim = clock();
	double time = static_cast<double>(finishHim - fight) / CLOCKS_PER_SEC * 1000000;
	int size = vec.size();
	printvec("After:  ", vec);
	std::cout << "Time to process a range of " << size << " elements with std::vector : " << time << " us" << std::endl;


	//* START TIMER HERE
	fight = clock();
	forDeque();
	finishHim = clock();
	time = static_cast<double>(finishHim - fight) / CLOCKS_PER_SEC * 1000000;
	size = deq.size();
	std::cout << "Time to process a range of " << size << " elements with std::deque : " << time << " us" << std::endl;

	isSorted();

}


void BinaryVec(std::vector<int>&chain, int val, int size){
	int low = 0;
    int high = size - 1;
    int mid = (high + low) / 2;
    int indexToInsert = -1;

	while(low <= high){
        if(mid < 0 || mid > size)
            break;
        if(val < chain[mid])
        {
            //check if previous index is valid and lesser than value
            if(mid - 1 >= 0)
            {
                if(chain[mid - 1] < val)
                {
                    indexToInsert = mid;
                    break;
                }
            }
            high = mid - 1;
        }
        else if(val > chain[mid])
        {
            //check if next index is valid and greater than value
            if(mid + 1 < size)
            {
                if(chain[mid + 1] > val)
                {
                    indexToInsert = mid + 1;
                    break;
                }
            }
            low = mid + 1;
        }
		mid = (high + low) / 2;
    }
    if(indexToInsert == -1)
    {
        if(mid <= 0)
            indexToInsert = 0;
        else if (mid >= size - 1)
            indexToInsert = size;
    }
    chain.insert(chain.begin() + indexToInsert, val);
}

void BinaryDeq(std::deque<int>&chain, int val, int size){
	int low = 0;
    int high = size - 1;
    int mid = (high + low) / 2;
    int indexToInsert = -1;
	//static int comp = 0;

	while(low <= high){
        if(mid < 0 || mid > size)
            break;
        if(val < chain[mid])
        {
			//comp++;
            //check if previous index is valid and lesser than value
            if(mid - 1 >= 0)
            {
                if(chain[mid - 1] < val)
                {
					//comp++;
                    indexToInsert = mid;
                    break;
                }
            }
            high = mid - 1;
        }
        else if(val > chain[mid])
        {
			//comp++;
            //check if next index is valid and greater than value
            if(mid + 1 < size)
            {
                if(chain[mid + 1] > val)
                {
					//comp++;
                    indexToInsert = mid + 1;
                    break;
                }
            }
            low = mid + 1;
        }
		mid = (high + low) / 2;
    }
	//std::cout << "COMP: " << comp << std::endl;
    if(indexToInsert == -1)
    {
        if(mid <= 0)
            indexToInsert = 0;
        else if (mid >= size - 1)
            indexToInsert = size;
    }
    chain.insert(chain.begin() + indexToInsert, val);
}

void PmergeMe::forVector(){

	//int count = 0;
	//* Make pairwise comparisons of [n/2] disjoint pairs of elements. (If n is odd, leave one element out.)
	for (size_t i = 0; i < vec.size() - 1; i += 2){
		if (vec[i] > vec[i + 1]){
			std::swap(vec[i], vec[i + 1]);
			//count++;
		}
	}
	
	//debug("ORIGINAL AFTER STEP 1", vec);


	//* Sort the pairs by their larger number
	for (size_t i = 3; i <= vec.size() - 1; i += 2){
		for (size_t d = 1; i < vec.size(); d += 2){
			if (d == i)
				break;
			if (vec[i] < vec[d]){
				//count++;
				std::swap(vec[i - 1], vec[d - 1]);
				std::swap(vec[i], vec[d]);
			}	
		}
	}

	//debug("ORIGINAL AFTER STEP 2", vec);


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

	int end = 0;
	int t = 1;
	int t_before = 0;
	int k = 2;
	int k_before = k - 1;

	std::vector<int> chainOriginal = chain;

	while (true){

		if (end == 1){
			break;
		}

		t = (pow(2, k + 1) + pow(-1, k)) /3;
		k_before = k - 1;
		t_before = (pow(2, k_before + 1) + pow(-1, k_before)) / 3;

		for (int i = t; i > t_before; i--){
			//* Correct Sequence
			if (i - 2 > static_cast<int>(pend.size()) - 1){
				end = 1;
				continue;
			}
			if (i >= static_cast<int>(chainOriginal.size())){
				BinaryVec(chain, pend[i - 2], chain.size());
			}
			else {
				std::vector<int>::const_iterator it = std::find(chain.begin(), chain.end(), chainOriginal[i]);

				int index = it - chain.begin();
				//std::cout << "DISTANCE: "<< std::distance(chain.begin(), std::find(chain.begin(), chain.end(), chainOriginal[i])) << std::endl;
				BinaryVec(chain, pend[i - 2], index);
			}
		}
		//debug("MAIN CHAIN: ", chain);
		k++;
		
	}
	vec = chain;
}


void PmergeMe::forDeque(){
	//int count = 0;
	//* Make pairwise comparisons of [n/2] disjoint pairs of elements. (If n is odd, leave one element out.)
	for (size_t i = 0; i < deq.size() - 1; i += 2){
		if (deq[i] > deq[i + 1]){
			std::swap(deq[i], deq[i + 1]);
			//count++;
		}
	}
	
	//debug("ORIGINAL AFTER STEP 1", deq);


	//* Sort the pairs by their larger number
	for (size_t i = 3; i <= deq.size() - 1; i += 2){
		for (size_t d = 1; i < deq.size(); d += 2){
			if (d == i)
				break;
			if (deq[i] < deq[d]){
				//count++;
				std::swap(deq[i - 1], deq[d - 1]);
				std::swap(deq[i], deq[d]);
			}	
		}
	}

	//debug("ORIGINAL AFTER STEP 2", deq);


	//* CREATING MAIN CHAIN AND PEND
	std::deque<int> chain;
	std::deque<int> pend;

	chain.push_back(deq[0]);
	for (size_t i = 1; i <= deq.size() - 1; i += 2){
		chain.push_back(deq[i]);
		if (i > 1)
			pend.push_back(deq[i - 1]);
	}
	int haslonely = deq.size() % 2;
	if (haslonely){
		pend.push_back(deq[deq.size() - 1]);
	}

	//debug("MAIN CHAIN: ", chain);
	//debug("PEND: ", pend);

	int end = 0;
	int t = 1;
	int t_before = 0;
	int k = 2;
	int k_before = k - 1;

	std::deque<int> chainOriginal = chain;

	while (true){

		if (end == 1){
			break;
		}

		t = (pow(2, k + 1) + pow(-1, k)) /3;
		k_before = k - 1;
		t_before = (pow(2, k_before + 1) + pow(-1, k_before)) / 3;

		for (int i = t; i > t_before; i--){
			//* Correct Sequence
			if (i - 2 > static_cast<int>(pend.size()) - 1){
				end = 1;
				continue;
			}
			if (i >= static_cast<int>(chainOriginal.size())){
				BinaryDeq(chain, pend[i - 2], chain.size());
			}
			else {
				std::deque<int>::const_iterator it = std::find(chain.begin(), chain.end(), chainOriginal[i]);
				int index = it - chain.begin();
				BinaryDeq(chain, pend[i - 2], index);
			}
		}
		//debug("MAIN CHAIN: ", chain);
		k++;
		
	}
	deq = chain;
}

const std::vector<int> *PmergeMe::getVec()const {
	return &vec;
}

std::ostream &operator<<(std::ostream &os, const PmergeMe& pm){
	 for ( std::vector<int>::const_iterator it = pm.getVec()->begin(); it != pm.getVec()->end(); ++it )
        os << *it << " || ";
    return os;
}

