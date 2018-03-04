#ifndef IDV_PARSER
#define IDV_PARSER

#include<vector>
#include<string>

class Parser
{
public:
	struct Vertex
	{
		float x, y, z, w=1;
		float xn, yn, zn, wn=1;
		float u, v;
	};

	struct VertexIndex
	{
		float x, y, z;
	};
	
	int totalVertex, totalIndexes, totalNormals;
	std::vector<Vertex> vertexVec;

	std::vector<VertexIndex> indexCoordinates;

	Parser();
	void CargarVertices();
	void Imprimir(int totalVertex);
};



#endif

