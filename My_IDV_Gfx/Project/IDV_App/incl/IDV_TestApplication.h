#ifndef IDV_TEST_APPLICATION
#define IDV_TEST_APPLICATION

#include <IDVBase/IDVCoreBase.h>
#include <IDVScene/IDVPrimitiveManager.h>
#include <IDVScene/IDVPrimitiveInstance.h>
#include <IDVUtils\Camera.h>

class IDVTestApplication : public IDVBaseApplication {
public:
	IDVTestApplication() : IDVBaseApplication() {}
	void InitVars();
	void CreateAssets();
	void DestroyAssets();
	void OnUpdate();
	void OnDraw();
	void OnInput();

	Camera MainCamera;

	IDVPrimitiveManager *PrimitiveMgr;
	IDVPrimitiveInst	 QuadInst;
	IDVPrimitiveInst	Models[10];
};

#endif