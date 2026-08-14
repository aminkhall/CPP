#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <climits>
#include <ctime>

struct PendingItem
{
    int value;
    int partner;
    bool hasPartner;
};

class PmergeMe
{
private:
    std::vector<int> _vector;
    std::deque<int> _deque;
    bool _isSorted;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &);
    PmergeMe &operator=(const PmergeMe &);
    ~PmergeMe();

    void isSorted(const std::vector<int> &);
    bool isDuplicate(int);
    bool isValid(const std::string &, int &);
    void parseArguments(int, char **);
    void printSequence(std::string);

    std::vector<int> generateJacobsthalSequence(int);

    std::vector<int> fordJohnsonSort(const std::vector<int> &input);
    void sortVector();

    std::deque<int> fordJohnsonSort(const std::deque<int> &input);
    void sortDeque();
};

#endif