.equ CM_PER_GPIO1_CLKCTRL, 0X44E000AC
.equ GPIO1_OE, 0x4804C134
.equ GPIO1_CLEARDATAOUT, 0X4804C190
.equ GPIO1_SETDATAOUT, 0X4804C194
.equ GPIO1_DATAIN, 0x4804C138
.equ WDT_BASE, 0X44E35000

.global _start

_start:
    ldr sp, =0x80001000         
    mrs r0, cpsr                
    bic r0, r0, #0x1F           
    orr r0, r0, #0x13           
    msr cpsr, r0                

    bl .gpio_setup
    bl .disable_wdt

.main:
    mov r7, #0			

.piscar_internos:
    bl .checar_botao2
    cmp r8, #1
    beq .mudar_para_externos_binario

    bl .checar_botao1
    cmp r6, #1
    beq .piscar_externos

    // Liga os 4 LEDs internos
    ldr r0, = GPIO1_SETDATAOUT
    ldr r1, = ((1 << 21) | (1 << 22) | (1 << 23) | (1 << 24))
    str r1, [r0]
    bl .delay

    // Desliga os 4 LEDs internos
    ldr r0, = GPIO1_CLEARDATAOUT
    ldr r1, = ((1 << 21) | (1 << 22) | (1 << 23) | (1 << 24))
    str r1, [r0]
    bl .delay

    b .piscar_internos

.piscar_externos:
    bl .checar_botao2
    cmp r8, #1
    beq .mudar_para_externos_binario

    // Liga os 4 LEDs externos
    ldr r0, = GPIO1_SETDATAOUT
    ldr r1, = ((1 << 28) | (1 << 16) | (1 << 17) | (1 << 13))
    str r1, [r0]
    bl .delay

    // Desliga os 4 LEDs externos
    ldr r0, = GPIO1_CLEARDATAOUT
    ldr r1, = ((1 << 28) | (1 << 16) | (1 << 17) | (1 << 13))
    str r1, [r0]
    bl .delay

    b .piscar_externos

.mudar_para_externos_binario:
    mov r7, #0
    b .externos_binario

.externos_binario:
    // Verifica botão 1 para voltar aos LEDs externos piscando
    bl .checar_botao1
    cmp r6, #1
    beq .piscar_externos

    // Configura LEDs externos para mostrar contagem binária
    ldr r0, = GPIO1_SETDATAOUT
    mov r1, r7                   
    and r2, r1, #0x0F            
    mov r1, #0                   
    
    tst r2, #1                  
    orrne r1, r1, #(1 << 28)     
    tst r2, #2                   
    orrne r1, r1, #(1 << 16)     
    tst r2, #4                  
    orrne r1, r1, #(1 << 17)     
    tst r2, #8                   
    orrne r1, r1, #(1 << 13)     
    
    str r1, [r0]                 
    bl .delay

    // Desliga LEDs externos
    ldr r0, = GPIO1_CLEARDATAOUT
    ldr r1, = ((1 << 28) | (1 << 16) | (1 << 17) | (1 << 13))
    str r1, [r0]                 
    bl .delay
    
    add r7, r7, #1               
    cmp r7, #16                  
    bge .reset_binario           

    b .externos_binario

.reset_binario:
    mov r7, #0
    b .externos_binario

.checar_botao1:
    ldr r0, = GPIO1_DATAIN
    ldr r1, [r0]                
    and r0, r1, #(1 << 12)      
    cmp r0, #0                  
    moveq r6, #0                
    movne r6, #1                
    bx lr    
    
.checar_botao2:
    ldr r0, = GPIO1_DATAIN
    ldr r1, [r0]                
    and r0, r1, #(1 << 15)      
    cmp r0, #0                  
    moveq r8, #0                
    movne r8, #1                
    bx lr  

.delay:
    ldr r1, = 0xfffffff
.wait: 
    sub r1, r1, #0x01
    cmp r1, #0
    bne .wait
    bx lr

.gpio_setup:
    ldr r0, = CM_PER_GPIO1_CLKCTRL
    ldr r1, = 0x40002
    str r1, [r0]

	//leds externos:
    ldr r0, = GPIO1_OE
    ldr r1, [r0]
    bic r1, r1, #(1 << 28)
    str r1, [r0]
    
    ldr r2, [r0]
    bic r2, r2, #(1 << 16)
    str r2, [r0]
    
    ldr r3, [r0]
    bic r3, r3, #(1 << 17)
    str r3, [r0]
    
    ldr r4, [r0]
    bic r4, r4, #(1 << 13)
    str r4, [r0]
    
    ldr r5, [r0]
    bic r5, r5, #(1 << 21) | (1 << 22) | (1 << 23) | (1 << 24)
    str r5, [r0]
    
    ldr r6, [r0]                
    orr r6, r6, #(1 << 12)      
    str r6, [r0]                
    
    ldr r7, [r0]                
    orr r7, r7, #(1 << 15)      
    str r7, [r0]                
    
    bx lr

.disable_wdt:
    stmfd sp!, {r0-r1, lr}
    ldr r0, = WDT_BASE

    ldr r1, = 0xAAAA
    str r1, [r0, #0x48]

    bl .pull_write_wdt

    ldr r1, = 0x5555
    str r1, [r0, #0x48]

    bl .pull_write_wdt
    ldmfd sp!, {r0-r1, pc}

.pull_write_wdt:
    ldr r1, [r0, #0x34]         
    and r1, r1, #(1 << 4)
    cmp r1, #0
    bne .pull_write_wdt
    bx lr
