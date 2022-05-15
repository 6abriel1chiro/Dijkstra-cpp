#pragma once
#include "Node.h"
#define TAM 100


template <class T>
class graph
{
private:
	Node<T> arr[TAM];
	Lista8<T>* cola;
public:
	graph();
	~graph();
	void insArista(T dato1, T dato2);
	void mostrarPadres();
	void mostrar();
	bool DFS(T ori, T dest);
	bool BFS(T ori, T dest);
	void cargarArchivo(string nom);

	void mostrarCamino(T dest);
	void Dikjstra(graph g, string ori);

	Lista8<T>* getLista();




};
template <class T>
graph<T>::graph()
{
	cola = new Lista8<T>();
}
template <class T>
graph<T>::~graph()
{

}
template <class T>
void graph<T>::insArista(T dato1, T dato2)
{
	arr[dato1].getLista()->addFront(dato2);

}
template <class T>
void graph<T>::mostrarPadres()
{
	for (int i = 0; i < TAM; i++)
	{
		if (arr[i].getLista()->findInPos(0) != NULL)
			cout << arr[i].getPadre() << " ";
	}
}
template <class T>
void graph<T>::mostrar()
{
	for (int i = 0; i < TAM; i++)
	{
		if (arr[i].getLista()->findInPos(0) != NULL)
			cout << i << "->";
		arr[i].getLista()->mostrar();
	}
}
template <class T>
bool graph<T>::DFS(T ori, T dest)
{
	bool found = false;
	arr[ori].setMarca(true);
	int i = 0;
	T adya = arr[ori].getLista()->findInPos(i);
	while (adya != NULL)
	{
		if (found == false && arr[adya].getMarca() == false)
		{
			arr[adya].setPadre(ori);
			if (adya == dest)
			{
				found = true;
			}
			else
			{
				found = DFS(adya, dest);
			}
		}
		i += 1;
		adya = arr[ori].getLista()->findInPos(i);
	}
	return found;
}
template <class T>
bool graph<T>::BFS(T ori, T dest)
{
	int i;
	bool found = false;
	arr[ori].setMarca(true);
	cola->addBack(ori);
	while (cola != NULL && found == false)
	{
		i = 0;
		T vert = cola->findInPos(0);
		T adya = arr[vert].getLista()->findInPos(i);
		while (adya != NULL && found == false)
		{
			if (arr[adya].getMarca() == false)
			{
				arr[adya].setPadre(vert);
				if (adya == dest)
				{
					found = true;
				}
				else
				{
					arr[adya].setMarca(true);
					cola->addBack(adya);
				}
			}
			i += 1;
			adya = arr[vert].getLista()->findInPos(i);

		}
	}
	return found;
}
template <class T>
void graph<T>::cargarArchivo(string nom)
{
	int i = 0;
	ifstream arch;
	arch.open(nom);
	T vec[100];

	while (!arch.eof())
	{
		T dato = 0;
		while (dato != -1)
		{
			arch >> dato;
			vec[i] = dato;
			if (dato != -1)
				i += 1;
		}
		for (int pos = 1; pos < i; pos += 1)
		{
			insArista(vec[0], vec[pos]);
		}
		for (int pos = 0; pos < i; pos += 1)
		{
			vec[i] = NULL;
		}
		i = 0;
	}



}

template <class T>
void graph<T>::mostrarCamino(T dest)
{
	if (dest != -1)
	{
		mostrarCamino(arr[dest].getPadre());
		cout << dest << " - ";
	}
}

template<class T>
inline void graph<T>::Dikjstra(graph grafo, string ori)
{



		priority_queue <Point, vector<Point>, myComparator > ColaP; // el primero en salir es el de Distancia 1, luego 2, etc. Se puede  usar montículo MIN


		grafo[ori].setDistancia(0);
		ColaP. (G[ori].Dist, ori); // El montículo tiene nodos con 2 atributos: Distancia y Vértice origen

	while (ColaPpq.empty() == false) 
	{

		Point Duo = ColaP.top();	// Duo tiene una Distancia y el vértice
		string Vi = Duo.getY();  // El Vértice es el segundo elemento

		if ((grafo[Vi].getMarca == false))
		{
			grafo[Vi].setMarca(true);
			Tripla<T> Ady = grafo[Vi].getLista().getPrimer(); //Se puede usar sacar siguiente adyacente
			while (Ady != NULL)
			{

				if (grafo[Ady.pos()].getMarca == false and Ady.Peso() > 0) {
					if ((grafo[Vi].Distancia() + Ady.Peso) < (grafo[Ady.pos()].Distancia()) )
					{
					grafo[Ady.pos()].Distancia() = grafo[Vi].Distancia() + Ady.Peso();
					grafo[Ady.pos()].Padre() = Vi;
					ColaP.push(grafo[Ady.pos()].Distancia(), Ady.pos());
					}
				}

			}			
		}
		Ady = Ady.getSiguiente(); //Se puede usar sacar siguiente adyacente

	}
	return grafo;

}

template<class T>
inline Lista8<T>* graph<T>::getLista()
{
	return cola;
}


