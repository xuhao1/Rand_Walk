//
//  Metropolis.h
//  Rand_Walk
//
//  Created by xuhao on 14-1-3.
//  Copyright (c) 2014年 xuhao. All rights reserved.
//

#ifndef __Rand_Walk__Metropolis__
#define __Rand_Walk__Metropolis__
#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include "vector2f.h"
class Metropolis
{
	double BETA,STEP;
	vector2f vel0;
public:
	Metropolis(double v2):
		BETA(1/v2),STEP(0.2*sqrt(v2)),vel0(sqrt(v2),sqrt(v2))
	{
		srand(time(NULL));
		vector2f vel1(0,0);
		for(long i=0;i<100000;i++)
		{
			vel1=rand_nextStep(vel0,STEP);
			if(accept(vel1,vel0))
			{
				vel0=vel1;
			}
		}
	}
	vector2f mk();
	private:
	bool accept(vector2f s1,vector2f s0);
	double P(vector2f vel);
	double Ham(vector2f vel);
	vector2f rand_nextStep(vector2f vel0,double step);
};
double randf();
#endif /* defined(__Rand_Walk__Metropolis__) */
