#include <string>
#include <iostream>

class CommonEntity {
private:
	int m_age{0};
	std::string m_name{};

public:
	mutable float popularity{ 0.0 };

	int getAge() const {
		// popularity marked as mutable, so can still be modified even if medthod is a getter
		popularity += 1.0;
		return m_age;
	}

	int setAge(int newAge) {
		popularity += 3.0;
		m_age = newAge;

		return m_age;
	}

	const std::string& getName() const {
		return m_name;
	}

	std::string setName(const std::string& newName) {
		m_name = newName;

		return newName;
	}
};

void readCommonEntity(const CommonEntity& entity) {
	// popularity marked as mutable, so I can still modify even if class is const reference
	entity.popularity += 55.5;

	std::cout << entity.getAge() << std::endl;
	std::cout << entity.getName() << std::endl;
	std::cout << entity.popularity << std::endl;
}

void contesto() {
	CommonEntity entity;
	entity.setAge(10);
	entity.setName("Good");

	readCommonEntity(entity);

}