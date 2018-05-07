#include <iostream>
using namespace std;
void PrintHello();
void ADD(int x , int y);
void SUB(int x , int y);

int main() {
    int x,y;
    cout<<"please input first number : ";
    cin>>x;
    cout<<"please input second number : ";
    cin>>y;
    PrintHello();
    ADD(x,y);
    SUB(x,y);

    return  0;
}