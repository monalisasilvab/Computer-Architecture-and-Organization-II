# ARM Thumb Instruction Decoder

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/yourusername/decoder_arm_assembly)
[![License](https://img.shields.io/badge/license-MIT-blue)](LICENSE)

A disassembler tool that converts ARM Thumb machine code into human-readable assembly instructions, following the specification from Table B-5 of *ARM System Developer's Guide* (1st Edition).

This work consists of implementing a program (in any programming language) that decodes a memory map into its respective Thumb code. The decoder must receive as input a memory map and return a text file containing the code to be executed, in Thumb, according to table B-5 of the book ARM System Developer’s Guide, 1st edition. Example:

<table style="text-align: center; border-collapse: collapse; width: 30%; border: 1px solid white;">
    <thead>
        <tr>
            <th style="border: 1px solid white; padding: 8px; text-align: center;">Entrada</th>
            <th style="border: 1px solid white; padding: 8px; text-align: center;">Saída</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">e7ff</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">e7ff &emsp; B #4098</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">2003</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">2003 &emsp; MOV r0 , #3</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">2105</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">2105 &emsp; MOV r1 , #5</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">1840</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">1840 &emsp; ADD r0 , r0 , r1</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">1a40</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">1a40 &emsp; SUB r0 , r0 , r1</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">b406</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">b406 &emsp; PUSH { r1 , r2 }</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">e7fe</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">e7fe &emsp; B #4096</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">bc03</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">bc03 &emsp; POP { r0 , r1 }</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">be00</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">be00 &emsp; BKPT #4</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">df32</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">df32 &emsp; SWI #104</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">43c7</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">43c7 &emsp; MVN r7 , r0</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">432d</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">432d &emsp; ORR r5 , r0</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">438a</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">438a &emsp; BIC r2 , r0</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">6038</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">6038 &emsp; STR r0 , [ r7 , #0]</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">6070</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">6070 &emsp; STR r0 , [ r6 , #1]</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">4800</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">4800 &emsp; LDR r0 , [ pc , #0]</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">1a9b</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">1a9b &emsp; SUB r3 , r3 , r2</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">42ab</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">42ab &emsp; CMP r3 , r0</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">4008</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">4008 &emsp; AND r0 , r0</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">4232</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">4232 &emsp; TST r2 , r0</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">0052</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">0052 &emsp; LSL r2 , r2 , #1</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">d1e8</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">d1e8 &emsp; BNE #468</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">f7ff</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">f7ff &emsp; BL #4098</td>
        </tr>
        <tr>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">fff0</td>
            <td style="border: 1px solid white; padding: 8px; text-align: center;">fff0 &emsp; BL #4068</td>
        </tr>
    </tbody>
</table>

The program must read input from a .em file and save the result in a .out file.

## 🤖 Features

- Converts hexadecimal memory maps to Thumb assembly mnemonics
- Supports a wide range of Thumb instructions including:
  - Data processing (MOV, ADD, SUB, AND, ORR, BIC, MVN)
  - Memory operations (LDR, STR)
  - Stack operations (PUSH, POP)
  - Control flow (B, BL, BNE)
  - Special instructions (SWI, BKPT)
- Generates formatted output with original hex and decoded instructions
- Handles both 16-bit and 32-bit Thumb instructions (if implemented)

## ⚙️ Installation

### 🔓 Prerequisites
- GNU Make
- C Compiler (gcc or clang recommended)

### ⚒️ Building
Build the project using GNU Make:
```bash
git clone https://github.com/monalisasilvab/decoder_arm_assembly.git
cd decoder_arm_assembly
make all 
```

## 💻 Usage
Basic execution:
```bash
./bin/app <input_file.in> <output_file.out>
```

## 📊 Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository
2. Create a feature branch (git checkout -b feature/improvement)
3. Commit changes (git commit -am 'Add new feature')
4. Push to branch (git push origin feature/improvement)
5. Open a Pull Request

## 📘 Acknowledgements
- Reference: Table B-5 from ARM System Developer's Guide (Andrew N. Sloss et al.)
- ARM Architecture Reference Manual for Thumb instruction set](https://documentation.espressif.com/esp32_datasheet_en.pdf)
