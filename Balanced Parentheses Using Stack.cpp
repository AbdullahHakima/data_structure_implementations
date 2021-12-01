#include<iostream>
#include<string>
using namespace std;
template<class T>
class Stack
{
	template<class l>
	class Node
	{
	public:
		l data;
		Node<l>* next;
	};
	Node<T>* Top;
	int counter;
public:
	Stack()
	{
		Top = NULL;
		counter = 0;
	}
	template<class T>
	void push(T& element)
	{
		Node <T>* NewNode = new Node<T>;
		NewNode->data = element;
		if (Top == NULL)
		{
			Top = NewNode;
			counter++;
		}
		else
		{
			NewNode->next = Top;
			Top = NewNode;
			counter++;
		}
	}
	bool Isempty()
	{
		return (Top == NULL);
	}
	void pop()
	{
		if (Isempty())
		{
			cout << "Can not pop, stack empty\n";
		}
		else
		{
			Node<T>* Temp = Top;
			Top = Top->next;
			Temp->next = NULL;
			delete Temp;
			counter--;
		}
	}
	template<class T>
	void pop(T& stacktop)
	{
		if (Isempty())
		{
			cout << "Can not pop, stack empty\n";
		}
		else
		{
			stacktop = Top->data;
			Node<T>* Temp = Top;
			Top = Top->next;
			Temp = Temp->next = NULL;
			delete Temp;
			counter--;
		}
	}
	T GetTop()
	{
		if (Isempty())
		{
			return -1;
		}
		else
			return Top->data;
	}
	void print()
	{
		Node<T>* current = new Node<T>;
		current = Top;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
	}
};
bool ArePair(char open, char close)
{
	if (open == '(' && close == ')')
		return true;
	else if (open == '{' && close == '}')
		return true;
	else if (open == '[' && close == ']')
		return true;
	return false;
}
bool Arebalanced(string exp)
{
	Stack<char>s;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
			s.push(exp[i]);
		else if (exp[i] == ']' || exp[i] == '}' || exp[i] == ')')
		{
			if (s.Isempty() || !ArePair(s.GetTop(), exp[i]))
				return false;
			else
			{
				s.pop();
			}
		}
	}
	if (s.Isempty())
	{
		return true;
	}
}
int main()
{
	string expression;
	cin >> expression;
	if (Arebalanced(expression))
	{
		cout << "Balanced\n";
	}
	else
		cout << "Not balanced\n";
	return 0;
}