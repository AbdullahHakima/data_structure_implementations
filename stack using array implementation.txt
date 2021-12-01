#include<iostream>
#include<string>
using namespace std;
template <class t>
class Stack
{
private:
	int Top;
	t *List;
public:
	Stack()
	{
		List = new t[100];
		Top = -1;
	}
	Stack(int size)
	{
		if (size < 0)
		{
			cout << "The size MUST be positive\n";
			size = 100;
			List = new t[size];
		}
		else
		{
			List = new t[size];
		}
		Top = -1;
	}
	bool IsEmpty()
	{
		return (Top == -1);
	}
	bool IsFull()
	{
		return (Top == Stack_size - 1);
	}
	void push(t Element)
	{
		if (IsFull())
		{
			cout << "Stack is full \n";
		}
		else
		{
			Top++;
			List[Top] = Element;
		}
	}
	void pop()
	{
		if (IsEmpty())
		{
			cout << "Stack is empty can not pop\n";
		}
		else
			Top--;
	}
	void pop(t&popelement)
	{
		if (IsEmpty())
		{
			cout << "Stack is empty can not pop\n";
		}
		else
		{
			popelement = List[Top];
			Top--;
		}
	}
	void GetTop(t&topelement)
	{
		if (IsEmpty())
		{
			cout << "Stack is empty no Top\n";
		}
		else
		{
			topelement = List[Top];
			cout << "Top = " << topelement << "\n";
		}
	}
	void print()
	{
		cout << "List in Stack : ";
		for (int i = Top; i >= 0; i--)
		{
			cout << List[i] << " ";
		}
		cout << "\n";
	}
};
int main()
{
	Stack<char>S;
	S.push('A');
	S.push('B');
	S.push('C');
	S.push('D');
	S.push('E');
	S.push('F');
	S.print();
	S.pop();
	char top;
	S.GetTop(top);
	char pop;
	S.pop(pop);
	S.GetTop(top);
	return 0;
}