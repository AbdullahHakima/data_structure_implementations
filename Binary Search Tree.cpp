#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* Left;
	Node* Right;
	Node()
	{
		data = 0;
		Left = NULL;
		Right = NULL;
	}
};
class Tree
{
private:
	Node* Root;
	void Insert(int& element, Node*& Current)
	{
		Node* NewNode = new Node;
		NewNode->data = element;
		NewNode->Left = NULL;
		NewNode->Right = NULL;
		if (Current == NULL)//case if EMPTY TREE
			Current = NewNode;
		else if (element < Current->data)//element less than Root
			Insert(element, Current->Left);
		else if (Current->data < element)//element greater than Root
			Insert(element, Current->Right);
		else
		{
			//Duplicate
		}
	}
	void PreorderTraversal(Node* Current)
	{
		if (Current != NULL)
		{
			cout << Current->data << " ";
			PreorderTraversal(Current->Left);
			PreorderTraversal(Current->Right);
		}
	}
	void PostorderTraversal(Node* Current)
	{
		if (Current != NULL)
		{
			PostorderTraversal(Current->Left);
			PostorderTraversal(Current->Right);
			cout << Current->data << " ";
		}
	}
	void InorderTraversal(Node* Current) 
	{
		if (Current != NULL)
		{
			InorderTraversal(Current->Left);
			cout << Current->data << " ";
			InorderTraversal(Current->Right);
		}
	}

	Node* FindMin(Node* Current)//find the minimum value in right sub tree
	{
		if (Current == NULL)
			return NULL;
		else if (Current->Left == NULL)
			return Current;
		return FindMin(Current->Left);
	}
	void Remove(int& element, Node*& Current)
	{
		if (Current == NULL)
		{
			//tree in EMPTY 
		}
		if (element < Current->data)
			Remove(element, Current->Left);
		else if (element > Current->data)
			Remove(element, Current->Right);
		else if (Current->Left != NULL && Current->Right != NULL)//case that node have two children
		{
			Current->data = FindMin(Current->Right)->data;//search about the minimum value in right sub tree
			Remove(Current->data, Current->Right);
		}
		else
		{
			Node* Temp = Current;
			if (Current->Left != NULL)
				Current = Current->Left;
			else
				Current = Current->Right;
			delete Temp;
		}
	}
public:
	Tree()
	{
		Root = NULL;
	}
	void Preorder()
	{
		PreorderTraversal(Root);
	}
	void Postorder()
	{
		PostorderTraversal(Root);
	}
	void Inorder()
	{
		InorderTraversal(Root);
	}
	void InsertElement(int& element)
	{
		Insert(element, Root);
	}
	void RemoveElement(int& element)
	{
		Remove(element, Root);
	}
};
int main()
{
	Tree List;
	int x = 50, y = 20, z = 22, a = 16, b = 60, c = 51;
	List.InsertElement(x);
	List.InsertElement(y);
	List.InsertElement(z);
	List.InsertElement(a);
	List.InsertElement(b);
	List.Preorder();
	cout << "\n";
	List.InsertElement(c);
	List.Preorder();
	cout << "\n";
	List.RemoveElement(x);
	List.Preorder();
	cout << "\n";
	List.Postorder();
	cout << "\n";
	List.Inorder();
	return 0;

}