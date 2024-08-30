#include<iostream>
#include<conio.h>
using namespace std;
const int size=100;
class Queue
{
    int Front;
    int Rear;
    int *arr;
public:
    Queue()
    {
        Front=-1;
        Rear=-1;
        arr=new int[size];
    }
    void inQueue(int element)
    {
        if(Rear==size-1 && Front>0)
        {
            Rear=-1;
            cout<<"Con"<<endl;
        }
        if(Rear!=Front-1)
        {
            arr[++Rear]=element;
        }
        else{
            cout<<"Queue is Full"<<endl;
        }

        if(Front==-1)
        {
            Front=0;
        }

    }
    void deQueue()
    {
        if(Front!=-1)
        {
            cout<<"DeQueue : "<<arr[Front++]<<endl;
            if(Front>Rear)
            {
                Rear=-1;
                Front=-1;
            }
        }
        else{
            cout<<"Queue is Empty"<<endl;
        }
    }
    void display()
    {
        if(Front!=-1)
        {
            cout<<"Display"<<endl;
            for(int i=Front;i<=Rear;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"Queue is Empty"<<endl;
        }
    }
};
int main()
{
    Queue q;
    int choice;
    int val;
    while(1)
    {
        //system("cls");
        cout<<"1 - EnQueue"<<endl;
        cout<<"2 - DeQueue"<<endl;
        cout<<"3 - Display"<<endl;
        cout<<"Choice : ";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter Value : ";
            cin>>val;
            q.inQueue(val);
        }
        else if(choice==2)
        {
            q.deQueue();

        }
        else if(choice==3)
        {
            q.display();
        }
    }

}
