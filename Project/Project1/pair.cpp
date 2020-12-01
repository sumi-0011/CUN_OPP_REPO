#include <stdio.h>
#include <iostream>
#include <string>

class Animal {
protected:
	int age;

public:
	Animal(int age) : age(age) {};
	virtual void printString()=0;
	virtual void total_count(int a)=0;
};

class Dog :public Animal {
protected:
	std::string name;
	int count = 1;
	bool isSmall;
public:
	Dog(std::string name, int age) :name(name), Animal(age) {};

	void printString(){
		std::cout << "Dog Name : " << name << " / Dog's age : " << age << " / ";
		std::cout << "isSmallDog? = " << Small() << " / ";
		printSpecies();
	};
	int operator+(Dog& d) {
		return this->count + d.count;
	};
	int operator+(int a) {
		return this->count + a;
	}
	void total_count(int a) {
		std::cout << "Dog count : " << a << std::endl;
	};
	
	//가상함수 선언
	virtual bool Small() =0;
	virtual void printSpecies() =0;

};

class Maltese : public Dog {
public:
	Maltese(std::string name, int age) : Dog(name, age) {};

	void printSpecies() {
		std::cout << "Dog's Species: Maltese" << std::endl;
	}
	bool Small() {
		return true;
	}
};

class Poddle : public Dog {
public:
	Poddle(std::string name, int age) : Dog(name, age){};

	void printSpecies() {
		std::cout << "Dog's Species: Poddle" << std::endl;
	}
	bool Small() {
		return true;
	}
};

class Retriever : public Dog {
public:
	Retriever(std::string name, int age) : Dog(name, age) {};

	void printSpecies() {
		std::cout << "Dog's Species: Retriever" << std::endl;
	}
	bool Small() {
		return false;
	}
};

class Bird  : public Animal{
protected:
	int count = 1;
public:
	Bird(int age) : Animal(age) {};
	
	void printString() {
		std::cout << "Bird's Age : " << age << " / ";
		swim();
		printSound();
	}
	int operator+(Bird& b) {
		return this->count + b.count;
	}
	int operator+(int a) {
		return this->count + a;
	}
	void total_count(int a) {
		std::cout << "Bird count : " << a << std::endl;
	}

	//가상함수 선언
	virtual void swim() = 0;
	virtual void printSound() = 0;
};
class Eagle : public Bird {
public: 
	Eagle(int age) : Bird(age) {};
	void swim() {
		std::cout << "CanSwim : " << false << " / ";
	}
	void printSound() {
		std::cout << "Eagle's Sound : shriek" << std::endl;
	}
	
};
class Sparrow : public Bird {
public:
	Sparrow(int age) : Bird(age) {};
	void  swim() {
		std::cout << "CanSwim : " << false << " / ";
	}
	void printSound() {
		std::cout << "Sparrow's Sound : chatter" << std::endl;
	}

};
class Duck : public Bird {
public:
	Duck(int age) : Bird(age) {};
	void  swim() {
		std::cout << "CanSwim : " << true << " / ";
	}
	void printSound() {
		std::cout << "Duck's Sound : quack" << std::endl;
	}
};

int main() {
	Maltese maltese("Max", 5);
	Poddle poddle("Coco", 7);
	Retriever retriever("Happy", 3);
	maltese.printString();
	poddle.printString();
	retriever.printString();

	int b = (maltese + poddle);
	retriever.total_count(retriever+b);

	Eagle eagle(23);
	Sparrow sparrow(3);
	Duck duck(7);
	eagle.printString();
	sparrow.printString();
	duck.printString();

	int a = (sparrow + duck);
	duck.total_count(eagle + a);
};