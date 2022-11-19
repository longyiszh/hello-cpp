//void say(const char* message);
#include <iostream>

int crashProgramWithNullPointer();
void allocateMemory(int& bytes);

void initPointer() 
{
	//crashProgramWithNullPointer();
	int byteSize{8};
	int& byteSizeRef = byteSize;
	allocateMemory(byteSizeRef);
}

int crashProgramWithNullPointer() {
	// Exception thrown: write access violation.
	int* nullPointer = nullptr;
	*nullPointer = 100;
	return *nullPointer;
}

void allocateMemory(int& byteSize) {
	// char represents 1 byte
	char* buffer = new char[byteSize];

	// => Put a debugger in this line to see memory change
	memset(buffer, 0, byteSize);

	delete[] buffer;
}