# Computer-Architecture-and-Organization-II

This repository contains the activities, practices and work carried out in the discipline of computer architecture and organization II.

## Commands to compile and run the code
1. arm-none-eabi-as -o start.o start.s
2. arm-none-eabi-ld -Ttext=0x80000000 -o start.elf start.o
3. arm-none-eabi-objcopy -O binary start.elf start.bin
4. sudo cp start.bin /srv/tftp
5. sudo chmod 755 /srv/tftp/start.bin

## Commands for minicom
1. setenv ipaddr 10.4.1.2
2. setenv serverip 10.4.1.1
3. setenv loadaddr 0x80000000
4. tftp ${loadaddr} start.bin
5. go ${loadaddr}
