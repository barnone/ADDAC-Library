/*
 * ADDAC_Adsr
 * Version 0.1 November, 2011
 * Copyright 2011 Andr� Gon�alves
 */

#ifndef ADDAC_Env_h
#define ADDAC_Env_h

#include <StandardCplusplus.h>
#include <vector>


using namespace std;
// <iostream> declares cout/cerr, but the application must define them
// because it's up to you what to do with them.



#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include <WProgram.h>
#endif

#define addacMaxResolution 65535 

//#define DEBUG
//#define DEBUG_env

class ADDAC_Env{
public:
	ADDAC_Env();
	
	void envMode(bool _trigger, bool _inverted, float _A, float _Atime, float _D, float _Dtime, float _S,float _Stime, float _Rtime);
	void envLogExpMode(bool _trigger, bool _inverted, float _A, float _Atime, float _Ashape, float _D, float _Dtime, float _Dshape, float _S, float _Stime, float _Sshape, float _Rtime, float _Rshape);
	void envWeirdMode(bool _trigger, bool _inverted, float _A, float _Atime, float _Ashape, float _D, float _Dtime, float _Dshape);
	
	void AD_trigger(float _A);
	void AD_trigger();
	void AD_release();
	void AD_update(float _Atime, float _Dtime);
	void ENV_update(float _A, float _Atime, float _D, float _Dtime, float _S,float _Stime, float _Rtime);
    
    void MultiEnv(bool _trigger, bool _inverted);
    void MultiEnv(bool _trigger, bool _inverted, bool _loop);
    void PrintMultiEnv();
    void addPoint(float _amp, float _time);
	
	unsigned long ENVtriggerTime;
	int actualStep;
    bool ENVtrigger;
	
    float CVstream;
	unsigned int toAddDif;
	long TipPoint;
	float Attack;
	float floatPercentage, weakLink;
	
	bool SUSTAIN;
    
    vector<float> time;
    vector<float> amplitude;
	
};
#endif
