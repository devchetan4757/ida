#include <windows.h>
#include <string.h>

int main(void)
{
    HANDLE hFile = CreateFileA(
        "C:\\Temp\\practical6_test.txt",
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile != INVALID_HANDLE_VALUE) {
        CloseHandle(hFile);
    }

    HKEY hKey;
    LONG rc = RegCreateKeyExA(
        HKEY_CURRENT_USER,
        "Software\\Practical6Test",
        0,
        NULL,
        0,
        KEY_SET_VALUE,
        NULL,
        &hKey,
        NULL
    );

    if (rc == ERROR_SUCCESS) {
        const char *data = "HelloLab";

        RegSetValueExA(
            hKey,
            "TestValue",
            0,
            REG_SZ,
            (const BYTE *)data,
            (DWORD)strlen(data) + 1
        );

        RegCloseKey(hKey);
    }

    WinExec("notepad.exe", SW_SHOWNORMAL);

    return 0;
}