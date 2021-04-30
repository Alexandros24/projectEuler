#include <iostream>

int main()
{
    // initialize the sum
    unsigned int sum = 0;

    // 8 x 9! = 2903040 a  digit number, thus we know that all numbers will be <= limit.
    unsigned int limit = 2903040; 

    //create a cache since we know the factorial of number 1-6.
    int cache[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    for(int i = 10; i < limit; i++) // above 1-digit numbers
    {
        unsigned int tsum = 0; // the sum of the split fact numbers.

        // split the number to its digits 
        unsigned int temp = i;
        while(temp > 0)
        {
            // add the factorial of the split num
            tsum += cache[temp % 10];

            // remove the digit from the number
            temp /= 10;
        }
        // check if tsum is equal to the number
        if(tsum == i)
            sum += i;
    }
    std::cout << "The sum is equal to: " << sum << std::endl;
}