#include <IDVVideo/IDVGLShader.h>
#include <IDVUtils/IDVUtils.h>
#include <IDVScene/MYGLMesh.h>
#include <IDV_Math.h>
#include <string>

void GLMesh::Create() {
	SigBase = IDVSig::HAS_TEXCOORDS0 | IDVSig::HAS_NORMALS | IDVSig::HAS_TANGENTS | IDVSig::HAS_BINORMALS;

	char *vsSourceP = file2string("Shaders/VS_Mesh.glsl");
	char *fsSourceP = file2string("Shaders/FS_Mesh.glsl");

	std::string vstr = std::string(vsSourceP);
	std::string fstr = std::string(fsSourceP);

	free(vsSourceP);
	free(fsSourceP);

	parser.CargarVertices();
	Mesh_Info.reserve(parser.meshCount);

	for (int i = 0; i < parser.meshCount; i++)
	{
		MeshInfo tempMesh;
		Parser::Mesh mesh = parser.totalMeshes[i];

		g_pBaseDriver->CreateShader(vstr, fstr, SigBase);
		
		glGenBuffers(1, &tempMesh.VB);
		glBindBuffer(GL_ARRAY_BUFFER, tempMesh.VB);
		glBufferData(GL_ARRAY_BUFFER, mesh.totalVertex * sizeof(Parser::Vertex), &mesh.TotalVertex[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glGenBuffers(1, &tempMesh.IB);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tempMesh.IB);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indexCoordinatesMesh.size() * sizeof(unsigned short), &mesh.indexCoordinatesMesh[0], GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		for (int j = 0; j < mesh.totalMaterialsInMesh; j++)
		{
			SubsetInfo tmp_subset;
			glGenBuffers(1, &tmp_subset.Id);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tmp_subset.Id);
			glBufferData(
				GL_ELEMENT_ARRAY_BUFFER,
				mesh.totalMeshMaterials[j].mtlBuffer.size() * sizeof(unsigned short),
				&mesh.totalMeshMaterials[j].mtlBuffer[0],
				GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			tempMesh.SubSets.push_back(tmp_subset);
		}
		Mesh_Info.push_back(tempMesh);

	}
}

void GLMesh::Transform(float *t) {
	transform = t;
}

void GLMesh::Draw(float *t, float *vp) {

	if (t)
		transform = t;

	for (int i = 0; i < parser.meshCount; i++)
	{
		MeshInfo drawinfo = Mesh_Info[i];
		Parser::Mesh mesh = parser.totalMeshes[i];

		
		IDVGLShader * s=0;
		XMATRIX44 Scale;
		XMATRIX44 View;
		XMATRIX44 Projection;
		XMatViewLookAtLH(View, XVECTOR3(0.0f, 95.0f, -60.0f), XVECTOR3(0.0f, 10.0f, 1.0f), XVECTOR3(0.0f, 100.0f, 0.0f));
		XMatPerspectiveLH(Projection, Deg2Rad(100.0f), 1280.0f / 720.0f, 0.1f, 1000.0f);
		XMatScaling(Scale, 1.0f, 1.0f, 1.0f);

		XMATRIX44 VP = vp;
		XMATRIX44 WV = vp;
		XMATRIX44 WVP = Scale*View*Projection;
		
		unsigned int sig = SigBase;
		sig |= gSig;

		glBindBuffer(GL_ARRAY_BUFFER, drawinfo.VB);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, drawinfo.IB);

		for (int j = 0; j < drawinfo.SubSets.size(); j++)
		{
			SubsetInfo subinfo = drawinfo.SubSets[j];
			s = dynamic_cast<IDVGLShader*>(g_pBaseDriver->GetShaderSig(sig));
			glUseProgram(s->ShaderProg);

			glUniformMatrix4fv(s->matWorldUniformLoc, 1, GL_FALSE, &transform.m[0][0]);
			glUniformMatrix4fv(s->matWorldViewProjUniformLoc, 1, GL_FALSE, &WVP.m[0][0]);
			glUniformMatrix4fv(s->matWorldViewUniformLoc, 1, GL_FALSE, &WV.m[0][0]);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, subinfo.Id);

			glEnableVertexAttribArray(s->vertexAttribLoc);
			glVertexAttribPointer(s->vertexAttribLoc, 4, GL_FLOAT, GL_FALSE, sizeof(Parser::Vertex), BUFFER_OFFSET(0));
			glEnableVertexAttribArray(s->normalAttribLoc);
			glVertexAttribPointer(s->normalAttribLoc, 4, GL_FLOAT, GL_FALSE, sizeof(Parser::Vertex), BUFFER_OFFSET(16));
			glEnableVertexAttribArray(s->uvAttribLoc);
			glVertexAttribPointer(s->uvAttribLoc, 2, GL_FLOAT, GL_FALSE, sizeof(Parser::Vertex), BUFFER_OFFSET(32));

			glDrawElements(GL_TRIANGLES, mesh.totalMeshMaterials[j].mtlBuffer.size(), GL_UNSIGNED_SHORT, 0);
		}
	}
}

void GLMesh::Destroy() {

}
