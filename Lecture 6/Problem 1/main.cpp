#include <iostream>

void foo(int n, int sum)
{
	int k = 0, j = 0;
	if (n == 0) return;
	k = n % 10;
	j = n / 10;
	sum = sum + k;
	std::cout << j << " " << sum << std::endl;
	foo(j, sum);
	printf("%d", k);
}
int main()
{
	int a = 2048, sum = 0;
	foo(a, sum);
	printf("%d", sum);
}

/*
Result: 20480
Explanation: First iteration of foo passes to secound iteraion with (204, 8).
			 Secound iteration passes to third iteration with (20, 12).
			 Third iteration passes to fourth iteration with (2, 12).
			 Fourth iteration passes to Fith iteration with (0, 14).
			 After this it's printing k in reverse order.
*/