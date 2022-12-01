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
. LINE 5: begin
. subroutine body, nesting level 1
SUB0		
	. local variable "i" at [X + 0]
	. local variable "j" at [X + 3]
	LDA	#9
	SUBR	A,X
	STL	6,X
	STX	DISP1	. initial stack frame
. LINE 6: fori:=10to20doj:=j+10
	. For statment
. LINE 6: i:=10
	LDA	#10
	STA	0,X	. A -> i
	LDA	#20
	LDT	0,X	. i -> T
L1	COMPR	A,T	. test if value is less than
	JLT	L2
. LINE 6: j:=j+10
	LDA	#10
	RMO	A,B
	LDA	3,X	. j -> A
	ADDR	B,A
	STA	3,X	. A -> j
	. incrementing / decrementing
	LDT	0,X	. i -> T
	LDS	#1	. load 1 into register
	ADDR	S,T	. Increment
	STT	0,X	. A -> i
	LDA	#20
	J	L1	. Retest condition
L2			. end of for loop
	. End of for statment
	RMO	A,A
END0		
	LDL	6,X
	LDB	#9	. release stack frame
	ADDR	B,X
	RSUB	
