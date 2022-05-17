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
	void Dikjstra(graph grafo, string ori);

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
template<class T>
 void graph<T>::Dikjstra(graph G, string ori)
{

	

		minHeap<int> ColaP;
		G[ori].setDistancia(0);
		ColaP.insertar(G[ori].getDistancia(), ori); // El montículo tiene nodos con 2 atributos: Distancia y Vértice origen

	while (ColaP.empty() != false) 
	{

		Par<T> Duo;	// Duo tiene una Distancia y el vértice
		Duo.setElem(ColaP.getVert());
		Duo.setweight(ColaP.getElem());
		ColaP.eliminar();

		string Vi = Duo.getElem();  // El Vértice es el segundo elemento

		if ((graph[Vi].getMarca() == false))
		{
			graph[Vi].setMarca(true);
			Par<T>* Ady = graph[Vi].getLista().getFirst(); //Se puede usar sacar siguiente adyacente
			while (Ady != NULL)
			{

				if (graph[Ady.pos()].getMarca == false and Ady.getweight() > 0) {
					if ((graph[Vi].getDistancia() + Ady.getweight) < (graph[Ady.getElem()].getDistancia()) )
					{
					graph[Ady.getElem()].getDistancia() = grafo[Vi].getDistancia() + Ady.getweight();
					graph[Ady.getElem()].getPadre() = Vi;
					ColaP.insertar(graph[Ady.getElem()].getDistancia(), Ady.getElem());
					}
				}

			}			
		}
		Ady = Ady.getnext(); //Se puede usar sacar siguiente adyacente

	}
	return G;
	
}