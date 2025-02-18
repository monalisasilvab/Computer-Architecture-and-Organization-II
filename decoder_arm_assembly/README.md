# decoder_arm_assembly

### This work consists of implementing a program (in any programming language) that decodes a memory map into its respective Thumb code.

### 1. The decoder must receive as input a memory map and return a text file containing the code to be executed, in Thumb, according to table B-5 of the book ARM System Developer’s Guide, 1st edition. Example:

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

### 2. The program must read input from a .em file and save the result in a .out file.

### Informações adicionais:

## Compiling
make all

## Running
./bin/app