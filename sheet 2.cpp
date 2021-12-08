/*1. Create a student Record Management system Using Linked List that can perform the
following operations:
(1)Insert Student record
(2) Delete student record
(3)Show student record
(4)Search student record
The student record should contain the following items:
- Name of Student
- Roll Number of Student
- Course in which Student is Enrolled
- Total Marks of Student
More Explanation for understand:
- heck Record: It is a utility function of creating a record it checks before insertion
that the Record Already Exist or not. It uses the concept of checking for a Node
with given Data in a linked list.
- reate Record: It is as simple as creating a new node in the Empty Linked list or
inserting a new node in a non-Empty linked list.
- earch Record: Search a Record is similar to searching for a key in the linked list.
Here in the student record key is the roll number as roll number is unique for every
student.
- elete Record: Delete Record is similar to deleting a key from a linked list. Here
the key is the roll number. Delete record is an integer returning function it returns -
1 if no such record with a given roll number is found otherwise it deletes the node
with the given key and returns 0.
- Show Record: It shows the record is similar to printing all the elements of the
Linked list.*/
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
