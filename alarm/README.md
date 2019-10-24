## Dokumentasjon - Arbeidskrav 2 

## Beskrivelse 
Jeg har laget en innbruddsalarm. Den har en avstandssensor, som trigger alarmen ved en endring i avstand til det 
den er vendt mot (f.eks en dør, eller en gjenstand man ikke bli frastjålet). 

Dersom alt er OK, viser displayet grønn skjerm, med nåværende tidspunkt. Dersom alarmen har blitt trigget,
vil skjermen være rød, og vise tidspunktet alarmen gikk av. For å deaktivere alarmen, kan taste inn en kode 
på knappene. Denne er stilt til 1100 (1 -> hold inn, 0, ikke rør). 
Når alarmen er trigget, spilles det dessuten lyd på en høyttaler. 

Jeg tenkte at jeg ønsket en mekanisme som gjorde at man kunne deaktivere den. Derfor laget jeg en kodelås-mekanisme. 
Ellers synes jeg det er kjekt at den viser en farge, som lett sier hvilket modus den er i. Lyden har samme effekt som 
fargene. 

Jeg bruker følgende komponenter fra komponentsettet: 
1. knapper 4x
2. skjerm
3. avstandssensor
4. klokke 
5. høyttaler 


Koden sjekker for endringer i avstand. Dersom det har forekommet en større endring, er kontrolleren programmert til 
å sende strøm til høyttaleren, og å lytte på knappene. Dersom knappene leser riktig kode, vil det byttes tilbake. 

Nåværende tid hentes fra klokken, og printes til skjermen. 