#include<IDVParser.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <IDV_Math.h>



Parser::Parser()
{
}

void Parser::CargarVertices()
{
	std::fstream vertexFile;
	//int totalVertex, totalIndexes, totalNormals;
	std::vector<Vertex>::iterator vertexIterator;
	//std::vector<VertexIndex>vertexIndexes;
	std::string fileName, word;
	
	char ans;
	do
	{
		//system("cls");
		std::cout << "Por favor introduzca el nombre del archivo. \n";
		getline(std::cin, fileName);


		vertexFile.open(fileName + ".X", std::ios_base::in, std::ios::binary);

		if (vertexFile.is_open())
		{
			std::cout << "Archivo cargado con exito!" << std::endl;
			ans = 'l';
		}
		else
		{
			std::cout << "ERROR: No se pudo cargar el archivo. Revise que el nombre del archivo este escrito correctamente, o que el archivo se encuentre en la carpeta del programa.\n\nDesea intentarlo de nuevo?\ny/n" << std::endl;
			std::cin >> ans;
			std::cin.ignore();
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
				Vertex vertxCoordinates;
				vertexFile >> vertxCoordinates.x; // Agarra el vertice x
				vertexFile >> ans;				  //Se come el punto y coma
				vertexFile >> vertxCoordinates.y; // Agarra el vertice y
				vertexFile >> ans;				  //Se come el punto y coma
				vertexFile >> vertxCoordinates.z; // Agarra el vertice z
				vertexFile >> ans;				  //se come el ultimmo punto y coma
				vertexFile >> ans;				  //se come la coma del final de cada renglon

												  //meto la estructura en un vecotr
				vertexVec.push_back(vertxCoordinates);
			}
			vertexFile >> totalIndexes;
			vertexFile >> ans;
			//Ahora leo todos los vertices y los guardo en la estructura

			for (int i = 0; i < totalIndexes; i++)
			{
				unsigned short x, y, z;
				vertexFile >> ans;
				vertexFile >> ans;
				vertexFile >> x; // Agarra el vertice x
				vertexFile >> ans;				  //Se come el punto y coma
				vertexFile >> y; // Agarra el vertice y
				vertexFile >> ans;				  //Se come el punto y coma
				vertexFile >> z; // Agarra el vertice z
				vertexFile >> ans;				  //se come el ultimmo punto y coma
				vertexFile >> ans;				  //se come la coma del final de cada renglon

												  //meto la estructura en un vecotr
				indexCoordinates.push_back(x);
				indexCoordinates.push_back(y);
				indexCoordinates.push_back(z);
			}
		}

		if (!word.find("  MeshNormals "))
		{
			//primero leo el total de vertices 
			vertexFile >> totalVertex;
			vertexFile >> ans;
			//Ahora leo todos los vertices y los guardo en la estructura
			for (int i = 0; i < totalVertex; i++)
			{
				vertexFile >> vertexVec[i].xn; // Agarra el vertice x
				vertexFile >> ans;				  //Se come el punto y coma
				vertexFile >> vertexVec[i].yn; // Agarra el vertice y
				vertexFile >> ans;				  //Se come el punto y coma
				vertexFile >> vertexVec[i].zn; // Agarra el vertice z
				vertexFile >> ans;				  //se come el ultimmo punto y coma
				vertexFile >> ans;				  //se come la coma del final de cada renglon
			}

			//Ahora leo todos los vertices y los guardo en la estructura

		}

		if (!word.find("  MeshTextureCoords "))
		{
			//primero leo el total de vertices 
			vertexFile >> totalVertex;
			vertexFile >> ans;
			//Ahora leo todos los vertices y los guardo en la estructura
			for (int i = 0; i < totalVertex; i++)
			{
				vertexFile >> vertexVec[i].u; // Agarra el vertice x
				vertexFile >> ans;				  //Se come el punto y coma
				vertexFile >> vertexVec[i].v; // Agarra el vertice 
				vertexFile >> ans;				  //se come el ultimmo punto y coma
				vertexFile >> ans;				  //se come la coma del final de cada renglon
			}

			//Ahora leo todos los vertices y los guardo en la estructura

		}

	}
}


//void Parser::Imprimir(int totalVertex)
//{
//	////////////////////////////////////////////////////////////////////////////////////
//
//	cout << "Para imprimir el array linea por linea presiona espacio.\npara imprimir todos los vertices, presiona enter\n";
//	cout << "Vertices a imprimir: " << totalVertex << "\n";
//	
//	int cont = 0;
//	bool ex = false;
//	char ans;
//	do
//	{
//
//		ans = _getch();
//
//		if (ans == 32)
//		{
//			//cout << "Estoy imprimiendo el array linea por linea woooo\n";
//			cout << "(" << vertexVec[cont].x << ", " << vertexVec[cont].y << ", " << vertexVec[cont].z << ")\n";
//			cont++;
//
//			if (cont >= totalVertex)
//				ex = true;
//		}
//		else if (ans == 13)
//		{
//			cout << "Estoy imprimiendo el array enterooooooooo\n";
//			cout << "Vertices: \n";
//			for (vertexIterator = vertexVec.begin(); vertexIterator != vertexVec.end(); vertexIterator++)
//			{				
//				std::cout << "(" << vertexIterator->x << ", " << vertexIterator->y << ", " << vertexIterator->z << ")\n";
//				std::cout << "(" << vertexIterator->xn << ", " << vertexIterator->yn << ", " << vertexIterator->zn << ")\n";
//				std::cout << "(" << vertexIterator->u << ", " << vertexIterator->v << ")\n";
//			}
//			/*cout << "\n\n\n\n\nNormals: \n";
//			for (normalIterator = normalVec.begin(); normalIterator != normalVec.end(); normalIterator++)
//			{
//				
//			}*/
//			ex = true;
//		}
//
//	} while (!ex);
//}
