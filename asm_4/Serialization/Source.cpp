#include "stdafx.h"
#include "Serializer.h"

int main()
{
    setlocale(LC_ALL, "RU");
    Serializer serializer;

    char charArray[50];
    char boolInput[10];
    bool boolLiteral;

    cout << "Введите массив char (макс. 10 символов): ";
    cin.getline(charArray, 50);

    cout << "Введите bool литерал (true/false или 1/0): ";
    cin.getline(boolInput, 10);

    if (strcmp(boolInput, "true") == 0 || strcmp(boolInput, "1") == 0) {
        boolLiteral = true;
    }
    else {
        boolLiteral = false;
    }

    serializer.Serialize(charArray, boolLiteral);

    cout << "Данные сохранены:" << endl;
    cout << "Массив char: \"" << charArray << "\"" << endl;
    cout << "bool литерал: " << (boolLiteral ? "true" : "false") << endl;

    return 0;
}