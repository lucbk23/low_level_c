# Binær forståelse
Binary is a base-2 number system. It is the number system we use to represent data in computers.
It can consist of 0's and 1's.

# Byte vs bits
1 byte = 8 bits
1 bit is represented by a single digit in binary.
Binary is calculated by using the powers of 2. - That means that each space in the binary number system is a power of 2, which is 2^0, 2^1, 2^2, 2^3, 2^4, 2^5, 2^6, 2^7. *written the other way around, so starting from the right and going to the left*
Each whole row of numbers in binary is a byte, which represents 8 bits and can be converted to a single digit in decimal.

# Binary to decimal
 - For at konvertere resultatet til decimal, skal man multiplicere det tal (0 eller 1) med [fra højre] **2^0**, **2^1**, **2^2**, **2^3**, **2^4**, **2^5**, **2^6**, **2^7**.
    Eksempelvis: ```10101001```:

    - ```1010100__1__``` 1 * 2^0 = 1
    - ```101010__0__1``` 0 * 2^1 = 0
    - ```10101__0__01``` 0 * 2^2 = 0
    - ```1010__1__001``` 1 * 2^3 = 8
    - ```101__0__1001``` 0 * 2^4 = 0
    - ```10__1__01001``` 1 * 2^5 = 32
    - ```1__0__101001``` 0 * 2^6 = 0
    - ```__1__0101001``` 1 * 2^7 = 128
    - I decimal giver det: 128 + 32 + 8 + 1 = 169
    - I hexadecimal: 0x9A(2109)
- Binary to decimal
    - Binary to decimal
        - 10010110 = 101 (decimal)
        - 10101001 = 102 (decimal)
        - 11011010 = 110 (decimal)
        - 11101010 = 111 (decimal)

# Binary to hexadecimal

- Binary to hexadecimal
    - Binary to hexadecimal
        - 01010110 = 0xA6 (hexadecimal)
        - 10101001 = 0xA2 (hexadecimal)
        - 11011010 = 0xAC (hexadecimal)
        - 11101010 = 0xAE (hexadecimal)

# Operators in C
- Bitwise operators
    - Bitwise operators
        - `&` AND 
        - `|` OR
        - `^` XOR
        - `~` NOT
        - `<<` LEFT SHIFT
        - `>>` RIGHT SHIFT
## Explanation
- `&` AND
    - Think of it like a strict rule; if both things are true, then the result is true (1). If neither thing is true, then the result is false (0).
    - What it does: Compares two bits and gives 1 only if **both** bits are 1.
    - Example: ```01010110 & 01101001 = 01010110 & 01101001 = 10101001```
    - Ovenover: Kig på *01101001* og *01010110* - lad os dele den op fra højre til venstre og sammenlign om der står 1 på de samme pladser. Hvis der er 1 på de samme pladser, så returneres 1 i resultatet.
    - Hvis der ikke er 1 på de samme pladser, så returneres 0 i resultatet.
   

- `|` OR
    - What it does: Compares two bits and gives 1 if **either** bit is 1.
    - Think of it like a flexible rule; if at least one thing is true, then the result is true (1).
    - Example ```01010110 | 01101001 = 01111111
    - Ovenover: Kig på *01101001* og *01010110* - lad os dele den op fra højre til venstre og sammenlign om der står 1 på de samme pladser.
    - ```0110100__1__ | 0101011__0__``` = 1
    - ```011010__0__1 | 010101__1__0``` = 1
    - ```01101__0__01 | 01010__1__10``` = 1
    - ```0110__1__001 | 0101__0__110``` = 1
    - ```011__0__1001 | 010__1__0110``` = 1
    - ```01__1__01001 | 01__0__10110``` = 1
    - ```1__0__101001 | 0__1__010110``` = 1
    - ```__0__10101001 | __0__1010110``` = 0

- `^` XOR	
    - Its a little trickier; it gives true (1) if the two bits are different, and false (0) if they are the same.
    - If you compare 2 light switches, and one is on and other is off, the result is true (1).
    - If the two light switches are on, the result is false (0).
    - If the two light switches are off, the result is false (0).
    - If the two light switches are on and off, the result is true (1).

- `~` NOT
    - What it does: Reverses all the bits. If it is a 1, it becomes a 0. If it is a 0, it becomes a 1.
    - Example: ```01010110 = ~101```

- `<<` LEFT SHIFT
    - What it does: Shifts all the bits to the left by 1.
    - Example: ```01010110 << 1 = 10101100```

- `>>` RIGHT SHIFT
    - What it does: Shifts all the bits to the right by 1.
    - Example: ```10101100 >> 1 = 01010110```
    


# Hex Dump

Hex dump er en tekst-fil, der viser en binær fil i en hexadecimal format. Dette er et af de mest almindelige formater for at vise binære data. 

# Hexdumpers der kan bruges

- Hexyl
- Hexdumper

# Kommandoer til de forskellige.

## Hexyl
- Dump a file: Kommando: ```hexyl ${filename}```
- Dump a file and show the offset: Kommando: ```hexyl -s ${offset} ${filename}```
- Dump a file and show the offset and number of bytes: Kommando: ```hexyl -s ${offset} -n ${number_of_bytes} ${filename}```
- Dump a file and show more or less: ```hexyl ${filename} | less``` / ```hexyl ${filename} | more```
- Dump a file and save it to a file: Kommando: ```hexyl -n ${number_of_bytes} ${filename} > ${filename}.hex```
- Dump a file and save it to a file and show more or less: ```hexyl -n ${number_of_bytes} ${filename} > ${filename}.hex && less ${filename}.hex```
- Dump a file and search for a specific sequence of bytes: Kommando: ```hexyl -n ${number_of_bytes} ${filename} | grep ${sequence_of_bytes}```

## Hexdumper
- Dump a file: Kommando: ```hexdump -C ${filename}```
- Dump a file and show the offset: Kommando: ```hexdump -C -s ${offset} ${filename}```
- Dump a file and show the offset and number of bytes: Kommando: ```hexdump -C -s ${offset} -n ${number_of_bytes} ${filename}```
- Dump a file and show more or less: ```hexdump -C ${filename} | less``` / ```hexdump -C ${filename} | more```
- Dump a file and save it to a file: ```hexdump -C ${filename} > ${filename}.txt```
- Can now be opened in VS Code using CLI: ```code ${filename}.txt```

## Hvorfor man bruger disse kommandoer

### Hexyl & Hexdumper
1. For at få vist filen i hexadecimaler
2. for at vise et bestemt antal bits af filen
3. For at vise et bestemt antal bytes men samtidiigt starte med et bestemt offset.
4. For at vise en fil i hexadecimaler og vise den i et tekst format. *Til denne så brug hexdump, den giver det bedste resultat at vise det i*
5. For at søge efter en bestemt sekvens af bits i en fil *Til denne så brug hexdump, den giver det bedste resultat at vise det i*

