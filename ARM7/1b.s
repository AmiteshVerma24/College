AREA program,CODE,READONLY
ENTRY
	MOV R1,#1
	MOV R2, #5
	MOV R3, #0
LOOP
	BL SQ
	ADD R3,R3,R4
	ADD R1,R1,#1
	SUBS R2,R2,#1
	BNE LOOP
STOP B STOP
SQ
	MUL R4,R1,R1
	MOV PC,LR
	END