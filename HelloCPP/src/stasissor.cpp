#include <iostream>

class Singleton {
private:
	int m_count{};
public:
	explicit Singleton()
	{
		std::cout << "<!> Singleton created." << std::endl;
	}
	static Singleton& GetInstance() {
		// being static means it is created only once and exists forever
		static Singleton intance;
		return intance;
	}
	// getter - setter
	const int getCount() const {
		return m_count;
	}

	void setCount(int newCount) {
		m_count = newCount;
	}
};

void stasissor() {
	// Store by reference. We don't want to copy
	Singleton& instance1 = Singleton::GetInstance();
	instance1.setCount(100);

	std::cout << "instance1 Count: " << instance1.getCount() << std::endl;

	Singleton& instance2 = Singleton::GetInstance();
	instance2.setCount(200);

	std::cout << "instance2 Count: " << instance2.getCount() << std::endl;

	// We can see instance1 Count is also changed 
	std::cout << "instance1 After Count: " << instance1.getCount() << std::endl;
}
