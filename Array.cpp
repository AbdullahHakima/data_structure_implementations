#include<iostream>
using namespace std;
class Array
{
private:
	int* items;
	int size;
	int length;
public:
	Array(int Asize)//constructor to create the array with the given size
	{
		size = Asize;
		length = 0;
		items = new int[size];
	}
	void Fill()
	{
		int no_of_element;
		cout << "enter the number of element you want to fill\n";
		cin >> no_of_element;
		if (no_of_element > size)
		{
			cout << "Error cannot fill this size of array\n";
		}
		else
		{
			for (int i = 0; i < no_of_element; i++)
			{
				cout << "Enter the element @ position " << i << endl;
				cin >> items[i];
				length++;
			}
		}
	}
	void Display()
	{
		for (int i = 0; i < length; i++)
		{
			cout << items[i] << "\t";
		}
		cout << endl;
	}
	int getsize()
	{
		return size;
	}
	int getlength()
	{
		return length;
	}
	int search(int key)
	{
		int index = -1;
		for (int i = 0; i < length; i++)
		{
			if (items[i] == key)
			{
				index = i;
				break;
			}
		}
		return index;
	}
	void Append(int element)
	{
		if (length < size)
		{
			items[length] = element;
			length++;
		}
		else
		{
			cout << "Array is full\n";
		}
	}
	void insert(int index, int element)
	{
		if (length < size)
		{
			for (int i = length; i > index; i--)
			{
				items[i] = items[i - 1];
			}
			items[index] = element;
			length++;
		}
		else
			cout << "array is full\n";
	}
	void Delete(int index)
	{
		if(index>=0&&index<size)
			for (int i = index; i < length - 1; i++)
			{
				items[i] = items[i + 1];
			}
		length--;
	}
};
int main()
{
	Array myarray(10);
	myarray.Fill();
	cout << "the array size = " << myarray.getsize() << "\t" << "the array length = " << myarray.getlength() << endl;
	myarray.Display();
	int key;
	cout << "enter the element to search about it\n";
	cin>> key;
	int index = myarray.search(key);
	if (index == -1)
	{
		cout << "the element not founded\n";
	}
	else
	{
		cout << "the element founded @ position " << index << "\n";
	}
	int index, element,indexdelete;
	cout << "enter th index to insert\n";
	cin >> element;
	cout << "enter the position to insert\n";
	cin >> index;
	myarray.insert(index, element);
	myarray.Append(element);
	cout << "the array size = " << myarray.getsize() << "\t" << "the array length = " << myarray.getlength() << endl;
	myarray.Display();
	cout << "Enter the index to delete\n";
	cin >> indexdelete;
	myarray.Delete(indexdelete);
	cout << "the array size = " << myarray.getsize() << "\t" << "the array length = " << myarray.getlength() << endl;
	myarray.Display();
	return 0;
}