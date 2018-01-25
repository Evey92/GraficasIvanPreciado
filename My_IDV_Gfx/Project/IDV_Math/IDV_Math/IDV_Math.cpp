// IDV_Math.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <IDV_Math.h>
#include <iostream>
#include <vector>
#include <cmath>

////////Overloading de vector2
XVECTOR2 &XVECTOR2:: operator+=(const XVECTOR2& other)
{
	this->x = this->x + other.x; this->y = this->y + other.y;

	return *this;
}

XVECTOR2 &XVECTOR2:: operator-=(const XVECTOR2& other)
{
	this->x = this->x - other.x; this->y = this->y - other.y;

	return *this;
}

XVECTOR2 &XVECTOR2:: operator*= (float other)
{
	this->x = this->x * other; this->y = this->y * other;

	return *this;
}

XVECTOR2 &XVECTOR2:: operator/= (float other)
{
	this->x = this->x / other; this->y = this->y / other;

	return *this;
}

XVECTOR2 XVECTOR2:: operator + () const
{

}
XVECTOR2 XVECTOR2:: operator - () const
{

}

XVECTOR2 XVECTOR2:: operator+ (const XVECTOR2& other) const
{
	/*const  = this + other;

	return const;*/
}
XVECTOR2 XVECTOR2:: operator - (const XVECTOR2& other) const
{

}
XVECTOR2 XVECTOR2:: operator * (float other) const
{

}
XVECTOR2 XVECTOR2:: operator / (float other) const
{

}

bool XVECTOR2::operator== (const XVECTOR2&) const
{

}
bool XVECTOR2::operator!= (const XVECTOR2&) const
{

}

void Normalize()
{

}

///////////////////////////////////////////////////////////

////////Overloading de vector3

_XVECTOR3  &XVECTOR3::operator+=(const XVECTOR3& other)
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

friend XVECTOR3 operator * (float, const struct XVECTOR3&);

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
