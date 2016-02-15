def lis(arr):
	n=len(arr)
	#initialise
	# [1]*n is a row matix of valuue 1
	lis=[1]*n
	for i in range(1,n):
		for j in range(0,i):
			if arr[i]>arr[j] and lis[i]<lis[j] + 1:
				lis[i]=lis[j]+1
	maxi=max(lis)
	return maxi

arr=[10, 22, 9, 33, 21, 50, 41, 60]
print "Length of LIS is ",lis(arr)
