#include <stdio.h>
#include <iostream>
#include <string>

class Animal {
protected:
	int age;
public:
	Animal(int age) : age(age) {};
	virtual ~Animal() {}	//가상 소멸자의 선언

	virtual void printString() = 0;
	virtual int total_count(int a) = 0;

};

class Dog : public Animal {
protected:
	std::string name;
	int count = 1;
	bool isSmall;
public:
	Dog(std::string name, int age, bool isSmall) : name(name), Animal(age), isSmall(isSmall) {
	};

	void printString() {
		std::cout << "Dog Name: " << name << " / Dog's Average age: " << age << " / ";
		std::cout << " isSmallDog? = " << isSmall << " / ";
	}
	int operator+(Dog& d) {
		return this->count + d.count;
	}
	
	int total_count(int a) {
		std::cout << "Dog count: " << a << std::endl;
		return a;
	};

	virtual bool Small() {
		return false;
	}
	virtual void printSepcies() = 0;


};

class Maltese : public Dog {
public:
	Maltese(std::string name, int age, bool isSmall) : Dog(name, age, isSmall) {
		
	};
	void printSepcies() {
		std::cout << "Dog's Species: " << "Maltese" << std::endl;
	}
	bool Small() {
		return this->isSmall;
	}
};
class Poddle : public Dog {
public:
	Poddle(std::string name, int age, bool isSmall) : Dog(name, age, isSmall) {
	
	};
	void printSepcies() {
		std::cout << "Dog's Species: " << "Poddle" << std::endl;
	}
	bool Small() {
		return this->isSmall;
	}
};



class Bird : public Animal {
protected:
	int count = 1;
	bool can_swim;
public:
	Bird(int age, bool can_swim) : Animal(age), can_swim(can_swim) {};
	void printString() {
		std::cout << "Bird's Average age: " << age << " / ";
		std::cout << "canSwim? = " << can_swim << " / ";
	}
	int total_count(int a) {
		std::cout << "Bird count: " << a << std::endl;
		return a;
	};
	int operator+(Bird& b) {
		return this->count + b.count;
	}

	virtual void printSound() = 0;
	virtual bool swim() {
		return false;
	}

};
class Eagle : public Bird {
public:
	Eagle(int age, bool can_swim) : Bird(age, can_swim) {

	};
	void printSound() {
		std::cout << "Bird's Sound: " << "shriek" << std::endl;
	};
	bool swim() {
		return this->can_swim;
	}
};
class Sparrow : public Bird {
public:
	Sparrow(int age, bool can_swim) : Bird(age, can_swim) {
		
	};
	void printSound() {
		std::cout << "Bird's Sound: " << "chatter" << std::endl;
	};
	bool swim() {
		return this->can_swim;
	}
};

int main() {
	Maltese matese("max", 5, true);
	Poddle poddle("coco", 7, true);

	matese.printString();
	matese.printSepcies();
	poddle.printString();
	poddle.printSepcies();

	poddle.total_count(matese + poddle);

	Eagle eagle(6, true);
	Sparrow sparrow(2, false);

	eagle.printString();
	eagle.printSound();
	sparrow.printString();
	sparrow.printSound();

	sparrow.total_count(eagle + sparrow);



}

