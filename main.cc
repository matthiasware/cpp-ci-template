#include <iostream>
#include <gemv/gemv.h>

int main()
{
	using matthiasware::gemv;

	std::cout << "UPPER MAIN \n";
	int m = 3;
	int n = 2;
	int A[m * n] = {1,2,3,4,5,6};
	int y[3] = {4, 5, 6};
	int x[2] = {1, 2};
	int a {2};
	int b {3};
	gemv<int>(A, m, n, a, x, b, y);
	for(int i=0; i<m; i++)
	{
		std::cout << y[i] << std::endl;
	}

}