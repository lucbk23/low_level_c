
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

