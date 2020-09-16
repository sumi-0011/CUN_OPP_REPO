#include <iostream>
class SetValue {
	int x, y;		//디폴트 값이 private
public: 
	void setX(int a) {
		x = a;
	}
	void setY(int b) {
		y = b;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void print() {
		std::cout << "X = " << getX() << " ,Y = " << getY() << std::endl;
	}
};

int main() {
	SetValue obj;
	obj.setX(33);
	obj.setY(44);
	obj.print();

	return 0;
}