#include <iostream>
#include "Array.hpp"
#include "Array.cpp"
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    
    //const tests
    const Array<int> constNumbers(numbers);
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (constNumbers[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    const Array<int> constNumbers2 = constNumbers;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (constNumbers2[i] != constNumbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    numbers.~Array();
    int index = rand() % MAX_VAL;
    std::cout << "value of constNumbers index " << index << " is = " << constNumbers[index] << std::endl;
    std::cout << "value of constNumbers2 index " << index << " is = " << constNumbers2[index] << std::endl;
    // constNumbers[index] = 42;
    return 0;
}