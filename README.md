# PolkupyoraRekisteri
Ohjelma, joka on kirjoitettu C++ ohjelmointikieliellä, koulun kurssia varten / A program written in C++ for a school course

## Ohjelman käyttöohjeet 
Ohjelman projektitiedostot voidaan ladata GitHubista ja avata Visual Studio 2022 (tai vastaavalla ohjelmalla).
Sovelluksella ei vielä ole ladattavaa pakettia josta se olisi helppo suorittaa. Ohjelman saa pyöritettyä käyttämäsi
ohjelmointisovelluksen debuggaus toimintoa. 

Kaikki valikot toimivat numerosyötteellä ja numero joka valitsee valikon vaihtoehdon on merkitty numerolla valinnan vieressä.

## Päävalikko

Sovelluksessa on simppeli päävalikko.
Päävalikon rakenne:

1. Lisää polkupyörä
2. Näytä polkupyörät
3. Poista polkupyörä
4. Muokkaa pyörien tietoja
5. Tallenna tietokanta
0. Lopeta

Valikon selitykset on kirjoitettu mahdollisimman yksiselitteisellä ja helposti ymmärrettävällä suomenkielellä, jotta
ohjelman käyttö olisi mahdollisimman helppoa kenelle tahansa. Kun valintana annetaan syöte 1, se avaa polkupyörän lisäyksen.

## Polkupyörän lisäys
Polkupyörän lisäyksen valikkorakenne on vastaavanlainen.

1. Lisää polkupyörä
2. Lisää velomobiili
0. Palaa päävalikkoon

Tässä tilanteessa voidaan valita polkupyörän ja velomobiilin välillä. Näiden kahden luokan välillä on erona miten renkaiden määrä
määritetään. Polkupyörässä on 2 rengasta ja velomobiilissa voi olla 3 tai 4 rengasta. Velomobiili myös määrittää polkupyörän tyypin
automaattisesti velomobiiliksi, kun polkupyörän tyypin saa määritettyä omalla valintakyselyllä. Tällähetkellä pyörien tyyppejä on määritelty 12,
joista 11 on erilaisia pyörätyyppejä ja 12 valinta on muu, joka on tehty sitä varten, jos ei haluamasi pyörätyyppiä löydy.

Kun valitaan millainen pyörä halutaan lisätä, valitaan sopiva valinta. Jos pyöräsi on perinteinen polkupyörä, valitaan polkupyörä.
Jos polkupyöräsi on velomobiili, valitaan velomobiili. Kaikkia monirenkaisia pyöriä, kuten riksapyörä, ei sovellus vielä tue.
Kun pyörä on valittu, pyörä kysyy polkupyörän tietoja ja käyttäjä voi alkaa antamaan niitä.

Tiedot joita kysytään on:

- Pyörän valmistaja
- Pyörän malli
- Pyörän vuosimalli
- Pyörän runkokoko
- Pyörien koko
- Pyörien määrä (Velomobiilissa)
- Runkonumero
- Pyörän tyyppi (Polkupyörässä)

Kun pyörä on lisätty rekisteriin, ohjelma antaa pyörälle rekisterinumeron. Rekisterinumero on muodossa AA-111 ja sitä voi käyttää pyörän tietojen muokkaukseen
ja pyörän tietojen muokkaukseen. 

## Näytä polkupyörät

Tämä listaa kaikki rekisterissä olevat polkupyörät numerojärjestyksessä ja listaa seuraavat tiedot:

- Pyörän rekisterinumero
- Pyörän valmistaja
- Pyörän malli
- Pyörän vuosimalli
- Pyörän runkokoko
- Pyörien koko
- Pyörien määrä (Velomobiilissa)
- Runkonumero
- Pyörän tyyppi (Polkupyörässä)

Tätä ominaisuutta on helppo hyödyntää tietojen muokkaamisessa ja poistamisessa, kun esimerkiksi rekisterinumero on tieto jota tarvitaan kun halutaan muokata tai poistaa tietoja

## Poista polkupyörä

Tämä poistaa polkupyörän. Ohjelma kysyy polkupyörän rekisterinumeroa ja sen saatuaan, poistaa sen.

## Muokkaa pyörien tietoja

Tämä antaa mahdollisuuden muokata pyörien tietoja. Ohjelma kysyy onko muokattava pyörä polkupyörä vai velomobiili, muokattavat pyörän tiedot ja ohjeistaa ominaisuuden käytössä, esimerkiksi jos ei halua jotain tiettyä tietoa muuttaa.

## Tallenna tietokanta

Tämä tallentaa tietokannan tiedot, jos ei halua keskeyttää tietojen käsittelyä.

## Lopeta

Tämä lopettaa sovelluksen, samalla tallentaen muutetut tiedot. 

## Muuta huomioitavaa!

Sovellus ei tallenna tietoja kun painetaan ikkunan sulkemisnäppäintä oikeasta ylänurkasta.

## Itsearviointi

Tässä projektissa olisi aika paljonkin paranneltavaa. Tarkistuksia tietojen muokkausta varten, koodin tiivistystä käyttäen enemmän funktioita, vaikka mitä jos oikein syventyy ja aloittaisi viilaamaan.
Hankalin asia mihin on pitänyt totutella on luokkien teko C++ kielellä. Kahteen eri tiedostoon luokkien tekeminen on mielenkiintoinen tapa pitää koodi siistinä, mutta jotenkin tuntuu oudolta tavalta.
Ehkä tottunut liikaa C# ja samantapaisiin koodikieliin. C++ muuten koodikielenä ei ole vaikeaa kirjoittaa. Helpoin tässä projektissa oli itse koodin työstäminen, kun projektin teema oli itselle mieluinen ja
ideoita riitti, eikä koodikieli tuntunut vastustavan hirveästi. Jos tekisin projektin uudestaan keskittyisin enemmän tekemään asioita funktioilla, jotta koodi olisi tiiviimpää ja siistimpää, ja tutkisin enemmän luokkien
tekemistä, koska projektin alkupäässä luokkien saaminen toimimaan vaati useamman illan. Myös kirjastoja olisi hyvä opiskella, jos löytyisi lisää kirjastoja jotka olisi voinut tehdä tästä projektista helpomman. 

Koen onnistuneeni tekemään hyvän prototyypin pyörärekisteristä, jos tästä haluaisi lähteä oikeaa pyörien hallintaohjelmaa tästä haluaa lähteä tekemään. 
