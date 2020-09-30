#include <stdio.h>
#include <iostream>
#include <memory>
class Animal {
public : 
	char* name;
	int age;
	Animal(int age_, const char* name_) {
		age = age_;
		name = new char[strlen(name_) + 1];
		strcpy(name, name_);
	}
	Animal(Animal& a) {
		age = a.age;
		name = a.name;

	}
	void changeName(const char* newName) {
		strcpy(name, newName);

	}
	void printAnimal() {
		std::cout << "Name: " << name << "Age: " << age << std::endl;
	}
};
void main() {
	Animal A(10, "jenny");
	Animal b = A;
	A.age = 22;
	A.changeName("Brown");

	A.printAnimal();
	b.printAnimal();
	getchar();
}