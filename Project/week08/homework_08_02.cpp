#include <iostream>
#define interface struct
//interface : 소멸자와 순수 가상함수만 선언된 클래스
interface Strategy
{	
public:
	virtual int doOperation(int num1, int num2) =0;
};

class OperationAdd : public Strategy
{
public:
	virtual int doOperation(int num1, int num2) override {
		return num1 + num2;
	}
};
class OperationMultiply : public Strategy
{
public:
	virtual int doOperation(int num1, int num2) override {
		return num1 * num2;
	}
};
class OperationSubstract : public Strategy
{
public:
	virtual int doOperation(int num1, int num2) override  {
		return num1 - num2;
	}
};
class Context
{
private:
	Strategy* strategy;
public:
	Context(Strategy* s) {
		this->strategy = s;

		//std::cout << "생성자" << strategy->doOperation(10,5) << '\n';
	}
	int executeStrategy(int num1, int num2) {
		return strategy->doOperation(num1, num2);
	}
};

int main() {
	Context* context = new Context(new OperationAdd());
	std::cout << "10 + 5 = " << context->executeStrategy(10,5)<< std::endl ;

	context = new Context(new OperationSubstract());
	std::cout << "10 - 5 = " << context->executeStrategy(10, 5) << std::endl;

	context = new Context(new OperationMultiply());
	std::cout << "10 * 5 = " << context->executeStrategy(10, 5) << std::endl;
}
