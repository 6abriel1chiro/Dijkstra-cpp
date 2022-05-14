#pragma once
//#include "Lista8.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node
{
private:
	//Lista8<T>* lista;
	int padre;
	bool marca;
public:
	Node();
	~Node();
	//Lista8<T>* getLista();
	//void setLista(Lista8<T>* lista);

	int getPadre();
	bool getMarca();
	void insertarLista(T dato);
	void setPadre(int padre);
	void setMarca(bool marca);
};
template <class T>
Node<T>::Node()
{
	this->padre = -1;
	this->marca = false;
}
template <class T>
Node<T>::~Node()
{
	delete lista;
}

template <class T>
int Node<T>::getPadre()
{
	return padre;
}
template <class T>
bool Node<T>::getMarca()
{
	return marca;
}

template <class T>
void Node<T>::setPadre(int padre)
{
	this->padre = padre;
}
template <class T>
void Node<T>::setMarca(bool marca)
{
	this->marca = marca;
}
template <class T>
void Node<T>::insertarLista(T dato)
{
	lista->insPrin(dato);
}