main	START	3072
	LDX	#3072	. initial stack pointer
	JSUB	SUB0	. jump to the program's entry point
STOP	J	STOP	. stop execution here
DISP1	WORD	0	. stack frame pointers for 1..n nesting levels
DISP2	WORD	0	. stack frame pointers for 1..n nesting levels
DISP3	WORD	0	. stack frame pointers for 1..n nesting levels
ZERO	WORD	0	. zero constant to compare with
outdev	BYTE	5	. output device number
pstr	LDCH	0,X	. A = character to output
	COMP	#0	. check for null character
	JGT	pstr1	. if not null go to print the character
	RSUB		. If null all done printing
pstr1	TD	outdev	. test to see if output device is ready
	JEQ	pstr1	. device not ready
	WD	outdev	. output A register to output device
	TIX	1	. increment X to point to next character
	J	pstr	. loop
newline	WORD	10	. NEWLINE constant
	.  
. LINE 4: begin
. subroutine body, nesting level 1
SUB0		
	. local variable "i" at [X + 0]
	. local variable "j" at [X + 3]
	LDA	#9
	SUBR	A,X
	STL	6,X
	STX	DISP1	. initial stack frame
. LINE 5: j:=5
	LDA	#5
	STA	3,X	. A -> j
. LINE 6: i:=0
	LDA	#0
	STA	0,X	. A -> i
	. start of while loop
W1		
	LDA	0,X	. i -> A
	RMO	A,B
	LDA	#10
	COMPR	B,A	. comparing simp expression 1 to simp expression 2
	JLT	E2	. it is less than
	LDA	#0	. FALSE
	J	E3	. end of expression check
E2	LDA	#1	. TRUE
E3	RMO	A,A	. end
	COMP	ZERO	. test if value is false
	JEQ	W4	. jump to end
. LINE 9: j:=j+10
	LDA	#10
	RMO	A,B
	LDA	3,X	. j -> A
	ADDR	B,A
	STA	3,X	. A -> j
. LINE 10: i:=i+1
	LDA	#1
	RMO	A,B
	LDA	0,X	. i -> A
	ADDR	B,A
	STA	0,X	. A -> i
	J	W1	. jump to start
W4			. end of loop
	RMO	A,A
END0		
	LDL	6,X
	LDB	#9	. release stack frame
	ADDR	B,X
	RSUB	
