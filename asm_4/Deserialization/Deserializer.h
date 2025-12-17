#pragma once
class Deserializer
{
public:
    void Deserialize(char* charArray, bool* boolLiteral, int* arrayLength);
private:
    const char* FILENAME = "../Serialization/data.bin";
};