#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> find_factors(int number)
{
  vector<int> factors;
  int i, max_factor, key;

  if(number % 2 == 0)
  {
    factors.push_back(2);
    key = 0;
  }

  while(number % 2 == 0)
  {
      if (factors[key] != 2)
      {
        factors.push_back(2);
        key = factors.size() - 1;
      }

      number /= 2;
  }

  i = 3;
  max_factor = sqrt(number);

  while(i <= max_factor)
  {
    while (number % i == 0)
    {
      if (factors[key] != i)
      {
        factors.push_back(i);
        key = factors.size() - 1;
      }
      number /= i;
      max_factor = sqrt(number);
    }

    i += 2;
  }

  if (number > 1)
    factors.push_back(number);

  return factors;
}


int main()
{
  int number, i;
  cout<<"Enter the number"<<endl;
  cin>>number;

  vector<int> factors = find_factors(number);

  for(i = 0; i < factors.size(); i++)
    cout<<factors[i]<<" ";

  return 0;
}
