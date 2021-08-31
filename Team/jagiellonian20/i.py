ans = []
def inverse(n):
	inv = 0
	while n > 0:
		inv *= 10
		inv += n%10
		n //= 10

	return inv

def sum_digits(n):
	s = 0
	while n > 0:
		s += 1
		n //= 10

	return s

def function(n, digitos):
	if digitos == 0:
		return
	if digitos == 1:
		ans.append(n)
		return
	if digitos == 2:
		f = n//10
		if n >= f*10 + f:
			ans.append(f*11)
			ans.append(n - 11*f)
		else:
			if f == 1:
				ans.append(9)
				ans.append(1)
			else:
				ans.append((f-1)*11)
				ans.append(1)
				ans.append(n - (f-1)*11 - 1)


		return

	pwr10 = 1
	for i in range(0, digitos//2):
		pwr10 = pwr10 * 10

	left = n // pwr10
	if digitos%2 == 1:
		left = n // (pwr10 * 10)	

	right = n % pwr10

	left_inv = inverse(left)
	
	
	if left_inv <= right:
		ans.append(n - right + left_inv)
		function(right - left_inv, digitos//2)
	else:
		left = n // pwr10
		left -= 1
		left_inv = inverse(left)
		if digitos%2 == 1:
			left_inv = inverse(left//10)
		
		ans.append(left * pwr10 + left_inv)
		n -= (left * pwr10 + left_inv)
		function(n, sum_digits(n))


t = int(input())
while t > 0:
	t -= 1

	n = int(input())
	ans = []
	function(n, sum_digits(n))

	print(len(ans))
	for x in ans:
		print(x)
