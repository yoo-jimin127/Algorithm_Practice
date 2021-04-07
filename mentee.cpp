#include <stdio.h>
#include <math.h>

void func_addr(double (*f)(double)) {
	if (f == cos)
		printf("cos() 함수 주소 : %p\n", f);
	else
		printf("함수의 주소 : %p\n", f);
}
int main(void) {
	func_addr(cos);
	func_addr((double(*)(double))main);

	return 0;
}