//
//  Metropolis.cpp
//  Rand_Walk
//
//  Created by xuhao on 14-1-3.
//  Copyright (c) 2014年 xuhao. All rights reserved.
//

#include "metropolis.h"
double randf()
{
	return (double)rand()/(double)RAND_MAX;
}
bool Metropolis::accept(vector2f s1,vector2f s0)
{
	double r;
	if( (r=P(s1)/P(s0) )>=1)
		return 1;
	double es=randf();
	if(es<r)
		return 1;
	return 0;
}
double Metropolis::P(vector2f vel)
{
	return exp(-BETA*Ham(vel));
}
vector2f Metropolis::rand_nextStep(vector2f vel0,double step)
{
	double theta=randf()*M_PI*2;
	vector2f vel1(sin(theta)*step+vel0.x,cos(theta)*step+vel0.y);
	return vel1;
}
double Metropolis::Ham(vector2f vel)
{
	return vel.x*vel.x+vel.y*vel.y;
}
vector2f Metropolis::mk()
{
    vector2f vel1(0,0);
	while(true)
	{
		vel1=rand_nextStep(vel0,STEP);
		if(accept(vel1,vel0))
		{
			vel0=vel1;
			return vel1;
		}
	}
}
