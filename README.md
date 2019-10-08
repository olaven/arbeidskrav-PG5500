# Arbeidskrav - Embedded Systems 

## Overordnet 
I denne oppgaven har jeg koplet sammen en Arduino UNO med et 8x8 LED-display
()
ved hjelp av en MAX7219. Jeg har deretter skrevet et program som skriver ut 
scrollende tekst, slik som oppgaven krever. Programmet er skrevet med
LedControl-biblioteket. 

## Kobling 
Jeg har brukt dataark for [MAX7219](https://datasheets.maximintegrated.com/en/ds/MAX7219-MAX7221.pdf) og [matrisen](http://megtestesules.info/hobbielektronika/adatlapok/LED8x8_1088AS.pdf). 
Dataarkene brukte jeg til aa lage min [egen oversikt](#skjema) over hvordan ting skulle kobles. 

Matrisen sitt dataark viser hvilken PIN paa mtrisen som styrer hvilken kolonne/rad. Videre fant jeg ut at hver 
dig0-7 paa MAX7219 gikk til rader og SIG DP og SIG A-G gikk til kolonner. Basert paa denne informasjonen kunne 
jeg lage en oversikt over hvilke PINs paa MAX7219 som skulle til forskjellige PINs paa matrisen. 

## Virkemaate 
Matrisen fungerer i utgangspunktet slik: det dannes en krets ved aa sette stroem gjennom en gitt kolonne og en gitt rad, 
med tilfoersel i den ene enden og jording i den andre. Da lyser man opp en LED-paere. 

Dette er ikke nok; noen kombinasjoner er uforenelige med denne fremgangsmaaten. Dette kommer man rundt 
ved at matrisen blinker fort. Det gaar saa fort at vaare mennesklige oeyene ikke oppdager det. I tillegg 
sparer det stroem :) 


MAX7219 lar oss bruke matrisen uten aa koble den rett i Arduino-en. Vi kommer unna med aa bruke 3 PINs paa 
Arduino-brettet (eks. 5V og GND) istedenfor 16. Da har vi rom til aa gjoere andre flere ting med Arduino-brettet samtidig. 


# Skjema
![bilde av mitt skjema](./skjema.jpg)