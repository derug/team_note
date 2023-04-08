#include <stdio.h>
int main()
{
	int a = 5, b = 7;
	printf("%d\n", __builtin_popcount(a)); // 0b0101 : two
	printf("%d\n", __builtin_popcount(b)); // 0b0111 : three
	return 0;
}
__builtin_popcount(x) // x의 값을 이진수로 나타냈을 때, 1의 개수를 반환

int popcount(unsigned int n) {
	n = (n >>  1 & 0x55555555) + (n & 0x55555555);
	n = (n >>  2 & 0x33333333) + (n & 0x33333333);
	n = (n >>  4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
	n = (n >>  8 & 0x00FF00FF) + (n & 0x00FF00FF);
	n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
	return n;
}
// 위 함수 직접 구현


#include <stdio.h>
int main()
{
	int a = 5, b = 7;
	printf("%d\n", __builtin_parity(a)); // 0b0101 : two
	printf("%d\n", __builtin_parity(b)); // 0b0111 : three
	return 0;
}
__builtin_parity(x) // x의 값을 이진수로 나타냈을 때, 1의 개수가 홀수이면 1, 짝수이면 0을 반환

#include <stdio.h>
int main()
{
	int a = 5, b = 9; // 32bit signed integer type
	printf("%d\n", __builtin_clz(a)); // 00000000 00000000 00000000 00000101 : 29
	printf("%d\n", __builtin_clz(b)); // 00000000 00000000 00000000 00001001 : 28
	return 0;
}
__builtin_clz(x) // x의 값을 이진수로 나타냈을 때, MSB부터 오른쪽으로 이동하여 1이 나오기 직전까지의 0의 개수를 반환 (MSB 포함)

#include <stdio.h>
int main()
{
	int a = 16, b = 32; // 32bit signed integer type
	printf("%d\n", __builtin_ctz(a)); // 00000000 00000000 00000000 00010000 : 4
	printf("%d\n", __builtin_ctz(b)); // 00000000 00000000 00000000 00100000 : 5
	return 0;
}
__builtin_ctz(x) // LSB부터 왼쪽으로 이동하여 1이 나오기 직전까지의 0의 개수를 반환 (LSB 포함)

