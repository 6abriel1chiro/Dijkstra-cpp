#pragma once
#include "Lista8.h"
#include "nodoMinHeap.h"
#include "stdc++.h"


template <class T>
class Node
{
private:
	Lista8<T>* lista;
	string  padre;
	bool marca;
	int distancia = 99999;
public:
	Node();
	~Node();
	Lista8<T>* getLista();
	void setLista(Lista8<T>* lista);

	int getPadre();
	bool getMarca();
	void insertarLista(T dato);
	void setPadre(int padre);
	void setMarca(bool marca);

	int getDistancia();

	void setDistancia(int dis);
};
template <class T>
Node<T>::Node()
{
	this->padre = "NA";
	this->marca = false;
}
template <class T>
Node<T>::~Node()
{
	delete lista;
}

template<class T>
inline Lista8<T>* Node<T>::getLista()
{
	return lista;
}

template<class T>
inline void Node<T>::setLista(Lista8<T>* lista)
{
	this->lista = lista;
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
template<class T>
inline int Node<T>::getDistancia()
{
	return distancia;
}
template<class T>
inline void Node<T>::setDistancia(int dis)
{
	distancia = dis;
}
template <class T>
void Node<T>::insertarLista(T dato)
{
	lista->insPrin(dato);
}