// C++ program for the above approach 
  
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to check if a 
// number is prime or not 
int isprm(long n) 
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
  
// Function to count the prime numbers 
// which can be expressed as sum of  
// consecutive prime numbers 
int countprime(long n) 
{ 
    // Initialize count as 0 
    int count = 0; 
  
    // Stores prime numbers 
    vector<int> primevector; 
  
    for (int i = 2; i <= n; i++) { 
  
        // If i is prime 
        if (isprm(i) == 1) { 
            primevector.push_back(i); 
        } 
    } 
  
    // Initialize the sum 
    int sum = primevector[0]; 
  
    // Find all required primes upto N 
    for (int i = 1; 
         i < primevector.size(); i++) { 
  
        // Add it to the sum 
        sum += primevector[i]; 
        if (sum > n) 
            break; 
        if (isprm(sum) == 1) { 
            count++; 
        } 
    } 
  
    // Return the final count 
    return count; 
} 
  
// Driver Code 
int main() 
{ 
    // Given number N 
    long N = 1e6 - 1; 
  
    // Function Call 
    cout << countprime(N); 
  
    return 0; 
} 
