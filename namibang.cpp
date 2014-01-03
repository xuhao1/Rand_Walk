//
//  namibang.cpp
//  Rand_Walk
//
//  Created by xuhao on 14-1-3.
//  Copyright (c) 2014年 xuhao. All rights reserved.
//

#include "namibang.h"
#include "metropolis.h"
#include <sys/time.h>
//由于布朗运动的速度量级远小于分子热运动，所以由于布朗运动速度带来的各种效应可以一并忽略，本文件主要涉及模拟一维刚体在二维情况下的布朗运动。
//对于运动分子的速度抽样，我们采用后面说到的
//我们认为纳米棒质量为分子的1000000,设分子质量为1，其长度1微米（聚合钻石纳米棒），那么其转动惯量为(10^-12)/12
//
//实际数量可能远超过这个值。为了减少运算量方便估计.
//随机打到纳米棒任意位置，发生完全弹性碰撞.
Metropolis water(100);
long getCurrentTime()
{
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return tv.tv_sec * 1000000 + tv.tv_usec;
}
#define maxloop 10000000000
void collision(vector2f & vel,double&omega,double theta)
{
    double alpha=randf();
    double beta=randf()*M_PI;
    double v=water.mk().abs();
    omega+=12*(alpha-0.5)*v*beta/1000;
    vel+=v*cos(beta)/1000000*vector2f(cos(theta),sin(theta));
}
int work()
{
    FILE *fpvel=fopen("velbool.txt","w");
    FILE *fploc=fopen("locbool.txt","w");
    FILE *fpomega=fopen("omegabool.txt","w");
    FILE *fptheta=fopen("thetabool.txt","w");
    vector2f vel(0,0),loc(0,0);
    double theta=0;
	double omega=0;
	double dt=1e-17;
    long st=getCurrentTime();
    long ed=0;
    double proc=0,lasttime=0;
    for (long i=0; i<maxloop; i++)
    {
        
        theta+=omega*dt;
        loc+=vel*dt;
        collision(vel,omega,theta);
        if(i%100000==0)
        {
            ed=getCurrentTime();
            proc=((double)i)/maxloop;
            lasttime=(ed-st)/proc/1000000;
            printf("proc :%% %f lasttime:%f vel :%6.5f %6.5f loc :%e %e theta:%e omega:%f\n",proc,lasttime,vel.x,vel.y,loc.x,loc.y,theta,omega);
            fprintf(fpvel, "%f %f\n",vel.x,vel.y);
            fprintf(fploc, "%e %e\n",loc.x,loc.y);
            fprintf(fpomega, "%f\n",omega);
            fprintf(fptheta, "%e\n",theta);
        }
        
    }
    printf("%f",vel.abs());
    return 1;
}
