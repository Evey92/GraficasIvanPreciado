// IDV_Math.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <IDV_Math.h>
#include <iostream>
#include <vector>
#include <cmath>

XVECTOR2 &XVECTOR2:: operator+=(const XVECTOR2& other)
{
	this->x = this->x + other.x; this->y = this->y + other.y;

	return *this;
}

XVECTOR2 &XVECTOR2:: operator-=(const XVECTOR2& other)
{

}

XVECTOR2 &XVECTOR2:: operator*= (float other)
{

}

XVECTOR2 &XVECTOR2:: operator/= (float other)
{

}

XVECTOR2 XVECTOR2:: operator + () const
{

}
XVECTOR2 XVECTOR2:: operator - () const
{

}

XVECTOR2 XVECTOR2:: operator+ (const XVECTOR2& other) const
{

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


