def phii(n):
	i = 2
	phi = 1
	while i * i <= n:
		if n % i == 0:
			e = 0
			pwr = 1
			while n % i == 0:
				pwr *= i
				n = n // i
			phi *= (i - 1) * pwr // i

		i += 1

	if n > 1:
		phi *= (n - 1)

	return phi


t = int(input())
import list

while t > 0:
	n = int(input())
	t -= 1
	p = phii(9 * n)
	d = []
	i = 1
	while i * i <= p:
		if p % i == 0:
			d.append(i)
			if i * i != p:
				d.append(p // i)
		i += 1

	list.sort(d)
	ans = 1000000000
	for x in d:
		val = 2 * (10 ** x - 1) // 9
		if val % n == 0:
			ans = min(ans, x)
			break

	if ans == 1000000000:
		print(-1)
	else:
		print(ans)

