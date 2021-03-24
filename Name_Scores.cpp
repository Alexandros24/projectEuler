#include <fstream>
#include <iostream>
#include <cmath>

int main()
{
    char al[26];
    size_t len = sizeof(al) / sizeof(al[0]);
    for(int i = 0; i < len; i++)
        al[i] = 65 + i; //ascii values (65 is A)
    std::cout << al[1] << std::endl;
}