//
//  main.cpp
//  SaturnsDobbelt
//
//  Created by Anders Launer Bæk on 15/04/15.
//  Copyright (c) 2015 Anders Launer Bæk. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>
#include "nr3.h"
#include "stepper.h"
#include "odeint.h"
#include "stepperbs.h"
#include "stepperstoerm.h"

using namespace std;

const Doub m1   = 9.2e18;
const Doub m2   = 9.2e18;
const Doub M    = 5.68e26;
const Doub g    = 4.98e-10;

struct rhs{
    void operator() (const Doub x, VecDoub &y, VecDoub &dydx){
        dydx[0] = -M*g/(pow(pow(y[0]*y[0]+y[1]*y[1],0.5),3))*y[0] + m2*g/(pow(pow(pow(y[0]-y[2],2)+pow(y[1]-y[3],2),0.5),3))*(y[2]-y[0]);
        dydx[1] = -M*g/(pow(pow(y[0]*y[0]+y[1]*y[1],0.5),3))*y[1] + m2*g/(pow(pow(pow(y[0]-y[2],2)+pow(y[1]-y[3],2),0.5),3))*(y[3]-y[1]);
        dydx[2] = -M*g/(pow(pow(y[2]*y[2]+y[3]*y[3],0.5),3))*y[2] - m1*g/(pow(pow(pow(y[0]-y[2],2)+pow(y[1]-y[3],2),0.5),3))*(y[2]-y[0]);
        dydx[3] = -M*g/(pow(pow(y[2]*y[2]+y[3]*y[3],0.5),3))*y[3] - m1*g/(pow(pow(pow(y[0]-y[2],2)+pow(y[1]-y[3],2),0.5),3))*(y[3]-y[1]);
        dydx[4] = 0 ;
        dydx[5] = 0 ;
        dydx[6] = 0 ;
        dydx[7] = 0 ;
    }
};

int main() {
    // Initialize y start values
    VecDoub y_start(8);
    y_start[0] = 0;
    y_start[1] = 152870;
    y_start[2] = 0;
    y_start[3] = -153130;
    y_start[4] = -1360278.1;
    y_start[5] = 0;
    y_start[6] = 1359122.8;
    y_start[7] = 0;
    
    // Set stepper configurations
    const Doub atol=1.0e-3, rtol=0, h1=0.01, hmin=0.0, x1=0.0, x2=500.0;
    
    Output out(500);
    rhs func;
    
    Odeint<StepperStoerm<rhs> > ode(y_start,x1,x2,atol,rtol,h1,hmin,out,func);
    ode.integrate();
    /* Do what you need whit the output...
    for (int i=0;i<out.count;i++){
        Doub r1 = pow(pow(out.ysave[0][i],2) + pow(out.ysave[1][i],2),0.5)
        Doub r2 = pow(pow(out.ysave[2][i],2) + pow(out.ysave[3][i],2),0.5);
        Doub dTheta = atan2(out.ysave[1][i], out.ysave[0][i]) - atan2(out.ysave[3][i], out.ysave[2][i]);
    }
     */
    return 0;
}
