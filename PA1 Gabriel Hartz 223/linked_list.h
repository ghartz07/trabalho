#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include "node.h"

using std::fstream;
using std::endl;

template <class T>
class Linkedlist
{
public:
	Linkedlist(Node<T>* newpHead = nullptr);
	~Linkedlist();
	void insert(T &newCommand, T& newDescription);
	void deleteList();
	void deleteNode(T command);
	void randomizeCommand(T& randomCommand, T& description);
	void printList(fstream &outfile);
	bool searchCommand(T command);
private:
	Node<T>* pHead;
};

template <class T>
Linkedlist<T>::Linkedlist(Node<T>* newpHead)
{
	this->pHead = newpHead;
}

template <class T>
void Linkedlist<T>::insert(T& newCommand, T& newDescription)
{

	Node<T>* pMem = new Node<T>(newCommand, newDescription);
	if (this->pHead == nullptr)
	{
		this->pHead = pMem;
	}
	else
	{
		pMem->pNext = this->pHead;
		this->pHead = pMem;
	}
}

template <class T>
void Linkedlist<T>::deleteList()
{
	if (this->pHead != nullptr)
	{
		Node<T>* pCur = this->pHead, *pNext = nullptr;
		while (pCur != nullptr)
		{
			pNext = pCur->pNext;
			free(pCur);
			pCur = pNext;
		}
		pHead = nullptr;
	}
}

template <class T>
void Linkedlist<T>::deleteNode(T command)
{
	Node<T>* pCur = this->pHead, *pPrev = nullptr;

	while (pCur != nullptr)
	{
		if (pCur->command == command)//command was found
		{
			if (pPrev == nullptr)//Command choice is in the pHead
			{
				pHead = pCur->pNext;
				free(pCur);
			}
			else //List has more than 1 node
			{
				pPrev->pNext = pCur->pNext;
				free(pCur);
			}
			break;
		}
		pPrev = pCur;
		pCur = pCur->pNext;
	}
	if (pCur == nullptr)
	{
		system("cls");
		std::cout << "The command couldn't be found.\n";
		system("pause");
		system("cls");
	}
}

template <class T>
void Linkedlist<T>::randomizeCommand(T& randomCommand, T& description)
{
	int size = 0;
	int randomIndex;
	
	
	Node<T>* pCur = this->pHead;
	while (pCur != nullptr)
	{
		size += 1;
		pCur = pCur->pNext;
	}
	randomIndex = rand() % size + 1;
	pCur = this->pHead;
	int i = 1;
	while (i < randomIndex && pCur != nullptr)
	{
		pCur = pCur->pNext;
		i++;
	}

	randomCommand = pCur->command;
	description = pCur->description;
}

template <class T>
Linkedlist<T>::~Linkedlist()
{

}

template <class T>
void Linkedlist<T>::printList(fstream &outfile)
{
	Node<T>* pCur = this->pHead;

	while (pCur != nullptr)
	{
		if (pCur->pNext == nullptr)
		{
			outfile << pCur->command << ',' << pCur->description;
			pCur = pCur->pNext;
		}
		else
		{
			outfile << pCur->command << ',' << pCur->description << endl;
			pCur = pCur->pNext;
		}
		
	}
}

template <class T>
bool Linkedlist<T>::searchCommand(T command)
{
	Node<T>* pCur = this->pHead;

	while (pCur != nullptr)
	{
		if (pCur->command == command)
		{
			return true;
		}
		pCur = pCur->pNext;
	}
	return false;
}

