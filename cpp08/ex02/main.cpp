#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    printf("i am here\n");
    std::cout << mstack.top() << std::endl;
    printf("i am here\n");
    mstack.pop();
    MutantStack<int>::iterator a = mstack.begin();
    MutantStack<int>::iterator b = mstack.end();
    while (a != b)
    {
        std::cout << "num : " << *a << std::endl;
        a++;
    }
    printf("------------");
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
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
    return 0;
}