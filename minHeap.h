#pragma once
#include "minHeapNode.h"
#define TAM 32000
template <class T>
class minHeap
{
private:
	minHeapNode<T> mymyArray[TAM];
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
		mymyArray[i] = minHeapNode<T>();
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
			swap(myArray[pos], myArray[pos / 2]);
		}
	}
}
template <class T>
void minHeap<T>::recuperarArribaAbajo(int pos)
{
	int posMenor;
	if (mymyArray[pos * 2].getPresente() && mymyArray[pos * 2 + 1].getPresente())
	{
		if (mymyArray[pos * 2].getElem() > mymyArray[pos * 2 + 1].getElem())
		{
			posMenor = pos * 2;
		}
		else
		{
			posMenor = pos * 2 + 1;
		}
		if (mymyArray[posMenor].getElem() > mymyArray[pos].getElem())
		{
			T aux;
			aux = mymyArray[posMenor].getElem();
			mymyArray[posMenor].setElem(mymyArray[pos].getElem());
			mymyArray[pos].setElem(aux);
			recuperarArribaAbajo(posMenor);
		}
	}
	else
	{
		if (mymyArray[pos * 2].getPresente())
		{
			if (mymyArray[pos * 2].getElem() > mymyArray[pos].getElem())
			{
				T aux;
				aux = mymyArray[pos].getElem();
				mymyArray[pos].setElem(mymyArray[pos * 2].getElem());
				mymyArray[pos * 2].setElem(aux);
				recuperarArribaAbajo(pos * 2);
			}
		}
	}
}
template <class T>
void minHeap<T>::insertar(T elem, int pos)
{
	if (mymyArray[pos].getPresente() == false)
	{
		ultimo = 1;
		mymyArray[ultimo].setElem(elem);
		mymyArray[ultimo].setPresente(true);
	}
	else
	{
		ultimo += 1;
		mymyArray[ultimo].setElem(elem);
		mymyArray[ultimo].setPresente(true);
		recuperarAbajoArriba(ultimo);
	}
}
template <class T>
void minHeap<T>::recorrer(int pos)
{
	if (mymyArray[pos].getPresente() == true)
	{
		recorrer(pos * 2);
		cout << mymyArray[pos].getElem() << "---POSICION: " << pos << endl;
		recorrer(pos * 2 + 1);
	}
}
template <class T>
bool minHeap<T>::eliminar(int pos)
{
	bool esta = true;
	T mayor;
	if (mymyArray[pos].getPresente() == false)
	{
		esta = false;
	}
	else
	{
		mayor = mymyArray[1].getElem();
		mymyArray[1].setElem(mymyArray[ultimo].getElem());
		mymyArray[ultimo].setPresente(false);
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
	while (mymyArray[1].getPresente() != false)
	{
		T min = mymyArray[1].getElem();
		lista.push_back(min);
		eliminar(1);
	}
	return lista;
}



template<class T>
T minHeap<T>::getElem()
{
	return mymyArray[1].getElem()
}

template<class T>
string minHeap<T>::getVert()
{
	return mymyArray[1].getVert();
}
