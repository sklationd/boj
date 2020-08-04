D = 1000000007

def MatMul(mat1,mat2):
    a1 = mat1[0];b1 = mat1[1];c1 = mat1[2];d1 = mat1[3]
    a2 = mat2[0];b2 = mat2[1];c2 = mat2[2];d2 = mat2[3]
    return [(a1*a2 + b1*c2)%D, (a1*b2 + b1*d2)%D, (c1*a2 + d1*c2)%D, (c1*b2 + d1*d2)%D]

def MatPow(mat,n):
    if n==0:
        return [1,0,0,1]

    if n%2 == 0:
        half = MatPow(mat,n//2)
        return MatMul(half,half)
    else:
        half = MatPow(mat,n//2)
        res = MatMul(half,half)
        return MatMul(res,mat)

n = int(input())
fib = [1,1,1,0]
r = MatPow(fib,n)

print(r[1])