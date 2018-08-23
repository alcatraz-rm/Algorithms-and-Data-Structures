import random
import json


def read_message():
    with open('message.txt', 'r', encoding='utf-8') as file:
        return file.read()


class Decoder:
    def __init__(self):
        self.data = dict()

        try:
            self.read_data()

            try:
                if self.data_is_correct():
                    self.prime_number_1 = self.data['prime_number_1']
                    self.prime_number_2 = self.data['prime_number_2']
                    self.module = self.data['module']
                    self.secret_key = self.data['secret_key']
                    self.exponent = self.data['public_key_exponent']
                    self.euler_function = self.data['euler_function_result']

                else:
                    self.generate_keys()
            except:
                self.generate_keys()

        except:
            self.generate_keys()

    def data_is_correct(self):
        for key in self.data:
            if not self.data[key]:
                return False

        if not self.is_mutually_prime(self.data['prime_number_1'], self.data['prime_number_2']):
            return False

        if self.data['module'] != self.data['prime_number_1'] * self.data['prime_number_2']:
            return False

        if self.data['euler_function_result'] != (self.data['prime_number_1'] - 1) * (self.data['prime_number_2'] - 1):
            return False

        if not 1 <= self.data['public_key_exponent'] <= self.data['euler_function_result'] or \
           not self.is_mutually_prime(self.data['public_key_exponent'], self.data['euler_function_result']):
            return False

        if self.data['public_key_exponent'] * self.data['secret_key'] % self.data['euler_function_result'] != 1:
            return False

        return True

    def read_data(self):
        with open('config.json', 'r', encoding='utf-8') as file:
            self.data = json.load(file)

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
        prime_numbers = self.generate_prime_numbers(100, 500)

        return [prime_numbers[random.randint(0, len(prime_numbers))] for i in range(count)]

    def generate_secret_key(self):
        self.secret_key = 1

        while True:
            if (self.secret_key * self.exponent) % self.euler_function == 1:
                return

            self.secret_key += 1

    def encode(self, message):
        encoded_message = ';\n'.join([str(ord(char) ** self.exponent % self.module) for char in message])

        with open('result.txt', 'w', encoding='utf-8')as file:
            file.write(encoded_message)

        return encoded_message

    def decode(self, encoded_message):
        encoded_message = [int(i) for i in encoded_message.split(';\n')]

        return ''.join([chr(i ** self.secret_key % self.module) for i in encoded_message])

    def generate_keys(self):
        primes = self.get_big_prime_numbers()

        self.prime_number_1, self.prime_number_2 = primes[0], primes[1]
        self.module = self.prime_number_1 * self.prime_number_2
        self.euler_function = (self.prime_number_1 - 1) * (self.prime_number_2 - 1)
        self.generate_exponent()
        self.generate_secret_key()

        print('prime numbers: %d %d' % (self.prime_number_1, self.prime_number_2))
        print('module: %d' % self.module)
        print('euler function result: %d' % self.euler_function)
        print('public key exponent: %d' % self.exponent)
        print('secret key: %d\n' % self.secret_key)

        with open('config.json', 'w', encoding='utf-8') as file:
            json.dump({'prime_number_1': self.prime_number_1,
                       'prime_number_2': self.prime_number_2,
                       'module': self.module,
                       'euler_function_result': self.euler_function,
                       'public_key_exponent': self.exponent,
                       'secret_key': self.secret_key}, file, indent=4)


decoder = Decoder()
message = read_message()
encoded_message = decoder.encode(message)
print(encoded_message)

decoded_message = decoder.decode(encoded_message)
print(decoded_message)
