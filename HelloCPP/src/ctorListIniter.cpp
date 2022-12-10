#include <string>
#include <iostream>

class CTORObject
{
private:
	int m_cateIndex;
	std::string m_name;
public:
	CTORObject()
		: m_cateIndex(0), m_name("Default")
	{}

	CTORObject(int index, const std::string& name)
		: m_cateIndex(index), m_name(name)
	{}

	int getCateIndex() const {
		return m_cateIndex;
	}

	const std::string& getName() const {
		return m_name;
	}

};


void ctorListIniter() {
	CTORObject obj1;
	CTORObject obj2(1000, "Luabou");

	std::cout << obj1.getCateIndex() << "|" << obj1.getName() << std::endl;
	std::cout << obj2.getCateIndex() << "|" << obj2.getName() << std::endl;
}