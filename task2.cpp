#include <iostream>
using namespace std;
int main()
{
    int a,b,c,o;
    cout<<"Enter the first number:"<<endl;
    cin>>a;
    cout<<"Enter the second number:"<<endl;
    cin>>b;
    cout<<"Enter the operation to perform:...(Enter the number corresponding to operation as stated bellow)"<<endl<<"add(1)"<<endl<<"sub(2)"<<endl<<"mul(3)"<<endl<<"div(4)"<<endl;
    cin>>o;
    switch(o)
    {
        case 1:
        c=a+b;
        break;
        case 2:
        c=a-b;
        break;
        case 3:
        c=a*b;
        break;
        case 4:
        if(b==0)
        {
        cout<<"Cannot divide by 0..pls enter valid numb"<<endl;
        return 0;
        }
        else 
        c=a/b;
        break;
        default:
        cout<<"Enter valid operation!!"<<endl;
        break;
    }
    cout<<"Reult: "<<c;
}
