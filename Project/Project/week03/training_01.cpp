#include <iostream>
class SetValue {
	int x, y;		//기본 접근제어자는 private
public: 
	void setX(int a) {
		x = a;
	}
	void setY(int b) {
		y = b;
	}
	void print() {
		std::cout << "X = " << x << " ,Y = " << y << std::endl;
	}
};

int main() {
	SetValue obj;
	obj.setX(33);
	obj.setY(44);
	obj.print();

	return 0;
}