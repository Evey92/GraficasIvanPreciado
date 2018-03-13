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
	
	//totalMeshes=0;
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

			while (getline(vertexFile, word) && !vertexFile.eof())
			{
				if (!word.find(" Mesh mesh_"))
				{
					totalMeshes++;
				}
			} 
			vertexFile.clear();
			vertexFile.seekg(0,vertexFile.beg);

			for(int meshNum = 0; meshNum < totalMeshes; meshNum++)
			{
				std::vector<Vertex> tempVec;
				std::vector<unsigned short> indexCoordinates;
				totalVertex = 0;
				totalIndexes = 0;
				bool done = false;
				while(getline(vertexFile, word) && !done)
				{					
						//Si encuentro la palabra " Mesh" me detengo y empieso a guardar los valores
						if (!word.find(" Mesh mesh_"))
						{
							std::cout << "Cargadndo vertices del mesh " << meshNum + 1 << std::endl;
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
								tempVec.push_back(vertxCoordinates);
							}
							vertexFile >> totalIndexes;
							vertexFile >> ans;
							std::cout << "Indices: " << totalIndexes << std::endl;

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
							indexCoordinatesMesh.push_back(indexCoordinates);
						}

						if (!word.find("  MeshNormals n"))
						{
							std::cout << "Cargadndo Normals" << std::endl;
							//primero leo el total de vertices 
							vertexFile >> totalVertex;
							vertexFile >> ans;
							//Ahora leo todos los vertices y los guardo en la estructura
							for (int i = 0; i < totalVertex; i++)
							{
								vertexFile >> tempVec[i].xn; // Agarra el vertice x
								vertexFile >> ans;				  //Se come el punto y coma
								vertexFile >> tempVec[i].yn; // Agarra el vertice y
								vertexFile >> ans;				  //Se come el punto y coma
								vertexFile >> tempVec[i].zn; // Agarra el vertice z
								vertexFile >> ans;				  //se come el ultimmo punto y coma
								vertexFile >> ans;				  //se come la coma del final de cada renglon
							}

							//Ahora leo todos los vertices y los guardo en la estructura

						}

						if (!word.find("  MeshTextureCoords t"))
						{
							std::cout << "Cargadndo uvs" << std::endl;
							//primero leo el total de vertices 
							vertexFile >> totalVertex;
							vertexFile >> ans;
							//Ahora leo todos los vertices y los guardo en la estructura
							for (int i = 0; i < totalVertex; i++)
							{
								vertexFile >> tempVec[i].u; // Agarra el vertice x
								vertexFile >> ans;				  //Se come el punto y coma
								vertexFile >> tempVec[i].v; // Agarra el vertice 
								vertexFile >> ans;				  //se come el ultimmo punto y coma
								vertexFile >> ans;				  //se come la coma del final de cada renglon
							}	
						}

						if (!word.find("  DeclData {"))
						{
							std::cout << "Cargadndo Metadata" << std::endl;
							//primero leo el total de vertices 
							vertexFile >> totalMaterials;
							vertexFile >> ans;
							meshMetaInfo.resize(totalMaterials);
							//Ahora leo todos los vertices y los guardo en la estructura
							for (int i = 0; i < totalMaterials; i++)
							{
								unsigned short matType;
								vertexFile >> ans;				  
								vertexFile >> ans;
								vertexFile >> ans;				  
								vertexFile >> ans;
								vertexFile >> matType; 
								vertexFile >> ans;				  
								vertexFile >> ans;				  
								vertexFile >> ans;					
								vertexFile >> ans;			
								MaterialType.push_back(matType);
							}
							vertexFile >> totalMeta;
							vertexFile >> ans;
							meshMetaInfo.resize(totalMeta);
							for (int i = 0; i < totalVertex; i++)
							{
								for (int j = 0; j < totalMaterials; j++)
								{
									MetaObject metaObject;
									unsigned int x, y, z;
									vertexFile >> x;
									vertexFile >> ans;
									vertexFile >> y;
									vertexFile >> ans;
									vertexFile >> z;
									vertexFile >> ans;

									metaObject.mx = reinterpret_cast<float&>(x);
									metaObject.my = reinterpret_cast<float&>(y);
									metaObject.mz = reinterpret_cast<float&>(z);

									meshMetaInfo[i].submeta.push_back(metaObject);
								}
							}
						}

						if (!word.find("  MeshMaterialList"))
						{
							std::cout << "Cargadndo Materiales" << std::endl;
							//primero leo el total de vertices 
							vertexFile >> totalMaterialsInMesh;
							vertexFile >> ans;
							vertexFile >> totalMaterials;
							vertexFile >> ans;

							totalMeshMaterials.resize(totalMaterialsInMesh);
							int matID=-1;
							for (int i = 0; i < totalIndexes; i++)
							{
								vertexFile >> matID;
								vertexFile >> ans;
								totalMeshMaterials[matID].mtlBuffer.push_back(indexCoordinatesMesh[meshNum][(i * 3) + 0]);
								totalMeshMaterials[matID].mtlBuffer.push_back(indexCoordinatesMesh[meshNum][(i * 3) + 1]);
								totalMeshMaterials[matID].mtlBuffer.push_back(indexCoordinatesMesh[meshNum][(i * 3) + 2]);
							}

							done = true;
						}
						
						
					}
				TotalMeshes.push_back(tempVec);
				
				
			}
			vertexFile.close();
		}
		else
		{
			std::cout << "ERROR: No se pudo cargar el archivo. Revise que el nombre del archivo este escrito correctamente, o que el archivo se encuentre en la carpeta del programa.\n\nDesea intentarlo de nuevo?\ny/n" << std::endl;
			std::cin >> ans;
			std::cin.ignore();
		}
		//vertexFile.close();
	} while (ans == 'Y' || ans == 'y');
	
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