#pragma once
#include "Par.h"
template <class T>
class Lista7
{
private:
	Par<T>* first;
	Par<T>* last;
public:
	Lista7();
	~Lista7();
	void InsertFirst(T elem,int peso);
	void InsertLast(T elem);
	bool DeleteFirst();
	void showLista7(void (*f)(T*));
	void showLista7();

	bool DeleteLast();
	bool DeleteElem(T Elem);
	void ordenar(bool (comparar)(T*, T*));
	T SearchNoRec(T elem);
	T SearchRec(T elem, int pos);
	T SearchPos(int pos);
	T operator[](int pos);

	int countElements();

	void mostrarLista();
	Par<T>* getFirst();
};
template <class T>
Lista7<T>::Lista7()
{
	first = NULL;
	last = NULL;
}
template <class T>
Lista7<T>::~Lista7()
{

}

template <class T>
void Lista7<T>::InsertFirst(T elem, int peso)
{
	if (first == NULL)
	{
		first = new Par<T>(NULL, elem, peso);
		last = first;
	}
	else
	{
		Par<T>* aux = new Par<T>(first, elem, peso);
		first = aux;
	}


}


template <class T>
void Lista7<T>::InsertLast(T elem)
{
	Par<T>* aux;
	if (first == NULL)
	{
		first = new Par<T>(elem, NULL);
	}
	else
	{
		aux = first;
		while (aux->getnext() != NULL)
		{
			aux = aux->getnext();
		}
		aux = new Par<T>(elem, NULL);
	}
}
template <class T>
bool Lista7<T>::DeleteFirst()
{
	bool res;
	if (first == NULL)
	{
		res = false;
	}
	else
	{
		res = true;
		if (first == last) // 1 elemento
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			Par<T>* aux;
			aux = first->getnext();
			delete first;
			first = aux;
			first->setNext(aux);
		}
	}
	return res;
}
template <class T>
T Lista7<T>::SearchRec(T elem, int pos)
{
	T* value = NULL;
	Par<T>* aux = first;
	if (*aux->getElem() == elem)
	{
		value = aux->getElem();
	}
	else if (aux != NULL)
	{
		SearchRec(elem, pos + 1);
		aux = aux->getnext();
	}
	return value;
}
template <class T>
void Lista7<T>::showLista7(void (*f)(T*))
{
	Par<T>* aux = first;
	if (first == NULL)
	{
		cout << "Empty List";
	}
	while (aux != NULL)
	{
		(*f)(aux->getElem());
		aux = aux->getnext();
	}
}
template <class T>
void Lista7<T>::showLista7()
{
	Par<T>* aux = first;

	while (aux != NULL)
	{
		cout << aux->getElem()<<endl;
		aux = aux->getnext();
	}
}
template <class T>
T Lista7<T>::SearchNoRec(T elem)
{
	Par<T>* aux = first;
	while (aux != NULL)
	{
		if (aux->getElem() == elem)
		{
			return aux->getElem();
		}
		aux = aux->getnext();
	}
	return NULL;
}
template <class T>
T Lista7<T>::SearchPos(int pos)
{
	int posS = 0;
	Par<T>* aux = first;
	while (aux != NULL)
	{
		if (posS == pos)
		{
			return aux->getElem();
		}
		aux = aux->getnext();
		posS++;
	}
	return NULL;
}
template <class T>
T Lista7<T>::operator[](int pos)
{
	int posS = 0;
	Par<T>* aux = first;
	while (aux != NULL)
	{
		if (posS == pos)
		{
			return aux->getElem();
		}
		aux = aux->getnext();
		posS++;
	}

}
template <class T>
void Lista7<T>::ordenar(bool (comparar)(T*, T*))
{
	Par<T>* first = first;
	Par<T>* aux = NULL;
	T* auxEncon;
	while (first != NULL)
	{
		aux = first->getnext();

		while (aux != NULL)
		{
			if ((*comparar)(first->getElem(), aux->getElem()))
			{
				auxEncon = aux->getElem();
				aux->setElem(first->getElem());
				first->setElem(auxEncon);
			}
			aux = aux->getnext();
		}
		first = first->getnext();
	}

}
template <class T>
bool Lista7<T>::DeleteLast()
{
	bool res;
	if (first == NULL)
	{
		res = false;
	}
	else
	{
		res = true;
		if (first == last)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			Par<T>* aux = first;
			while (aux->getnext()->getnext() != NULL)
			{
				aux = aux->getnext();
			}
			delete last;
			last = aux;
			last->setNext(NULL);
		}
	}
	return res;
}

template <class T>
bool Lista7<T>::DeleteElem(T elemento)
{
	bool result = false;
	if (first == NULL)
	{
		result = false;
	}
	else
	{
		if (first->getElem() == elemento)
		{
			result = DeleteFirst();
		}
		else if (last->getElem() == elemento)
		{
			result = DeleteLast();
		}
		else
		{
			Par<T>* aux = first;
			while (aux->getnext()->getElem() != elemento && aux->getnext() != last)
			{
				aux = aux->getnext();
				if (aux->getnext() == last && aux->getnext()->getElem() == elemento)
				{
					delete aux->getnext();
					last = aux;
					last->setElem(NULL);
					result = true;
				}
				else
				{
					if (aux->getnext()->getElem() == elemento)
					{
						Par<T>* ayuda = aux->getnext()->getnext();
						delete aux->getnext();
						aux->setNext(ayuda);
						result = true;
					}
				}
			}
		}
	}
	return result;
}


template <class T>
int Lista7<T>::countElements()
{
    int counter = 0;
	Par<T>* aux = first;
	if (first == NULL)
	{
		cout << "Empty Lista7";
	}
	while (aux != NULL)
	{
		counter++;
		aux = aux->getnext();
	}
	return counter;
}
template <class T>
void Lista7<T>::mostrarLista()
{
	if (first == NULL)
	{
		cout << "Lista Vacia" << endl;
	}
	else
	{
		Par<T>* aux = first;
		while (aux != NULL)
		{
			cout << aux->getElem();
			cout << ":" << aux->getweight()<< " ";
			if (aux->getnext() != NULL)
			{
				cout << "/ ";
			}
			aux = aux->getnext();
		}
		cout << endl;
	}
}

template <class T>

Par<T>* Lista7<T>::getFirst(){

	return first;
}
	