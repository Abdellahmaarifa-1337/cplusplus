#include "PmergeMe.hpp"
#include <algorithm>

typedef std::vector<long>::size_type vec;
typedef std::deque<long>::size_type deq;
vec k = 1;

std::string trim(std::string str) {	
	size_t start, end;
	 
	start = str.find_first_not_of(" \t\v");
	end = str.find_last_not_of(" \t\v");
	if (start == std::string::npos) return ("");
	return str.substr(start, end - start + 1);
};



PmergeMe::PmergeMe(char **args, int n) : _vec_time(0), _deq_time(0) 
{
    char *str = NULL;
    // check if args correct and store them in list;
    for (int i = 0; i < n; i++)
    {
        long l = strtol(args[i], &str, 10);
        if (!trim(std::string(args[i])).size()
            || (*str && trim(std::string(str)).size()))
        {
            std::cerr << "Bad input.\n";
            exit(1);
        }
        if (l > INT_MAX || l < 0)
        {
            std::cerr << "Bad input.\n";
            exit(1);
        }
        _args.push_back(l);
    }
};

PmergeMe::PmergeMe(PmergeMe &p){
    *this = p;
};

PmergeMe &PmergeMe::operator=(PmergeMe &p){
    //_str_nums = p._str_nums;
    _args = p._args;
    _vec_nums = p._vec_nums;
    _deq_nums = p._deq_nums;
    _vec_time = p._vec_time;
    _deq_time = p._deq_time;
    return *this;
};

PmergeMe::~PmergeMe(){

};

//[-1 1 2 3 0 4]
std::vector<long> vec_merge_insert(std::vector<long> nums)
{
    int mid;
    if (nums.size() <= 1)
        return nums;
    if (nums.size() < k)
    {
        // for (vec i = 1 ; i < nums.size(); i++)
        // {
        //     long key = nums[i];
        //     std::vector<long>::iterator it = std::lower_bound(nums.begin(), nums.begin() + i, key);
        //     nums.insert(it, key);
        //     nums.erase(nums.begin() + i + 1);
        // }

        // THIS IS MORE EFFETIONT FOR VECTOR!!
        for (vec i = 1 ; i < nums.size(); i++)
        {
            long k = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > k)
            {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = k;
        }

        return nums;
    }

    // split
    mid = nums.size() / 2;


    std::vector<long> left(nums.begin(), nums.begin() + mid);
    std::vector<long> right(nums.begin() + mid, nums.end());
    left = vec_merge_insert(left);
    right = vec_merge_insert(right);

    //merge
    vec l(0),r(0),n(0);
    while (l < left.size() && r < right.size())
    {
        if (left[l] < right[r])
            nums[n++] = left[l++];
        else
            nums[n++] = right[r++];
    }

    while (l <left.size())
        nums[n++] = left[l++];

    while (r < right.size())
        nums[n++] = right[r++];
    
    return (nums);
};

std::deque<long>deq_merge_insert(std::deque<long> nums)
{
    int mid;
    if (nums.size() <= 1)
        return nums;
    if (nums.size() < k)
    {

        for (vec i = 1 ; i < nums.size(); i++)
        {
            long key = nums[i];
            std::deque<long>::iterator it = std::lower_bound(nums.begin(), nums.begin() + i, key);
            nums.insert(it, key);
            nums.erase(nums.begin() + i + 1);
        }

        // THE IS NOT EFFETIONT FOR DEQUE!
        // for (deq i = 1; i < nums.size(); i++)
        // {
        //     long k = nums[i];
        //     int j = i - 1;
        //     while (j >= 0 && nums[j] > k)
        //     {
        //         nums[j + 1] = nums[j];
        //         j--;
        //     }
        //     nums[j + 1] = k;
        // }
        return nums;
    }

    // split
    mid = nums.size() / 2;
    std::deque<long>left(nums.begin(), nums.begin() + mid);
    std::deque<long>right(nums.begin() + mid, nums.end());
    left = deq_merge_insert(left);
    right = deq_merge_insert(right);

    // merge
    deq l(0),r(0),n(0);
    while (l < left.size() && r < right.size())
    {
        if (left[l] < right[r])
            nums[n++] = left[l++];
        else
            nums[n++] = right[r++];
    }

    while (l <left.size())
        nums[n++] = left[l++];

    while (r < right.size())
        nums[n++] = right[r++];

    // std::deque<long> newnums;
    // while (left.size() && right.size())
    // {
    //     if (*(left.begin()) < *(right.begin()))
    //     {
    //         newnums.push_back(*(left.begin()));
    //         left.pop_front();
    //     }
    //     else
    //     {
    //         newnums.push_back(*(right.begin()));
    //         right.pop_front();
    //     }
    // }

    // while (left.size())
    // {
    //     newnums.push_back(*(left.begin()));
    //     left.pop_front();
    // }

    // while (right.size())
    // {
    //     newnums.push_back(*(right.begin()));
    //     right.pop_front();
    // }
    
    return (nums);
};

void PmergeMe::sort() {
    clock_t bg;
    
    bg = clock();
    _vec_nums = vec_merge_insert(std::vector<long>(_args.begin(), _args.end()));
    _vec_time = (clock() - bg) / (double)CLOCKS_PER_SEC * 1000.0; 

    bg = clock();
    _deq_nums = deq_merge_insert(std::deque<long>(_args.begin(), _args.end()));
    _deq_time = (clock() -  bg) / (double)CLOCKS_PER_SEC * 1000.0; 
}




void PmergeMe::display(){
    std::cout << "Before:\t";
    std::list<long>::iterator it = _args.begin();
    for (; it != _args.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    std::cout << "After:\t";
    for (std::vector<long>::size_type i = 0; i < _vec_nums.size(); i++)
        std::cout << _vec_nums[i] << " ";
    std::cout << "\n";
    std::cout << "Time to process a range of ";
    std::cout << _vec_nums.size() <<" elements with std::vector : ";
    std::cout << _vec_time << " ms\n";
    std::cout << "Time to process a range of ";
    std::cout << _deq_nums.size() << " elements with std::deque : ";
    std::cout << _deq_time << " ms\n";
};


void PmergeMe::test(){
    std::list<long> sorted = _args;
    sorted.sort();
    std::cout << "Testing with std::vector..." <<"\n";

    if (std::vector<long>(sorted.begin(), sorted.end()) == _vec_nums)
        std::cout << "[ success ] \n";
    else
        std::cout << "[ failed ]\n";
    
    std::cout << "Testing with std::deque..." <<"\n";
    if (std::deque<long>(sorted.begin(), sorted.end()) == _deq_nums)
        std::cout << "[ success ] \n";
    else
        std::cout << "[ failed ]\n";
}
