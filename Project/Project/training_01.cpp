#include <iostream>
class SetValue {
	int x, y;		//�⺻ ���������ڴ� private
public: 
	void setXY(int a, int b) {
		x = a;
		y = b;
	}
	void show() {
		std::cout << "X = " << x << " ,Y = " << y << std::endl;
	}
};

int main() {
	SetValue obj;
	obj.setXY(33, 44);
	obj.show();

	return 0;
}