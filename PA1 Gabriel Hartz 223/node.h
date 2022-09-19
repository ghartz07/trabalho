#pragma once
#include <iostream>
#include <string>

using std::string;

template <class T>

class Node
{
	template<class T> friend class Linkedlist;
public:
	Node(T& newCommand, T& newDescription);//constructor
	~Node();//destructor
private:
	Node* pNext;
	T command;
	T description;
};

template <class T>
Node<T>::Node(T& newCommand, T& newDescription)
{
	this->command = newCommand;
	this->description = newDescription;
}
template <class T>
Node<T>::~Node()
{

}
//template <class T>
//N