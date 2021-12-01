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
			Node<T>*Temp = Top;
			Top = Top->next;
			Temp->next = NULL;
			delete Temp;
			counter--;
		}
	}
	template<class T>
	void pop(T&stacktop)
	{
		if (Isempty())
		{
			cout << "Can not pop, stack empty\n";
		}
		else
		{
			stacktop = Top->data;
			Node<T>*Temp = Top;
			Top = Top->next;
			Temp=Temp->next = NULL;
			delete Temp;
			counter--;
		}
	}
	void GetTop(T& Topelement)
	{
		if (Isempty())
		{
			cout << "Stack is empty \n";
		}
		else
			Topelement = Top->data;
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
int main()
{
	Stack<int>S;
	int arr[5] = { 22,23,42,43,23 };
	S.push(arr[0]);
	S.push(arr[1]);
	S.push(arr[2]);
	S.push(arr[3]);
	S.print();
	S.pop();
	int y,x;
	S.pop(x);
	S.GetTop(y);
	S.push(arr[4]);
	S.print();
	cout << x << "       " << y << endl;

	return 0;
}