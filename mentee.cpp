#include <stdio.h>
#include <math.h>

void func_addr(double (*f)(double)) {
	if (f == cos)
		printf("cos() �Լ� �ּ� : %p\n", f);
	else
		printf("�Լ��� �ּ� : %p\n", f);
}
int main(void) {
	func_addr(cos);
	func_addr((double(*)(double))main);

	return 0;
}