#ifndef IDV_TEST_APPLICATION
#define IDV_TEST_APPLICATION
#include <IDV_Math.h>
#include <IDVBase/IDVCoreBase.h>
#include <IDVScene/IDVPrimitiveManager.h>
#include <IDVScene/IDVPrimitiveInstance.h>
#include <IDVUtils/Camera.h>
#include <IDVUtils\Timer.h>

class IDVTestApplication : public IDVBaseApplication {
public:
	IDVTestApplication() : IDVBaseApplication() {}
	void InitVars();
	void CreateAssets();
	void DestroyAssets();
	void OnUpdate();
	void OnDraw();
	void OnInput();

	float deltaTime;
	bool firstFrame;
	Camera MainCamera;

	XMATRIX44 View;
	XMATRIX44 Projection;
	XMATRIX44 Camera;
	Timer TimeManager;
	IDVPrimitiveManager *PrimitiveMgr;
	IDVPrimitiveInst	 QuadInst;
	IDVPrimitiveInst	Mesh[10];
	IDVSceneProps sceneProp;
	int instancesInScene;
	int numModelos;
};

#endif