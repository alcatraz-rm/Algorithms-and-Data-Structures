#include <iostream>
#include <vector>
using namespace std;

/* Данная программа реализует алгоритм под названием "решето Эратосфена", который находит все простые числа до введенного.
Это выполняется по следующему принципу: мы создаем массив логических переменных, изначально присваивая всем элементам true.
Он играет роль некой таблицы, где индекс является самим числом, а значение его "статусом". Далее запускаем цикл начиная от 2 и до
последнего элемента массива. Находим первое число, которое является "незачеркнутым" (имеет статус true) и "вычеркиваем" (присваиваем false)
все числа, которые кратны данному. На первой итерации таким числом будет 2, то есть вычеркнутся все четные числа. Далее переходим
к следующему незачеркнутому числу и вычеркиваем все числа, кратные ему и т.д. В конце необходим пройти по массиву и запомнить
индексы тех элементов, которые имеют значение true. Это и будут все простые числа в данном диапазоне. */

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
