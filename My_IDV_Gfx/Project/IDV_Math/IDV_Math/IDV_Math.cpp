// IDV_Math.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <IDV_Math.h>
#include <iostream>
#include <vector>
#include <cmath>

////////Overloading de vector2
XVECTOR2 &XVECTOR2:: operator+=(const XVECTOR2& otherVector)
{
	this->x = this->x + otherVector.x;
	this->y = this->y + otherVector.y;

	return *this;
}

XVECTOR2 &XVECTOR2:: operator-=(const XVECTOR2& otherVector)
{
	this->x = this->x - otherVector.x;
	this->y = this->y - otherVector.y;

	return *this;
}

XVECTOR2 &XVECTOR2:: operator*= (float scalar)
{
	this->x = this->x * scalar;
	this->y = this->y * scalar;

	return *this;
}

XVECTOR2 &XVECTOR2:: operator/= (float scalar)
{
	this->x = this->x / scalar;
	this->y = this->y / scalar;

	return *this;
}

XVECTOR2 XVECTOR2:: operator + () const
{
	XVECTOR2 vecTemp;
	if (this->x < 0)
		vecTemp.x = -1 * this->x;
	else
		vecTemp.x = this->x;

	if (this->y < 0)
		vecTemp.y = -1 * this->y;
	else
		vecTemp.y = this->y;

	return vecTemp;
}
XVECTOR2 XVECTOR2:: operator - () const
{
	XVECTOR2 vecTemp;
	vecTemp.x = -1 * this->x;
	vecTemp.y = -1 * this->y;
	return vecTemp;
}

XVECTOR2 XVECTOR2:: operator + (const XVECTOR2& otherVector) const
{
	XVECTOR2 vecTemp;
	vecTemp.x = this->x + otherVector.x;
	vecTemp.y = this->y + otherVector.y;

	return vecTemp;
}
XVECTOR2 XVECTOR2:: operator - (const XVECTOR2& otherVector) const
{
	XVECTOR2 vecTemp;
	vecTemp.x = this->x - otherVector.x;
	vecTemp.y = this->y - otherVector.y;

	return vecTemp;
}
XVECTOR2 XVECTOR2:: operator * (float scalar) const
{
	XVECTOR2 vecTemp;
	vecTemp.x = this->x * scalar;
	vecTemp.y = this->y * scalar;

	return vecTemp;
}
XVECTOR2 XVECTOR2:: operator / (float scalar) const
{
	XVECTOR2 vecTemp;
	vecTemp.x = this->x / scalar;
	vecTemp.y = this->y / scalar;

	return vecTemp;
}

bool XVECTOR2::operator== (const XVECTOR2& otherVector) const
{
	if (this->x == otherVector.x && this->y == otherVector.y)
	{
		return true;
	}

	return false;
}
bool XVECTOR2::operator!= (const XVECTOR2& otherVector) const
{
	if (this->x == otherVector.x && this->y == otherVector.y)
	{
		return false;
	}

	return true;
}

void Normalize()
{

}

///////////////////////////////////////////////////////////

////////Overloading de vector3

XVECTOR3  &XVECTOR3::operator+=(const XVECTOR3& otherVector)
{
	this->x = this->x + otherVector.x;
	this->y = this->y + otherVector.y;
	this->z = this->z + otherVector.z;

	return *this;
}
//
//
//
XVECTOR3 &XVECTOR3::operator -= (const XVECTOR3& otherVector)
{
	this->x = this->x - otherVector.x;
	this->y = this->y - otherVector.y;
	this->z = this->z - otherVector.z;

	return *this;
}

XVECTOR3 &XVECTOR3::operator *= (float scalar)
{
	this->x = this->x * scalar;
	this->y = this->y * scalar;
	this->z = this->z * scalar;
	return *this;
}

XVECTOR3 &XVECTOR3::operator /= (float scalar)
{
	this->x = this->x * scalar;
	this->y = this->y * scalar;
	this->z = this->z * scalar;
	return *this;
}
//
XVECTOR3 XVECTOR3::operator + () const
{
	XVECTOR3 vecTemp;
	if (this->x < 0)
		vecTemp.x = -1 * this->x;
	else
		vecTemp.x = this->x;

	if (this->y < 0)
		vecTemp.y = -1 * this->y;
	else
		vecTemp.y = this->y;

	if (this->z < 0)
		vecTemp.z = -1 * this->z;
	else
		vecTemp.z = this->z;

	return vecTemp;
}

XVECTOR3 XVECTOR3::operator - () const
{
	XVECTOR3 vecTemp;
	vecTemp.x = -1 * this->x;
	vecTemp.y = -1 * this->y;
	vecTemp.z = -1 * this->z;
	return vecTemp;
}

XVECTOR3 XVECTOR3::operator + (const XVECTOR3& otherVector) const
{
	XVECTOR3 vecTemp;
	vecTemp.x = this->x + otherVector.x;
	vecTemp.y = this->y + otherVector.y;
	vecTemp.z = this->z + otherVector.z;

	return vecTemp;
}

XVECTOR3 XVECTOR3::operator - (const XVECTOR3& otherVector) const
{
	XVECTOR3 vecTemp;
	vecTemp.x = this->x - otherVector.x;
	vecTemp.y = this->y - otherVector.y;
	vecTemp.z = this->z - otherVector.z;

	return vecTemp;
}

XVECTOR3 XVECTOR3::operator * (float scalar) const
{
	XVECTOR3 vecTemp;
	vecTemp.x = this->x * scalar;
	vecTemp.y = this->y * scalar;
	vecTemp.z = this->z * scalar;

	return vecTemp;
}

XVECTOR3 XVECTOR3::operator / (float scalar) const
{
	XVECTOR3 vecTemp;
	vecTemp.x = this->x / scalar;
	vecTemp.y = this->y / scalar;
	vecTemp.z = this->z / scalar;

	return vecTemp;
}


XVECTOR3 XVECTOR3::operator * (const XVECTOR3& referenceVector)
{
	return referenceVector;
}

//
//friend XVECTOR3 operator * (float, const struct XVECTOR3&)
//{
//
//}


bool XVECTOR3::operator == (const XVECTOR3& otherVector) const
{
	if (this->x == otherVector.x && this->y == otherVector.y && this->z == otherVector.z)
	{
		return true;
	}

	return false;
}
bool XVECTOR3::operator != (const XVECTOR3& otherVector) const
{
	if (this->x == otherVector.x && this->y == otherVector.y && this->z == otherVector.z)
	{
		return false;
	}

	return true;
}

void XVecCross(XVECTOR3 & Cross, const XVECTOR3 &FirstV, const XVECTOR3 &SecondV)
{
	Cross.x = ((FirstV.y*SecondV.z) - (FirstV.z*SecondV.y));
	Cross.y = ((FirstV.z*SecondV.x) - (FirstV.x*SecondV.z));
	Cross.z = ((FirstV.x*SecondV.y) - (FirstV.y*SecondV.x));
}

void XVecDot(float & Dot, const XVECTOR3 & FirstV, const XVECTOR3 & SecondV)
{
	Dot = (FirstV.x * SecondV.x) + (FirstV.y * SecondV.y) + (FirstV.z * SecondV.z);
}

void XVECTOR3::Normalize()
{
	float v = sqrt((this->x * this->x) + (this->y * this->y) + (this->z*this->z)); this->x = this->x / v; this->y = this->y / v; this->z = this->z / v;
}
float XVECTOR3::Length()
{
	return sqrt((this->x * this->x) + (this->y * this->y) + (this->z*this->z));
}

///////////////////////////////////////////////////////////

////////Overloading de Matrix

XMATRIX44 &XMATRIX44::operator *= (const XMATRIX44& otherMatrix)
{
	XMATRIX44 placeHolder = *this;

	this->m11 = (placeHolder.m11*otherMatrix.m11) + (placeHolder.m12*otherMatrix.m21) + (placeHolder.m13*otherMatrix.m31) + (placeHolder.m14*otherMatrix.m41);
	this->m12 = (placeHolder.m11*otherMatrix.m12) + (placeHolder.m12*otherMatrix.m22) + (placeHolder.m13*otherMatrix.m32) + (placeHolder.m14*otherMatrix.m42);
	this->m13 = (placeHolder.m11*otherMatrix.m13) + (placeHolder.m12*otherMatrix.m23) + (placeHolder.m13*otherMatrix.m33) + (placeHolder.m14*otherMatrix.m43);
	this->m14 = (placeHolder.m11*otherMatrix.m14) + (placeHolder.m12*otherMatrix.m24) + (placeHolder.m13*otherMatrix.m34) + (placeHolder.m14*otherMatrix.m44);

	this->m21 = (placeHolder.m21*otherMatrix.m11) + (placeHolder.m22*otherMatrix.m21) + (placeHolder.m23*otherMatrix.m31) + (placeHolder.m24*otherMatrix.m41);
	this->m22 = (placeHolder.m21*otherMatrix.m12) + (placeHolder.m22*otherMatrix.m22) + (placeHolder.m23*otherMatrix.m32) + (placeHolder.m24*otherMatrix.m42);
	this->m23 = (placeHolder.m21*otherMatrix.m13) + (placeHolder.m22*otherMatrix.m23) + (placeHolder.m23*otherMatrix.m33) + (placeHolder.m24*otherMatrix.m43);
	this->m24 = (placeHolder.m21*otherMatrix.m14) + (placeHolder.m22*otherMatrix.m24) + (placeHolder.m23*otherMatrix.m34) + (placeHolder.m24*otherMatrix.m44);

	this->m31 = (placeHolder.m31*otherMatrix.m11) + (placeHolder.m32*otherMatrix.m21) + (placeHolder.m33*otherMatrix.m31) + (placeHolder.m34*otherMatrix.m41);
	this->m32 = (placeHolder.m31*otherMatrix.m12) + (placeHolder.m32*otherMatrix.m22) + (placeHolder.m33*otherMatrix.m32) + (placeHolder.m34*otherMatrix.m42);
	this->m33 = (placeHolder.m31*otherMatrix.m13) + (placeHolder.m32*otherMatrix.m23) + (placeHolder.m33*otherMatrix.m33) + (placeHolder.m34*otherMatrix.m43);
	this->m34 = (placeHolder.m31*otherMatrix.m14) + (placeHolder.m32*otherMatrix.m24) + (placeHolder.m33*otherMatrix.m34) + (placeHolder.m34*otherMatrix.m44);

	this->m41 = (placeHolder.m41*otherMatrix.m11) + (placeHolder.m42*otherMatrix.m21) + (placeHolder.m43*otherMatrix.m31) + (placeHolder.m44*otherMatrix.m41);
	this->m42 = (placeHolder.m41*otherMatrix.m12) + (placeHolder.m42*otherMatrix.m22) + (placeHolder.m43*otherMatrix.m32) + (placeHolder.m44*otherMatrix.m42);
	this->m43 = (placeHolder.m41*otherMatrix.m13) + (placeHolder.m42*otherMatrix.m23) + (placeHolder.m43*otherMatrix.m33) + (placeHolder.m44*otherMatrix.m43);
	this->m44 = (placeHolder.m41*otherMatrix.m14) + (placeHolder.m42*otherMatrix.m24) + (placeHolder.m43*otherMatrix.m34) + (placeHolder.m44*otherMatrix.m44);

	return *this;
}

XMATRIX44 &XMATRIX44::operator += (const XMATRIX44& otherMatrix)
{
	XMATRIX44 placeHolder = *this;

	this->m11 = (placeHolder.m11+ otherMatrix.m11);
	this->m12 = (placeHolder.m12+ otherMatrix.m12);
	this->m13 = (placeHolder.m13+ otherMatrix.m13);
	this->m14 = (placeHolder.m14+ otherMatrix.m14);

	this->m21 = (placeHolder.m21+ otherMatrix.m21);
	this->m22 = (placeHolder.m22+ otherMatrix.m22);
	this->m23 = (placeHolder.m23+ otherMatrix.m23);
	this->m24 = (placeHolder.m24+ otherMatrix.m24);

	this->m31 = (placeHolder.m31+ otherMatrix.m31);
	this->m32 = (placeHolder.m32+ otherMatrix.m32);
	this->m33 = (placeHolder.m33+ otherMatrix.m33);
	this->m34 = (placeHolder.m34+ otherMatrix.m34);

	this->m41 = (placeHolder.m41+ otherMatrix.m41);
	this->m42 = (placeHolder.m42+ otherMatrix.m42);
	this->m43 = (placeHolder.m43+ otherMatrix.m43);
	this->m44 = (placeHolder.m44+ otherMatrix.m44);

	return *this;
}
XMATRIX44 &XMATRIX44::operator -= (const XMATRIX44& otherMatrix)
{
	XMATRIX44 placeHolder = *this;


	this->m11 = (placeHolder.m11 - otherMatrix.m11);
	this->m12 = (placeHolder.m12 - otherMatrix.m12);
	this->m13 = (placeHolder.m13 - otherMatrix.m13);
	this->m14 = (placeHolder.m14 - otherMatrix.m14);

	this->m21 = (placeHolder.m21 - otherMatrix.m21);
	this->m22 = (placeHolder.m22 - otherMatrix.m22);
	this->m23 = (placeHolder.m23 - otherMatrix.m23);
	this->m24 = (placeHolder.m24 - otherMatrix.m24);

	this->m31 = (placeHolder.m31 - otherMatrix.m31);
	this->m32 = (placeHolder.m32 - otherMatrix.m32);
	this->m33 = (placeHolder.m33 - otherMatrix.m33);
	this->m34 = (placeHolder.m34 - otherMatrix.m34);

	this->m41 = (placeHolder.m41 - otherMatrix.m41);
	this->m42 = (placeHolder.m42 - otherMatrix.m42);
	this->m43 = (placeHolder.m43 - otherMatrix.m43);
	this->m44 = (placeHolder.m44 - otherMatrix.m44);

	return *this;
}

XMATRIX44 &XMATRIX44::operator*= (float scalar)
{
	XMATRIX44 placeHolder = *this;

	this->m11 = (placeHolder.m11*scalar);
	this->m12 = (placeHolder.m12*scalar);
	this->m13 = (placeHolder.m13*scalar);
	this->m14 = (placeHolder.m14*scalar);

	this->m21 = (placeHolder.m21*scalar);
	this->m22 = (placeHolder.m22*scalar);
	this->m23 = (placeHolder.m23*scalar);
	this->m24 = (placeHolder.m24*scalar);

	this->m31 = (placeHolder.m31*scalar);
	this->m32 = (placeHolder.m32*scalar);
	this->m33 = (placeHolder.m33*scalar);
	this->m34 = (placeHolder.m34*scalar);

	this->m41 = (placeHolder.m41*scalar);
	this->m42 = (placeHolder.m42*scalar);
	this->m43 = (placeHolder.m43*scalar);
	this->m44 = (placeHolder.m44*scalar);

	return *this;
}
XMATRIX44 &XMATRIX44::operator/= (float scalar)
{
	XMATRIX44 placeHolder = *this;

	this->m11 = (placeHolder.m11 / scalar);
	this->m12 = (placeHolder.m12 / scalar);
	this->m13 = (placeHolder.m13 / scalar);
	this->m14 = (placeHolder.m14 / scalar);

	this->m21 = (placeHolder.m21 / scalar);
	this->m22 = (placeHolder.m22 / scalar);
	this->m23 = (placeHolder.m23 / scalar);
	this->m24 = (placeHolder.m24 / scalar);

	this->m31 = (placeHolder.m31 / scalar);
	this->m32 = (placeHolder.m32 / scalar);
	this->m33 = (placeHolder.m33 / scalar);
	this->m34 = (placeHolder.m34 / scalar);

	this->m41 = (placeHolder.m41 / scalar);
	this->m42 = (placeHolder.m42 / scalar);
	this->m43 = (placeHolder.m43 / scalar);
	this->m44 = (placeHolder.m44 / scalar);

	return *this;
}

//XMATRIX44 operator + () const;
//XMATRIX44 operator - () const;
//
//operator float*();
//operator const float* () const;
//

XMATRIX44 XMATRIX44::operator * (const XMATRIX44& otherMatrix) const
{
	//Se que aqui no es necesario el placeHolder, y que puedo usar this. Pero son las 3 de la manana y no quiero modificar todo nuevamente. Por ahora...

	XMATRIX44 placeHolder = *this, newMatrix;

	newMatrix.m11 = (placeHolder.m11*otherMatrix.m11) + (placeHolder.m12*otherMatrix.m21) + (placeHolder.m13*otherMatrix.m31) + (placeHolder.m14*otherMatrix.m41);
	newMatrix.m12 = (placeHolder.m11*otherMatrix.m12) + (placeHolder.m12*otherMatrix.m22) + (placeHolder.m13*otherMatrix.m32) + (placeHolder.m14*otherMatrix.m42);
	newMatrix.m13 = (placeHolder.m11*otherMatrix.m13) + (placeHolder.m12*otherMatrix.m23) + (placeHolder.m13*otherMatrix.m33) + (placeHolder.m14*otherMatrix.m43);
	newMatrix.m14 = (placeHolder.m11*otherMatrix.m14) + (placeHolder.m12*otherMatrix.m24) + (placeHolder.m13*otherMatrix.m34) + (placeHolder.m14*otherMatrix.m44);

	newMatrix.m21 = (placeHolder.m21*otherMatrix.m11) + (placeHolder.m22*otherMatrix.m21) + (placeHolder.m23*otherMatrix.m31) + (placeHolder.m24*otherMatrix.m41);
	newMatrix.m22 = (placeHolder.m21*otherMatrix.m12) + (placeHolder.m22*otherMatrix.m22) + (placeHolder.m23*otherMatrix.m32) + (placeHolder.m24*otherMatrix.m42);
	newMatrix.m23 = (placeHolder.m21*otherMatrix.m13) + (placeHolder.m22*otherMatrix.m23) + (placeHolder.m23*otherMatrix.m33) + (placeHolder.m24*otherMatrix.m43);
	newMatrix.m24 = (placeHolder.m21*otherMatrix.m14) + (placeHolder.m22*otherMatrix.m24) + (placeHolder.m23*otherMatrix.m34) + (placeHolder.m24*otherMatrix.m44);

	newMatrix.m31 = (placeHolder.m31*otherMatrix.m11) + (placeHolder.m32*otherMatrix.m21) + (placeHolder.m33*otherMatrix.m31) + (placeHolder.m34*otherMatrix.m41);
	newMatrix.m32 = (placeHolder.m31*otherMatrix.m12) + (placeHolder.m32*otherMatrix.m22) + (placeHolder.m33*otherMatrix.m32) + (placeHolder.m34*otherMatrix.m42);
	newMatrix.m33 = (placeHolder.m31*otherMatrix.m13) + (placeHolder.m32*otherMatrix.m23) + (placeHolder.m33*otherMatrix.m33) + (placeHolder.m34*otherMatrix.m43);
	newMatrix.m34 = (placeHolder.m31*otherMatrix.m14) + (placeHolder.m32*otherMatrix.m24) + (placeHolder.m33*otherMatrix.m34) + (placeHolder.m34*otherMatrix.m44);

	newMatrix.m41 = (placeHolder.m41*otherMatrix.m11) + (placeHolder.m42*otherMatrix.m21) + (placeHolder.m43*otherMatrix.m31) + (placeHolder.m44*otherMatrix.m41);
	newMatrix.m42 = (placeHolder.m41*otherMatrix.m12) + (placeHolder.m42*otherMatrix.m22) + (placeHolder.m43*otherMatrix.m32) + (placeHolder.m44*otherMatrix.m42);
	newMatrix.m43 = (placeHolder.m41*otherMatrix.m13) + (placeHolder.m42*otherMatrix.m23) + (placeHolder.m43*otherMatrix.m33) + (placeHolder.m44*otherMatrix.m43);
	newMatrix.m44 = (placeHolder.m41*otherMatrix.m14) + (placeHolder.m42*otherMatrix.m24) + (placeHolder.m43*otherMatrix.m34) + (placeHolder.m44*otherMatrix.m44);

	return newMatrix;
}

XMATRIX44 XMATRIX44::operator + (const XMATRIX44& otherMatrix) const
{
	XMATRIX44 placeHolder = *this;

	placeHolder.m11 = (this->m11 + otherMatrix.m11);
	placeHolder.m12 = (this->m12 + otherMatrix.m12);
	placeHolder.m13 = (this->m13 + otherMatrix.m13);
	placeHolder.m14 = (this->m14 + otherMatrix.m14);

	placeHolder.m21 = (this->m21 + otherMatrix.m21);
	placeHolder.m22 = (this->m22 + otherMatrix.m22);
	placeHolder.m23 = (this->m23 + otherMatrix.m23);
	placeHolder.m24 = (this->m24 + otherMatrix.m24);

	placeHolder.m31 = (this->m31 + otherMatrix.m31);
	placeHolder.m32 = (this->m32 + otherMatrix.m32);
	placeHolder.m33 = (this->m33 + otherMatrix.m33);
	placeHolder.m34 = (this->m34 + otherMatrix.m34);

	placeHolder.m41 = (this->m41 + otherMatrix.m41);
	placeHolder.m42 = (this->m42 + otherMatrix.m42);
	placeHolder.m43 = (this->m43 + otherMatrix.m43);
	placeHolder.m44 = (this->m44 + otherMatrix.m44);

	return placeHolder;
}

XMATRIX44 XMATRIX44::operator- (const XMATRIX44& otherMatrix) const
{
	XMATRIX44 placeHolder;

	placeHolder.m11 = (this->m11 - otherMatrix.m11);
	placeHolder.m12 = (this->m12 - otherMatrix.m12);
	placeHolder.m13 = (this->m13 - otherMatrix.m13);
	placeHolder.m14 = (this->m14 - otherMatrix.m14);

	placeHolder.m21 = (this->m21 - otherMatrix.m21);
	placeHolder.m22 = (this->m22 - otherMatrix.m22);
	placeHolder.m23 = (this->m23 - otherMatrix.m23);
	placeHolder.m24 = (this->m24 - otherMatrix.m24);

	placeHolder.m31 = (this->m31 - otherMatrix.m31);
	placeHolder.m32 = (this->m32 - otherMatrix.m32);
	placeHolder.m33 = (this->m33 + otherMatrix.m33);
	placeHolder.m34 = (this->m34 + otherMatrix.m34);

	placeHolder.m41 = (this->m41 + otherMatrix.m41);
	placeHolder.m42 = (this->m42 + otherMatrix.m42);
	placeHolder.m43 = (this->m43 + otherMatrix.m43);
	placeHolder.m44 = (this->m44 + otherMatrix.m44);

	return placeHolder;
}
XMATRIX44 XMATRIX44::operator * (float scalar) const
{
	XMATRIX44 newMatrix;

	newMatrix.m11 = (this->m11*scalar);
	newMatrix.m12 = (this->m12*scalar);
	newMatrix.m13 = (this->m13*scalar);
	newMatrix.m14 = (this->m14*scalar);

	newMatrix.m21 = (this->m21*scalar);
	newMatrix.m22 = (this->m22*scalar);
	newMatrix.m23 = (this->m23*scalar);
	newMatrix.m24 = (this->m24*scalar);

	newMatrix.m31 = (this->m31*scalar);
	newMatrix.m32 = (this->m32*scalar);
	newMatrix.m33 = (this->m33*scalar);
	newMatrix.m34 = (this->m34*scalar);

	newMatrix.m41 = (this->m41*scalar);
	newMatrix.m42 = (this->m42*scalar);
	newMatrix.m43 = (this->m43*scalar);
	newMatrix.m44 = (this->m44*scalar);

	return newMatrix;
}
XMATRIX44 XMATRIX44::operator / (float scalar) const
{
	XMATRIX44 newMatrix;

	newMatrix.m11 = (this->m11 / scalar);
	newMatrix.m12 = (this->m12 / scalar);
	newMatrix.m13 = (this->m13 / scalar);
	newMatrix.m14 = (this->m14 / scalar);

	newMatrix.m21 = (this->m21 / scalar);
	newMatrix.m22 = (this->m22 / scalar);
	newMatrix.m23 = (this->m23 / scalar);
	newMatrix.m24 = (this->m24 / scalar);

	newMatrix.m31 = (this->m31 / scalar);
	newMatrix.m32 = (this->m32 / scalar);
	newMatrix.m33 = (this->m33 / scalar);
	newMatrix.m34 = (this->m34 / scalar);

	newMatrix.m41 = (this->m41 / scalar);
	newMatrix.m42 = (this->m42 / scalar);
	newMatrix.m43 = (this->m43 / scalar);
	newMatrix.m44 = (this->m44 / scalar);

	return newMatrix;
}
//
//friend XMATRIX44 operator * (float, const XMATRIX44&);
//

bool XMATRIX44::operator== (const XMATRIX44& otherMatrix) const
{
	if (otherMatrix.m11 == this->m11 &&
		otherMatrix.m12 == this->m12 &&
		otherMatrix.m13 == this->m13 &&
		otherMatrix.m14 == this->m14 &&

		otherMatrix.m21 == this->m21 &&
		otherMatrix.m22 == this->m22 &&
		otherMatrix.m23 == this->m23 &&
		otherMatrix.m24 == this->m24 &&

		otherMatrix.m31 == this->m31 &&
		otherMatrix.m32 == this->m32 &&
		otherMatrix.m33 == this->m33 &&
		otherMatrix.m34 == this->m34 &&

		otherMatrix.m41 == this->m41  &&
		otherMatrix.m42 == this->m42 &&
		otherMatrix.m43 == this->m43 &&
		otherMatrix.m44 == this->m44)
	{
		return true;
	}
	else
		return false;
}
bool XMATRIX44::operator != (const XMATRIX44& otherMatrix) const
{
	if (otherMatrix.m11 == this->m11 &&
		otherMatrix.m12 == this->m12 &&
		otherMatrix.m13 == this->m13 &&
		otherMatrix.m14 == this->m14 &&

		otherMatrix.m21 == this->m21 &&
		otherMatrix.m22 == this->m22 &&
		otherMatrix.m23 == this->m23 &&
		otherMatrix.m24 == this->m24 &&

		otherMatrix.m31 == this->m31 &&
		otherMatrix.m32 == this->m32 &&
		otherMatrix.m33 == this->m33 &&
		otherMatrix.m34 == this->m34 &&

		otherMatrix.m41 == this->m41  &&
		otherMatrix.m42 == this->m42 &&
		otherMatrix.m43 == this->m43 &&
		otherMatrix.m44 == this->m44)
	{
		return false;
	}
	else
		return true;
}

///////////////////////////////////////////////////////////

///////////////////////// Transformaciones lineales ///////////////

void XMatTranslation(XMATRIX44 &modMatrix, const float &x, const float &y, const float &z)
{
	
	//modMatrix.m11 += x; 
	//modMatrix.m21 += y;
	//modMatrix.m31 += z; 
	////modMatrix.m41 += x;
	//
	//modMatrix.m12 += x; 
	//modMatrix.m22 += y; 
	//modMatrix.m32 += z; 
	////modMatrix.m42 += y;
	//
	//modMatrix.m13 += x; 
	//modMatrix.m23 += y; 
	//modMatrix.m33 += z; 
	////modMatrix.m43 += z;
	//
	//modMatrix.m14 += x;
	//modMatrix.m24 += y;
	//modMatrix.m34 += z;
	////modMatrix.m44 += ;
	modMatrix.m42 += y;
	modMatrix.m43 += z;
}

void XMatTranslation(XMATRIX44& modMatrix, XVECTOR3& trasnlateVec)
{
	
	/*modMatrix.m11 += trasnlateVec.x; 
	modMatrix.m21 += trasnlateVec.y;
	modMatrix.m31 += trasnlateVec.z;
	
	modMatrix.m12 += trasnlateVec.x;
	modMatrix.m22 += trasnlateVec.y;
	modMatrix.m32 += trasnlateVec.z;
	
	modMatrix.m13 += trasnlateVec.x; 
	modMatrix.m23 += trasnlateVec.y;
	modMatrix.m33 += trasnlateVec.z;
	
	modMatrix.m14 += trasnlateVec.x;
	modMatrix.m24 += trasnlateVec.y;
	modMatrix.m34 += trasnlateVec.z;*/

	modMatrix.m42 += trasnlateVec.y;
	modMatrix.m43 += trasnlateVec.z;

}

void XMatScaling(XMATRIX44& modMatrix, const float& x, const float & y , const float & z)
{
	modMatrix.m11*x;
	modMatrix.m21*y;
	modMatrix.m31*z;

	modMatrix.m12*x;
	modMatrix.m22*y;
	modMatrix.m32*z;

	modMatrix.m13*x;
	modMatrix.m23*y;
	modMatrix.m33*z;

	modMatrix.m14*x;
	modMatrix.m24*y;
	modMatrix.m34*z;
}

void XMatRotationXLH(XMATRIX44 &mpout, const float &x) {
	XMATRIX44 pivot = mpout;
	mpout.m21 = pivot.m21*cos(x) + pivot.m31*sin(x);
	mpout.m31 = -pivot.m21*sin(x) + pivot.m31*cos(x);

	mpout.m22 = pivot.m22*cos(x) + pivot.m32*sin(x);
	mpout.m32 = -pivot.m22*sin(x) + pivot.m32*cos(x);

	mpout.m23 = pivot.m23*cos(x) + pivot.m33*sin(x);
	mpout.m33 = -pivot.m23*sin(x) + pivot.m33*cos(x);

	mpout.m24 = pivot.m24*cos(x) + pivot.m34*sin(x);
	mpout.m34 = -pivot.m24*sin(x) + pivot.m34*cos(x);

}
void XMatRotationXRH(XMATRIX44 &mpout, const float &x) {
	XMATRIX44 pivot = mpout;
	mpout.m21 = pivot.m21*cos(x) - pivot.m31*sin(x);
	mpout.m31 = pivot.m21*sin(x) + pivot.m31*cos(x);

	mpout.m22 = pivot.m22*cos(x) - pivot.m32*sin(x);
	mpout.m32 = pivot.m22*sin(x) + pivot.m32*cos(x);

	mpout.m23 = pivot.m23*cos(x) - pivot.m33*sin(x);
	mpout.m33 = pivot.m23*sin(x) + pivot.m33*cos(x);

	mpout.m24 = pivot.m24*cos(x) - pivot.m34*sin(x);
	mpout.m34 = pivot.m24*sin(x) + pivot.m34*cos(x);
}
void XMatRotationYLH(XMATRIX44 &mpout, const float &y) {
	XMATRIX44 pivot = mpout;
	mpout.m11 = pivot.m11*cos(y) - pivot.m31*sin(y);
	mpout.m31 = pivot.m11*sin(y) + pivot.m31*cos(y);

	mpout.m12 = pivot.m12*cos(y) - pivot.m32*sin(y);
	mpout.m32 = pivot.m12*sin(y) + pivot.m32*cos(y);

	mpout.m13 = pivot.m13*cos(y) - pivot.m33*sin(y);
	mpout.m33 = pivot.m13*sin(y) + pivot.m33*cos(y);

	mpout.m14 = pivot.m14*cos(y) - pivot.m34*sin(y);
	mpout.m34 = pivot.m14*sin(y) + pivot.m34*cos(y);
}
void XMatRotationYRH(XMATRIX44 &mpout, const float &y) {
	XMATRIX44 pivot = mpout;
	mpout.m11 = pivot.m11*cos(y) + pivot.m31*sin(y);
	mpout.m31 = -pivot.m11*sin(y) + pivot.m31*cos(y);

	mpout.m12 = pivot.m12*cos(y) + pivot.m32*sin(y);
	mpout.m32 = -pivot.m12*sin(y) + pivot.m32*cos(y);

	mpout.m13 = pivot.m13*cos(y) + pivot.m33*sin(y);
	mpout.m33 = -pivot.m13*sin(y) + pivot.m33*cos(y);

	mpout.m14 = pivot.m14*cos(y) + pivot.m34*sin(y);
	mpout.m34 = -pivot.m14*sin(y) + pivot.m34*cos(y);
}
void XMatRotationZLH(XMATRIX44 &mpout, const float &z) {
	XMATRIX44 pivot = mpout;
	mpout.m11 = pivot.m11*cos(z) + pivot.m21*sin(z);
	mpout.m21 = -pivot.m11*sin(z) + pivot.m21*cos(z);

	mpout.m12 = pivot.m12*cos(z) + pivot.m22*sin(z);
	mpout.m22 = -pivot.m12*sin(z) + pivot.m22*cos(z);

	mpout.m13 = pivot.m13*cos(z) + pivot.m23*sin(z);
	mpout.m23 = -pivot.m13*sin(z) + pivot.m23*cos(z);

	mpout.m14 = pivot.m14*cos(z) + pivot.m24*sin(z);
	mpout.m24 = -pivot.m14*sin(z) + pivot.m24*cos(z);
}
void XMatRotationZRH(XMATRIX44 &mpout, const float &z) {
	XMATRIX44 pivot = mpout;
	mpout.m11 = pivot.m11*cos(z) - pivot.m21*sin(z);
	mpout.m21 = pivot.m11*sin(z) + pivot.m21*cos(z);

	mpout.m12 = pivot.m12*cos(z) - pivot.m22*sin(z);
	mpout.m22 = pivot.m12*sin(z) + pivot.m22*cos(z);

	mpout.m13 = pivot.m13*cos(z) - pivot.m23*sin(z);
	mpout.m23 = pivot.m13*sin(z) + pivot.m23*cos(z);

	mpout.m14 = pivot.m14*cos(z) - pivot.m24*sin(z);
	mpout.m24 = pivot.m14*sin(z) + pivot.m24*cos(z);
}

void XMatTranspose(XMATRIX44 &modMatrix, XMATRIX44 A)
{
	modMatrix = A;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			modMatrix.m[j][i] = A.m[i][j];
		}
	}

}

void XMatIdentity(XMATRIX44 & modMatrix)
{
	modMatrix.m11 = 1;
	modMatrix.m21 = 0;
	modMatrix.m31 = 0;
	modMatrix.m41 = 0;

	modMatrix.m12 = 0;
	modMatrix.m22 = 1;
	modMatrix.m32 = 0;
	modMatrix.m42 = 0;
	
	modMatrix.m13 = 0;
	modMatrix.m23 = 0;
	modMatrix.m33 = 1;
	modMatrix.m43 = 0;

	modMatrix.m14 = 0;
	modMatrix.m24 = 0;
	modMatrix.m34 = 0;
	modMatrix.m44 = 1;
}

void XMatRotationAxisRH(XMATRIX44 &, const XVECTOR3 &, const float &)
{

}

void XMatRotationAxisLH(XMATRIX44 &modMatrix, const XVECTOR3 & vec1, const float & theta)
{

}
void XMatViewLookAtLH(XMATRIX44 &mpout, const XVECTOR3 &camPos, const XVECTOR3 &lookAt, const XVECTOR3 &upAxis) {
	XVECTOR3 zaxe = lookAt - camPos;
	zaxe.Normalize();

	XVECTOR3 xaxe;
	XVecCross(xaxe, upAxis, zaxe);
	xaxe.Normalize();

	XVECTOR3 yaxe;
	XVecCross(yaxe, zaxe, xaxe);

	mpout.m[0][0] = xaxe.x;
	mpout.m[0][1] = yaxe.x;
	mpout.m[0][2] = zaxe.x;
	XVecDot(mpout.m[3][0], xaxe, camPos);
	mpout.m[3][0] = -mpout.m[3][0];

	mpout.m[1][0] = xaxe.y;
	mpout.m[1][1] = yaxe.y;
	mpout.m[1][2] = zaxe.y;
	XVecDot(mpout.m[3][1], yaxe, camPos);
	mpout.m[3][1] = -mpout.m[3][1];

	mpout.m[2][0] = xaxe.z;
	mpout.m[2][1] = yaxe.z;
	mpout.m[2][2] = zaxe.z;
	XVecDot(mpout.m[3][2], zaxe, camPos);
	mpout.m[3][2] = -mpout.m[3][2];

	mpout.m[0][3] = 0.0f;
	mpout.m[1][3] = 0.0f;
	mpout.m[2][3] = 0.0f;
	mpout.m[3][3] = 1.0f;
}

void XMatPerspectiveLH(XMATRIX44 &mpout, const float &FOV, const float &Aspect, const float &NearPlane, const float &FarPlane) {
	float x, y;
	float ang = FOV / 2.0f;

	y = cos(ang) / sin(ang);
	x = y / Aspect;

	mpout.m[0][0] = x;
	mpout.m[1][1] = y;
	mpout.m[2][2] = FarPlane / (FarPlane - NearPlane);
	mpout.m[2][3] = 1.0;
	mpout.m[3][2] = -(NearPlane*FarPlane) / (FarPlane - NearPlane);
	mpout.m[3][3] = 0.0f;

}

void XMatPerspectiveRH(XMATRIX44 &mpout, const float &FOV, const float &Aspect, const float &NearPlane, const float &FarPlane)
{
	float x, y;
	float ang = FOV / 2.0f;

	y = cos(ang) / sin(ang);
	x = y / Aspect;

	mpout.m[0][0] = x;
	mpout.m[1][1] = y;
	mpout.m[2][2] = FarPlane / (NearPlane - FarPlane);
	mpout.m[2][3] = -1.0;
	mpout.m[3][2] = (NearPlane*FarPlane) / (NearPlane - FarPlane);
	mpout.m[3][3] = 0.0f;
}

void XMatOrthoLH(XMATRIX44 &m, const float &w, const float &h, const float &zn, const float &zf) {
	m.m[0][0] = 2.0f / w;
	m.m[1][1] = 2.0f / h;
	m.m[2][2] = 1.0f / (zf - zn);
	m.m[3][2] = -zn / (zf - zn);
	m.m[3][3] = 1.0f;
}

void XMatOrthoRH(XMATRIX44 &m, const float &w, const float &h, const float &zn, const float &zf) {
	m.m[0][0] = 2.0f / w;
	m.m[1][1] = 2.0f / h;
	m.m[2][2] = 1.0f / (zn - zf);
	m.m[3][2] = zn / (zn - zf);
	m.m[3][3] = 1.0f;
}