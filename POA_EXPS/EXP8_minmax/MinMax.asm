DATA SEGMENT
    N1 DB 34H, 26H, 99H
DATA ENDS

CODE SEGMENT
    START:
    
    MOV AX,DATA
    MOV DS,AX
    LEA SI,N1
    MOV CL,03H
    
    MOV AL,[SI]
    L1:
        MOV BL,[SI+1]
        CMP AL,BL
        JC L2
        MOV AL,BL
    L2:
        INC SI
        DEC CL
        JNZ L1

    
CODE ENDS
END START