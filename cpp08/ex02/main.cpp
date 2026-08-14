#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    const MutantStack<int> mstack2(mstack);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::const_iterator cit2 = mstack2.begin();
    MutantStack<int>::iterator ite = mstack.end();
    MutantStack<int>::const_iterator cite2 = mstack2.end();
    ++it;
    ++cit2;
    --it;
    --cit2;
    std::cout << mstack.top() << std::endl;
    std::cout << mstack2.top() << std::endl;
    std::cout << "\n mstack -------------  \n";

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\n mstack2 -------------  \n";
    while (cit2 != cite2)
    {
        std::cout << *cit2 << std::endl;
        ++cit2;
    }
    std::stack<int> s(mstack);

    std::cout << "\n--- Testing with std::list ---\n";

    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);

    std::cout << mlist.back() << std::endl;

    mlist.pop_back();

    std::cout << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::list<int>::iterator lit = mlist.begin();
    std::list<int>::iterator lite = mlist.end();

    ++lit;
    --lit;

    std::cout << "\n--- --------------------------- ---\n";
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    return 0;
}