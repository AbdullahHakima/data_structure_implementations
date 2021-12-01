#include<iostream>
#include<cassert>
#include<string>
using namespace std;
template<class T>
class Node
{
public:
	T data;
	Node<T>* next;
};
template<class t>
class Queue
{
private:
	Node<t>* front;
	Node<t>* rear;
	int count;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
		count = 0;
	}
	bool IsEmpty()
	{
		return (front == NULL && rear == NULL);
	}
	void Enqueue(t element)
	{
		Node<t>* Newnode = new Node<t>;
		Newnode->data = element;
		if (IsEmpty())
		{
			front = rear = Newnode;
			Newnode->next = NULL;
			count++;
		}
		else
		{
			rear->next = Newnode;
			rear = Newnode;
			count++;
		}
	}
	void Dequeue()
	{
		if (IsEmpty())
		{
			cout << "Empty Queue\n";
		}
		else
		{
			Node<t>* current = front;
			front = front->next;
			current->next = NULL;
			delete current;
			count--;
		}
	}
	t ReturnDequeue()
	{
		if (IsEmpty())
		{
			cout << "Empty Queue\n";
		}
		else
		{
			Node<t>* current = front;
			front = front->next;
			current->next = NULL;
			return current->data;
			delete current;
			count--;
		}
	}
	void Print()
	{
		if (IsEmpty())
		{
			cout << "Empty Queue\n";
		}
		else
		{
			Node<t>*current = front;
			while (current != NULL)
			{
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
	}
	t Getfront()
	{
		assert(!IsEmpty());
			return front->data;
	}
	t Getrear()
	{
		assert(!IsEmpty());
			return rear->data;
	}
	int size()
	{
		return count;
	}
	~Queue()
	{
		Node<t>* current;
		while (front != NULL)
		{
			current = front;
			front = front->next;
			delete current;
			count--;
		}
		rear->next = NULL;
		if(IsEmpty());
			cout << "Queue destroyed\n";
	}
	int Search(t element)
	{
		bool flag = true;
		Node<t>* current = front;
		while (current != NULL)
		{
			if (current->data == element)
			{
				cout << "the " << element << " has founded \n";
				flag = false;
				break;
				return 1;
			}
			else
			{
				current = current->next;
			}
		}
		if (flag)
		{
			cout << "the " << element << " has not founded\n";
			return 0;
		}
	}
};
int main()
{
	Queue<int>Q1;
	Q1.Enqueue(1);
	Q1.Enqueue(2);
	Q1.Enqueue(3);
	Q1.Enqueue(4);
	Q1.Enqueue(5);
	Q1.Search(4);
	return 0;
}
