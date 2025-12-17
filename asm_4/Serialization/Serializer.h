#pragma once
class Serializer
{
public:
    void Serialize(const char* charArray, bool boolLiteral);
private:
    const char* FILENAME = "data.bin";
};