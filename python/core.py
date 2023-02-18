a = 'abc'
l = [a[i:j]for i in range(len(a)) for j in range(i+1,len(a)+1)]
print(l)