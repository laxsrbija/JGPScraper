# JGPScraper
===========
### JGPScraper
JGPScraper je softver za parcijalnu automatizaciju unosa polazaka gradskog prevoza i adekvatno formatiranje za unos preko sajta Moovit.
Skraćuje trajanje unosa po liniji sa 10 na manje od 2 minuta.

### Zahtevi
Pre upotrebe programa, neophodno je korisnik ima instaliran Visual C++ Redistributable Packages for Visual Studio 2013.

Paket softvera je moguće besplatno preuzeti sa sledeće adrese:
https://www.microsoft.com/en-gb/download/details.aspx?id=40784

### Upotreba
JGPScraper funkcioniše tako što koristi sirove nizove podataka sa sajta JGP-a i od njih generiše datoteke sa sadržajem koji se može direktno uneti.

Nakon otvaranja programa, od korisnika se traži da unese adresu do datoteke iz koje se čitaju polasci. Ta datoteka mora biti u obliku koji se nalazi ispod da bi čitanje bilo korektno.

Zavisno od toga da li linija ima specijalne polaske, program će generisati jednu ili više datoteka sa sadržajem oblika *HH:MM* za radni dan, subotu i nedelju.

Za više detalja, pogledati primer ulaza i izlaza.

###  Šablon
```
br_linije br_specijalnih_polazaka prvi_polazak poslednji_polazak
string_polazaka
string_polazaka
q
string_polazaka
...
```

*br_linije* - Označava broj linije. Može sadržati i slova. Koristi se isključivo u nazivu izlazne datoteke.

*br_specijalnih_polazaka* - Označava specijalan broj polazaka. Može imati vrednost u opsegu 0-4.

*prvi_polazak* - Čas prvog polaska

*poslednji_polazak* - Čas poslednjeg polaska

*string_polazaka* - Sirov string koji sadrži minute polazaka, prekopiran direktno sa sajta JGP-a

*q* - Oznaka da nema polazaka u datom času (čas se preskače)

Ekstenzija i naziv datoteke nisu važni, ali se preporučuje *TXT*.


### Primer ulaza
Primer ulazne datoteke za liniju 7.
```
7 2 4 22
50*
30, 40*
20*, 30
00*, 30, 40*
30, 30*
20*
00*, 15, 40*
15, 20*
00*, 15, 40*
15, 20*
00*, 15, 40*
20*, 30
10*, 30
00*, 30, 40*
20*, 30
00*, 40*
00, 30*
00, 20*, 55**
50*
q
00, 00*
00, 00*
00*
00*
00*, 45
00*, 45
00*, 45
00*, 45
00*, 45
00*
00*
00*
00*
00*, 45
00*
10**
q
q
q
00, 00*
00, 15*
30*
q
00*, 45
45
30*, 45 
10*, 45 
45
30*
q
10*
40*
45
20*
10**, 15*
00*, 40*
```

### Primer izlaza
Kako linija 7 ima dva specijalna polaska, generisaće se tri datoteke sa nazivima *7 - Osnovni polaci*, *7 - Specijalni polasci 1* i *7 - Specijalni polasci 2*.

**7 - Osnovni polaci**
```
RADNI DAN:
05:30
06:30
07:30
08:30
10:15
11:15
12:15
13:15
14:15
15:30
16:30
17:30
18:30
20:00
21:00

SUBOTA:
05:00
06:00
09:45
10:45
11:45
12:45
13:45
18:45

NEDELJA:
05:00
06:00
09:45
10:45
11:45
12:45
13:45
18:45
```

**7 - Specijalni polasci 1**
```
RADNI DAN:
04:50
05:40
06:20
07:00
07:40
08:30
09:20
10:00
10:40
11:20
12:00
12:40
13:20
14:00
14:40
15:20
16:10
17:00
17:40
18:20
19:00
19:40
20:30
21:20
22:50

SUBOTA:
05:00
06:00
07:00
08:00
09:00
10:00
11:00
12:00
13:00
14:00
15:00
16:00
17:00
18:00
19:00

NEDELJA:
05:00
06:15
07:30
09:00
11:30
12:10
14:30
16:10
17:40
19:20
20:15
21:00
21:40
22:00
22:40
```

**7 - Specijalni polasci 2**
```
RADNI DAN:
21:55

SUBOTA:
20:10

NEDELJA:
20:10
```

### Licenca
Copyright (c) 2015 Lazar Stanojević. 

Pogledati LICENSE datoteku za informacije i ograničenja licence (MIT).