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
        cout << "3. mostrar " << endl;
		cout << "4. djikstra " << endl;
		cout << "5. reset " << endl;
        cout << "6-Salir--" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1)
        {
          //  myGraph.leerArchivo();
			myGraph.readFile("test.txt");
        }
		        if (opcion == 2)
        {
          //  myGraph.leerArchivo();


        }

				        if (opcion == 3)
        {
          //  
			myGraph.mostrar();


        }

			 if (opcion == 4)
        {
          // 
		//	myGraph.Dikjstra(myGraph,"Sacaba");


        }

			 			 if (opcion == 5)
        {
          // 
			myGraph.reset();


        }



    } while (opcion != 6);

}
int main()
{

    testMenu();

}