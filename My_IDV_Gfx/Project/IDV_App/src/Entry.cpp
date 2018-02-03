#include <IDVDefs.h>

#include <IDVWindow/IDVWin32Manager.h>
#include <IDV_TestApplication.h>

#include <IDVParser.h>
#include <IDV_Math.h>
 
IDVBaseApplication *g_pApplication = 0;
IDVBaseWindow	   *g_pWindow = 0;

void testFunciones()
{
	XMATRIX44 mat1 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	XVECTOR3 vec1 = { 3,5,8 };

	std::cout << "OG matrix: mat1\n" << 
		mat1.m11<<", " <<mat1.m12<< ", " << mat1.m13<< ", " << mat1.m14 << "\n" <<
		mat1.m21 << ", " << mat1.m22 << ", " << mat1.m23 << ", " << mat1.m24 << "\n"<<
		mat1.m31 << ", " << mat1.m32 << ", " << mat1.m33 << ", " << mat1.m34 << "\n" <<
		mat1.m41 << ", " << mat1.m42 << ", " << mat1.m43 << ", " << mat1.m44 << "\n";

	//XMatTranslation(mat1,vec1);
	XMatIdentity(mat1);

	std::cout << "New matrix: mat1\n" <<
		mat1.m11 << ", " << mat1.m12 << ", " << mat1.m13 << ", " << mat1.m14 << "\n" <<
		mat1.m21 << ", " << mat1.m22 << ", " << mat1.m23 << ", " << mat1.m24 << "\n" <<
		mat1.m31 << ", " << mat1.m32 << ", " << mat1.m33 << ", " << mat1.m34 << "\n" <<
		mat1.m41 << ", " << mat1.m42 << ", " << mat1.m43 << ", " << mat1.m44 << "\n";
	
	//
	//std::cout << "los vectores actuales son: vec1{" << mat1 << ", " << mat1 << "}\n";
	//
		

}


int main(int arg, char ** args) {

	//PrintFromLibrary();
	testFunciones();

	g_pApplication = new IDVTestApplication();
	g_pWindow = new IDVWin32Manager((IDVBaseApplication*)g_pApplication);
	g_pWindow->InitGlobalVars();
	g_pWindow->OnCreateApplication();

	g_pWindow->UpdateApplication();

	g_pWindow->OnDestroyApplication();

	delete g_pWindow;
	delete g_pApplication;
	
	return 0;
}