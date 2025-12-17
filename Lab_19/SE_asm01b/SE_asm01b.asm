.586P
.MODEL FLAT, STDCALL

includelib ucrt.lib
includelib kernel32.lib
includelib "..\Debug\SE_asm01a.lib"

ExitProcess         PROTO : DWORD
system              PROTO C : DWORD
GetStdHandle        PROTO : DWORD
WriteConsoleA       PROTO : DWORD, : DWORD, : DWORD, : DWORD, : DWORD
SetConsoleTitleA    PROTO : DWORD
SetConsoleOutputCP  PROTO : DWORD
SetConsoleCP        PROTO : DWORD

printConsole        PROTO : DWORD, : DWORD
getmin              PROTO : DWORD, : DWORD
getmax              PROTO : DWORD, : DWORD

.STACK 4096

.CONST
endl        equ 0Ah
str_endl    BYTE endl, 0
str_pause   BYTE "pause", 0

.DATA
Array           SDWORD -5, 5, 23, -1, 25, 8, -4, 22, 9, 0
consoleTitle    BYTE "Задание 3", 0

text            BYTE "Задача : getmax + getmin = ", 0
string          BYTE 40 dup(0)

min_string      BYTE "Минимальное значение = ", 0
min_str         BYTE 40 dup(0)

max_string      BYTE "Максимальное значение = ", 0
max_str         BYTE 40 dup(0)

min             SDWORD ?
max             SDWORD ?
result          SDWORD ?

.CODE

int_to_char PROC uses eax ebx ecx edi esi,
    pstr : DWORD,
    intfield : SDWORD

    mov edi, pstr
    mov eax, intfield
    xor esi, esi
    mov ebx, 10

    test eax, eax
    jge skip_neg
    mov BYTE PTR [edi], '-'
    inc edi
    neg eax
skip_neg:

convert_loop:
    xor edx, edx
    div ebx
    push dx
    inc esi
    test eax, eax
    jnz convert_loop

write_loop:
    pop dx
    add dl, '0'
    mov [edi], dl
    inc edi
    dec esi
    jnz write_loop

    mov BYTE PTR [edi], 0
    ret
int_to_char ENDP

main PROC

    INVOKE SetConsoleOutputCP, 1251
    INVOKE SetConsoleCP, 1251

  
    INVOKE getmin, OFFSET Array, LENGTHOF Array
    mov min, eax
    INVOKE int_to_char, OFFSET min_str, min
    INVOKE printConsole, OFFSET min_string, OFFSET consoleTitle
    INVOKE printConsole, OFFSET min_str, OFFSET consoleTitle
    INVOKE printConsole, OFFSET str_endl, OFFSET consoleTitle

   
    INVOKE getmax, OFFSET Array, LENGTHOF Array
    mov max, eax
    INVOKE int_to_char, OFFSET max_str, max
    INVOKE printConsole, OFFSET max_string, OFFSET consoleTitle
    INVOKE printConsole, OFFSET max_str, OFFSET consoleTitle
    INVOKE printConsole, OFFSET str_endl, OFFSET consoleTitle

   
    mov eax, max
    add eax, min
    mov result, eax

    INVOKE int_to_char, OFFSET string, result
    INVOKE printConsole, OFFSET text, OFFSET consoleTitle
    INVOKE printConsole, OFFSET string, OFFSET consoleTitle
    INVOKE printConsole, OFFSET str_endl, OFFSET consoleTitle

    push OFFSET str_pause
    call system

    push 0
    call ExitProcess

main ENDP



printConsole PROC uses eax ebx ecx edi esi,
    pstr : DWORD,
    ptitle : DWORD

    INVOKE SetConsoleTitleA, ptitle
    INVOKE GetStdHandle, -11

    mov esi, pstr
    mov edi, -1
count:
    inc edi
    cmp BYTE PTR [esi+edi], 0
    jne count

    INVOKE WriteConsoleA, eax, pstr, edi, 0, 0
    ret
printConsole ENDP

END main
