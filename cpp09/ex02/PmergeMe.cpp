#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _isSorted(true) {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printSequence(std::string message)
{
    std::cout << message;
    for (size_t i = 0; i < _vector.size(); ++i)
    {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;
}

bool PmergeMe::isValid(const std::string &arg, int &num)
{
    if (arg.empty())
        throw std::runtime_error("Error");

    std::stringstream ss(arg);
    long long tmp;
    ss >> tmp;

    if (ss.fail() || !ss.eof() || tmp > INT_MAX || tmp < 0)
        throw std::runtime_error("Error");
    num = tmp;
    return true;
}

bool PmergeMe::isDuplicate(int number)
{
    if (std::find(_vector.begin(), _vector.end(), number) != _vector.end())
        throw std::runtime_error("Error");
    return false;
}

void PmergeMe::isSorted(const std::vector<int> &container)
{
    for (size_t i = 0; i < container.size() - 1; ++i)
    {
        if (container[i] > container[i + 1])
        {
            _isSorted = false;
            return;
        }
    }
}

void PmergeMe::parseArguments(int ac, char **av)
{
    int num;
    std::string arg;
    for (int i = 1; i < ac; ++i)
    {
        arg = av[i];

        isValid(arg, num);
        isDuplicate(num);

        _vector.push_back(num);
        _deque.push_back(num);
    }

    clock_t start;
    clock_t end;
    double timeTaken;
    isSorted(_vector);
    printSequence("Before: ");
    start = std::clock();
    if (!_isSorted)
        sortVector();
    end = std::clock();

    printSequence("After:  ");
    timeTaken = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time to process a range of " << ac - 1
              << " elements with std::vector : " << timeTaken << " us" << std::endl;

    start = std::clock();
    if (!_isSorted)
        sortDeque();
    end = std::clock();

    timeTaken = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time to process a range of " << ac - 1
              << " elements with std::deque : " << timeTaken << " us" << std::endl;
}

std::vector<int> PmergeMe::generateJacobsthalSequence(int smallSize)
{
    std::vector<int> sequence;

    int jacobPrev = 1;
    int jacobCurr = 3;
    int lastInsertedSize = 1;

    while (jacobCurr < smallSize)
    {
        for (int i = jacobCurr - 1; i >= lastInsertedSize; --i)
        {
            sequence.push_back(i);
        }

        lastInsertedSize = jacobCurr;

        int nextJacob = jacobCurr + 2 * jacobPrev;
        jacobPrev = jacobCurr;
        jacobCurr = nextJacob;
    }

    for (int i = smallSize - 1; i >= lastInsertedSize; --i)
    {
        sequence.push_back(i);
    }
    return sequence;
}

std::vector<int> PmergeMe::fordJohnsonSort(const std::vector<int> &input)
{
    if (input.size() < 2)
        return input;

    std::vector<int> values(input);
    std::vector<int> winners;
    std::vector<PendingItem> pending;

    winners.reserve((values.size() + 1) / 2);
    pending.reserve((values.size() + 1) / 2);

    bool hasStraggler = false;
    int straggler = -1;

    if (values.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = values.back();
        values.pop_back();
    }

    for (size_t i = 0; i < values.size(); i += 2)
    {
        int a = values[i];
        int b = values[i + 1];

        if (a > b)
        {
            winners.push_back(a);
            pending.push_back((PendingItem){b, a, true});
        }
        else
        {
            winners.push_back(b);
            pending.push_back((PendingItem){a, b, true});
        }
    }

    std::vector<int> chain = fordJohnsonSort(winners);

    if (!chain.empty() && !pending.empty())
    {
        std::vector<int>::iterator limit = std::lower_bound(
            chain.begin(), chain.end(), pending[0].partner);
        chain.insert(std::lower_bound(
                         chain.begin(), limit, pending[0].value),
                     pending[0].value);
    }

    if (hasStraggler)
        pending.push_back((PendingItem){straggler, 0, false});

    std::vector<int> order = generateJacobsthalSequence(static_cast<int>(pending.size()));

    for (size_t i = 0; i < order.size(); ++i)
    {
        int index = order[i];
        int value = pending[index].value;

        std::vector<int>::iterator limit = chain.end();
        if (pending[index].hasPartner)
            limit = std::lower_bound(chain.begin(), chain.end(), pending[index].partner);
        chain.insert(std::lower_bound(chain.begin(), limit, value), value);
    }

    return chain;
}

void PmergeMe::sortVector()
{
    if (_vector.size() < 2)
        return;

    _vector = fordJohnsonSort(_vector);
}

std::deque<int> PmergeMe::fordJohnsonSort(const std::deque<int> &input)
{
    if (input.size() < 2)
        return input;

    std::deque<int> values(input);
    std::deque<int> winners;
    std::deque<PendingItem> pending;


    bool hasStraggler = false;
    int straggler = -1;

    if (values.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = values.back();
        values.pop_back();
    }

    for (size_t i = 0; i < values.size(); i += 2)
    {
        int a = values[i];
        int b = values[i + 1];

        if (a > b)
        {
            winners.push_back(a);
            pending.push_back((PendingItem){b, a, true});
        }
        else
        {
            winners.push_back(b);
            pending.push_back((PendingItem){a, b, true});
        }
    }

    std::deque<int> chain = fordJohnsonSort(winners);

    if (!chain.empty() && !pending.empty())
    {
        std::deque<int>::iterator limit = std::lower_bound(
            chain.begin(), chain.end(), pending[0].partner);
        chain.insert(std::lower_bound(
                         chain.begin(), limit, pending[0].value),
                     pending[0].value);
    }

    if (hasStraggler)
        pending.push_back((PendingItem){straggler, 0, false});

    std::vector<int> order = generateJacobsthalSequence(static_cast<int>(pending.size()));

    for (size_t i = 0; i < order.size(); ++i)
    {
        int index = order[i];
        int value = pending[index].value;

        std::deque<int>::iterator limit = chain.end();
        if (pending[index].hasPartner)
            limit = std::lower_bound(chain.begin(), chain.end(), pending[index].partner);
        chain.insert(std::lower_bound(chain.begin(), limit, value), value);
    }

    return chain;
}

void PmergeMe::sortDeque()
{
    if (_deque.size() < 2)
        return;

    _deque = fordJohnsonSort(_deque);
}