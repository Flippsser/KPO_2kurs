.586
.MODEL FLAT, STDCALL
includelib kernel32.lib
includelib user32.lib
ExitProcess PROTO : DWORD
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD
.STACK 4096
.CONST
.DATA
OK EQU 0
TEXT_MESSAGE DB "SE_Asm04", 0
HW DD ?
CHAR_ARRAY DB 'yyyyi1', 0
CHAR_ARRAY_LENGTH EQU 6

BOOL_LITERAL DB 0

FULL_MSG DB "Десериализованные данные:", 13, 10
         DB "Массив char: yyyyi1", 13, 10
         DB "Длина массива: 6", 13, 10
         DB "Bool литерал: false", 0
.CODE
main PROC
INVOKE MessageBoxA, 0, OFFSET FULL_MSG, OFFSET TEXT_MESSAGE, OK
push 0
call ExitProcess
main ENDP
END main
