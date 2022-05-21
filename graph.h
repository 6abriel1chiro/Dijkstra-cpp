#pragma once
#include "Node.h"
#include "minHeap.h"
template <class T>
class graph
{
public:
	graph();
	~graph();
	void readFile(string name);
	void mostrar();
	void Dikjstra(map<T, Nodo<T>>& grafos, string ori);
	void inicio(map<T, Nodo<T>>& grafos);
	map<T, Nodo<T>>& getGrafo();
	void reset();

private :
	map<string, Node<string>> grafo;
};
template <class T>
graph<T>::graph()
{
	//
}
template <class T>
graph<T>::~graph()
{

}
template <class T>
void graph<T>::readFile(string name)
{
	ifstream file;
	string dato1, dato2;
	int dato3;
	file.open(name);
	while (!file.eof())
	{
		file >> dato1>> dato2>>dato3;
		grafo[dato1].getLista()->InsertFirst(dato2, dato3);
		grafo[dato2].getLista()->InsertFirst(dato1, dato3);
	}
	file.close();

}
template <class T>
void graph<T>::mostrar()
{
	map<string, Node<string>>::iterator it;
	for (it = grafo.begin(); it != grafo.end(); it++) 
	{
		cout << it->second.getPadre() << " "<<it->second.getDistancia()<< " ";
		cout << it->first << " -> ";
		it->second.getLista()->mostrarLista();
	}
}

template<class T>
 void graph<T>::reset()
{


}

template <class T>
void Grafo<T>::inicio(map<T, Nodo<T>>& grafos)
{
	map<string, Nodo<string>>::iterator it;
	for (it = grafos.begin(); it != grafos.end(); it++)
	{
		it->second.setMarca(false);
		it->second.setDistancia(9999);
		it->second.setPadre("#");
	}
}
template <class T>
map<T, Nodo<T>>& Grafo<T>::getGrafo()
{
	return grafo;
}
template <class T>
void Grafo<T>::llenarGrafo(map<T, Nodo<T>>& grafos, string nom)
{
	ifstream arch;
	string dato1, dato2;
	int dato3;
	arch.open(nom);
	while (!arch.eof())
	{
		arch >> dato1;
		arch >> dato2;
		arch >> dato3;
		grafos[dato1].getLista()->insertarPrincipio(dato2, dato3);
		grafos[dato2].getLista()->insertarPrincipio(dato1, dato3);
	}
	arch.close();
}

template<class T>
 void graph<T>::Dikjstra(map<T, Nodo<T>>& grafos, string ori)
 {
	inicio(grafos);
	string Vi;
	NodoMonticulo<int> Duo;
	Par<string>* Ady;

	Monticulo<int> colaP;
	grafos[ori].setDistancia(0);
	colaP.poner(grafos[ori].getDistancia(), ori);

	while (colaP.vacio() != false)
	{
		//Duo
		Duo.poner(colaP.buscarMenor(), colaP.buscarOrigen());
		colaP.eliminar();
		Vi = Duo.getVert();

		if (grafos[Vi].getMarca() == false)
		{
			grafos[Vi].setMarca(true);
			if (grafos[Vi].getLista() != NULL)
			{
				Ady = grafos[Vi].getLista()->getPrimer();
				while (Ady != NULL)
				{
					if (grafos[Ady->getElem()].getMarca() == false && Ady->getPeso() > 0)
					{
						int dist = grafos[Vi].getDistancia() + Ady->getPeso();
						if (dist < grafos[Ady->getElem()].getDistancia())
						{
							grafos[Ady->getElem()].setDistancia(dist);
							grafos[Ady->getElem()].setPadre(Vi);
							colaP.poner(grafos[Ady->getElem()].getDistancia(), Ady->getElem());
						}
					}
					Ady = Ady->getSig();
				}
			}
		}
	}
}
