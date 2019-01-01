#ifndef GEMV_H_
#define GEMV_H_

namespace matthiasware {
// y = a A x + b y
// y (m)
// a (1)
// A (m, n)
// x (n)
// b (1)
template <typename T>
void gemv(T* A, int m, int n, T a, T *x,  T b, T *y);

template <typename T>
void gemv(T* A, int m, int n, T a, T *x,  T b, T *y)
{
	for(int r=0; r<m; ++r)
	{
		y[r] = b * y[r];
		for(int c=0; c<n; ++c)
		{
			y[r] += a * A[r * n + c] * x[c];
		}
	}
}

} // namespace: matthiasware

#endif  // GEMV_H_
