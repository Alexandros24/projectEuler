//problima 50
#include <stdio.h>
#include <math.h>
#include <time.h>

int isPrime(long n);

int main()
{
    clock_t begin = clock();
    long primes[10000];
    size_t len = sizeof(primes) / sizeof(primes[0]);
    int k = 0;
    for(int i = 0; i < 10000; i++)
    {
        if(isPrime(i) == 1)
        {
            primes[k] = i;
            k++;
        }
    }
    long max = 0;
    int thmax = -1;
    for(int i = 0; i < len; i++)
    {
        long sum = 0;
        for (int j = i; j < len; j++) 
        {
            sum+= primes[j];
            if (sum > 10e5)
                break;
            if(isPrime(sum) == 1 && sum > max && j - i > thmax) 
            {
                thmax = j - i;
                max = sum;
            }
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%li\nTime: %f\nIt requires some optimizing, but not now(dynamic memory allocation)", max, time_spent);

    return 0;
}

int isPrime(long n)
{
    if(n == 2)
        return 1;
    for(int i = 2; i < sqrt(n) + 1; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}