.equ SOC_PRCM_REGS,     (0x44E00000)
.equ SOC_CM_PER_REGS,                       (SOC_PRCM_REGS + 0)
.equ SOC_CONTROL_REGS,                     (0x44E10000)
.equ SOC_GPIO_1_REGS,                      (0x4804C000)

.equ CM_PER_GPIO1,								    (0xAC)
.equ CM_PER_GPIO2,								    (0xAC)
.equ CM_PER_GPIO_CLKCTRL_MODULEMODE_ENABLE,         (0x2u)
.equ CM_PER_GPIO_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK,   (0x00040000u)

.equ CM_conf_gpmc_ben1,      	 					(0x0878)	//GPIO1_28
.equ CM_conf_gpmc_a5,         						(0x0854)
.equ CM_conf_gpmc_a6,         						(0x0858)
.equ CM_conf_gpmc_a7,         						(0x085C)
.equ CM_conf_gpmc_a8,         						(0x0860)
.equ CM_conf_gpmc_clk,								(0x088C)	  //GPIO2_1
.equ CM_conf_gpmc_ad12,								(0x0830)	  //GPIO1_12

.equ GPIO_DATAIN,        										0x138
.equ GPIO_DATAOUT,        										0x13C
.equ GPIO_OE,                 									0x134
.equ GPIO_CLEARDATAOUT,       									0x190
.equ GPIO_SETDATAOUT,         									0x194
