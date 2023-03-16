# Novel Permutation Algorithm By Promise Anendah
# February 2023
# Permutation Implementation in Python

def swap(arr, a, b):
	temp = arr[a]
	arr[a] = arr[b]
	arr[b] = temp

def permutate(items):
	a = 0
	n = len(items)
	permutes = [items]
	temps = []
	while(a < n - 1):
		# print('stage',a+1)
		for perm in permutes:			
			for i in range(a+1, n):
				# print('now working {0}'.format(perm))
				mPerm = list(perm)
				# print('a,i-', a,i)
				swap(mPerm, a, i)
				# print(mPerm)
				temps.append(mPerm)
		permutes += temps
		# print(permutes)
		temps = []
		a += 1
	# print(permutes)
	print(len(permutes), 'permutations')
	return permutes

if __name__ == "__main__":
	items = [1,2,3,4,6,7,8,9,10]
	permutations = permutate(items)
	print('printing all {0} permutations'.format(len(permutations)))
	for perm in permutations:
		print(perm)