#include "interface.h"
#include <iostream.h>
#include <comutil.h>
#include "windows.h"


int main(int argc,char * argv[])
{
	IUnknown * pUnknown;
	ISimpleMath *pS = NULL;
	IAdvancedMath * pA = NULL;
	HRESULT hResult = 0;


	if(CoInitialize(NULL)!= S_OK)
	{
		cout<<"Initialize COM library failed!"<<endl;
		return -1;
	}

	hResult = CoCreateInstance(CLSID_Math,NULL,CLSCTX_INPROC_SERVER,IID_IUnknown,(void * * )&pUnknown);
	if(hResult != S_OK)
	{
		cout<<"Create object failed!"<<endl;
		return -2;
	}


	hResult = pUnknown ->QueryInterface(IID_ISimpleMath,(void * * )&pS);
	if(hResult != S_OK)
	{
		cout<<"QueryInterface ISimpleMath failed!"<<endl;
	}
	cout<<"Client::Succeeded getting ISimpleMath."<<endl;
	int kk;
	pS ->Add(2,3,&kk);
	pS ->Release();
	cout<<"Client::Get another IAdvancedMath"<<endl;

	hResult= pUnknown ->QueryInterface(IID_IAdvancedMath,(void * * )&pA);
	if(SUCCEEDED(hResult))
	{
		cout<<"Succeeded getting IAdvancedMath."<<endl;
		int mm;
		pA ->Factorial(5,&mm);
		pA ->Release();
	}
	cout<<"Client: Release intface IUnknown"<<endl;
	pUnknown ->Release();
	CoUninitialize();  // Õ∑≈COMø‚
	return 0;
}
