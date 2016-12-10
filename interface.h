#pragma once
#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#include "unknwn.h"
static const GUID CLSID_Math =
{ 0xeed9d53a, 0xf674, 0x48d3, { 0x8c, 0x38, 0xd8, 0xf0, 0xf7, 0x48, 0x83, 0x5c }};
static const GUID  IID_ISimpleMath = 
{ 0xeed9d53a, 0xf673, 0x48d3, { 0x8c, 0x38, 0xd8, 0xf8, 0xf7, 0x48, 0x8c, 0x5c } };

static const GUID IID_IAdvancedMath  = 
{ 0x1d5978a9, 0xf14, 0x4964, { 0xaa, 0xce, 0xbe, 0x3d, 0xf8, 0x67, 0x6b, 0x87 } };

class ISimpleMath : public IUnknown
{
public:
	virtual  void _stdcall Add(int nOp1,int nOp2,int * pret) = 0;
};

class IAdvancedMath : public IUnknown
{
public:
	virtual void _stdcall Factorial(int nOp1,int *pret) = 0;
	
};
#endif//__INTERFACE_H__
