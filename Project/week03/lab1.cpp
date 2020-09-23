#include <stdio.h>


int getByte(int x, int n) {
	int g;
	int k = n << 3;
	//printf("n : %#x\n",k);
	g = x >> (n<<3);
	//printf("g : %#x\n",g);
	return g&0xFF;
	
}
int main() {
	printf("getByte(0x12345678, 1) : %#x\n", getByte(0x12345678, 1));
	printf("getByte(0xDEADBEEF, 1) : %#x\n", getByte(0xDEADBEEF, 1));
}