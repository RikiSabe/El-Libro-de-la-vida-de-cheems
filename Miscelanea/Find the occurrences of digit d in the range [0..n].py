import math

def myCountX(N, X):
	e = int(math.log10(N))
	r = 0

	while e >= 0:
		x = N // 10**e % 10
		a = x * e * 10**(e - 1)
		r += a

		if x == X:
			a = N % 10**e + 1

			if X == 0:
				a -= 10**e

			r += a

		if x > X and X != 0:
			a = 10**e
			r += a

		e -= 1

	return r

if __name__ == "__main__":
	N = 1000
	X = 0
	print(myCountX(N, X)) # Output: 192
