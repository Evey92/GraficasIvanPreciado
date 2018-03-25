#include <IDVUtils\Camera.h>

Camera::Camera()
{
	Right = XVECTOR3(1, 0, 0);
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
	Speed = 10;
	Friction = 1;
	LeftHanded = lf;
	CreatePojection();
	Eye = position;
	SetLookAt(XVECTOR3(0, 0, 0));
	Update(1.0f);
	
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
		XVECTOR3 moveVector(Look.x, 0.0f, 0.0f);
		moveVector *= dt;
		m_Velocity += moveVector;

}

void Camera::MoveBackward(float dt)
{
	std::cout << "Te moviste para atras" << std::endl;
	XVECTOR3 moveVector(Look.x, 0.0f, 0.0f);
	moveVector *= dt;
	m_Velocity -= moveVector;
}

void Camera::StrafeLeft(float dt)
{
	m_Velocity += Right * dt;
}

void Camera::StrafeRight(float dt)
{
	m_Velocity -= Right * dt;
}


void Camera::MoveYaw(float f)
{

}

void Camera::MovePitch(float f)
{

}

void Camera::MoveRoll(float f)
{

}

void Camera::Update(float dt)
{
	VP = View*Projection;
	Eye += m_Velocity;
	//
	m_Velocity = XVECTOR3(0.0f, 0.0f, 0.0f);
	//
	LookAt = Eye + Look;

	XVECTOR3 up = XVECTOR3(0.0f, 1.0f, 0.0f);
	XMatViewLookAtLH(View, Eye, Look, Up);
	
	float lookLengthOnXZ = sqrtf(Look.z * Look.z + Look.x * Look.x);
	Pitch = atan2f(Look.y, lookLengthOnXZ);
	Yaw = atan2f(Look.x, Look.z);
}

void Camera::Reset()
{

}

void Camera::SetFov(float f)
{

}

void Camera::SetRatio(float r)
{

}

void Camera::SetPlanes(float n, float f)
{

}