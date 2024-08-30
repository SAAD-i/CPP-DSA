///Muhammad Saad
///Code to convert infix to prefix
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
string infix_prefix(string);

//////////////////////////////////////////////////////////////////////////////

int main()
{
	Stack stack;
	string infix,prefix;
	cout<<"Enter A Infix Expression : ";
	cin>>infix;
	prefix=infix_prefix(infix);
	cout<<"Enter A PreFix Expression : ";
	cout<<prefix<<endl;
}

////////////////////////////////////////////////////////////////////////////

string reverse(string exp)
{
	Stack s;
	int n = exp.length();
	for(int i=0;i<n;i++)
	{
		s.push(exp[i]);
	}
	for(int i=0;i<n;i++)
	{
		exp[i]=s.top();
		s.pop();
	}
	/*for(int i=0;i<n/2;i++)
	{
		char temp = exp[i];
		exp[i] = exp[n-i-1];
		exp[n-i-1] = temp;
	}*/
	for(int i=0;i<n;i++)
	{
		if(exp[i]=='(')
		{
			exp[i]=')';
		}
		else if(exp[i]==')')
		{
			exp[i]='(';
		}
	}
	//cout<<infix;
	return exp;
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
int pre(char element)
{
	if(element == '+' || element == '-')
	{
		return 1;
	}
	else if(element == '*' || element == '/')
	{
		return 2;
	}
	else if(element == '^')
	{
		return 3;
	}
	else
	{
		return 0;
	}
}
string infix_prefix(string infix)
{
	Stack s;
	infix = reverse(infix);
	string prefix;
	int length=cal_len(infix);
	for(int i=0;i<length;i++)
	{
		if(is_operand(infix[i])==true)
		{
			prefix += infix[i];
		}
		else if(infix[i]=='(')
		{
			s.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while(s.top()!='(' || s.is_empty())
			{
				prefix += s.top();
				//cout<<" OKAY "<<endl;
				s.pop();
			}
			s.pop();
		}
		else
		{
			if(s.is_empty())
			{
				s.push(infix[i]);
			}
			else
			{
				if(pre(infix[i])>pre(s.top()))
				{
					s.push(infix[i]);
				}
				else if(pre(infix[i])==pre(s.top()) && infix[i]=='^')
				{
					prefix += s.top();
					s.pop();
				}
				else if(pre(infix[i])==pre(s.top()))
				{

					s.push(infix[i]);
				}
				else
				{
					while(pre(infix[i])<=pre(s.top()) && !s.is_empty())
					{
						prefix += s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}

	while(!s.is_empty())
	{
		prefix += s.top();
		s.pop();
	}

	prefix = reverse(prefix);

	return prefix;
}
