#include "stdafx.h"
#include "AsmGeneration.h"
#include "Deserializer.h"

int main()
{
    setlocale(LC_ALL, "RU");

    char charArray[11];
    bool boolLiteral;
    int arrayLength;

    Deserializer deserializer;
    deserializer.Deserialize(charArray, &boolLiteral, &arrayLength);

    cout << "Десериализованные данные:" << endl;
    cout << "Массив char: \"" << charArray << "\"" << endl;
    cout << "Длина массива: " << arrayLength << endl;
    cout << "bool литерал: " << (boolLiteral ? "true" : "false") << endl;

    AsmGeneration AG;
    const char* asmFilePath = "../SE_Asm04/asmFile.asm";
    AG.CreateFile(charArray, boolLiteral, arrayLength, asmFilePath);

    system("pause");
    return 0;
}