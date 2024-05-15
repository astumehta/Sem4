DATA SEGMENT
    ARR DB 1,2,3,4,5 
    LEN DW $-ARR 
    AVG DW ? 
ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX
    LEA SI, ARR
    MOV CX, LEN
    MOV AL, 00  ; Initialize AL to 0 
    MOV AH, 00  ; Initialize AH to 0
Adding:
    MOV DL, [SI]  ; Load the element into DL
    ADD AL, DL    ; Add DL (element) to AL (sum)
    INC SI        ; Move to the next element
    LOOP Adding   ; Iterate same way for all elements in array

    MOV CX, LEN
    DIV CL         ; Divide AX by the length of the array to get the average
    MOV AVG, AL    ; Store the average in AVG

    MOV AX, 4CH
    INT 21H
ENDS
END START
