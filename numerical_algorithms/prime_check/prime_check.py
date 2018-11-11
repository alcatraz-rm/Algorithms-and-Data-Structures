import random


def is_prime(number):
    max_tests = number // 4
    if max_tests < 10:
        max_tests = 10
    elif max_tests > 1000:
        max_tests = 1000

    for i in range(10):
        test = random.randint(1, number - 1)
        if test ** (number - 1) % number != 1:
            return False

    return True


print(is_prime(int(input('Enter the number: '))))
