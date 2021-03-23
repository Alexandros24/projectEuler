//problem76//
#include <iostream>
#include <cstring>

using namespace std;

class PE0076
{
private:
    static const int max_num = 400;
public:
    long long countingSummations(int max_num);
};

long long PE0076::countingSummations(int num)
{
    long long mul_array[max_num+1] = { 0 };
    long long tmp_array[max_num+1] = { 0 };
    int fact_array[max_num+1];

    mul_array[0] = 1;
    for (int k = 0; k <= num; k++)
    {
        fact_array[k] = k + 1;
    }

    for (int i = 0; i <= num - 2; i++)
    {
        memset(tmp_array, 0, sizeof(tmp_array));  // initialize tmp_array[]

        for (int j = 0; j <= num; j += fact_array[i]) // j power
        {
            for (int k = 0; k + j <= num; k++)        // k power
            {
                tmp_array[k + j] += mul_array[k];
            }
        }
        copy(tmp_array, tmp_array+num+1, mul_array); // copy tmp_array[] to mul_array[]
    }

    return mul_array[num];
}

int main()
{
    PE0076 pe0076;

    int n = 100;

    cout << "Number " << n << " can be written " << pe0076.countingSummations(n) << " ways!" <<endl;
}