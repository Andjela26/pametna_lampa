Sistem inteligentne lampe se sastoji iz sledećih elemenata:
•	Lampa (kao simulaciju lampe koristiti LED diodu po zelji)
•	Relej za paljenje/gašenje lampe (NE povezivati potrošač na 230VAC)
•	PIR senzor za detekciju pokreta 
•	Senzor osvetljenja, za merenje intenziteta svetla
Stanje lampe (upaljena/ugašena) zavisi od nivoa intenziteta svetala u sobi, ali i od toga da li je u sobi prisutna osoba. Uslovi za paljenje i gašenje lampe se razlikuju:
•	Lampa se pali, ako je lampa ugašena, u sobi je mrak i detektovano je prisustvo osobe. Smatra se da je u sobi mrak ako je intenzitet svetala manji od graničnog nivoa, koji koji je definisan kao konstanta u kodu. Detektovan impuls PIR senzora znači prisustvo osobe u sobi.
•	Lampa se gasi, ako je lampa upaljena, ne detektuje se prisustvo osobe ili je intenzitet svetla postao veći za unapred definisani nivo u odnosu na intenzitet svetala neposredno nakon paljenja lampe.
