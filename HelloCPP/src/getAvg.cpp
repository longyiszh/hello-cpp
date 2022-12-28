#include <iostream>

double getAvgFunc(const int nums[], int size) {
	int sum{};
	for (int i = 0; i < size; i++) {
		sum += nums[i];
	}

	return sum / (double)size;
}

void getAvg() {
	const int nums[]{ 1, 2, 3, 4, 5 };
	std::cout << getAvgFunc(nums, 5) << std::endl;
}
