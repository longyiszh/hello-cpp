#include <iostream>
#include <string>

bool explicitContains(const std::string& input, const std::string& search) {
	return input.find(search) != std::string::npos;
}

void stringShape() {
	using namespace std::string_literals;

	std::string aString{ "hello" };

	// concatenation
	aString += " ABC ";
	// This is wrong: aString = "PP" + " PPT" - You can't add two pointers
	aString += "PP" + std::string(" PPT");

	// Standard C way of string
	const char* searchToken{ "ccd" };

	if (explicitContains(aString, searchToken)) {
		std::cout << aString << " Contains " << searchToken << std::endl;
	}
	else {
		std::cout << aString << " does not contain " << searchToken << std::endl;
	}

	// std::string_literals namespace available utils
	// concatenation
	std::string bString{ "hello "s + "PPT"s }; // <== letter s

	const char* multiLineStr{
		R"(
			"Console"
			"."
			"WriteLine("Hello world from C#")
		)"
	};

	std::cout << "bString: " << bString << std::endl;
	std::cout << "multiLineStr: " << multiLineStr << std::endl;

}