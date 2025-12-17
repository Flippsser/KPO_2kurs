#include "AsmGeneration.h"
#include "stdafx.h"
#include <string>

using namespace std;

void AsmGeneration::CreateFile(const char* charArray, bool boolLiteral, int arrayLength, const char* outputFilePath)
{
    ofstream file(outputFilePath);
    if (file.is_open())
    {
        file << ".586" << endl;
        file << ".MODEL FLAT, STDCALL" << endl;
        file << "includelib kernel32.lib" << endl;
        file << "includelib user32.lib" << endl;
        file << "ExitProcess PROTO : DWORD" << endl;
        file << "MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD" << endl;
        file << ".STACK 4096" << endl;
        file << ".CONST" << endl;
        file << ".DATA" << endl;

        file << "OK EQU 0" << endl;
        file << "TEXT_MESSAGE DB \"SE_Asm04\", 0" << endl;
        file << "HW DD ?" << endl;

        file << "CHAR_ARRAY DB '" << charArray << "', 0" << endl;
        file << "CHAR_ARRAY_LENGTH EQU " << arrayLength << endl;
        file << endl;

        file << "BOOL_LITERAL DB " << (boolLiteral ? "1" : "0") << endl;
        file << endl;

        file << "FULL_MSG DB \"Десериализованные данные:\", 13, 10" << endl;
        file << "         DB \"Массив char: " << charArray << "\", 13, 10" << endl;
        file << "         DB \"Длина массива: " << arrayLength << "\", 13, 10" << endl;
        file << "         DB \"Bool литерал: " << (boolLiteral ? "true" : "false") << "\", 0" << endl;

        file << ".CODE" << endl;
        file << "main PROC" << endl;

        file << "INVOKE MessageBoxA, 0, OFFSET FULL_MSG, OFFSET TEXT_MESSAGE, OK" << endl;

        file << "push 0" << endl;
        file << "call ExitProcess" << endl;

        file << "main ENDP" << endl;
        file << "END main" << endl;

        file.close();
        cout << "Ассемблерный файл создан: " << outputFilePath << endl;
    }
    else
    {
        cout << "Не удалось открыть файл для записи" << endl;
    }
}