#include <stdio.h>

int main() {
	long long a, b;

	scanf("%d %d", &a, &b);

	printf("%d + %d = %d\n", a, b, a + b);
    printf("%d * %d = %lld\n", a, b, a * b);
    printf("%d - %d = %d\n", a, b, a - b);
}