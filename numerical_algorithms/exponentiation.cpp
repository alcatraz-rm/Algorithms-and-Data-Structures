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

int main()
{
  int number, power;
  cout<<"Enter number and power"<<endl;
  cin>>number>>power;
  cout<<raise_to_power(number, power);

  return 0;
}
