#pragma once
#include "minHeapNode.h"
#define TAM 32000
template <class T>
class minHeap
{
private:
	minHeapNode<T> myArray[TAM];
	int ultimo;
	int posMenor;
	list<int> lista;
public:
	minHeap();
	~minHeap();
	void recuperarAbajoArriba(int pos);
	void recuperarArribaAbajo(int pos);
	void insertar(T elem, int pos);
	void recorrer(int pos);
	bool eliminar(int pos);
	void leerArchivo(int pos);
	int getposMenor();
	void showlist();
	list<T> heapSort();


	T getElem();
	string getVert();
};
template <class T>
minHeap<T>::minHeap() {
	for (int i = 0; i < TAM; i += 1) {
		myArray[i] = minHeapNode<T>();
	}
	ultimo = -1;
}
template <class T>
minHeap<T>::~minHeap() {

}
template <class T>
void minHeap<T>::recuperarAbajoArriba(int pos) {
	T aux;
	if (myArray[pos / 2].getPresente())
	{
		if (myArray[pos].getElem() < myArray[pos / 2].getElem())
		{
			aux = myArray[pos / 2].getElem();
			myArray[pos / 2].setElem(myArray[pos].getElem());
			myArray[pos].setElem(aux);
			recuperarAbajoArriba(pos / 2);
		}
	}
}
template <class T>
void minHeap<T>::recuperarArribaAbajo(int pos)
{
	int posMenor;
	if (myArray[pos * 2].getPresente() && myArray[pos * 2 + 1].getPresente())
	{
		if (myArray[pos * 2].getElem() > myArray[pos * 2 + 1].getElem())
		{
			posMenor = pos * 2;
		}
		else
		{
			posMenor = pos * 2 + 1;
		}
		if (myArray[posMenor].getElem() > myArray[pos].getElem())
		{
			T aux;
			aux = myArray[posMenor].getElem();
			myArray[posMenor].setElem(myArray[pos].getElem());
			myArray[pos].setElem(aux);
			recuperarArribaAbajo(posMenor);
		}
	}
	else
	{
		if (myArray[pos * 2].getPresente())
		{
			if (myArray[pos * 2].getElem() > myArray[pos].getElem())
			{
				T aux;
				aux = myArray[pos].getElem();
				myArray[pos].setElem(myArray[pos * 2].getElem());
				myArray[pos * 2].setElem(aux);
				recuperarArribaAbajo(pos * 2);
			}
		}
	}
}
template <class T>
void minHeap<T>::insertar(T elem, int pos)
{
	if (myArray[pos].getPresente() == false)
	{
		ultimo = 1;
		myArray[ultimo].setElem(elem);
		myArray[ultimo].setPresente(true);
	}
	else
	{
		ultimo += 1;
		myArray[ultimo].setElem(elem);
		myArray[ultimo].setPresente(true);
		recuperarAbajoArriba(ultimo);
	}
}
template <class T>
void minHeap<T>::recorrer(int pos)
{
	if (myArray[pos].getPresente() == true)
	{
		recorrer(pos * 2);
		cout << myArray[pos].getElem() << "---POSICION: " << pos << endl;
		recorrer(pos * 2 + 1);
	}
}
template <class T>
bool minHeap<T>::eliminar(int pos)
{
	bool esta = true;
	T mayor;
	if (myArray[pos].getPresente() == false)
	{
		esta = false;
	}
	else
	{
		mayor = myArray[1].getElem();
		myArray[1].setElem(myArray[ultimo].getElem());
		myArray[ultimo].setPresente(false);
		ultimo -= 1;
		recuperarArribaAbajo(1);
	}
	return esta;
}
template <class T>
void minHeap<T>::leerArchivo(int pos)
{
	T dato;
	ifstream Archivo;
	//Archivo.open(ruta);
	while (!Archivo.eof())
	{
		Archivo >> dato;
		insertar(dato, 1);
	}
}
template <class T>
int minHeap<T>::getposMenor()
{
	return posMenor;
}
template <class T>
void minHeap<T>::showlist()
{
	list<int>::iterator it;
	for (it = lista.begin(); it != lista.end(); ++it)
		cout << *it << endl;
}

template <class T>
list<T> minHeap<T>::heapSort()
{
	while (myArray[1].getPresente() != false)
	{
		T min = myArray[1].getElem();
		lista.push_back(min);
		eliminar(1);
	}
	return lista;
}



template<class T>
T minHeap<T>::getElem()
{
	return myArray[1].getElem()
}

template<class T>
string minHeap<T>::getVert()
{
	return myArray[1].getVert();
}
