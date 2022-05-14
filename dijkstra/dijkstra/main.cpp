#include "graph.h"

void testMenu()
{

    graph<int> myGraph;
    int opcion;
    do
    {
        cout << "MENU" << endl;
        cout << "1. load file--" << endl;
        cout << "2. Insertar Arista--" << endl;
        cout << "3. MostrarPadres" << endl;
        cout << "4--Mostrar Grafo--" << endl;
        cout << "5--Dijkstra--" << endl;
        cout << "6--Reset--" << endl;
        cout << "7-- --" << endl;
        cout << "8-Salir--" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1)
        {
            myGraph.cargarArchivo("testDefensa.txt");


        }
        if (opcion == 2)
        {

            myGraph.insArista(2, 3);
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
            int ori, dest;
            cout << "ingrese origen "; cin >> ori;
            cout << "ingrese origen "; cin >> dest;


        }
        if (opcion == 6)
        {


        }

        if (opcion == 7)
        {

        }

    } while (opcion != 8);

}


int main()
{

    testMenu();

}