#include <vector>
#include <iostream>

int copyCount{0};

class IntWrap {
private:
	int m_number;

public:
	explicit IntWrap(int number) :
		m_number(number) {}

	explicit IntWrap(const IntWrap& other):
		m_number(other.m_number)
	{
		copyCount++;
	}

	const int getNumber() const {
		return m_number;
	}
};

void pushBatchToArray(std::vector<IntWrap>& integers, int batchSize) {
	for (int i = 0; i < batchSize; i++) {
		// push_back: copy the objects created in other stack into the dynamic array
		// check capacity changes
		// std::cout << "scalingBagInts capacity: " << integers.capacity() << std::endl;
		integers.push_back(IntWrap(i + 1));
	}
}

void emplaceBatchToArray(std::vector<IntWrap>& integers, int batchSize) {
	for (int i = 0; i < batchSize; i++) {
		// emplace_back: create the object in-place. No copying from another stack
		// important: should pass only the parameter list for the constructor
		integers.emplace_back(i + 1);
	}
}

void vectorDynamicArray() {
	std::vector<IntWrap> scalingBagInts;

	std::cout << "ScalingBag Init Copy Count: " << copyCount << std::endl;
	pushBatchToArray(scalingBagInts, 8);
	std::cout << "ScalingBag after 1st batch Copy Count: " << copyCount << std::endl;
	pushBatchToArray(scalingBagInts, 15);
	std::cout << "ScalingBag after 2nd Copy Count: " << copyCount << std::endl;
	// each object needs another copy into the dynamic array to be used
	// scalingBagInts capacity changes:
	// 0 => (init) => 0 => 1 => 2 => 3 => 4 => 6 => 9 => (1st Copy done) => 9 => 13 => 19 => 28 => (2nd Copy done)

	// remove the 5th element
	scalingBagInts.erase(scalingBagInts.begin() + 4);
	
	std::cout << "Stuff in the scaling bag: " << std::endl;
	// std::vector knows its size
	for (IntWrap& currentIntWrap : scalingBagInts) {
		std::cout << currentIntWrap.getNumber() << std::endl;
	}

	copyCount = 0;
	std::cout << "reset copy counter" << std::endl;

	// Avoid resizing or copying in our new bag
	std::vector<IntWrap> optimizedScalingBagInts;
	optimizedScalingBagInts.reserve(30);

	std::cout << "Optimized Scaling Bag Init Copy Count: " << copyCount << std::endl;
	emplaceBatchToArray(optimizedScalingBagInts, 8);
	std::cout << "Optimized Scaling Bag after 1st Copy Count: " << copyCount << std::endl;
	emplaceBatchToArray(optimizedScalingBagInts, 15);
	std::cout << "Optimized Scaling Bag after 2nd Copy Count: " << copyCount << std::endl;

	std::cout << "Stuff in the optimized scaling bag: " << std::endl;
	for (IntWrap& currentIntWrap : optimizedScalingBagInts) {
		std::cout << currentIntWrap.getNumber() << std::endl;
	}

}