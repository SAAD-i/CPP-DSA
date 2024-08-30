///Muhammad Saad
///Code to convert postfix to infix
#include<iostream>
using namespace std;

int const size=25;
class Stack
{
	private:
		int top_position;
		string *arr;
	public:
		Stack()//////////////////////////
		{
			top_position=-1;
			arr = new string[size];
		}
		bool is_empty()//////////////////
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
		string top()/////////////////////
		{
			return arr[top_position];
		}
		void push(string element)////////
		{
			top_position++;
			arr[top_position]=element;
		}
		void pop()///////////////////////
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

////////////////////////////////////////////////////////////////////////////////

int cal_len(string);
bool is_operand(char);
string postfix_infix(string);

///////////////////////////////////////////////////////////////////////////////

int main()
{
	Stack stack;
	string infix,postfix;
	cout<<"Enter A PostFix Expression : ";
	cin>>postfix;
	infix=postfix_infix(postfix);
	cout<<"inFix Expression : "<<infix;
}

//////////////////////////////////////////////////////////////////////////////

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


string postfix_infix(string postfix)
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
			temp+='(';
			top_operand+=s.top();
			s.pop();
			temp+=s.top();
			s.pop();
			temp+=postfix[i];
			temp+=top_operand;
			temp+=')';
			s.push(temp);
		}
	}
	string infix;
	infix=s.top();
	return infix;
}
