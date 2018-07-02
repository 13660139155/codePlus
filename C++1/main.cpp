#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double num;
    num = (double)10/3;
    cout<<fixed;
    cout<<setprecision(3);
    cout <<num<< endl;
    return 0;
}
