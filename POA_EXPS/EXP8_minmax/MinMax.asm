DATA SEGMENT
    ARR DB 5,3,7,1,9,2,4
    LEN DW $-ARR
    MIN DB ?
    MAX DB ?
ENDS

CODE SEGMENT
    ASSUME DS:DATA CS:CODE
    START:
        MOV AX,DATA
        MOV DS,AX
    
        LEA SI,ARR           ;Array ka address in SI
        
        MOV AL,ARR[SI]       ;Array[0] ko AL mein and ussi ko MIN and MAX initialise kardo
        MOV MIN,AL
        MOV MAX,AL
    
        MOV CX,LEN           ;Length of array in CX
    
    REPEAT:
        MOV AL,ARR[SI]       ;Every element of array comes in AL ek ek karke to be checked with MAX AND MIN
        CMP MIN,AL           ;Compare current element "i" with current MIN
        JL CHECKMAX          ;If above is true, jump to CHECKMAX (if MIN is "lower" than AL means AL isnt MIN but possibility of being MAX)
        MOV MIN,AL           ;Make AL new MIN(if CHECKMAX is not called , it means that AL is "lower" than MIN)

    CHECKMAX:
        CMP MAX,AL           ;Compare MAX AND AL by (MAX-AL) , if MAX-AL is negative( current value is greater)
        JG DONE              ;if above is true, jump to DONE (if MAX>AL)
        MOV MAX,AL           ;Make AL new Max if DONE is not called
    
    DONE:
        INC SI               ;Increment start index by 1 to check the next element in the array
        LOOP REPEAT          ;call the main loop (LOOP LIKHNA WARNA DEC CX shit karna padega)
    
    MOV AX,4CH               ;Both lines used to end program
    INT 21H                  ;Both lines used to end program
    CODE ENDS
END START
    