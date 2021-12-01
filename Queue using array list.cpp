#include<iostream>
#include<cassert>
#include<string>
using namespace std;
template<class T>
class ArrayQueue
{
private:
	int front;
	int rear;
	int count;
	T* List;
	int MaxSize;
public:
	ArrayQueue() {}
	ArrayQueue(int size)
	{
		if (size <= 0)
		{
			cout << "Size MUST be positive\n";
			MaxSize = 100;
		}
		else
			MaxSize = size;
			List = new T[MaxSize];
			count = 0;
			front = 0;
			rear = MaxSize-1;
	}
	bool IsEmpty()
	{
		return (count == 0);
	}
	bool IsFull()
	{
		return (count == MaxSize);
	}
	void Enqueue(T element)
	{
		if (IsFull())
		{
			cout << "it Full Queue,Can't enqueue\n";
		}
		else
		{
			rear = (rear + 1) % MaxSize;
			List[rear] = element;
			count++;
		}

	}
	void Dequeue()
	{
		if (IsEmpty())
		{
			cout << "it empty queue,Can't Dequeue\n";
		}
		else
		{
			front = (front + 1) % MaxSize;
			count--;
		}
	}
	T GetDequeue()
	{
		if (IsEmpty())
		{
			cout << "it empty queue,Can't Dequeue\n";
		}
		else
		{
			front = (front + 1) % MaxSize;
			count--;
			return List[front];
		}
	}
	T GetFront()
	{
		assert(!IsEmpty());
			return List[front];
	}
	T GetRear()
	{
		assert(!IsEmpty());
			return List[rear];
	}
	void Print()
	{
		if (!IsEmpty())
		{
			for (int i = front; i != rear; i = (i + 1) % MaxSize)
			{
				cout << List[i] << " ";
			}
			cout << List[rear];
			cout << endl;
		}
		else
			cout << "Empty Queue\n";
	}
	int Search(T element)
	{
		int position = -1;
		if (IsEmpty())
		{
			cout << "Queue is Empty\n";
		}
		else
		{
			for (int i = front; i != rear; i = (i + 1) % MaxSize)
				if (List[i] == element)
				{
					position = i;
					break;
				}

				else
				{
					if (position == -1)
					{
						if (List[rear] == element)
							position = rear;
					}
				}
			return position;
		}
	}
};
int main()
{
	ArrayQueue<char>Q1(7);
	Q1.Enqueue('A');
	Q1.Enqueue('B');
	Q1.Enqueue('D');
	Q1.Enqueue('U');
	Q1.Enqueue('L');
	Q1.Enqueue('L');
	Q1.Enqueue('A');
	Q1.Enqueue('A');
	cout << Q1.Search('c') << "\n";
	Q1.Print();
	return 0;
}