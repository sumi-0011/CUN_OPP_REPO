#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <vector>

class Animal {
 
	char * name;
	int age;
	public:
	Animal(int age_, const char* name_) {
		age = age_;
		name = new char[strlen(name_) + 1];
		strcpy(name, name_);
	}
	Animal(const Animal & a) {//Copy constructor with deep copy
		age = a.age;
		name = new char[strlen(a.name) + 1];
		strcpy(name, a.name);
		std::cout << "Copy constructor is invoked!!\n";
	}
	~Animal(){
		 std::cout <<"Destructor!!" << std::endl;
		 delete [] name;
	}
	void changeName(const char *newName) {
		strcpy(name, newName);
	}
	void printAnimal() {
		std::cout << "Name: " << name << " Age: "
		<< age << std::endl;
	}
};
 
int main() {
	Animal A(10, "Jenny");
 
	A.printAnimal();
 
	std::vector<Animal> vec; //Vector for Animal type
 
	std::cout << "-----1st push-----\n";
	vec.push_back(A);   //Insert an Animal object to vec
	std::cout << "-----2nd push-----\n";
	vec.push_back(A);
	std::cout << "-----3rd push-----\n";
	vec.push_back(A);
	std::cout << "-----4th push-----\n";
	vec.push_back(A);
	std::cout << "-----5th push-----\n";
	vec.push_back(A);
 
	A.printAnimal();
	vec[0].printAnimal();
	vec[1].printAnimal();
	vec[2].printAnimal();
	vec[3].printAnimal();
	vec[4].printAnimal();
 
	return 0;
}
