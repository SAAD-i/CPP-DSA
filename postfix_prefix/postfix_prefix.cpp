///Muhammad Saad
///Code to convert postfix to prefix
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
int cal_len(string);
bool is_operand(char);
string postfix_prefix(string);

////////////////////////////////////////////////////////////////////////

int main()
{
	Stack stack;
	string prefix,postfix;
	cout<<"Enter A PostFix Expression : ";
	cin>>postfix;
	prefix=postfix_prefix(postfix);
	cout<<"PreFix Expression : "<<prefix;
}

///////////////////////////////////////////////////////////////////

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
string postfix_prefix(string postfix)
{
	Stack s;
	int length=cal_len(postfix);
	for(int i=0;i<length;i++)
	{
		if(is_operand(postfix[i]))
		{
			string temp;
			temp += postfix[i];
			s.push(temp);
		}
		else
		{
			string temp,top_operand;
			temp+=postfix[i];
			top_operand+=s.top();
			s.pop();
			temp+=s.top();
			s.pop();
			temp+=top_operand;
			s.push(temp);
		}
	}
	string prefix;
	prefix=s.top();
	return prefix;
}
