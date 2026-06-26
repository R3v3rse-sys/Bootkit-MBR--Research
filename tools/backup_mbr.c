#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hDrive = CreateFileA("\\\\.\\PhysicalDrive0", GENERIC_READ, 
                                FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (hDrive == INVALID_HANDLE_VALUE) {
        printf("Run as Administrator!\n");
        return 1;
    }

    BYTE mbr[512];
    DWORD bytesRead;
    SetFilePointer(hDrive, 0, NULL, FILE_BEGIN);
    ReadFile(hDrive, mbr, 512, &bytesRead, NULL);
    CloseHandle(hDrive);

    HANDLE hFile = CreateFileA("mbr_backup.bin", GENERIC_WRITE, 0,
                               NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    DWORD bytesWritten;
    WriteFile(hFile, mbr, 512, &bytesWritten, NULL);
    CloseHandle(hFile);

    printf("MBR backup saved to mbr_backup.bin\n");
    return 0;
}
