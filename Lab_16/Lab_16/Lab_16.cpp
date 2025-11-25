#include "FST.h"
#include <tchar.h>
#include <locale.h>
#include <iostream>

int _tmain(int argc, TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");

    // Примеры цепочек, удовлетворяющих регулярному выражению
    char str1[] = "a;b;c;d;e;";
    char str2[] = "a;c;b;d;e;";
    char str3[] = "a;b;c;e;";
    char str4[] = "a;d;c;e;";
    char str5[] = "a;b;b;d;e;";
    char str6[] = "a;c;e;";
    char str7[] = "a;d;e;";

    // Две неудовлетворяющие цепочки
    char str8[] = "a;b;d;";     // нет e;
    char str9[] = "b;c;d;e;";   // нет a;

    char* chains[] = { str1, str2, str3, str4, str5, str6, str7, str8, str9 };

    for (int i = 0; i < sizeof(chains) / sizeof(char*); i++)
    {
        FST::FST fst(chains[i], 6,
            FST::NODE(1, FST::RELATION('a', 1)),   // состояние 0: ждём 'a'
            FST::NODE(1, FST::RELATION(';', 2)),   // состояние 1: ждём ';'
            FST::NODE(4, FST::RELATION('b', 3), FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('e', 4)), // состояние 2: ждём b/c/d/e
            FST::NODE(1, FST::RELATION(';', 2)),   // состояние 3: ждём ';' и возвращаемся в состояние 2
            FST::NODE(1, FST::RELATION(';', 5)),   // состояние 4: ждём ';' после 'e'
            FST::NODE()                            // состояние 5: конечное
        );

        bool result = FST::execute(fst);
        std::cout << "Цепочка " << fst.string << " результат выполнения: " << result << std::endl;

        if (result)
            std::cout << "Цепочка " << fst.string << " распознана\n" << std::endl;
        else
            std::cout << "Цепочка " << fst.string << " не распознана\n" << std::endl;
    }
    return 0;
}

//a;(□)*( (b+c+d); )+□*e;
