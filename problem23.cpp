#include <iostream>
#include <vector>
#include <time.h>

int SumPrimeFactors(int a) {
	int s = 1;
	for (int k = 2; k*k <= a; k++) {
		int p = 1;
		while (a % k == 0) {
			p *= k;
			p++;
			a /= k;
		}
		s *= p;
	}
	if (a > 1) {
		s *= a + 1;
	}
	return s;
}

bool IsAbundant(int a) {
	return SumPrimeFactors(a) > a << 1;
}

int Sum(bool nonSum[], int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		if (!nonSum[i]) {
			sum += i + 1;
		}
	}
	return sum;
}

int main() {
	int start = clock();
	const int limit = 20161; // wolfram states that this is the number which above it all numbers are abundant
	
	std::vector<int> abundant;
	for (int i = 12; i <= limit; i++) {
		if (IsAbundant(i)) {
			abundant.push_back(i);
		}
	}

	bool nonSumMask[limit] = {false};
	for (int a = 0; a < abundant.size(); a++) {
		for (int b = a; b < abundant.size(); b++) {
			if (abundant[a] + abundant[b] < limit) {
				nonSumMask[abundant[a] + abundant[b] - 1] = true;
			}
		}
	}
	
	int sum = Sum(nonSumMask, limit);
	int stop = clock();
	
	std::cout << "Sum:  " << sum << std::endl;

	// Core 2 Duo E6600 @ 2.4Ghz = 22ms (when compiled with -O3)
	std::cout << "Time: " << (stop - start) / (CLOCKS_PER_SEC / 1000) << "ms" << std::endl;
}