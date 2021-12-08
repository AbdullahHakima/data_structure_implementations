q1:
#include<iostream>
#include<string>
#include<cassert>
using namespace std;
struct studentinfo
{
	string name="name", course="course";
	int id=0, total=0;
};
class RecordManagement
{
private:
	class node
	{
	public:
		studentinfo data;
		node* next;
		node()
		{
			next = NULL;
		}
	};
	node* first, * last;
	int counter;
public:
	RecordManagement()
	{
		first = last = NULL;
		counter = 0;
	}
	bool isempty()
	{
		return (first == NULL);
	}
	bool checkrecord(studentinfo info)
	{
		node* current = first;
		if (isempty())
			return false;
		while (current != NULL)
		{
			if (current->data.id == info.id)
				return true;
			else
				current = current->next;
		}
		return false;
	}
	void addrecord(studentinfo info)
	{
		if (!checkrecord(info))
		{
			node* newnode = new node;
			newnode->data.name = info.name;
			newnode->data.id = info.id;
			newnode->data.course = info.course;
			newnode->data.total = info.total;
			newnode->next = NULL;
			if (isempty())
			{
				first = last = newnode;
			}
			else
			{
				last->next = newnode;
				last = newnode;
			}
			counter++;
		}
	}
	void showrecord()
	{
		node* temp = first;
		cout << "the record list :\n";
		while (temp != NULL)
		{
			cout << "Student Name : " << temp->data.name << " \n"
				<< "Rolled Number : " << temp->data.id << "\n"
				<< "Course : " << temp->data.course << "\n"
				<< "Total Mark : " << temp->data.total << "\n"
				<< "\t----------------------\n";
			temp = temp->next;
		}
	}
	int findrecord(int key)
	{
		int index = 0;
		if (isempty())
			return -1;
		else
		{
			node* current = first;
			while (current != NULL)
			{
				if (current->data.id == key)
					return index;
				else
				{
					current = current->next;
					index++;
				}
			}
		}
		return -1;
	}
	int removerecord(int key)
	{
		if (isempty())//list is empty of nodes
			return -1;
		else
		{
			node* current = first->next;
			node* previous = first;
			if (first->data.id == key)//the node to delete at front of list
			{
				current = first;
				first = first->next;
				delete current;
				counter--;
				return 0;
			}
			else//the node to delete not at front or end of list
			{
				while (current != NULL)
				{
					if (current->data.id == key)
						break;
					else
					{
						previous = current;
						current = current->next;
					}
				}
				if (current == NULL)
					return -1;
				else
				{
					previous->next = current->next;
					if (last == current)
						last = previous;
					delete current;
					counter--;
					return 0;
				}
			}
		}
	}
};
int main()
{
	RecordManagement RM;
	studentinfo st1,st2,st3,st4;
	st1.name = "Abdullah";
	st1.id = 123;
	st1.course = "data structure";
	st1.total = 200;
	st2.name = "Mohamed";
	st2.id = 423;
	st2.course = "data structure";
	st2.total = 200;
	st3.name = "Ahmed";
	st3.id = 454;
	st3.course = "data structure";
	st3.total = 200;
	st4.name = "Mohamed";
	st4.id = 423;
	st4.course = "data structure";
	st4.total = 200;
	RM.addrecord(st1);
	RM.addrecord(st2);
	RM.addrecord(st3);
	RM.addrecord(st4);//ignore because have same rolled number 
	RM.showrecord();
	cout << "\n";
	if (RM.findrecord(423))
	{
		cout << "founded\n";
	}
	RM.removerecord(423);
	RM.showrecord();
	cout << RM.findrecord(423);//not founded because had removed 


	return 0;
}
------------------------------------------------------------
q2:
