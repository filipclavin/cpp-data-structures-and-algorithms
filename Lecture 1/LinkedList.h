#pragma once

template <class T>
struct Node
{
	T* data;
	Node* next;
};

template <class T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void Add(T* data);
	void Remove(T* data);
	void RemoveAt(int index);
	void Clear();
	T* Get(int index);
	int Count();

private:
	Node<T>* head;
	int count;
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	count = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Clear();
}

template <class T>
void LinkedList<T>::Add(T* data)
{
	Node<T>* node = new Node<T>();
	node->data = data;
	node->next = nullptr;

	if (head == nullptr)
	{
		head = node;
	}
	else
	{
		Node<T>* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}

		current->next = node;
	}

	count++;
}

template <class T>
void LinkedList<T>::Remove(T* data)
{
	if (head == nullptr)
	{
		return;
	}

	if (head->data == data)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		count--;
		return;
	}

	Node<T>* current = head;
	while (current->next != nullptr)
	{
		if (current->next->data == data)
		{
			Node<T>* temp = current->next;
			current->next = current->next->next;
			delete temp;
			count--;
			return;
		}

		current = current->next;
	}
}

template <class T>
void LinkedList<T>::RemoveAt(int index)
{
	if (index < 0 || index >= count)
	{
		return;
	}

	if (index == 0)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		count--;
		return;
	}

	Node<T>* current = head;
	for (int i = 0; i < index - 1; i++)
	{
		current = current->next;
	}

	Node<T>* temp = current->next;
	current->next = temp->next;
	delete temp;
	count--;
}

template <class T>
void LinkedList<T>::Clear()
{
	Node<T>* current = head;
	while (current != nullptr)
	{
		Node<T>* temp = current;
		current = current->next;
		delete temp;
	}

	head = nullptr;
	count = 0;
}

template <class T>
T* LinkedList<T>::Get(int index)
{
	if (index < 0 || index >= count)
	{
		return nullptr;
	}

	Node<T>* current = head;
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current->data;
}

template <class T>
int LinkedList<T>::Count()
{
	return count;
}