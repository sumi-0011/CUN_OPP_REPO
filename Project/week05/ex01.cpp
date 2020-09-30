#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>	
#include <string.h>

class Animal {
public:
	char* name;
	int age;
	Animal(int age_, const char* name_) {
		age = age_;
		name = new char[strlen(name_) + 1];
		strcpy(name, name_);
	}
	Animal(const Animal& a) {//Copy constructor with deep copy
		age = a.age;
		name = new char[strlen(a.name) + 1];
		strcpy(name, a.name);
		std::cout << "Copy constructor" << std::endl;
	}

	Animal(Animal&& a)  noexcept{	//move constructor with Shallow copy
		age = a.age;
		name = a.name;
		std::cout << "Move constructor is invoked!!\n";
		a.name = nullptr;
	}
	~Animal() {	//社瑚切 持失
		std::cout << "Destructor!!" << std::endl;
		if (name) {
			delete[] name;
		}
	}
	void changeName(const char* newName) { 
		strcpy(name, newName);
	}
	void printAnimal() {
		std::cout << "Name: " << name << "Age: " << age << std::endl;
	}
};
int main() {
	Animal A(10, "jenny");
	A.printAnimal();

	std::vector<Animal> vec;	//Vector for Animal type;

	std::cout << "-----1st push-----\n";
	vec.push_back(A);	//Insert an Animal object to vec
	std::cout << "-----2st push-----\n";
	vec.push_back(A);	//Insert an Animal object to vec
	std::cout << "-----3st push-----\n";
	vec.push_back(A);	//Insert an Animal object to vec
	std::cout << "-----4st push-----\n";
	vec.push_back(A);	//Insert an Animal object to vec
	std::cout << "-----5st push-----\n";
	vec.push_back(A);	//Insert an Animal object to vec

	A.printAnimal();
	vec[0].printAnimal();
	vec[1].printAnimal();
	vec[2].printAnimal();
	vec[3].printAnimal();
	vec[4].printAnimal();

	return 0;
}