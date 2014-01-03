//
//  vector2f.cpp
//  Rand_Walk
//
//  Created by xuhao on 13-12-16.
//  Copyright (c) 2013年 xuhao. All rights reserved.
//

#include "vector2f.h"
vector2f operator +(vector2f a,vector2f b)
{
	vector2f res(a.x+b.x,a.y+b.y);
	return res;
}
vector2f operator -(vector2f a,vector2f b)
{
	vector2f res(a.x-b.x,a.y-b.y);
	return res;
}
double operator *(vector2f a,vector2f b)//dot
{
	double res=a.x*b.x+a.y*b.y;
	return res;
}

vector2f operator *(vector2f a,double b)//times
{
	vector2f res(a.x*b,a.y*b);
	return res;
}
vector2f operator *(double b,vector2f a)//times
{
	vector2f res(a.x*b,a.y*b);
	return res;
}
vector2f operator/(vector2f a,double b)//div
{
	vector2f res(a.x/b,a.y/b);
	return res;
}
double operator %(vector2f a,vector2f b)//cross
{
	double res=a.x*b.y-a.y*b.x;
	return res;
}
vector2f& vector2f::operator=(const vector2f&a)
{
	x=a.x;
	y=a.y;
	return *this;
}

vector2f& vector2f::operator+=(const vector2f&a)
{
	x+=a.x;
	y+=a.y;
	return *this;
}