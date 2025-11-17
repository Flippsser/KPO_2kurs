#pragma once
#define IN_MAX_LEN_TEXT 1024*1024
#define IN_CODE_ENDL '\n'


// таблица проверки входной информации, индекс = код(Windows-1251) символа
// значение IN::F - запрещенный символ,IN::T - разрешенный символ, IN::I - игнорировать(не вводить)Б
// если 0 <= значение < 256 - то вводить данное значение
#define IN_CODE_TABLE {\
/*00*/ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, /* управляющие */\
/*10*/ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, /* управляющие */\
/*20*/ IN::I, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, /* ' ' ! " # ... / */\
\
/*30*/ IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, /* 0 1 2 3 4 5 6 7 8 9 */\
/*40*/ IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::T, IN::F, IN::F, IN::T, IN::T, IN::T, IN::T, IN::F, /* @ A B C D E F G H I J K L M N O */\
/*50*/ IN::F, IN::F, IN::T, IN::T, IN::F, IN::T, IN::F, IN::T, IN::I, IN::T, IN::T, IN::F, IN::T, IN::F, IN::F, IN::F, /* P Q R S T U V W X Y Z [ \ ] ^ _ */\
/*60*/ IN::F, IN::T, IN::F, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, IN::T, /* ` a b c d e f g h i j k l m n o */\
/*70*/ IN::F, IN::F, IN::T, IN::T, IN::T, IN::T, IN::T, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, /* p q r s t u v w x y z { | } ~ <DEL> */\
\
/*80*/ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, /* 128-143 */\
/*90*/ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::I, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, /* 144-159 */\
/*A0*/ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, /* 160-175 */\
/*B0*/ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, /* 176-191 */\
\
/*C0*/ IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::T, IN::T, IN::F, IN::T, IN::T, IN::F, /* А Б В Г Д Е Ж З И Й К Л М Н О */\
/*D0*/ IN::T, IN::F, IN::T, IN::T, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, /* П Р С Т У Ф Х Ц Ч Ш Щ Ъ Ы Ь Э Ю */\
/*E0*/ IN::T, IN::F, IN::T, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::T, IN::T, IN::F, IN::T, IN::T, IN::T, IN::T, /* а б в г д е ж з и й к л м н о */\
/*F0*/ IN::F, IN::T, IN::T, IN::F, IN::T, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F  /* п р с т у ф х ц ч ш щ ъ ы ь э ю я */\
}
namespace In
{
    struct IN
    {
        enum { T = 1024, F = 2048, I = 4096 };
        int size;
        int lines;
        int ignore;
        unsigned char* text;
        int code[256] = IN_CODE_TABLE;
    };
    IN getin(wchar_t infile[]);
};