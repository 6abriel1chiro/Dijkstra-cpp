#pragma once
#include "Lista7.h"
template <class T>
class Node
{
private:
	string padre;
	bool marca;
	int distancia;
	Lista7<T>* lista;
public:
	Node();
	~Node();
	void mostrar();
	string getPadre();
	bool getMarca();
	int getDistancia();
	Lista7<T>* getLista();
	void setPadre(string padre);
	void setMarca(bool marca);
	void setLista(Lista7<string>* lista);
	void setDistancia(int distancia);
};
template <class T>
Node<T>::Node()
{
	lista = new Lista7<T>();
	padre = "#";
	distancia = 9999;
	marca = false;
}

template <class T>
Node<T>::~Node()
{
}
template <class T>
void Node<T>::mostrar()
{
	if (lista != NULL)
	{
		lista->mostrarLista();
	}
}
template <class T>
string Node<T>::getPadre()
{
	return padre;
}
template <class T>
bool Node<T>::getMarca()
{
	return marca;
}
template <class T>
Lista7<T>* Node<T>::getLista()
{
	return lista;
}
template <class T>
int Node<T>::getDistancia()
{
	return distancia;
}
template <class T>
void Node<T>::setPadre(string padre)
{
	this->padre = padre;
}
template <class T>
void Node<T>::setMarca(bool marca)
{
	this->marca = marca;
}
template <class T>
void Node<T>::setLista(Lista7<string>* lista)
{
	this->lista = lista;
}
template <class T>
void Node<T>::setDistancia(int distancia)
{
	this->distancia = distancia;
}