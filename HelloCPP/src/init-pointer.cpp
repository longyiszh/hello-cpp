//void say(const char* message);
#include <iostream>

int crashProgramWithNullPointer();
void allocateMemory();

void initPointer() 
{
	//crashProgramWithNullPointer();
	allocateMemory();
}

int crashProgramWithNullPointer() {
	// Exception thrown: write access violation.
	int* nullPointer = nullptr;
	*nullPointer = 100;
	return *nullPointer;
}

void allocateMemory() {
	// char represents 1 byte
	char* buffer = new char[8];

	// => Put a debugger in this line to see memory change
	memset(buffer, 0, 8);

	delete[] buffer;
}