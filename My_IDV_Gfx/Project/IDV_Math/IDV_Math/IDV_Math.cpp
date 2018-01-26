// IDV_Math.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <IDV_Math.h>
#include <iostream>
#include <vector>
#include <cmath>

////////Overloading de vector2
XVECTOR2 &XVECTOR2:: operator+=(const XVECTOR2& otherVector)
{
	this->x = this->x + otherVector.x; this->y = this->y + otherVector.y;

	return *this;
}

XVECTOR2 &XVECTOR2:: operator-=(const XVECTOR2& otherVector)
{
	this->x = this->x - otherVector.x; this->y = this->y - otherVector.y;

	return *this;
}

XVECTOR2 &XVECTOR2:: operator*= (float otherVector)
{
	this->x = this->x * otherVector; this->y = this->y * otherVector;

	return *this;
}

XVECTOR2 &XVECTOR2:: operator/= (float otherVector)
{
	this->x = this->x / otherVector; this->y = this->y / otherVector;

	return *this;
}

XVECTOR2 XVECTOR2:: operator + () const
{

}
XVECTOR2 XVECTOR2:: operator - () const
{

}

XVECTOR2 XVECTOR2:: operator+ (const XVECTOR2& otherVector) const
{
	/*const  = this + other;

	return const;*/
}
XVECTOR2 XVECTOR2:: operator - (const XVECTOR2& otherVector) const
{

}
XVECTOR2 XVECTOR2:: operator * (float otherVector) const
{

}
XVECTOR2 XVECTOR2:: operator / (float otherVector) const
{

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

_XVECTOR3  &XVECTOR3::operator+=(const XVECTOR3& otherVector)
{

	//return *this;
}



_XVECTOR3 XVECTOR3::operator -= (const XVECTOR3& other)
{

}

_XVECTOR3 XVECTOR3::operator *= (float)
{

}

_XVECTOR3 &XVECTOR3::operator /= (float)
{

}

_XVECTOR3 &XVECTOR3::operator + () const
{

}

_XVECTOR3 operator - () const
{

}

_XVECTOR3 &XVECTOR3::operator + (const XVECTOR3& other) const
{

}

_XVECTOR3 XVECTOR3::operator - (const XVECTOR3& other) const
{

}

_XVECTOR3 XVECTOR3 operator * (float) const
{

}

_XVECTOR3 XVECTOR3 operator / (float) const
{

}

_XVECTOR3::operator * (const XVECTOR3&)
{

}

friend XVECTOR3 operator * (float, const struct XVECTOR3&)
{

}

bool XVECTOR3::operator == (const XVECTOR3& other) const
{

}
bool XVECTOR3::operator != (const XVECTOR3& other) const
{

}
///////////////////////////////////////////////////////////

////////Overloading de Matrix

//XMATRIX44& operator *= (const XMATRIX44&);
//XMATRIX44& operator += (const XMATRIX44&);
//XMATRIX44& operator -= (const XMATRIX44&);
//XMATRIX44& operator *= (float);
//XMATRIX44& operator /= (float);
//
//XMATRIX44 operator + () const;
//XMATRIX44 operator - () const;
//
//operator float*();
//operator const float* () const;
//
//XMATRIX44 operator * (const XMATRIX44&) const;
//XMATRIX44 operator + (const XMATRIX44&) const;
//XMATRIX44 operator - (const XMATRIX44&) const;
//XMATRIX44 operator * (float) const;
//XMATRIX44 operator / (float) const;
//
//friend XMATRIX44 operator * (float, const XMATRIX44&);
//
//bool operator == (const XMATRIX44&) const;
//bool operator != (const XMATRIX44&) const;

///////////////////////////////////////////////////////////
