#include <vector>
#include <iostream>

void pushBatchToArray(std::vector<int>& integers, int batchSize) {
	for (int i = 0; i < batchSize; i++) {
		integers.push_back(i + 1);
	}
}

void vectorDynamicArray() {
	std::vector<int> scalingBagInts;

	pushBatchToArray(scalingBagInts, 8);

	pushBatchToArray(scalingBagInts, 15);

	// remove the 5th element
	scalingBagInts.erase(scalingBagInts.begin() + 4);
	
	std::cout << "Stuff in the scaling bag: " << std::endl;
	// std::vector knows its size
	for (int currentInteger : scalingBagInts) {
		std::cout << currentInteger << std::endl;
	}

}