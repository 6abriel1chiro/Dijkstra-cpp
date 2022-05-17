#pragma once
#include "stdc++.h"
using namespace std;
template <class T>
class Par
{
private:
	Par<T>* next;
	T elem;
	int weight;
public:
	Par(Par<T>* next, T elem, int weight);
	Par(Par<T>* next, T elem);
	~Par();
	Par* getnext();
	T getElem();
	int getweight();
	void setnext(Par<T>* next);
	void setElem(T elem);
	void setweight(int weight);
};
template <class T>
Par<T>::Par(Par<T>* next, T elem, int weight)
{
	this->next = next;
	this->elem = elem;
	this->weight = weight;
}

template <class T>
Par<T>::Par(Par<T>* next, T elem)
{
	this->next = next;
	this->elem = elem;
	this->weight = -1;
}
template <class T>
Par<T>::~Par()
{
}
template <class T>
Par<T>* Par<T>::getnext()
{
	return next;
}

template <class T>
T Par<T>::getElem()
{
	return elem;
}
template <class T>
int Par<T>::getweight()
{
	return weight;
}
template <class T>
void Par<T>::setnext(Par<T>* next)
{
	this->next = next;
}
template <class T>
void Par<T>::setElem(T elem)
{
	this->elem = elem;
}

template <class T>
void Par<T>::setweight(int weight)
{
	this->weight = weight;
}