#include <iostream>
#include <vector>
using namespace std;

vector<int> factors_find(int number)
{
  vector<bool> number_vals(number + 1);
  vector<int> primes;
  int i, j;

  for(i = 2; i < number + 1; i++)
      number_vals[i] = true;

  for (i = 2; i < number + 1; i++)
  {
    if (number_vals[i] == true)
    {
      for(j = i * 2; j < number + 1; j += i)
        number_vals[j] = false;
    }
  }

  for (i = 2; i < number + 1; i++)
    if(number_vals[i])
      primes.push_back(i);

  return primes;
}

int main()
{
  int number, i;
  cout<<"Enter the number"<<endl;
  cin>>number;

  vector<int> primes = factors_find(number);

  for (i = 0; i < primes.size(); i++)
    cout<<primes[i]<<" ";

  return 0;
}
