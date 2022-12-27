from math import factorial
import sys

dp = [[-1 for i in range(22)] for i in range(22)]

def N(k, d):
    num = int((pow(k, d + 1) - 1) / (k - 1))
    return int(num)

def compute(k, d):

    if(k<=1):
        return 1
    if(d<=0):
        return 1
    
    num = factorial(N(k, d))
    
    N_kd = N(k,d) - 1
    N_kd1 = int(N_kd/k)
    #print(N_kd,N_kd1)

    dp[k][d] = 1
    
    dp[k][d] = (dp[k][d] * factorial(N_kd) // pow(factorial(N_kd1), k))
    dp[k][d] = dp[k][d]*pow(compute(k,d-1),k)

    return int(dp[k][d])

flag = True
while flag:
    try:
        k, d = input().split(" ")
        k,d = int(k),int(d)
        if dp[k][d] != -1:
            print(dp[k][d])
        else:
            print(compute(k, d))
    except EOFError:
        flag = False