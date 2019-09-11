#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;

vector<HWND> okna;

void barel_roll(){
    DEVMODE dm;
    dm.dmSize=sizeof(DEVMODE);
    dm.dmDriverExtra=0;
    for (int i = 3; i > -1; i--){
        EnumDisplaySettings(NULL,ENUM_CURRENT_SETTINGS,&dm);
        DWORD temp=dm.dmPelsHeight;
        dm.dmPelsHeight=dm.dmPelsWidth;
        dm.dmPelsWidth=temp;
        dm.dmDisplayOrientation=i;
        Sleep(800);
        if (ChangeDisplaySettings(&dm,0) != DISP_CHANGE_SUCCESSFUL){
            MessageBox(NULL, "noce se vrtet", "meeee error", MB_OK);
        }
    }
}

BOOL CALLBACK pridobi_okna(HWND hwnd, LPARAM args){
    okna.push_back(hwnd);
}

void spin(){
    EnumWindows(pridobi_okna, NULL);
    for (std::vector<HWND>::iterator i = okna.begin(); i != okna.end(); i++){
        cout << *i << endl;
    }
}

int main(int argc, char *argv[]){
    if (argc == 1){
        while(1){
          barel_roll();
        }
    }
    else if (argc > 1){
        spin();
    }
    return 0;
}
