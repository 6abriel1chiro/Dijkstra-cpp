#include "graph.h"

void testMenu()
{

    graph<string> myGraph;
    int opcion;
    do
    {

        cout << "MENU" << endl;
        cout << "1. load file--" << endl;
        cout << "2. Insertar Arista--" << endl;
        cout << "3. MostrarPadres" << endl;
        cout << "4--Mostrar Grafo--" << endl;
        cout << "5--BFS--" << endl;
        cout << "6--DFS--" << endl;
        cout << "7--mostrart camino--" << endl;
        cout << "8-Salir--" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1)
        {
            myGraph.cargarArchivo("testDefensa.txt");


        }
        if (opcion == 2)
        {
            string value1, value2;
            cout << "ingrese los valores que forman la arista:  ";

            cin >> value1 >> value2;
            myGraph.insArista(value1, value2);
        }
        if (opcion == 3)
        {
            myGraph.mostrarPadres();
        }
        if (opcion == 4)
        {
            myGraph.mostrar();
        }
        if (opcion == 5)
        {
            string ori, dest;
            cout << "ingrese origen "; cin >> ori;
            cout << "ingrese origen "; cin >> dest;

            if (myGraph.BFS(ori, dest))
            {
                cout << " camino encontrado " << endl;
            }
            else
            {
                cout << " camino no encontrado " << endl;

            }

        }
        if (opcion == 6)
        {
            string ori, dest;
            cout << "ingrese origen "; cin >> ori;
            cout << "ingrese origen "; cin >> dest;
            if (myGraph.DFS(ori, dest))
            {
                cout << " camino encontrado " << endl;
            }
            else
            {
                cout << " camino no encontrado " << endl;

            }

        }

        if (opcion == 7)
        {
            string  dest;
            cout << "ingrese dest "; cin >> dest;
            myGraph.mostrarCamino(dest);
        }
        if (opcion == 8)
        {
            string ori, dest;

            cout << "ingrese origen "; cin >> ori;
            cout << "ingrese origen "; cin >> dest;
             myGraph.Dikjstra(myGraph, ori);
        }
        if (opcion == 9)
        {


            // myGraph.reset();
        }

    } while (opcion != 10);

}
int main()
{

    testMenu();

}