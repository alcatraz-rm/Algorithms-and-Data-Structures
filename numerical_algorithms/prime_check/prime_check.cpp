#include <iostream>
using namespace std;

long raise_to_power(int number, int power)
{
  long result = 1;

  while (power > 0)
  {
      if (power % 2 == 0)
      {
        power /= 2;
        number *= number;
      }
      else
      {
        power--;
        result *= number;
      }
  }

  return result;
}

bool number_is_prime(int number)
{
  int max_tests = 100, i, test;

  for(i = 0; i < max_tests; i++)
  {
    test = rand() % (number - 1) + 1;
    if (raise_to_power(test, number - 1) % number != 1)
      return false;
  }

  return true;
}

int main()
{
  srand(0);
  int number;
  cout<<"Enter the number"<<endl;
  cin>>number;
  cout<<number_is_prime(number);

  return 0;
}
