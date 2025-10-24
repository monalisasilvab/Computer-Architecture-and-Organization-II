/*
.include "defs.inc"

.equ PIN_AS_GPIO,         										(0b111U << 0)
.equ PIN_AS_RECEIVER,         									(0b1U << 5)

.equ LED_01,													(1U << 21)
.equ LED_02,													(1U << 22)
.equ LED_03,													(1U << 23)
.equ LED_04,													(1U << 24)

.equ LED_EXT_01,												(1U << 16)  //GPIO1_16 (CHECAR)
.equ LED_EXT_02,												(1U << 17)  //GPIO1_17 (CHECAR)
.equ LED_EXT_03,												(1U << 28)  //GPIO1_28
.equ LED_EXT_04,												(1U << 29)  //GPIO1_29 (CHECAR)

.equ BTN_01,													(1U << 12)  //GPIO1_12
.equ BTN_02,													(1U << 13)  //GPIO1_13 (CHECAR)

.data
leds: .word 0
seq: .word 0
contagem: .word 0
            
.text
_start:
    mrs r0, cpsr
    bic r0, r0, #0x1F @ clear mode bits
    orr r0, r0, #0x13 @ set SVC mode
    orr r0, r0, #0xC0 @ disable FIQ and IRQ
    msr cpsr, r0

    ldr sp, =0x4030CDFC  @6kB public stack  TMR 26.1.3.2

    bl _main

    b .

_main:
    bl _gpio_init

_while:

_check_btn_1:
    ldr r0, =SOC_GPIO_1_REGS 
    ldr r1, [r0, #GPIO_DATAIN]
    ands r1, r1, #BTN_01
    beq _check_btn_2

    ldr r0, =leds
    ldr r1, [r0]
    cmp r1, #1
    moveq r1, #0
    movne r1, #1
    str r1, [r0]

_check_btn_2:
    ldr r0, =SOC_GPIO_1_REGS 
    ldr r1, [r0, #GPIO_DATAIN]
    ands r1, r1, #BTN_02
    beq _set_leds
    
    ldr r0, =seq
    ldr r1, [r0]
    add r1, r1, #1
    cmp r1, #2
    movgt r1, #0
    str r1, [r0]

_set_leds:
    ldr r0, =leds
    ldr r1, [r0]
    cmp r1, #1
    bleq external_led
    blne internal_led

    bl _delay

    ldr r0, =contagem
    ldr r1, [r0]
    add r1, r1, #1
    cmp r1, #15
    movgt r1, #0
    str r1, [r0]

    b _while

_delay:
    ldr r0, =1000000

_wait:
    subs r0, r0, #1
    bne _wait

    mov pc, lr

internal_led:
    ldr r0, =contagem
    ldr r1, [r0]

    ldr r0, =SOC_GPIO_1_REGS

    ldr r3, =LED_04
    ands r2, r1, #1
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]

    ldr r3, =LED_03
    ands r2, r1, #2
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]

    ldr r3, =LED_02
    ands r2, r1, #4
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]

    ldr r3, =LED_01
    ands r2, r1, #8
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]
    
    mov pc, lr

external_led:
    ldr r0, =contagem
    ldr r1, [r0]

    ldr r0, =SOC_GPIO_1_REGS

    ldr r3, =LED_EXT_04
    ands r2, r1, #1
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]

    ldr r3, =LED_EXT_03
    ands r2, r1, #2
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]

    ldr r3, =LED_EXT_02
    ands r2, r1, #4
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]

    ldr r3, =LED_EXT_01
    ands r2, r1, #8
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]
    
    mov pc, lr


_gpio_init:
    ldr r0, =SOC_CM_PER_REGS

    // Enable GPIO1 Clock
    ldr r1, =(CM_PER_GPIO_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK | CM_PER_GPIO_CLKCTRL_MODULEMODE_ENABLE)
    str r1, [r0, #CM_PER_GPIO1] 

    ldr r0, =SOC_CONTROL_REGS

    //  Enable LED pins
    ldr r1, =(PIN_AS_GPIO)
    str r1, [r0, #CM_conf_gpmc_a5] 
    str r1, [r0, #CM_conf_gpmc_a6] 
    str r1, [r0, #CM_conf_gpmc_a7] 
    str r1, [r0, #CM_conf_gpmc_a8] 

    @ str r1, [r0, #EXT1]  (CHECAR)
    @ str r1, [r0, #EXT2]  (CHECAR)
    @ str r1, [r0, #EXT3]  (CHECAR)
    @ str r1, [r0, #EXT4]  (CHECAR)

    //  Enable Button pins
    ldr r1, =(PIN_AS_GPIO | PIN_AS_RECEIVER)
    str r1, [r0, #CM_conf_gpmc_ad12] 
    @ str r1, [r0, #BTN2]  (CHECAR)

    ldr r0, =SOC_GPIO_1_REGS

    // Setup pin direction
    ldr r1, =(BTN_01)
    str r1, [r0, #GPIO_OE]

    mov pc, lr

*/


//////////////////////////////////////////////////////////////////////////////////////

.include "defs.inc"

.equ PIN_AS_GPIO,         										(0b111U << 0)
.equ PIN_AS_RECEIVER,         									(0b1U << 5)

.equ LED_01,													(1U << 21)
.equ LED_02,													(1U << 22)
.equ LED_03,													(1U << 23)
.equ LED_04,													(1U << 24)

.equ LED_EXT_01,												(1U << 16)  // GPIO1_16
.equ LED_EXT_02,												(1U << 17)  // GPIO1_17
.equ LED_EXT_03,												(1U << 28)  // GPIO1_28
.equ LED_EXT_04,												(1U << 29)  // GPIO1_29

.equ BTN_01,													(1U << 12)  // GPIO1_12
.equ BTN_02,													(1U << 13)  // GPIO1_13

.data
leds: .word 0
seq: .word 0
contagem: .word 0

.text
_start:
    mrs r0, cpsr
    bic r0, r0, #0x1F @ clear mode bits
    orr r0, r0, #0x13 @ set SVC mode
    orr r0, r0, #0xC0 @ disable FIQ and IRQ
    msr cpsr, r0

    ldr sp, =0x4030CDFC  @ 6kB public stack (TMR 26.1.3.2)

    bl _main

    b .

_main:
    bl _gpio_init

_while:

_check_btn_1:
    ldr r0, =SOC_GPIO_1_REGS 
    ldr r1, [r0, #GPIO_DATAIN]
    ands r1, r1, #BTN_01
    beq _check_btn_2

    ldr r0, =leds
    ldr r1, [r0]
    cmp r1, #1
    moveq r1, #0
    movne r1, #1
    str r1, [r0]

_check_btn_2:
    ldr r0, =SOC_GPIO_1_REGS 
    ldr r1, [r0, #GPIO_DATAIN]
    ands r1, r1, #BTN_02
    beq _set_leds
    
    ldr r0, =seq
    ldr r1, [r0]
    add r1, r1, #1
    cmp r1, #2
    movgt r1, #0
    str r1, [r0]

_set_leds:
    ldr r0, =leds
    ldr r1, [r0]
    cmp r1, #1
    bleq external_led
    blne internal_led

    bl _delay

    ldr r0, =contagem
    ldr r1, [r0]
    add r1, r1, #1
    cmp r1, #15
    movgt r1, #0
    str r1, [r0]

    b _while

_delay:
    ldr r0, =1000000

_wait:
    subs r0, r0, #1
    bne _wait

    mov pc, lr

internal_led:
    ldr r0, =contagem
    ldr r1, [r0]

    ldr r0, =SOC_GPIO_1_REGS

    ldr r3, =LED_04
    ands r2, r1, #1
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]

    ldr r3, =LED_03
    ands r2, r1, #2
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]

    ldr r3, =LED_02
    ands r2, r1, #4
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]

    ldr r3, =LED_01
    ands r2, r1, #8
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]
    
    mov pc, lr

external_led:
    ldr r0, =contagem
    ldr r1, [r0]

    ldr r0, =SOC_GPIO_1_REGS

    ldr r3, =LED_EXT_04
    ands r2, r1, #1
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]

    ldr r3, =LED_EXT_03
    ands r2, r1, #2
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]

    ldr r3, =LED_EXT_02
    ands r2, r1, #4
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]

    ldr r3, =LED_EXT_01
    ands r2, r1, #8
    streq r3, [r0, #GPIO_CLEARDATAOUT]
    strne r3, [r0, #GPIO_SETDATAOUT]
    
    mov pc, lr

_gpio_init:
    ldr r0, =SOC_CM_PER_REGS

    // Enable GPIO1 Clock
    ldr r1, =(CM_PER_GPIO_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK | CM_PER_GPIO_CLKCTRL_MODULEMODE_ENABLE)
    str r1, [r0, #CM_PER_GPIO1] 

    ldr r0, =SOC_CONTROL_REGS

    // Enable LED pins (internos e externos)
    ldr r1, =(PIN_AS_GPIO)
    str r1, [r0, #CM_conf_gpmc_a5]  // LED_01 (GPIO1_21)
    str r1, [r0, #CM_conf_gpmc_a6]  // LED_02 (GPIO1_22)
    str r1, [r0, #CM_conf_gpmc_a7]  // LED_03 (GPIO1_23)
    str r1, [r0, #CM_conf_gpmc_a8]  // LED_04 (GPIO1_24)
    str r1, [r0, #CM_conf_gpmc_a16] // LED_EXT_01 (GPIO1_16)
    str r1, [r0, #CM_conf_gpmc_a17] // LED_EXT_02 (GPIO1_17)
    str r1, [r0, #CM_conf_gpmc_a28] // LED_EXT_03 (GPIO1_28)
    str r1, [r0, #CM_conf_gpmc_a29] // LED_EXT_04 (GPIO1_29)

    // Enable Button pins (BTN_01 e BTN_02)
    ldr r1, =(PIN_AS_GPIO | PIN_AS_RECEIVER)
    str r1, [r0, #CM_conf_gpmc_ad12]  // BTN_01 (GPIO1_12)
    str r1, [r0, #CM_conf_gpmc_ad13]  // BTN_02 (GPIO1_13)

    ldr r0, =SOC_GPIO_1_REGS

    // Setup pin direction: LEDs as outputs, buttons as inputs
    ldr r1, =(LED_01 | LED_02 | LED_03 | LED_04 | LED_EXT_01 | LED_EXT_02 | LED_EXT_03 | LED_EXT_04)
    bic r1, r1, #(BTN_01 | BTN_02)  // Configura BTN_01 e BTN_02 como entradas
    str r1, [r0, #GPIO_OE]

    mov pc, lr