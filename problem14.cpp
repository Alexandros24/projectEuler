#include <iostream>

int main()
{
    //working with checkpoints
    int N           = 1000000;
    int CHECKPOINT  = 800000;
    long long nTemp = N;
    int chainCount  = 1;
    int check       = 0;
    long long myNum = 0;
    
    for (int i = N; i > CHECKPOINT; --i)
    {
        while (nTemp != 1)
        {
            if ((nTemp%2) == 0)
            {
                nTemp = nTemp/2;
            }   
            else
            {
                nTemp = (nTemp*3) + 1;
            }
            ++chainCount;
        }
        --N;
        nTemp = N;
        
        if (check < chainCount)
        {
            check = chainCount;
            myNum = nTemp;
        }
        chainCount = 1;
    }
    std::cout << "The number " << myNum + 1 << " has longest chain of " << check << std::endl;
}