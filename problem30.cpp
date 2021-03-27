//problem 30//
#include <iostream>
#include <cmath>

int main()
{
    int result(0);
    for (int i = 2; i < 10e6; i++)
    { 
        int sumOfPowers = 0; 
        int number = i; 
        while (number > 0) 
        {
            int d = number % 10;
            number /= 10;
 
            int temp = d;
            for(int j = 1; j < 5; j++)
            {
            temp *= d;
            }
        sumOfPowers += temp;
        }
 
        if (sumOfPowers == i) 
        {
            result += i;
        }
    }
    std::cout << "The sum of fifth...: "<< result << std::endl;
}