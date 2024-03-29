#include "pch.h"
#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next;
	Node(int);
	~Node();
};

Node::Node(int data)
{
	value = data;
	next = NULL;
}

Node::~Node()
{
	cout << "removed node: " << value << endl;
}

struct LinkedList
{
	int length;
	Node* head;
	Node* tail;

	LinkedList();
	~LinkedList();

	void remove(int value)
	{
		Node* _node = head;
		Node* prevNode = nullptr;

		while (_node->next && _node->value != value)
		{
			prevNode = _node;
			_node = _node->next;
		}

		if (!prevNode) //is head
		{
			if (length > 1) //if more than one node's
			{
				head = _node->next;
			}
			else
			{
				head = nullptr;
				tail = nullptr;
			}
		}
		else if (_node->next && prevNode) //is middle
		{
			prevNode->next = _node->next;
		}
		else if (!_node->next) //is tail
		{
			prevNode->next = nullptr;
			tail = prevNode;
		}

		delete _node;
		length--;
	}

	Node* search(int value)
	{
		Node* _head = head;
	
		for (int i = 0; i < length; i++)
		{
			if (_head->value == value)
			{
				return _head;
			}

			_head = _head->next;
		}

		return _head;
	}

	void insert(int value, Node* index = NULL)
	{
		Node* temp = new Node(value);

		if (head == NULL)
		{
			head = tail = temp;
		}
		else
		{
			tail = tail->next = temp;
		}

		length++;
	}
};

LinkedList::LinkedList()
{
	length = 0;
	head = NULL;
	tail = NULL;
}

LinkedList::~LinkedList()
{
}

int main()
{
	LinkedList* ll = new LinkedList();
	
	ll->insert(1);
	ll->insert(2);
	ll->insert(3);
	ll->insert(4);
	ll->insert(5);

	Node* search = ll->search(5);
	cout << "search node result: " << search->value << " node adress: " << search << endl;

	ll->remove(1);

	cout << ll->head->value << endl;

	return 0;
}
