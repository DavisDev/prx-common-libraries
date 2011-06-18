#include <pspsdk.h>
#include <pspkernel.h>
#include <pspctrl.h>
#include <pspctrl_kernel.h>

#include "cmLibMask.h"


PSP_MODULE_INFO("cmLibMask", PSP_MODULE_KERNEL, 0, 0);


int flag = 0;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  maskAllButton
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

bool maskAllButton()
{
	if(flag < 0)flag = 0;
	sceCtrl_driver_7CA723DC(0xFFFF, (flag > 0 ? 1 : 0));
	
	if(flag >0)return true;
	else return false;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  maskAllButtonOn
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int maskAllButtonOn(bool *status)
{
	if(*status != true){
		*status = true;
		flag ++;
		maskAllButton();
		return 0;
	}
	return -1;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  maskAllButtonOff
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int maskAllButtonOff(bool *status)
{
	if(*status == true){
		*status = false;
		flag --;
		maskAllButton();
		return 0;
	}
	return -1;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  maskAllButtonStatus
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

bool maskAllButtonStatus()
{
	if(flag > 0)return true;
	else return false;
}

bool maskAllButtonAgain()
{
	return maskAllButton();
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  maskButtonOn
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int maskButtonOn(int PspCtrlButtons)
{
	sceCtrl_driver_7CA723DC(PspCtrlButtons,1);
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  maskButtonOff
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int maskButtonOff(int PspCtrlButtons)
{
	sceCtrl_driver_7CA723DC(PspCtrlButtons,0);
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  maskButtonStatus
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

bool maskButtonStatus(int PspCtrlButtons)
{
	int status = sceCtrl_driver_5E77BC8A(PspCtrlButtons);
	
	if(status == 1)return true;
	else return false;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  ENTRY POINT
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int module_start(SceSize args, void *argp)
{
	return 0;
}

int module_stop(SceSize args, void *argp)
{
	return 0;
}
