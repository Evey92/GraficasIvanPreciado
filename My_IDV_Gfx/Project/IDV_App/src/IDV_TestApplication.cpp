#include <IDV_TestApplication.h>
#include <stdio.h>
#include <IDV_Math.h>
#include <IDVUtils\Timer.h>



void IDVTestApplication::InitVars() {

	TimeManager.Init();
	TimeManager.Update();
	MainCamera.Init(XVECTOR3(0.0f, 1.0f, -10.0f), Deg2Rad(100.0f), (16.0f / 9.0f), 0.1f, 100000, 1);
	MainCamera.Update(0.0f);
	srand((unsigned int)TimeManager.GetDTSecs());
	sceneProp.AddCamera(&MainCamera);
	firstFrame = true;
}

void IDVTestApplication::CreateAssets() {

	XMATRIX44 VP;

	PrimitiveMgr = new IDVPrimitiveManager(m_pWindow->m_pVideoDriver->SelectedApi);

	//int index = PrimitiveMgr->CreateQuad();
	
	int index;
	//Mesh[0].CreateInstance(PrimitiveMgr->GetPrimitive(index), &MainCamera.VP);
	
	std::cout << "Cuantos modelos desea cargar. \n";
	std::cin>> numModelos;
	std::cin.ignore();

	for (int i = 0; i < numModelos; i++)
	{
		index = PrimitiveMgr->CreateMesh();
		Mesh[i].CreateInstance(PrimitiveMgr->GetPrimitive(index), &MainCamera.VP);
	}
	


	PrimitiveMgr->SetSceneProps(&sceneProp);

	
	
}



void IDVTestApplication::DestroyAssets() {
	delete PrimitiveMgr;
}

void IDVTestApplication::OnUpdate() {
	TimeManager.Update();
	deltaTime = TimeManager.GetDTSecs();
	OnInput();
	MainCamera.Update(deltaTime);

	/*Meshes[1].TranslateAbsolute(Position.x, Position.y, Position.z);
	Meshes[1].RotateXAbsolute(Orientation.x);
	Meshes[1].RotateYAbsolute(Orientation.y);
	Meshes[1].RotateXAbsolute(Orientation.z);
	Meshes[1].ScaleAbsolute(0.15f);
	Meshes[1].Update();*/

	OnDraw();

}

void IDVTestApplication::OnDraw(){
	m_pWindow->m_pVideoDriver->Clear();

	for (int i = 0; i < numModelos; i++)
	{
		Mesh[i].Draw();
	}
	
	m_pWindow->m_pVideoDriver->SwapBuffers();
	firstFrame = false;
}

void IDVTestApplication::OnInput() {
	for (int i = 0; i< MAXKEYS; i++)
	{
		if (inputManager.PressedKey(T800K_w))
		{
			//std::cout << "Amos pa delanteprrro" << std::endl;
			MainCamera.MoveForward(deltaTime);
		}
		else if (inputManager.PressedKey(T800K_a))
		{
			MainCamera.StrafeLeft(deltaTime);
		}
		else if(inputManager.PressedKey(T800K_s))
		{
			MainCamera.MoveBackward(deltaTime);
		}
		else if (inputManager.PressedKey(T800K_d))
		{

			MainCamera.StrafeRight(deltaTime);
		}
		else if (inputManager.PressedKey(T800K_SPACE))
		{

			MainCamera.MoveUp(deltaTime);
		}
		else if (inputManager.PressedKey(T800K_c))
		{

			MainCamera.MoveDown(deltaTime);
		}
		else if (inputManager.PressedKey(T800K_e))
		{

			MainCamera.TurnRight(deltaTime);
		}
		else if (inputManager.PressedKey(T800K_q))
		{

			MainCamera.TurnLeft(deltaTime);
		}
	}
}