
///Muhammad Saad
///Code to convert prefix to postfix
#include<iostream>
using namespace std;
int const size=25;
class Stack
{
	private:
		int top_position;
		string *arr;
	public:
		Stack()
		{
			top_position=-1;
			arr = new string[size];
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
		string top()
		{
			return arr[top_position];
		}
		void push(string element)
		{
			top_position++;
			arr[top_position]=element;
		}
		void pop()
		{
			if(top_position!=-1)
			{
				top_position--;
			}
			else
			{
				cout<<"Stack UnderFlow"<<endl;

			}
		}
		~Stack()
		{
			delete[] arr;
		}
};
string reverse(string);
int cal_len(string);
bool is_operand(char);
string prefix_postfix(string);

//////////////////////////////////////////////////////////////////////////

int main()
{
	Stack stack;
	string prefix,postfix;
	cout<<"Enter A PreFix Expression : ";
	cin>>prefix;
	cout<<"PostFix Expression : "<<prefix_postfix(prefix);
}

/////////////////////////////////////////////////////////////////////

string reverse(string infix)
{
	int n = infix.length();
	for(int i=0;i<n/2;i++)
	{
		char temp = infix[i];
		infix[i] = infix[n-i-1];
		infix[n-i-1] = temp;
	}
	return infix;
}
int cal_len(string exp)
{
	int len=0;
	for(int i=0;exp[i]!='\0';i++)
	{
		len++;
	}
	return len;
}
bool is_operand(char element)
{
	if((element >= 'a' && element <='z') || (element >= 'A' && element <='Z'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
string prefix_postfix(string prefix)
{
	Stack s;
	prefix = reverse(prefix);
	int length=cal_len(prefix);
	for(int i=0;i<length;i++)
	{
		if(is_operand(prefix[i]))
		{
			string temp;
			temp += prefix[i];
			s.push(temp);
		}
		else
		{
			string temp;
			temp+=s.top();
			s.pop();
			temp+=s.top();
			s.pop();
			temp+=prefix[i];
			s.push(temp);
		}
	}
	string postfix;
	postfix=s.top();
	return postfix;
}
