#include <iostream>
#include <string>
#include <Windows.h>

class Animal {
public:
	Animal() {
		std::cout << "Person " << _name << " created. Count: " << count << std::endl;
	}

	~Animal() {
		std::cout << "Person " << _name << " deleted. Count: " << count << std::endl;
	}
private:
	// Поле возраст приватное по умолчанию https://stackoverflow.com/a/1247753
	unsigned int _age;
	std::string _name;
	static inline unsigned count{};
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Animal animals[3] {};
	
	for (Animal animal : animals) {
		std::cout << animal.name << std::endl;
	}
	
	std::cout << std::endl << "Имя\tВозраст\tВес" << std::endl;
	std::cout << animals[4]._name << '\t' << animals[4].age << '\t' << animals[4].weight << std::endl;

	try {
		animals[4]._age = 2;
	}
	catch (...) {
		std::cout << "У сторонних методов нет доступа к приватным членам класса" << std::endl;
	}

	std::cout << animals[4]._name << '\t' << animals[4]._age << '\t' << animals[4].weight << std::endl;
	return 0;
}