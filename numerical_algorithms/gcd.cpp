# include<iostream>
using namespace std;

int gcd(int a, int b)
{
  int rm;
  while (b != 0)
  {
    rm = a % b;
    a = b;
    b = rm;
  }

  return a;
}

int main()
{
  int a, b;
  cout<<"Enter two numbers"<<endl;
  cin>>a>>b;
  cout<<gcd(a, b);

  return 0;
}
