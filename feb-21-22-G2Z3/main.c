#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element
{
    char prodavnica[50];
    char naziv[50];
    int cena1;
    int cena2;
    struct Element *sledeci;
}Element;

char buffer[200];
char prod1[20] = "";
void skrati(char *string)
{
    if(string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = 0;
}

int meni()
{
    printf("MENI:\nOpcija 1: Ucitavanje podataka\nOpcija 2: Ispis svih artikala\nOpcija 3: Prikaz najjeftinije radnje za artikle\n");
    printf("Opcija 4: Prikaz posebnih artikala\nOpcija 5: Brisanje liste i zavrsavanje programa\n");
    while(1)
    {
        fgets(buffer, 200, stdin);
        skrati(buffer);
        int op = atoi(buffer);
        if(op >= 1 && op <= 5)
            return op;
        printf("Pogresan unos, molimo unesite broj izmedju 1 i 5!\n");
    }
}

Element *napraviNoviElement(char *prod, char *naziv, int cena)
{
    Element *novi = (Element *)calloc(1, sizeof(Element));
    if(strcmp(prod, prod1) == 0)
        novi->cena1 = cena;
    else
        novi->cena2 = cena;
    strcpy(novi->naziv, naziv);
    strcpy(novi->prodavnica, prod);
    return novi;
}

Element *dodajUListu(Element *koren, Element *novi)
{
    if(koren == NULL)
    {
        return novi;
    }
    if(strcmp(koren->naziv, novi->naziv) < 0)
    {
        novi->sledeci = koren;
        return novi;
    }
    Element *temp = koren;
    while(temp->sledeci && strcmp(temp->sledeci->naziv, novi->naziv) > 0)
    {
        temp = temp->sledeci;
    }
    novi->sledeci = temp->sledeci;
    temp->sledeci = novi;
    return koren;
}

Element *modifikujListu(Element *koren)
{
    Element *temp = koren;
    while(temp && temp->sledeci)
    {
        if(strcmp(temp->naziv, temp->sledeci->naziv) == 0)
        {
            if(temp->cena1 == 0)
            {
                temp->cena1 = temp->sledeci->cena1;
            }
            else
            {
                temp->cena2 = temp->sledeci->cena2;
            }
            Element *zaBrisanje = temp->sledeci;
            temp->sledeci = temp->sledeci->sledeci;
            free(zaBrisanje);
        }
        temp = temp->sledeci;
    }
    return koren;
}

void prikazPosebnihArtikalaIterativno(Element *koren, char *string)
{
    while(koren)
    {
        if(strcmp(string, prod1) == 0)
        {
            if(koren->cena2 == 0)
                printf("%15s %5d %5d\n", koren->naziv, koren->cena1, koren->cena2);
        }
        else
        {
            if(koren->cena1 == 0)
                printf("%15s %5d %5d\n", koren->naziv, koren->cena1, koren->cena2);
        }
        koren = koren->sledeci;
    }

}

void prikazPosebnihArtikalaRekurzivno(Element *koren, char *string)
{
    if(koren == NULL)
        return;
    prikazPosebnihArtikalaRekurzivno(koren->sledeci, string);
    if(strcmp(string, prod1) == 0)
    {
        if(koren->cena2 == 0)
            printf("%15s %5d %5d\n", koren->naziv, koren->cena1, koren->cena2);
    }
    else
    {
        if(koren->cena1 == 0)
            printf("%15s %5d %5d\n", koren->naziv, koren->cena1, koren->cena2);
    }
}

/*void daLiIma(Element *koren, char *rec, int *sum1, int *sum2, int *f1, int *f2)
{
    if(koren == NULL)
        return;
    while(koren->sledeci && strcmp(koren->sledeci->naziv, rec) > 0)
    {
        koren = koren->sledeci;
    }
    if(strcmp(koren->sledeci->naziv, rec) == 0)
    {
        if(koren->sledeci->cena1 != 0 && koren->sledeci->cena2 != 0)
        {
            *sum1 += koren->sledeci->cena1;
            *sum2 += koren->sledeci->cena2;
        }
        else if(koren->sledeci->cena1)
        {
            printf
        }
    }
}

void najjeftinijaRadnja(Element *koren)
{
    int f1 = 0, f2 = 0, sum1 = 0, sum2 = 0;
    fgets(buffer, 200, stdin);
    skrati(buffer);
    char *token = strtok(buffer, ",");
    do
    {
        daLiIma
    }while(token = strtok(NULL, ","));
}*/

void ispisListe(Element *koren)
{
    if(koren == NULL)
        return NULL;
    ispisListe(koren->sledeci);
    printf("%15s %5d %5d\n", koren->naziv, koren->cena1, koren->cena2);
}

Element *brisanjeListe(Element *koren)
{
    Element *temp = koren;
    while(temp)
    {
        koren = koren->sledeci;
        free(temp);
        temp = koren;
    }
    return koren;
}

Element *citanjeFajla(Element *koren)
{
    printf("Molimo unesite naziv fajla za citanje:\n");
    fgets(buffer, 60, stdin);
    skrati(buffer);
    FILE *f = fopen(buffer, "r");
    if(f)
    {
        while(fgets(buffer, 200, f))
        {
            skrati(buffer);
            char *token = strtok(buffer, ",");
            char prodavnica[20] = "";
            strcpy(prodavnica, token);
            if(strcmp(prod1, "") == 0)
                strcpy(prod1, token);
            token = strtok(NULL, ",");
            char proizvod[20] = "";
            strcpy(proizvod, token);
            token = strtok(NULL, ",");
            int cena = atoi(token);
            Element *novi = napraviNoviElement(prodavnica, proizvod, cena);
            koren = dodajUListu(koren, novi);
        }
        fclose(f);
        return koren;
    }
    else
    {
        printf("Uneti fajl nije dostupan za citanje, molimo unesite ispravan naziv fajla\n");
    }
    fclose(f);
    return NULL;
}
int main()
{
    int op;
    Element *koren = NULL;
    while(1)
    {
        op = meni();
        switch(op)
        {
        case 1:
            koren = citanjeFajla(koren);
            break;
        case 2:
            koren = modifikujListu(koren);
            ispisListe(koren);
            break;
        case 3:
            //najjeftinijaRadnja(koren);
            break;
        case 4:
            printf("Molimo unesite naziv prodavnice\n");
            char prodavnica[20];
            fgets(prodavnica, 20, stdin);
            skrati(prodavnica);
            printf("Iterativno:\n");
            prikazPosebnihArtikalaIterativno(koren, prodavnica);
            printf("Rekurzivno:\n");
            prikazPosebnihArtikalaRekurzivno(koren, prodavnica);

            break;
        case 5:
            koren = brisanjeListe(koren);
            if(koren == NULL)
                printf("Lista uspesno obrisana");
            return 0;
        }
    }
    koren = brisanjeListe(koren);
    return 0;
}
