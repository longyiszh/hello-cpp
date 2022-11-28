#include <string>
#include <iostream>

class IGreetable {
public:
	virtual std::string Greet() = 0;
};

class EntityService : public IGreetable
{
protected:
	std::string m_CurrentName;

public:
	virtual std::string GetName()
	{
		return m_CurrentName;
	}
	void SetCurrentName(std::string newName)
	{
		m_CurrentName = newName;
	}
	std::string Greet() override
	{
		return "Basic hello";
	}
};

class PlayerService : public EntityService
{
private:
	int m_CurrentAge{0};

public:
	std::string GetName() override
	{
		return m_CurrentName + " " + std::to_string(m_CurrentAge);
	}
	void SetCurrentAge(int newAge)
	{
		m_CurrentAge = newAge;
	}
	std::string Greet() override
	{
		return "Dance and sing and laugh and rooooolll!";
	}
};

void makeGreet(IGreetable* greeter) {
	std::cout << greeter->Greet() << std::endl;
}

void classing() {
	PlayerService* playerService = new PlayerService();
	playerService->SetCurrentName("Wawoo");
	playerService->SetCurrentAge(5);

	std::cout << playerService->GetName() << std::endl;
	makeGreet(playerService);
	
}