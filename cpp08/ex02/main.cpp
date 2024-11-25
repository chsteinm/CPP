#include "MutantStack.hpp"

int main()
{
    {
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
        std::stack<int> s(mstack);
        std::cout << "Elements in s in reverse order : ";
        while (!s.empty())
        {
            std::cout << s.top() << ' ';
            s.pop();
        }
        std::cout << std::endl;
        std::stack<int> scpy;
        scpy = mstack;
        std::cout << "Elements in scpy in reverse order : ";
        while (!scpy.empty())
        {
            std::cout << scpy.top() << ' ';
            scpy.pop();
        }
        std::cout << std::endl;

        std::cout << "const_iterator test :" << std::endl;
        MutantStack<int>::const_iterator cit = mstack.begin();
        MutantStack<int>::const_iterator cite = mstack.end();
        while (cit != cite)
        {
            std::cout << *cit << std::endl;
            ++cit;
        }
        std::cout << "reverse_iterator test :" << std::endl;
        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();
        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            ++rit;
        }
        std::cout << "const_reverse_iterator test :" << std::endl;
        MutantStack<int>::const_reverse_iterator crit = mstack.crbegin();
        MutantStack<int>::const_reverse_iterator crite = mstack.crend();
        while (crit != crite)
        {
            std::cout << *crit << std::endl;
            ++crit;
        }
    }
    std::cout << std::endl;
    {
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
        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    return 0;
}