#include<IDVParser.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <IDV_Math.h>
#include <iomanip>




Parser::Parser()
{
}

void Parser::CargarVertices()
{
	std::fstream vertexFile;
	//int totalVertex, totalIndexes, totalNormals;
	std::vector<Vertex>::iterator vertexIterator;
	//std::vector<VertexIndex>vertexIndexes;
	std::string fileName, word, textureName, normalName, txtNormal;
	
	//totalMeshes=0;
	char ans;
	
	/*std::cout << "Cuantos modelos desea cargar. \n";
	std::cin>>modelos;
	std::cin.ignore();
	for (int x = 0; x < modelos; x++)
	{*/
		
		do
		{
			//system("cls");
			std::cout << "Por favor introduzca el nombre del archivo. \n";
			getline(std::cin, fileName);
			std::string path = "Models/";

			vertexFile.open(path + fileName + ".X", std::ios_base::in, std::ios::binary);



			if (vertexFile.is_open())
			{
				std::cout << "Archivo cargado con exito!" << std::endl;
				ans = 'l';

				while (getline(vertexFile, word) && !vertexFile.eof())
				{
					if (!word.find(" Mesh mesh_"))
					{
						meshCount++;
					}
				}
				vertexFile.clear();
				vertexFile.seekg(0, vertexFile.beg);

				for (int meshNum = 0; meshNum < meshCount; meshNum++)
				{
					std::vector<Vertex> tempVec;
					std::vector<unsigned short> indexCoordinates;
					Mesh mesh;
					int txts = 0;
					mesh.totalVertex = 0;
					mesh.totalIndexes = 0;
					bool  done = false;
					std::cout << "Cargando datos del Mesh: " << meshNum + 1 << std::endl;
					while (getline(vertexFile, word) && !done)
					{
						//Si encuentro la palabra " Mesh" me detengo y empieso a guardar los valores
						if (!word.find(" Mesh mesh_"))
						{
							std::cout << "Cargando vertices." << std::endl;
							//primero leo el total de vertices 
							vertexFile >> mesh.totalVertex;
							vertexFile >> ans;
							//Ahora leo todos los vertices y los guardo en la estructura
							for (int i = 0; i < mesh.totalVertex; i++)
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
							vertexFile >> mesh.totalIndexes;
							vertexFile >> ans;
							std::cout << "Indices: " << mesh.totalIndexes << std::endl;

							//Ahora leo todos los vertices y los guardo en la estructura

							for (int i = 0; i < mesh.totalIndexes; i++)
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
								mesh.indexCoordinatesMesh.push_back(x);
								mesh.indexCoordinatesMesh.push_back(y);
								mesh.indexCoordinatesMesh.push_back(z);
							}
							//indexCoordinatesMesh.push_back(indexCoordinates);
						}

						if (!word.find("  MeshNormals n"))
						{
							std::cout << "Cargando Normals" << std::endl;
							//primero leo el total de vertices 
							vertexFile >> mesh.totalVertex;
							vertexFile >> ans;
							//Ahora leo todos los vertices y los guardo en la estructura
							for (int i = 0; i < mesh.totalVertex; i++)
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
							std::cout << "Cargando uvs" << std::endl;
							//primero leo el total de vertices 
							vertexFile >> mesh.totalVertex;
							vertexFile >> ans;
							//Ahora leo todos los vertices y los guardo en la estructura
							for (int i = 0; i < mesh.totalVertex; i++)
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
							std::cout << "Cargando Metadata" << std::endl;
							//primero leo el total de vertices 
							vertexFile >> mesh.totalMaterials;
							vertexFile >> ans;
							mesh.meshMetaInfo.resize(mesh.totalMaterials);
							//Ahora leo todos los vertices y los guardo en la estructura
							for (int i = 0; i < mesh.totalMaterials; i++)
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
								mesh.MaterialType.push_back(matType);
							}
							vertexFile >> mesh.totalMeta;
							vertexFile >> ans;
							mesh.meshMetaInfo.resize(mesh.totalMeta);
							for (int i = 0; i < mesh.totalVertex; i++)
							{
								for (int j = 0; j < mesh.totalMaterials; j++)
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

									mesh.meshMetaInfo[j].submeta.push_back(metaObject);
								}
							}
						}


						if (!word.find("  MeshMaterialList"))
						{
							std::cout << "Cargando Materiales" << std::endl;
							//primero leo el total de vertices 
							vertexFile >> mesh.totalMaterialsInMesh;
							vertexFile >> ans;
							vertexFile >> mesh.totalMaterials;
							vertexFile >> ans;

							mesh.totalMeshMaterials.resize(mesh.totalMaterialsInMesh);
							int matID = -1;
							for (int i = 0; i < mesh.totalIndexes; i++)
							{
								vertexFile >> matID;
								vertexFile >> ans;

								mesh.totalMeshMaterials[matID].mtlBuffer.push_back(mesh.indexCoordinatesMesh[(i * 3) + 0]);
								mesh.totalMeshMaterials[matID].mtlBuffer.push_back(mesh.indexCoordinatesMesh[(i * 3) + 1]);
								mesh.totalMeshMaterials[matID].mtlBuffer.push_back(mesh.indexCoordinatesMesh[(i * 3) + 2]);
							}

							//done = true;
						}
						bool cycle = true;
						for (unsigned int i = 0; i < mesh.totalMaterials; i++)
						{
							std::string normal;
							std::string texture;
							while (cycle)
							{
								if (!word.find("EffectParamString"))
								{
									if (!word.find("\"normalMap\";"))
									{
										char brake = 92;
										vertexFile >> std::quoted(normalName);
										if (normalName.find_last_of(brake) != std::string::npos)
										{
											int last = normalName.find_last_of(brake);
											normal = normalName.substr(last + 1, normalName.size() - last);
										}
										else
											normal = normalName;
									}
								}

								
								if (!word.find("TextureFilename"))
								{
									if (!word.find("Diffuse"))
									{
										cycle = false;
									}
								}
							}
							cycle = true;
							char brake = 92;
							vertexFile >> ans >> std::quoted(txtNormal);
							if (txtNormal.find_last_of(brake) != std::string::npos)
							{
								int last = txtNormal.find_last_of(brake);
								texture = txtNormal.substr(last + 1, a.size() - last);
							}
							else
								texture = txtNormal;
							actual.txtbuffer.push_back(texture);
							actual.nrmFileBuffer.push_back(normal);
						}

						if (!word.find("    TextureFilename Diffuse"))
						{
							vertexFile >> quoted(textureName);


							mesh.nombresTexturas.push_back(textureName);
							std::cout << "Nombre del tga: " << textureName << std::endl;
							mesh.totaltext++;
							txts++;
							//done = true;

						}

						if (txts >= mesh.totalMaterialsInMesh)
						{
							done = true;
						}
					}

					mesh.TotalVertex = tempVec;
					
					std::cout << "Texturas: " << mesh.totaltext << std::endl;
					std::cout << "Materials: " << mesh.totalMaterialsInMesh << std::endl;
					totalMeshes.push_back(mesh);
				}
			}
			else
			{
				std::cout << "ERROR: No se pudo cargar el archivo. Revise que el nombre del archivo este escrito correctamente, o que el archivo se encuentre en la carpeta del programa.\n\nDesea intentarlo de nuevo?\ny/n" << std::endl;
				std::cin >> ans;
				std::cin.ignore();
			}
			//vertexFile.close();
			std::cout << "Modelo cargado con exito." << std::endl;


		} while (ans == 'Y' || ans == 'y');
	
	vertexFile.close();
	//std::cout << "TextName " << totalMeshes[0].nombresTexturas << std::endl;
}


