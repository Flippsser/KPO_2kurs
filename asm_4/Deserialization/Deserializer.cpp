#include "stdafx.h"
#include "Deserializer.h"

#define TYPE_BOOL 0x01
#define TYPE_CHAR_ARRAY 0x02
#define MAX_CHAR_ARRAY_LENGTH 10

void Deserializer::Deserialize(char* charArray, bool* boolLiteral, int* arrayLength)
{
    ifstream file(FILENAME, ios::binary);
    if (file.is_open())
    {

        unsigned char type_char, length_char;
        file.read(reinterpret_cast<char*>(&type_char), sizeof(type_char));
        file.read(reinterpret_cast<char*>(&length_char), sizeof(length_char));


        file.read(charArray, length_char);
        charArray[length_char] = '\0'; 
        *arrayLength = length_char;


        unsigned char type_bool, length_bool;
        file.read(reinterpret_cast<char*>(&type_bool), sizeof(type_bool));
        file.read(reinterpret_cast<char*>(&length_bool), sizeof(length_bool));


        file.read(reinterpret_cast<char*>(boolLiteral), sizeof(bool));

        file.close();
        cout << "Данные успешно десериализованы" << endl;
    }
    else
    {
        cout << "Не удалось открыть файл" << endl;
    }
}