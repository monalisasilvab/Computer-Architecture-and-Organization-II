.equ CM_PER_GPIO1_CLKCTRL, 0x44e000AC
.equ GPIO1_OE, 0x4804C134
.equ GPIO1_CLEARDATAOUT, 0x4804C190
.equ GPIO1_SETDATAOUT, 0x4804C194
.equ WDT_BASE, 0x44E35000

.global _start
_start:
	MRS r0, cpsr @ mov r0 = cpsr
    	BIC r0, r0, #0x1F
    	ORR r0, r0, #0x13
    	ORR r0, r0, #0xC0
    	MSR CPSR, r0

    	BL .gpio_setup
    	BL .disable_wdt

.main:
    	@ Apaga os quatro LEDs
	LDR r0, =GPIO1_CLEARDATAOUT
    	LDR r1, =(1 << 21 | 1 << 22 | 1 << 23 | 1 << 24)
    	STR r1, [r0]
    	BL .delay

    	@ Acende os quatro LEDs
    	LDR r0, =GPIO1_SETDATAOUT
    	LDR r1, =(1 << 21 | 1 << 22 | 1 << 23 | 1 << 24)
    	STR r1, [r0]
    	BL .delay

    	B .main

.delay:
    	LDR r1, =0xFFFFFF

.wait:
    	SUB r1, r1, #0x01
    	CMP r1, #0
    	BNE .wait
    	BX LR

.gpio_setup:
    	@ Habilita o clock para o GPIO1
    	LDR r0, =CM_PER_GPIO1_CLKCTRL
    	LDR r1, =0x40002
    	STR r1, [r0]

    	@ Configura os pinos GPIO1_21, GPIO1_22, GPIO1_23 e GPIO1_24 como saída
    	LDR r0, =GPIO1_OE
    	LDR r1, [r0]
    	BIC r1, r1, #(1 << 21 | 1 << 22 | 1 << 23 | 1 << 24)
    	STR r1, [r0]
    	BX LR

.disable_wdt:
    	LDR r0, =WDT_BASE
    	LDR r1, =0xAAAA
    	STR r1, [r0, #0x48]
    	LDR r1, =0x5555
    	STR r1, [r0]
    	BX LR

