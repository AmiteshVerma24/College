AREA program,CODE,READONLY
N RN 1
LOC RN 2
SUM RN 3
EVEN_NUM RN 4
ENTRY
	MOV N, #10
	MOV LOC,#0x40000000
	MOV SUM,#0
	MOV EVEN_NUM,#2
LOOP
	ADD SUM,SUM,EVEN_NUM
	ADD EVEN_NUM,EVEN_NUM,#2
	SUBS N,N,#1
	BNE LOOP
	STR SUM,[LOC]
STOP B STOP
	END