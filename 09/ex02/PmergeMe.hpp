#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <list>

class PmergeMe {
    private:
        std::list<long>      _args;
        std::vector<long>   _vec_nums;
        std::deque<long>    _deq_nums;
        double             _vec_time;
        double             _deq_time;
    public:
    PmergeMe(char **args, int n);
    void sort();
    void display();
    PmergeMe(PmergeMe &p);
    PmergeMe &operator=(PmergeMe &p);
    void test();
    ~PmergeMe();
};