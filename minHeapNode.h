#pragma once
#include "stdc++.h"
using namespace std;

template <class T>
class minHeapNode
{
private:
	T elem;
	bool presente;
	string vertice;

public:
	minHeapNode();
	~minHeapNode();
	T getElem();
	bool getPresente();
	void setPresente(bool val);
	void setElem(T Elem);

	string getVert();

	void setVert(string vertice);

};

template<class T>
minHeapNode<T>::minHeapNode()
{
	//this->elem = NULL;
	this->presente = false;
}

template<class T>
minHeapNode<T>::~minHeapNode()
{

    
}



template<class T>
T minHeapNode<T>::getElem()
{
	return elem;
}

template<class T>
bool minHeapNode<T>::getPresente()
{
	return presente;
}

template<class T>
void minHeapNode<T>::setPresente(bool val)
{
	this->presente = val;
}

template<class T>
void minHeapNode<T>::setElem(T elem)
{
	this->elem = elem;
}


template<class T>
string minHeapNode<T>::getVert()
{
	return vertice;
}

template<class T>
void minHeapNode<T>::setVert(string vertice)
{
	this->vertice = vertice;
}
