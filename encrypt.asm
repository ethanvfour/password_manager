section .text



; rdi will be the string addy

; void function, string will be passed by ref

;This function will take in a string and use the ror implication in assembly to decrypt each byte
;String is passed by ref

;just do 4
global encryptString
encryptString:
    push rbx
    push r12
    
        mov r12, 0 ; counter
        goingThroughString:

    pop r12
    pop rbx
ret



; rdi will be the string addy

; void function, string will be passed by ref

;This function will take in a string and use the rol implication in assembly to decrypt each byte
;String is passed by ref

;just do 4
global decryptString
decryptString:
    push rbx

        

    pop rbx
ret

