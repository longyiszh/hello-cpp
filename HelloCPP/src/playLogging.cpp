#include <iostream>

class HCPLogger {

private:
	int m_logLevel{0};

public:
	static const int INFO{ 0 };
	static const int WARNING{ 1 };
	static const int ERROR{ 2 };

public:

	void setLogLevel(int level) {
		m_logLevel = level;
	}

	void logInfo(const char* message) {
		if (m_logLevel <= INFO) {
			std::cout << "[Info]:" << message << std::endl;
		}
	}

	void logWarning(const char* message) {
		if (m_logLevel <= WARNING) {
			std::cout << "[WARNING]:" << message << std::endl;
		}
	}

	void logError(const char* message) {
		if (m_logLevel <= ERROR) {
			std::cout << "[ERROR]:" << message << std::endl;
		}
	}

};

void playLogging() {
	int currentLogLevel{ HCPLogger::INFO };
	HCPLogger logger;
	logger.setLogLevel(currentLogLevel);

	logger.logInfo("Good news! Logger has started.");
	logger.logWarning("The key element might have been mis-spelled.");
	logger.logError("Forbidden operation. This incident will be reported.");
}