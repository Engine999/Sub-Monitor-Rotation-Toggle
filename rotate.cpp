#include<stdio.h>
#include<windows.h>

int main(){
	DWORD i = 0; 
	int num = 2; //모니터 개수  // num of moniter 
	DISPLAY_DEVICEA	 monitor;
	
	
	//모니터 순회하며 서브모니터 찾기  //// enumerate displays and find the secondary monitor
	for(i=0;i<num;i++){
		memset(&monitor,0,sizeof(monitor));
		monitor.cb = sizeof(monitor);
		EnumDisplayDevices(NULL, i, &monitor, 0);
		
		// 서브모니터 식별  // 
		if( (monitor.StateFlags & DISPLAY_DEVICE_ATTACHED_TO_DESKTOP) &&
            !(monitor.StateFlags & DISPLAY_DEVICE_PRIMARY_DEVICE) ) {
            	//printf("%s",monitor.DeviceName);
				DEVMODEA dm = {0};
				dm.dmSize = sizeof(dm);
				dm.dmFields = DM_DISPLAYORIENTATION | DM_PELSWIDTH | DM_PELSHEIGHT;	
				
				if (!EnumDisplaySettingsExA(monitor.DeviceName,ENUM_CURRENT_SETTINGS, &dm, 0)){
					printf("error");
					return 0;
				}
					
				if(dm.dmDisplayOrientation == DMDO_90) {
					dm.dmDisplayOrientation = DMDO_DEFAULT;
					dm.dmPelsWidth  = 1920;   // 회전 후 폭 //width after rotation
					dm.dmPelsHeight = 1080;   // 회전 후 높이 //height after rotation
				}
				else{
					dm.dmDisplayOrientation = DMDO_90;
					dm.dmPelsWidth  = 1080;   // 회전 후 폭 //width after rotation
					dm.dmPelsHeight = 1920;   // 회전 후 높이 //height after rotation
				}
				
            	LONG r = ChangeDisplaySettingsExA(monitor.DeviceName, &dm, NULL, CDS_TEST, NULL);
				if (r == DISP_CHANGE_SUCCESSFUL) {
    				r = ChangeDisplaySettingsExA(monitor.DeviceName, &dm, NULL,
                                 CDS_UPDATEREGISTRY | CDS_RESET, NULL);
				}		
			}
			
	}
	return 0;
}



