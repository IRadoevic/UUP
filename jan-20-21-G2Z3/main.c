#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element
{
    int redniBroj;
    char predmet[5];
    int ocena;
    char datum[15];
    int datumVrednost;
    struct Element *sledeci;
}Element;

typedef struct NoviElement
{
    double avg1, avg2, avg3, avg4, avg5, avg6;
    int redniBrojUcenika;
    struct NoviElement *sledeci;
}NoviElement;



char buffer[200];
char mat[5] = "MAT";
char srp[5] = "SRP";
char eng[5] = "ENG";
char pid[5] = "PID";
char lik[5] = "LIK";
char muz[5] = "MUZ";
void skrati(char *string)
{
    if(string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = 0;
}

Element *napraviNoviElement(int redniBroj, char *predmet, int ocena, char *datum)
{
    Element *novi = (Element *)calloc(1, sizeof(Element));
    novi->redniBroj = redniBroj;
    strcpy(novi->predmet, predmet);
    novi->ocena = ocena;
    strcpy(novi->datum, datum);
    char *token = strtok(datum, "-");
    novi->datumVrednost = atoi(token) * 10000;
    token = strtok(NULL, "-");
    novi->datumVrednost = novi->datumVrednost + atoi(token)*100;
    token = strtok(NULL, "-");
    novi->datumVrednost = novi->datumVrednost + atoi(token);
    //printf("%2d %s %d %s %12d\n", novi->redniBroj, novi->predmet, novi->ocena, novi->datum, novi->datumVrednost);
    return novi;
}

Element *dodajUListu(Element *glava, Element *novi)
{
    if(glava == NULL)
        return novi;
    else if(glava->redniBroj > novi->redniBroj || (glava->redniBroj == novi->redniBroj && glava->datumVrednost > novi->datumVrednost))
    {
        novi->sledeci = glava;
        return novi;
    }
    Element *temp = glava;
    while(temp->sledeci && temp->sledeci->redniBroj < novi->redniBroj)
        temp = temp->sledeci;
    while(temp->sledeci && temp->sledeci->redniBroj == novi->redniBroj && temp->sledeci->datumVrednost > novi->datumVrednost)
        temp = temp->sledeci;
    novi->sledeci = temp->sledeci;
    temp->sledeci = novi;
    return glava;

}

void ispisListe(Element *glava)
{
    Element *temp = glava;
    while(temp)
    {
        printf("%2d %s %d %s %12d\n", temp->redniBroj, temp->predmet, temp->ocena, temp->datum, temp->datumVrednost);
        temp = temp->sledeci;
    }
}

Element *brisanjeIzListe(Element *glava)
{
    printf("Molimo unesite datum za koji zelite da obrisete ocenu\n(datum 4. januar 2022. treba uneti u formatu 2022-01-04)\n");
    fgets(buffer, 50, stdin);
    skrati(buffer);
    Element *trenutni = glava;
    Element *sledeci = glava->sledeci;
    if(glava == NULL)
        printf("Lista je prazna - brisanje nije moguce");
    if(strcmp(glava->datum, buffer) == 0)
    {
        glava = glava->sledeci;
        free(trenutni);
        trenutni = glava;
    }
    while(sledeci)
    {
        if(strcmp(sledeci->datum, buffer) == 0)
        {
            trenutni->sledeci = sledeci->sledeci;
            free(sledeci);
            sledeci = trenutni->sledeci;
            continue;
        }
        sledeci = sledeci->sledeci;
        trenutni = trenutni->sledeci;
    }
    ispisListe(glava);
    return glava;
}

Element *brisanjeListe(Element *glava)
{
    Element *temp = glava;
    while(temp)
    {
        glava = glava->sledeci;
        free(temp);
        temp = glava;
    }
    return glava;
}

NoviElement *napravi(int redniBroj, double avg1, double avg2, double avg3, double avg4, double avg5, double avg6)
{
    NoviElement *novi = (NoviElement *)calloc(1, sizeof(NoviElement));
    novi->redniBrojUcenika = redniBroj;
    novi->avg1 = avg1;
    novi->avg2 = avg2;
    novi->avg3 = avg3;
    novi->avg4 = avg4;
    novi->avg5 = avg5;
    novi->avg6 = avg6;
    printf("%d %6f %6f %6f %6f %6f %6f", novi->redniBrojUcenika, novi->avg1, novi->avg2, novi->avg3, novi->avg4, novi->avg5, novi->avg6);
    printf(", ukupan prosek = %6f\n", (avg1+avg2+avg3+avg4+avg5+avg6) / 6);
    free(novi);
    return novi;
}

NoviElement *zakljucivanjeOcena(NoviElement *novaLista, Element *glava)
{
    Element *temp = glava;
    int sum1 = 0;
    int nmb1 = 0;
    int sum2 = 0;
    int nmb2 = 0;
    int sum3 = 0;
    int nmb3 = 0;
    int sum4 = 0, nmb4 = 0, sum5 = 0, nmb5 = 0, sum6 = 0, nmb6 = 0;
    while(temp)
    {
        while(temp->sledeci && temp->sledeci->redniBroj == temp->redniBroj)
        {
            if(strcmp(temp->predmet, mat) == 0)
            {
                sum1 += temp->ocena;
                nmb1++;

            }
            else if(strcmp(temp->predmet, srp) == 0)
            {
                sum2 += temp->ocena;
                nmb2++;

            }
            else if(strcmp(temp->predmet, eng) == 0)
            {
                sum3 += temp->ocena;
                nmb3++;

            }
            else if(strcmp(temp->predmet, pid) == 0)
            {
                sum4 += temp->ocena;
                nmb4++;

            }
            else if(strcmp(temp->predmet, lik) == 0)
            {
                sum5 += temp->ocena;
                nmb5++;

            }
            else if(strcmp(temp->predmet, muz) == 0)
            {
                sum6 += temp->ocena;
                nmb6++;

            }
            temp = temp->sledeci;
        }
        NoviElement *noviEl = napravi(temp->redniBroj, 1.0*sum1/nmb1, 1.0*sum2/nmb2, 1.0*sum3/nmb3, 1.0*sum4/nmb4, 1.0*sum5/nmb5, 1.0*sum6/nmb6);
        //novaLista = dodajNaNovu(novaLista, noviEl);
        temp = temp->sledeci;
    }
}

Element *ucitavanjeFajla(Element *glava)
{
    printf("Molimo unesite naziv fajla\n");
    fgets(buffer, 100, stdin);
    skrati(buffer);
    FILE *f = fopen(buffer, "r");
    if(f)
    {
        while(fgets(buffer, 100, f))
        {
            skrati(buffer);
            char *token = strtok(buffer, " ");
            int redniBroj = atoi(token);
            token = strtok(NULL, " ");
            char predmet[5] = "";
            strcpy(predmet, token);
            token = strtok(NULL, " ");
            int ocena = atoi(token);
            token = strtok(NULL, " ");
            char datum[15] = "";
            strcpy(datum, token);
            Element *novi = napraviNoviElement(redniBroj, predmet, ocena, datum);
            glava = dodajUListu(glava, novi);
        }
    }
    else
    {
        printf("Uneti fajl nije dostupan za citanje, molimo pokusajte ponovo\n");
    }
    fclose(f);
    return glava;
}

int meni()
{
    while(1)
    {
        printf("MENI:\nOpcija 1: Ucitavanje fajla i unos u listu\nOpcija 2: Brisanje ocena za datum\n");
        printf("Opcija 3: Zakljucivanje ocena\nOpcija 4: Brisanje liste i izlazak iz programa\n");
        fgets(buffer, 100, stdin);
        skrati(buffer);
        int op = atoi(buffer);
        if(op >= 1 && op <= 4)
            return op;
        else
            printf("Neispravan ulaz, molimo unesite broj izmedju 1 i 4\n");
    }
}

int main()
{
    int op;
    Element *glava = NULL;
    NoviElement *novaLista = NULL;
    while(1)
    {
        op = meni();
        switch(op)
        {
        case 1:
            glava = ucitavanjeFajla(glava);
            ispisListe(glava);
            break;
        case 2:
            glava = brisanjeIzListe(glava);
            break;
        case 3:
            novaLista = zakljucivanjeOcena(novaLista, glava);
            break;
        case 4:
            glava = brisanjeListe(glava);
            if(glava == NULL)
                printf("Lista uspesno obrisana");
            return 0;
        }
    }
    glava = brisanjeListe(glava);
    return 0;
}
