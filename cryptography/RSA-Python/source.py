import random


class Decoder:
    def __init__(self):
        self.prime_number_1 = 0
        self.prime_number_2 = 0
        self.module = 0
        self.secret_key = 0
        self.exponent = 0
        self.euler_function = 0

    def generate_prime_numbers(self, low_limit, top_limit):
        length = top_limit
        numbers = [True for i in range(length)]

        for i in range(2, length - 1):
            if numbers[i]:
                for j in range(i + 1, length):
                    if numbers[j] and j % i == 0:
                        numbers[j] = False

        return [i for i in range(2, length) if i > low_limit and numbers[i]]

    @staticmethod
    def is_mutually_prime(a, b):
        while b > 0:
            remainder = a % b
            a = b
            b = remainder

        if a == 1:
            return True
        else:
            return False

    def generate_exponent(self):
        self.exponent = random.randint(1, self.euler_function)

        while not self.is_mutually_prime(self.euler_function, self.exponent):
            self.exponent = random.randint(1, self.euler_function)

    def get_big_prime_numbers(self, count=2):
        prime_numbers = self.generate_prime_numbers(50, 100)

        return [prime_numbers[random.randint(0, len(prime_numbers))] for i in range(count)]

    def generate_secret_key(self):
        self.secret_key = 1

        while True:
            if (self.secret_key * self.exponent) % self.euler_function == 1:
                return

            self.secret_key += 1

    def encode(self, message):
        encoded_message = list()

        primes = self.get_big_prime_numbers()

        self.prime_number_1, self.prime_number_2 = primes[0], primes[1]
        self.module = self.prime_number_1 * self.prime_number_2
        self.euler_function = (self.prime_number_1 - 1) * (self.prime_number_2 - 1)
        self.generate_exponent()
        self.generate_secret_key()

        print(self.prime_number_1, self.prime_number_2, self.module, self.euler_function, self.exponent, self.secret_key)

        for char in message:
            print(char)
            encoded_message.append(str(ord(char) ** self.exponent % self.module))

        return ' '.join(encoded_message)

    def decode(self, encoded_message):
        encoded_message = [int(i) for i in encoded_message.split()]

        decoded_message = [chr(i ** self.secret_key % self.module) for i in encoded_message]
        return ''.join(decoded_message)


decoder = Decoder()
message = 'hello'
encoded_message = decoder.encode(message)
print(encoded_message)

decoded_message = decoder.decode(encoded_message)
print(decoded_message)
