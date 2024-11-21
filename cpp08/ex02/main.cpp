#include "MutantStack.hpp"

int main()
{
    std::cout << "mstack :" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    std::cout << "top : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size : " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << std::endl << "List :" << std::endl;
    
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::list<int>::iterator end = list.end();
    end--;
    std::cout << "top : " << *end << std::endl;
    list.pop_back();
    std::cout << "size : " << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    std::list<int>::iterator lit = list.begin();
    std::list<int>::iterator lite = list.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << "Copy constructor and const_iterator test :" << std::endl;
    std::stack<int> s(mstack);
    MutantStack<int>::const_iterator cit = s.begin();
    MutantStack<int>::const_iterator cite = s.end();
    ++cit;
    --cit;
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
    
    // std::cout << std::endl;
    // std::stack<int> scpy;
    // scpy = mstack;
    // std::cout << "Copy assignment operator and reverse_iterator test : " << std::endl;
    // while (!scpy.empty())
    // {
    //     std::cout << scpy.top() << ' ';
    //     scpy.pop();
    // }
    // std::cout << std::endl;
    return 0;
}