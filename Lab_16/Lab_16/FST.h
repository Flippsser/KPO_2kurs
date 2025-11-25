#pragma once
#include <cstddef>

namespace FST
{
    struct RELATION
    {
        char symbol;  // символ перехода
        short nnode;  // номер смежной вершины
        RELATION(
            char c = 0x00,    // символ перехода
            short ns = NULL   // новое состояние
        );
    };

    struct NODE
    {
        short n_relation;      // количество ребер
        RELATION* relations;   // инцидентные ребра
        NODE();
        NODE(
            short n,           // количество инцидентных ребер
            RELATION rel, ...  // список ребер
        );
    };

    struct FST
    {
        char* string;
        short position;
        short nstates;    // количество состояний автомата
        NODE* nodes;      // граф переходов: [0] - начальное состояние, [nstate - 1] - конечное
        short* rstates;   // возможные состояния автомата на данной позиции
        FST(
            char* s,       // цепочка
            short ns,      // количество состояний автомата
            NODE n, ...    // список состояний (граф переходов)
        );
    };

    bool execute(FST& fst);
}
