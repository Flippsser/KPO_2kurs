.386
.model flat, stdcall
.stack 4096

includelib kernel32.lib
includelib user32.lib
ExitProcess PROTO, dwExitCode:DWORD

.data
myBytes    BYTE    10h, 20h, 30h, 40h
myWords    WORD    8Ah, 38h, 44h, 5Fh, 99h
myDoubles  DWORD   1, 2, 3, 4, 5, 6
myPointer  DWORD   myDoubles

myArray    DWORD   15, 8, 1, 25, 12, 7, 30
arraySize  DWORD   7

.code
main PROC

    mov ESI, 0
    mov EAX, myDoubles[ESI]
    mov EDX, [myDoubles + ESI]

    mov EAX, 0
    mov ECX, arraySize
    mov ESI, 0

calculate_sum:
    add EAX, myArray[ESI*4]
    inc ESI
    loop calculate_sum

    mov EBX, 1
    mov ECX, arraySize
    mov ESI, 0

check_for_zero:
    cmp myArray[ESI*4], 0
    je zero_detected
    inc ESI
    loop check_for_zero
    jmp check_complete

zero_detected:
    mov EBX, 0

check_complete:
    INVOKE ExitProcess, 0
main ENDP
END main
