#ifndef __WLCOMP__
#define __WLCOMP__

struct LDevice;

#ifdef __cplusplus
extern "C" {
#endif
    struct LDevice* CreateLDevice(unsigned int Slot, unsigned int* err);
    void ReleaseLDevice(struct LDevice* hIfc);

    unsigned int PlataTest(struct LDevice* hIfc);

    unsigned int OpenLDevice(struct LDevice* hIfc);
    unsigned int CloseLDevice(struct LDevice* hIfc);

    unsigned int InitStartLDevice(struct LDevice* hIfc);
    unsigned int StartLDevice(struct LDevice* hIfc);
    unsigned int StopLDevice(struct LDevice* hIfc);

    unsigned int LoadBios(struct LDevice* hIfc, char *FileName);

    unsigned int IoAsync(struct LDevice* hIfc, WASYNC_PAR* sp);

    unsigned int GetSlotParam(struct LDevice* hIfc, SLOT_PAR* slPar);
    unsigned int EnableCorrection(struct LDevice* hIfc, unsigned short Enabled);
#ifdef __cplusplus
}
#endif

#endif
