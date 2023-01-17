#include <iostream>

class OldSchoolString {
private:
	char* m_buffer;
	int m_size;

public:
	OldSchoolString(const char* chars)
	{
		m_size = strlen(chars);
		m_buffer = new char[m_size + 1];
		memcpy(m_buffer, chars, static_cast<size_t>(m_size) + 1);
		m_buffer[m_size] = '\0';
	}

	OldSchoolString(const OldSchoolString& other)
		: m_size(other.m_size)
	{
		m_buffer = new char[other.m_size + 1];
		memcpy(m_buffer, other.m_buffer, static_cast<size_t>(other.m_size) + 1);
	}

	~OldSchoolString()
	{
		delete[] m_buffer;
	}

	char& operator[](unsigned int index) const {
		return m_buffer[index];
	}

	void print() {
		std::cout << m_buffer << std::endl;
	}
};

void oldSchoolStringCopy()
{
	OldSchoolString str1 = "Rub-out";
	OldSchoolString str2 = str1;

	str2[3] = '|';

	str1.print();
	str2.print();
}