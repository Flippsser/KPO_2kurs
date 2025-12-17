#include "stdafx.h"
#include "Serializer.h"

#define TYPE_BOOL 0x01
#define TYPE_CHAR_ARRAY 0x02
#define MAX_CHAR_ARRAY_LENGTH 10

void Serializer::Serialize(const char* charArray, bool boolLiteral)
{
    ofstream file(FILENAME, ios::binary);
    if (file.is_open())
    {

        unsigned char type_char = TYPE_CHAR_ARRAY;
        unsigned char length_char = strlen(charArray);

        if (length_char > MAX_CHAR_ARRAY_LENGTH) {
            length_char = MAX_CHAR_ARRAY_LENGTH;
        }

        file.write(reinterpret_cast<const char*>(&type_char), sizeof(type_char));
        file.write(reinterpret_cast<const char*>(&length_char), sizeof(length_char));
        file.write(charArray, length_char);

        unsigned char type_bool = TYPE_BOOL;
        unsigned char length_bool = sizeof(bool);

        file.write(reinterpret_cast<const char*>(&type_bool), sizeof(type_bool));
        file.write(reinterpret_cast<const char*>(&length_bool), sizeof(length_bool));
        file.write(reinterpret_cast<const char*>(&boolLiteral), sizeof(boolLiteral));

        file.close();
        cout << "Данные успешно сериализованы" << endl;
    }
    else
    {
        cout << "Не удалось открыть файл" << endl;
    }
}