

DATA SEGMENT
    N1 DB 45H,78H,98H,89H,66H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    MOV CH,04H

    L1:
        LEA SI,N1
        MOV CL, 04H

        L2:
            MOV AL,[SI]
            MOV BL,[SI+1]
            CMP AL,BL
            JNC JUMP
            MOV DL,[SI+1]
            XCHG [SI],DL
            MOV [SI+1],DL
    
    JUMP:
    INC SI
    DEC CL
    JNZ L2
    DEC CH
    JNZ L1    
CODE ENDS    
END START

ret




