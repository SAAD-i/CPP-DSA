//Muhammad Saad
//FA21-BCS-114

#include <iostream>

using namespace std;
const int size=25;
class Stack
{
    int top;
    char *arr;
public:
    Stack()
    {
        top=-1;
        arr=new char[size];
    }
    void push(char element)
    {
        if(top<size)
        {
            arr[++top]=element;
        }
        else
        {
            cout<<"Stack OverFlow"<<endl;
        }
    }
    char top_()
    {
        if(top>=0)
        {
            return arr[top];
        }
        else
        {
            return '0';
        }
    }
    void pop()
    {
        if(top>=0)
        {
            //cout<<arr[top]<<endl;
            top--;
            //return 1;
        }
        else
        {
            cout<<"Stack UnderFlow"<<endl;
            //return 0;
        }
    }
    ~Stack()
    {
        delete arr;
    }
};

string Reverse(string str)
{
    Stack s;
    int len=0;
    for(int i=0;str[i]!='\0';i++)
    {
        len++;
        s.push(str[i]);
    }
    for(int i=0;i<len;i++)
    {
        str[i]=s.top_();
        s.pop();
    }
    return str;
}

int main()
{
    cout<<"Enter A String Value : ";
    string str;
    getline(cin,str);
    cout<<"Reversed String : "<<Reverse(str)<<endl;
}
