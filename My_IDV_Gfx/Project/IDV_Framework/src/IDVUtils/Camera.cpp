#include <IDVUtils\Camera.h>

Camera::Camera()
{
	Right = XVECTOR3(0, 0, 1);
	Up = XVECTOR3(0, 1, 0);
}

void Camera::Init(XVECTOR3 position, float fov, float ratio, float np, float fp, bool lf)
{
	XMatTranslation(Position, position);
	Fov = fov;
	AspectRatio = ratio;
	NPlane = np;
	FPlane = fp;
	Yaw = 0;
	Pitch = 0;
	Roll = 0;
	MaxRoll = Deg2Rad(45.0f);
	MaxPitch = Deg2Rad(90.0f);
	MaxYaw = Deg2Rad(360.0f);
	Speed = .005;
	Friction = 1;
	LeftHanded = lf;
	CreatePojection();
	Eye = position;
	SetLookAt(XVECTOR3(0, 0, 0));
	Update(.5f);
	
}

void Camera::CreatePojection()
{
	XMatPerspectiveLH(Projection, Fov, AspectRatio, NPlane, FPlane);
}

void Camera::SetLookAt(XVECTOR3 v)
{
	Look = v;
	//XMatViewLookAtLH(View, Eye, Look, Up);
}

void Camera::MoveForward(float dt)
{
	XVECTOR3 moveVector = Look - Eye;
	moveVector.Normalize();
	Look += moveVector*Speed;
	Eye += moveVector*Speed;
}

void Camera::MoveBackward(float dt)
{
	//std::cout << "Te moviste para atras" << std::endl;
	XVECTOR3 moveVector = Look - Eye;
	moveVector.Normalize();
	Look -= moveVector*Speed;
	Eye -= moveVector*Speed;
}

void Camera::StrafeLeft(float dt)
{
	XVECTOR3 moveVector = Right;
	moveVector.Normalize();
	Look -= moveVector*Speed;
	Eye -= moveVector*Speed;
}

void Camera::StrafeRight(float dt)
{
	XVECTOR3 moveVector = Right;
	moveVector.Normalize();
	Look += moveVector*Speed;
	Eye += moveVector*Speed;
	//std::cout << dt << std::endl;
}

void	Camera::MoveUp(float dt)
{
	XVECTOR3 moveVector = Up;
	moveVector.Normalize();
	Look += moveVector*Speed;
	Eye += moveVector*Speed;
}

void	Camera::MoveDown(float dt)
{
	XVECTOR3 moveVector = XVECTOR3(0, 1, 0);
	moveVector.Normalize();
	Look -= moveVector*Speed;
	Eye -= moveVector*Speed;
}

void	Camera::TurnLeft(float dt)
{
	//std::cout << "Estoy girando!";
	m_Velocity += Right*Speed;
}
void	Camera::TurnRight(float dt)
{
	m_Velocity -= Right*Speed;
}
void	Camera::TurnUp(float dt)
{
	m_Velocity -= Up*dt * 2;
}
void	Camera::TurnDown(float dt)
{
	m_Velocity += Up*dt * 2;
}

void Camera::MoveYaw(float f)
{
	if (f = 0.0f)
	{
		return;
	}
	XMATRIX44 rotation;
	XMatRotationAxisLH(rotation, Up, f);
	/*XVecTransformNormalLH(Right, Right, rotation);
	XVecTransformNormalLH(Look, Look, rotation);*/
}

void Camera::MovePitch(float f)
{

}

void Camera::MoveRoll(float f)
{

}

void Camera::Update(float dt)
{
	
	/*Eye += m_Velocity;
	XMatTranslation(Position, m_Velocity);
	m_Velocity = XVECTOR3(0.0f, 0.0f, 0.0f);
	
	LookAt = Eye + Look;
	Up = XVECTOR3(0.0f, 1.0f, 0.0f);
	XMatViewLookAtLH(View, Eye, Look, Up);
	XMatTranslation(Position, Look);

	float lookLengthOnXZ = sqrtf(Look.z * Look.z + Look.x * Look.x);
	Pitch = atan2f(Look.y, lookLengthOnXZ);
	Yaw = atan2f(Look.x, Look.z);*/
	XMatTranslation(Position, m_Velocity);
	Eye += m_Velocity;
	m_Velocity = XVECTOR3(0, 0, 0);
	Up = XVECTOR3(0, 1, 0);
	XMatTranslation(Position, Look);
	XMatViewLookAtLH(View, Eye, Look, Up);
	Right.x = View.m11;
	Right.y = View.m21;
	Right.z = View.m31;
	float lookLengthOnXZ = sqrtf(Look.z * Look.z + Look.x * Look.x);
	Pitch = atan2f(Look.y, lookLengthOnXZ);
	Yaw = atan2f(Look.x, Look.z);
	VP = View*Projection;
}

void Camera::Reset()
{

}

void Camera::SetFov(float f)
{

}

void Camera::SetRatio(float r)
{
	AspectRatio = r;
}

void Camera::SetPlanes(float n, float f)
{

}