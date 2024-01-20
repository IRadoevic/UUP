#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element
{
    int redniBroj;
    char predmet[5];
    int nizOcena[6];
    int brojOcena;
    struct Element *sledeci;
}Element;
char buffer[100];
void skrati(char *string)
{
    if(string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = 0;
}
int meni()
{
    printf("MENI:\nOpcija 1: Ucitavanje fajla\nOpcija 2: Broj ocena na predmet\nOpcija 3: Dodavanje ocena\nOpcija 4: Brisanje i kraj\n");
    while(1)
    {
        int op;
        fgets(buffer, 100, stdin);
        skrati(buffer);
        op = atoi(buffer);
        if(op >= 1 && op <= 4)
            return op;
        printf("Neispravan ulaz, molimo unesite broj izmedju 1 i 4\n");
    }
}

Element *napraviNoviElement(int redniBroj, char *predmet, int nizOcena[5], int brOcena)
{
    Element *novi = (Element *)calloc(1, sizeof(Element));
    novi->redniBroj = redniBroj;
    strcpy(novi->predmet, predmet);
    for(int i = 0; i < brOcena; i++)
    {
        novi->nizOcena[i] = nizOcena[i];
    }
    novi->brojOcena = brOcena;
    //printf("%4d %5s\n", novi->redniBroj, novi->predmet);
    return novi;
}

Element *dodajUListu(Element *glava, Element *novi)
{
    if(glava == NULL)
        return novi;
    if(glava->redniBroj > novi->redniBroj || (glava->redniBroj == novi->redniBroj && strcmp(glava->predmet, novi->predmet) > 0))
    {
       novi->sledeci = glava;
       return novi;
    }
    Element *temp = glava;
    while(temp->sledeci && temp->sledeci->redniBroj < novi->redniBroj)
        temp = temp->sledeci;
    while(temp->sledeci && temp->sledeci->redniBroj == novi->redniBroj && strcmp(temp->sledeci->predmet, novi->predmet) < 0)
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
        printf("%4d %5s", temp->redniBroj, temp->predmet);
        for(int i = 0; i < temp->brojOcena; i++)
        {
            printf(" %3d", temp->nizOcena[i]);
        }
        printf("\n");
        temp = temp->sledeci;
    }
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

void brojOcenaIterativno(Element *glava)
{
    printf("Molimo unesite predmet i raspon ocena u formatu 'predmet donja granica gornja granica'");
    printf("\nZa matematiku i ocene od 3 do 5 bi to bilo 'MAT 3 5'\n");
    fgets(buffer, 50, stdin);
    skrati(buffer);
    char predmet[5] = "";
    int donjaGranica, gornjaGranica;
    char *token = strtok(buffer, " ");
    strcpy(predmet, token);
    token = strtok(NULL, " ");
    donjaGranica = atoi(token);
    token = strtok(NULL, " ");
    gornjaGranica = atoi(token);
    int counter = 0;
    Element *temp = glava;
    while(temp)
    {
        if(strcmp(temp->predmet, predmet) == 0)
        {
            for(int i = 0; i < temp->brojOcena; i++)
            {
                if(temp->nizOcena[i] >= donjaGranica && temp->nizOcena[i] <= gornjaGranica)
                    counter++;
            }
        }
        temp = temp->sledeci;
    }
    printf("Broj ocena u intervalu %d %d iz predmeta %s je %d\n", donjaGranica, gornjaGranica, predmet, counter);
    printf("A rekurzivno je %d\n", brojOcenaRekurzivno(predmet, donjaGranica, gornjaGranica, glava));
}

int brojOcenaRekurzivno(char *predmet, int donjaGranica, int gornjaGranica, Element *temp)
{
    if(temp == NULL)
        return 0;
    int a = 0;
    if(strcmp(temp->predmet, predmet) == 0)
    {
        for(int i = 0; i < temp->brojOcena; i++)
        {
            if(temp->nizOcena[i] >= donjaGranica && temp->nizOcena[i] <= gornjaGranica)
                a++;
        }
    }
    return a + brojOcenaRekurzivno(predmet, donjaGranica, gornjaGranica, temp->sledeci);
}

Element *dodavanjeOceneUceniku(Element *glava)
{
    printf("Molimo unesite redni broj ucenika, naziv predmeta i ocenu koju zelite da dodate\n");
    printf("Ukoliko biste zeleli da 4. uceniku iz engleskog dodate ocenu 3, format bi bio '4 ENG 3'\n");
    fgets(buffer, 50, stdin);
    skrati(buffer);
    char *token = strtok(buffer, " ");
    int redniBroj = atoi(buffer);
    token = strtok(NULL, " ");
    char predmet[5] = "";
    strcpy(predmet, token);
    token = strtok(NULL, " ");
    int ocena = atoi(token);

    Element *temp = glava;
    if(glava == NULL)
    {
        printf("Lista je prazna");
        return;
    }
    while(temp->sledeci && temp->sledeci->redniBroj < redniBroj)
        temp = temp->sledeci;
    while(temp->sledeci && temp->sledeci->redniBroj == redniBroj && strcmp(temp->sledeci->predmet, predmet) < 0)
        temp = temp->sledeci;
    if(temp->sledeci && strcmp(temp->sledeci->predmet, predmet) == 0)
    {
        if(temp->sledeci->brojOcena < 5)
        {
            temp->sledeci->nizOcena[temp->brojOcena] = ocena;
            temp->sledeci->brojOcena = temp->brojOcena + 1;
        }
        else
        {
            printf("Ucenik sa rednim brojem %d vec ima maksimalan broj ocena iz predmeta %s\n", redniBroj, predmet);
        }
    }
    else
    {
        printf("Ne postoje ocene iz predmeta %s za ucenika sa rednim brojem %d\n", predmet, redniBroj);
    }
    ispisListe(glava);
    return glava;
}

Element *citanjeFajla(Element *glava)
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
            int redniBroj = atoi(buffer);
            token = strtok(NULL, " ");
            char predmet[20] = "";
            strcpy(predmet, token);
            int nizOcena[5];
            int brOcena = 0;
            while(token = strtok(NULL, " "))
            {
                nizOcena[brOcena] = atoi(token);
                brOcena++;
            }
            Element *novi = napraviNoviElement(redniBroj, predmet, nizOcena, brOcena);
            glava = dodajUListu(glava, novi);
        }
        fclose(f);
        return glava;
    }
    else
    {
        printf("Molimo unesite ispravan naziv\n");
    }
    fclose(f);
    return glava;
}

int main()
{
    int op;
    Element *glava = NULL;
    while(1)
    {
        op = meni();
        switch(op)
        {
        case 1:
            glava = citanjeFajla(glava);
            ispisListe(glava);
            break;
        case 2:
            brojOcenaIterativno(glava);
            break;
        case 3:
            glava = dodavanjeOceneUceniku(glava);
            break;
        case 4:
            glava = brisanjeListe(glava);
            if(glava == NULL)
                printf("Lista je uspesno obrisana");
            return 0;
        }
    }
    glava = brisanjeListe(glava);
    return 0;
}
