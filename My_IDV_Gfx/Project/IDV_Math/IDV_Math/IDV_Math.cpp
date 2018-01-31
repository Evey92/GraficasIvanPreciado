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

//_XVECTOR3::operator * (const XVECTOR3&)
//{
//
//}
//
//friend XVECTOR3 operator * (float, const struct XVECTOR3&)
//{
//
//}
//
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

//void Normalize()
//{
//
//}

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

//XMATRIX44& operator += (const XMATRIX44&);
//XMATRIX44& operator -= (const XMATRIX44&);

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

//XMATRIX44 operator + (const XMATRIX44&) const;
//XMATRIX44 operator - (const XMATRIX44&) const;

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