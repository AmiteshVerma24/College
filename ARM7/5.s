AREA PGM,CODE,READONLY
DIVIDEND RN 1
DIVISOR RN 2
QUOTIENT RN 3
REMAINDER RN 4
SUM RN 5
ENTRY
	MOV DIVISOR,#10
	LDR DIVIDEND,=2345
	MOV SUM,#0
LOOP
	BL DIV
	ADD SUM,SUM,REMAINDER
	CMP QUOTIENT,#0
	MOVNE DIVIDEND,QUOTIENT
	BNE LOOP
STOP B STOP
DIV
	MOV QUOTIENT,#0
REM
	SUBS DIVIDEND,DIVIDEND,DIVISOR
	ADDPL QUOTIENT,QUOTIENT,#1
	BPL REM
	ADDMI REMAINDER,DIVISOR,DIVIDEND
	MOV PC,LR
	END