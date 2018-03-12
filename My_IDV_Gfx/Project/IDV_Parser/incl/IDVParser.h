#pragma once
#include<vector>
#include<string>

class Parser
{
public:
	struct Vertex
	{
		float x, y, z, w = 1;
		float xn, yn, zn, wn = 1;
		float u, v;
	};

	struct VertexIndex
	{
		float x, y, z;
	};

	struct MetaObject
	{
		float mx, my, mz;
	};

	struct MetaSubset
	{
		std::vector<MetaObject> submeta;
	};

	struct MatSubset
	{
		std::vector<unsigned short> mtlBuffer;
	};


	unsigned int totalVertex, totalIndexes, totalNormals, totalMeshes=0, totalMeta, totalMaterials;
	unsigned short type, totalMaterialsInMesh;
	//std::vector<Vertex> vertexVec;

	


	//std::vector<unsigned short> indexCoordinates;
	//struct Mesh
	//{
	//	//std::vector<std::vector<unsigned short>> indexCoordinatesMesh;
	//	std::vector<std::vector<Vertex>> TotalMeshes;
	//};

	std::vector<std::vector<unsigned short>> indexCoordinatesMesh;
	std::vector<std::vector<Vertex>> TotalMeshes;
	std::vector<MatSubset> totalMeshMaterials;
	std::vector<MetaSubset> meshMetaInfo;
	std::vector<unsigned short> MaterialType;


	Parser();
	void CargarVertices();
	void Imprimir(int totalVertex);
};