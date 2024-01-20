#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
(25p) Napisati program koji iz fajla učitava podatke efektima dijete na određene osobe. U svakom
redu se nalaze ime osobe, naziv dijete i broj kilograma koje je osoba izgubila, razdvojene zapetom.
Primer: Vladimir,paleo,5. Napraviti meni za interakciju preko konzole sa sledećim opcijama:
a) (10p) Učitavanje podataka – unosi se naziv fajla, a podaci se učitavaju u binarno pretraživačko stablo,
sortirani rastuće po nazivu dijete.
b) (2p) Ispis podataka. Nakon učitavanja ispisati podatke iz stabla sortirano rastuce.
c) (4p) Ispis najefikasnije dijete – ispisati naziv dijete sa najvećom prosečnom izgubljenom masom po
osobi i odgovarajuću prosečnu vrednost na dve decimale. Ukoliko ima više najboljih, ispisati bilo koju.
d) (8p) Pronalaženje podataka o osobi – unosi se string – deo imena osobe, ispisuju se podaci o svim
osobama čije ime sadrži uneti string. Pretraga treba da bude neosetljiva na mala i velika slova.
e) (1p) Izlaz iz programa i brisanje stabla.*/

typedef struct Element
{
    char ime[20];
    char dijeta[20];
    int kg;
    struct Element* desni;
    struct Element* levi;
}Element;

Element *napraviNovi(char *ime, char* dijeta, int kg)
{
    Element *novi = (Element *)calloc(1, sizeof(Element));
    strcpy(novi->ime, ime);
    strcpy(novi->dijeta, dijeta);
    novi->kg = kg;
    return novi;
}

char buffer[255];

void skrati(char *buf)
{
    if(buffer[strlen(buf)-1] == '\n')
        buffer[strlen(buf)-1] = 0;
}

int meni()
{
    while(1)
    {
        printf("MENI:\nOpcija 1: Unos naziva fajla\nOpcija 2: Ispis podataka\nOpcija 3: Ispis najefikasnije dijete\n");
        printf("Opcija 4: Pronalazenje podataka\nOpcija 5: Izlaz i brisanje\n");
        fgets(buffer, 255, stdin);
        skrati(buffer);
        int op = atoi(buffer);
        if(op >=1 && op <=5)
            return op;
        printf("Nevalidan unos\n");
    }
}

Element *dodajSortirano(Element *koren, Element *novi)
{
    if(koren == NULL)
    {
        koren = novi;
        return koren;
    }
    if(strcmp(koren->dijeta, novi->dijeta) <= 0)
    {
        koren->desni = dodajSortirano(koren->desni, novi);
    }
    else
    {
        koren->levi = dodajSortirano(koren->levi, novi);
    }
    return koren;
}

Element *ucitavanjeFajla(Element *koren)
{
    printf("Uneiste naziv fajla\n");
    fgets(buffer, 255, stdin);
    skrati(buffer);
    FILE *f = fopen(buffer, "r");
    if(f == NULL)
    {
        printf("Uneti fajl nije dostupan");
    }
    else
    {
        while(fgets(buffer, 255, f))
        {
            skrati(buffer);
            //fputs(buffer, stdout);
            char *token = strtok(buffer, ",");
            char *ime = token;
            token = strtok(NULL, ",");
            char *dijeta = token;
            token = strtok(NULL, ",");
            int kg = atoi(token);
            Element *novi = napraviNovi(ime, dijeta, kg);
            koren = dodajSortirano(koren, novi);
        }
        fclose(f);
        return koren;
    }
    fclose(f);
    return NULL;
}

void ispisSvihKojiSadrze(Element *koren)
{
    printf("Unesite string:\n");
    fgets(buffer, 255, stdin);
    skrati(buffer);
    Element *pomocni = koren;
    char *uppBuff = strupr(buffer);
    prolazakKrozStablo(pomocni, uppBuff);
}

void prolazakKrozStablo(Element *koren, char *string)
{
    if(koren)
    {
        char *uppPom = strupr(koren->ime);
        if(strstr(uppPom, string))
        {
            printf("%s, %s, %d\n", koren->ime, koren->dijeta, koren->kg);
        }
        prolazakKrozStablo(koren->desni, string);
        prolazakKrozStablo(koren->levi, string);
    }
}

void ispisStabla(Element *koren)
{
    if(koren)
    {
        ispisStabla(koren->levi);
        printf("%s, %s, %d\n", koren->ime, koren->dijeta, koren->kg);
        ispisStabla(koren->desni);
    }
    return;
}

Element * izbrisiStablo(Element *koren)
{
    if(koren)
    {
        izbrisiStablo(koren->levi);
        izbrisiStablo(koren->desni);
        free(koren);
    }
    return NULL;
}

int main()
{
    int op;
    Element *koren = NULL;
    while(1){
        op = meni();
        switch(op)
        {
            case 1:
                koren = ucitavanjeFajla(koren);
                break;
            case 2:
                ispisStabla(koren);
                break;
            case 3:
                break;
            case 4:
                ispisSvihKojiSadrze(koren);
                break;
            case 5:
                koren = izbrisiStablo(koren);
                if(koren == NULL)
                {
                    printf("Stablo je uspesno obrisano");
                }
                return 0;
        }
    }
    return 0;
}
