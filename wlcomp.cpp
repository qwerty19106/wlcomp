#include <windows.h>
#include <objbase.h>
#include <initguid.h>

#include "ioctl.h"
#include "ifc_ldev.h"

#include <cassert>

#include "wlcomp.h"

extern "C" LUnknown* CreateInstance(ULONG Slot);

LDevice* CreateLDevice(unsigned int Slot, unsigned int* err)
{
    LUnknown* pIUnknown = CreateInstance(Slot);// pointer to interface
    if(!pIUnknown) {
        //CallCreateInstance failed
        *err = GetLastError();
        return 0;
    }
    IDaqLDevice* pI;
    HRESULT hr = pIUnknown->QueryInterface(IID_ILDEV,(void**)&pI);
    if(hr != S_OK) {
        //IDaqLDevice failed
        pIUnknown->Release();
        *err = L_ERROR;
        return 0;
    }

    pIUnknown->Release();
    *err = L_SUCCESS;
    return (LDevice*)pI;
}

void ReleaseLDevice(LDevice* hIfc)
{
    assert(hIfc);
    ((IDaqLDevice*)hIfc)->Release();
}

unsigned int PlataTest(LDevice* hIfc)
{
    assert(hIfc);
    return ((IDaqLDevice*)hIfc)->PlataTest();
}

unsigned int OpenLDevice(LDevice* hIfc)
{
    assert(hIfc);
    HANDLE handle = ((IDaqLDevice*)hIfc)->OpenLDevice();
    if (handle == INVALID_HANDLE_VALUE)
    {
        return L_ERROR;
    }
    return L_SUCCESS;
}

unsigned int CloseLDevice(LDevice* hIfc)
{
    assert(hIfc);
    return ((IDaqLDevice*)hIfc)->CloseLDevice();
}

unsigned int InitStartLDevice(LDevice* hIfc)
{
    assert(hIfc);
    return ((IDaqLDevice*)hIfc)->InitStartLDevice();
}

unsigned int StartLDevice(LDevice* hIfc)
{
    assert(hIfc);
    return ((IDaqLDevice*)hIfc)->StartLDevice();
}

unsigned int StopLDevice(LDevice* hIfc)
{
    assert(hIfc);
    return ((IDaqLDevice*)hIfc)->StopLDevice();
}

unsigned int LoadBios(LDevice* hIfc, char* FileName)
{
    assert(hIfc);
    return ((IDaqLDevice*)hIfc)->LoadBios(FileName);
}

unsigned int IoAsync(LDevice* hIfc, WASYNC_PAR* sp)
{
    assert(hIfc);
    return ((IDaqLDevice*)hIfc)->IoAsync(reinterpret_cast<ASYNC_PAR*>(sp));
}

unsigned int GetSlotParam(LDevice* hIfc, SLOT_PAR* slPar)
{
    assert(hIfc);
    return ((IDaqLDevice*)hIfc)->GetSlotParam(slPar);
}

unsigned int EnableCorrection(LDevice* hIfc, unsigned short Enabled)
{
    assert(hIfc);
    return ((IDaqLDevice*)hIfc)->EnableCorrection(Enabled);
}
