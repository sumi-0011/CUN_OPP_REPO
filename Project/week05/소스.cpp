#include <stdio.h>

class Animal {
public:
	Animal(int numberOfLeg) {
		this->numberOfLeg = numberOfLeg;

	}
private:
	int numberOfLeg;
};
int main() {
	Animal a = Animal(1);
	return 0;
}