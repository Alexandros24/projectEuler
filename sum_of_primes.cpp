#include <iostream>
using namespace std;

int isPrime(long n) 
{ 
    // Base Case 
    if (n <= 1) 
        return 0; 
    if (n <= 3) 
        return 1; 
    if (n % 2 == 0 || n % 3 == 0) 
        return 0; 
  
    // Iterate till [5, sqrt(N)] to 
    // detect primality of numbers 
    for (int i = 5; 
         i * i <= n; i = i + 6) { 
  
        // If N is divisible by i 
        // or i + 2 
        if (n % i == 0 || n % (i + 2) == 0) 
            return 0; 
    } 
  
    // Return 1 if N is prime 
    return 1; 
} 

int main()
{
    long long sum = 0;
    long n = 2000000;
    while(n >= 2)
    {
        if(isPrime(n) == 1)
        {
            sum += n;
        }
        n--;       
    }
    cout << sum << endl;
}