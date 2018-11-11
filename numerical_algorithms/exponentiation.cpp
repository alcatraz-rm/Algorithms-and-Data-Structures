#include <iostream>
using namespace std;

/* Данная функция реализует быстрое возведение числа в степень. Суть ее работы заключается в уменьшении количества операций
умножения.
Используются две ключевые формулы:
  1) p^2n = (p^2)^n;
  2) p^n = p * p^(n-1);

Алгоритм работы такой: заводим цикл, условием выхода из которого является равенство степени нулю. На каждом этапе проверяем,
если степень кратна 2 - возводим исходное число (number) в квадрат и уменьшаем степень в 2 раза (здесь применяется формула 1),
если же число нечетное, то отнимаем от степени один и результат (result) умножаем на текущее значение числа (здесь применяется
формула 2). Такой подход позволяет нам уменьшить сложность алгоритма почти в 2 раза, что играет значенительную роль при
работе с большими числами. */

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
