#include <iostream>
using namespace std;

void foo(int a, int b, int c=0);
int main()
{
    foo(10, 2);
}
void foo(int a, int b, int c)
{
    cout << a << " " << b << " " << c;
}