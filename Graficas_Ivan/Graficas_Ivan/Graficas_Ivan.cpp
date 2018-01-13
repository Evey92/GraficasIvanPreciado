// Graficas_Ivan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>


using namespace std;

struct Vertex
{
	float x, y, z;
};

int main()
{
	fstream vertexFile;
	int totalVertex;
	char ans;
	string fileName, word;
	bool ex = false;
	Vertex vertxCoordinates;
	vector<Vertex> model;
	vector<Vertex>::iterator iterator;
	
	do
	{
		system("cls");
		cout << "Por favor introduzca el nombre del archivo. \n";
		getline(cin, fileName);
		

		vertexFile.open(fileName + ".X", ios_base::in, ios::binary);
	
		if (vertexFile.is_open())
		{
			cout << "Archivo cargado con exito!" << endl;
			ans = 'l';
		}
		else
		{			
			cout << "ERROR: No se pudo cargar el archivo. Revise que el nombre del archivo este escrito correctamente, o que el archivo se encuentre en la carpeta del programa.\n\nDesea intentarlo de nuevo?\ny/n" << endl;
			cin >> ans;
			cin.ignore();

			if (ans == 'n')
			return 0;
		}
		
	} while (ans == 'Y' || ans == 'y');

	//Aqui va lo sabroso////////////////////////////////////////////////////////////////////

	while (getline(vertexFile, word))
	{
		//Si encuentro la palabra " Mesh" me detengo y empieso a guardar los valores
		if (!word.find(" Mesh "))
		{
			//primero leo el total de vertices 
			vertexFile >> totalVertex;
			vertexFile >> ans;
			//Ahora leo todos los vertices y los guardo en la estructura
			for (int i = 0; i < totalVertex; i++)
			{
				vertexFile >> vertxCoordinates.x; // Agarra el vertice x
				vertexFile >> ans;				  //Se come el punto y coma
				vertexFile >> vertxCoordinates.y; // Agarra el vertice y
				vertexFile >> ans;				  //Se come el punto y coma
				vertexFile >> vertxCoordinates.z; // Agarra el vertice z
				vertexFile >> ans;				  //se come el ultimmo punto y coma
				vertexFile >> ans;				  //se come la coma del final de cada renglon

				//meto la estructura en un vecotr
				model.push_back(vertxCoordinates);
			}
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	
	cout << "Para imprimir el array linea por linea presiona espacio.\npara imprimir todos los vertices, presiona enter\n";
	cout << "Vertices a imprimir: " << totalVertex << "\n";
	int cont = 0;
	do
	{	
		
		ans = _getch();
		
		if (ans == 32)
		{
			//cout << "Estoy imprimiendo el array linea por linea woooo\n";
			cout << "(" << model[cont].x << ", " << model[cont].y << ", " << model[cont].z << ")\n";
			cont++;

			if (cont >= totalVertex)
				ex = true;	
		}
		else if (ans == 13)
		{
			cout << "Estoy imprimiendo el array enterooooooooo\n";
			for (iterator = model.begin(); iterator != model.end(); iterator++)
			{
				cout << "(" << iterator->x << ", " << iterator->y << ", " << iterator->z << ")\n";
			}
			ex = true;
		}

	} while(!ex);

	vertexFile.close();

	return 0;

    
}

