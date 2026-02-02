Inlämning -algoritmer-sort
event 
event är en class som inheretar värden från andra classer som TEMP, MOTION, BUTTON med hjälp av enums

Event_list
Eventlist kan ta en Event class fylled med värden och länkar next* till tidigare list entrys

Queue
andvänds för att göra en cirkulärbuffer

sortmanager
har båda sorterings algoritmerna som används selectionsort och quicksort
selectionsort för små dataset som typ 10-1000 med dens tids complexitet som är O(n^2)
quicksort för stora dataset som 1000-10000 med dens tids complexitet som är O(n*log n)

utilitys
här här alla hjälp functioner som inputvalidation som ser om du klicka in en bokstav istället för een siffra. samt randomnumbergenerator och timestamp functioner.

program genomföring 
startar i main. och går genom run functionen där en 2 structs deklareras en för länkade listan och den andra för menu exitstatusen. sen börjar en do while loop som loopar tills exit status är true 
i loopen printas menyn ut och man kommer in i select_menu functionen där man kan välja mellan tick, print, sort, search, help och exit.
tick<n>
låter dig välja hur många events  du vill göra sen deklareras en cirkuler buffer som tar alla event och sen lägger i dem i listan och till sist så deletas queuen
print 
som namnet printar alla värden från listan
sort
låter dig välja vilken sorterings algoritm att använda sammt om man vill ha stigande eller fallande sortering.
search
låter dig söka efter ett id och så kommer alla event med det idt upp
help
förklarar alla menu options
EXIT
gör om menu exit status till true vilket kommer avsluta programet 
till sist så deletas main listan
