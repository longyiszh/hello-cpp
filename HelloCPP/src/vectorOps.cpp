#include <string>
#include <iostream>

struct Vector2
{
	float x;
	float y;

	Vector2 add(const Vector2& other) const {
		return Vector2{
			.x{x + other.x},
			.y{y + other.y}
		};
	}

	Vector2 operator+(const Vector2& other) const {
		return add(other);
	}

	Vector2 multiply(const Vector2& other) const {
		return Vector2{
			.x{x * other.x},
			.y{y * other.y}
		};
	}

	Vector2 operator*(const Vector2& other) const {
		return multiply(other);
	}

	bool equals(const Vector2& other) const {
		return x == other.x && y == other.y;
	}

	bool operator==(const Vector2& other) const {
		return equals(other);
	}

	bool operator!=(const Vector2& other) const {
		return !equals(other);
		// Also doable:
		//   return !this->equals(other);
		//   return !(*this == other) 
		//   return !operator==(other);
	}

	std::string toString() const {
		return "X: " + std::to_string(x) + ", Y: " + std::to_string(y);
	}

};

/**
* Overloading `<<` operator
*/
std::ostream& operator<<(std::ostream& stream, const Vector2& vector) {
	stream << "left shift overriden --> " << "X: " << vector.x << ", Y: " << vector.y;
	return stream;
}

void vectorOps() {
	Vector2 position{
		.x{4.0f},
		.y{3.0f}
	};

	Vector2 speed{
		.x{2.0f},
		.y{5.2f}
	};

	Vector2 accelerator{
		.x{1.5f},
		.y{0.8f}
	};

	Vector2 result1A{ position.add(speed) };
	Vector2 result1B{ position + speed };
	Vector2 result2A{ position.add(speed.multiply(accelerator)) };
	// Note, operator priority does not change even after overloading.
	// `*` executes first before `+`
	Vector2 result2B = position + speed * accelerator;

	std::cout << "result1A: " << result1A.toString() << std::endl;
	std::cout << "result1B: " << result1B.toString() << std::endl;
	std::cout << "result2A: " << result2A.toString() << std::endl;
	std::cout << "result2B: " << result2B.toString() << std::endl;

	// With `<<` overriden, this works too:
	std::cout << "result2B: " << result2B << std::endl;

	// Equal check

	std::cout << "result1A == result1B: " << (result1A == result1B) << std::endl;
	std::cout << "result1A != result1B: " << (result1A != result1B) << std::endl;

}