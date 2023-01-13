#include <string>
#include <iostream>
#include <memory>

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
	// Using `new` to allocate on the Heap
	// Note: Whenever possible, don't do this. Allocate on the Stack instead.
	PlayerService* playerService = new PlayerService();
	playerService->SetCurrentName("Wawoo");
	playerService->SetCurrentAge(5);

	std::cout << playerService->GetName() << std::endl;
	makeGreet(playerService);

	// always call `delete` after `new` for now
	delete playerService;

	// smart pointers example
	{
		// scope 1
		std::shared_ptr<PlayerService> sharedPlayerService;
		std::weak_ptr<PlayerService> weakPlayerService;
		{
			// scope 2
			std::unique_ptr<PlayerService> uniquePlayerService = std::make_unique<PlayerService>();
			uniquePlayerService->SetCurrentAge(10);

			std::shared_ptr<PlayerService> scopedSharedPlayerService = std::make_shared<PlayerService>();
			sharedPlayerService = scopedSharedPlayerService;
			weakPlayerService = scopedSharedPlayerService;
		}
		// At this point:
		// memory of uniquePlayerService is gone!
		// but memory of sharedPlayerService is still intact.
		// -> sharedPlayerService will be gone when all references are gone.
		// memory of weakPlayerService is gone!

		std::cout << "sharedPlayerService useCount in scope 1: " << sharedPlayerService.use_count() << std::endl;
		std::cout << "weakPlayerService expired: " << weakPlayerService.expired() << std::endl;

	}

	// At this point: 
	// memory of sharedPlayerService is gone!
}