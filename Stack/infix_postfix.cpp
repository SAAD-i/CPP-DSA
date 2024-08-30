#include<iostream>
using namespace std;
int const size=25;
class Stack
{
	private:
		int top_position;
		char *arr;
	public:
		Stack()
		{
			top_position=-1;
			arr = new char[size];
		}
		bool is_empty()
		{
			if(top_position==-1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		char top()
		{
			return arr[top_position];
		}
		void push(char element)
		{
			top_position++;
			arr[top_position]=element;
		}
		char pop()
		{
			if(top_position!=-1)
			{

				return arr[top_position--];

			}
			else
			{
				cout<<"Stack UnderFlow"<<endl;
				return '0';
			}

		}
		~Stack()
		{
			delete[] arr;
		}
};

//////////////////////////////////////////////////////////////////////////////

int main()
{
	Stack s;
	string x;
	cout<<"Enter A String : ";
	getline(cin,x);
	int count=0;
	for(int i=0;x[i]!='\0';i++)
    {
        if(x[i]!=' ')
        {
            count++;
        }
        else if(x[i]==' ')
        {
            if(count==5)
            {
                int j=i-count;
                while(j<i)
                {
                    s.push(x[j]);
                    j++;
                }
                j=i-count;
                while(j<i)
                {
                    x[j]=s.pop();
                    j++;
                }
            }
            count=0;
        }
        if(x[i+1]=='\0')
        {
            if(count==5)
            {
                int j=(i+1)-count;
                while(j<=i)
                {
                    s.push(x[j]);
                    j++;
                }
                j=(i+1)-count;
                while(j<=i)
                {
                    x[j]=s.pop();
                    j++;
                }
            }
            count=0;
        }
    }
    cout<<"Reversed String  = "<<x<<endl;
}

////////////////////////////////////////////////////////////////////////////


