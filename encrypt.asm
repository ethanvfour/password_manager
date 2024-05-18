section .text



; rdi will be the string addy

; void function, string will be passed by ref

;This function will take in a string and use the ror implication in assembly to decrypt each byte
;String is passed by ref
global encryptString
encryptString:
    push rbx



    pop rbx
ret
