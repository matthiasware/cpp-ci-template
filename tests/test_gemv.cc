#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <gemv/gemv.h>
#include <iostream>
using namespace matthiasware;

TEST_CASE("FIRST")
{
	int m = 3;
	int n = 2;
	int A[m * n] = {1,2,3,4,5,6};
	int y[3] = {4, 5, 6};
	int x[2] = {1, 2};
	int a {2};
	int b {3};
	SUBCASE(""){
		gemv<int>(A, m, n, a, x, b, y);
		CHECK(y[0] == 22);
		CHECK(y[1] == 37);
		CHECK(y[2] == 52);
	}
	SUBCASE(""){
		gemv<int>(A, m, n, a, x, 0, y);
		CHECK(y[0] == 10);
		CHECK(y[1] == 22);
		CHECK(y[2] == 34);
	}
}