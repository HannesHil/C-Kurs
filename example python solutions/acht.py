def fac(i):
    if i is 1:
        return 1
    else:
        return i * fac(i-1)


def fib(n):
    if n is 1:
        return 1
    elif n is 2:
        return 1
    else:
        return fib(n-1) + fib(n-2)


print(fac(10))
print(fib(5))
print(fib(27))