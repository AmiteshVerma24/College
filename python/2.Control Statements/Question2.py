# Find the sum of all the primes below two million.
import math
current, limit, total = 2, 2000000, 0

def check_prime(num):
    cur = 2
    while(cur <= math.sqrt(num)):
        if(num % cur == 0):
            return False
        cur += 1
    return True

while(current <= limit):
    if(check_prime(current)):
        total += current
    current += 1
print("The sum is: ", total)