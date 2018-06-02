#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/* Функция find_factors реализует поиск простых делителей числа. Это выполняется по следующему алгоритму: сначала мы проверяем
делимость числа на 2, если оно делится, то запоминаем 2 в качестве простого делителя и делим число на 2 до тех пор, пока оно
не станет нечетным. Далее проверяем делимость числа на все нечетные числа, находящиеся в диапазоне от 3 до квадратного корня из числа.
Как только находим новый множитель, запоминаем его, делим на него число (до тех пор, пока оно делится) и определяем новую
верхнюю границу (квадратный корень из текущего значения числа). Если после данного цикла число != 1, то запоминаем и его
значение, так как это тоже множитель. */

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
      number /= 2;

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
