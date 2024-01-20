#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element
{
    char prodavnica[30];
    char naziv[30];
    int cena;
    int brojKomada;
    struct Element *sledeci;
}Element;

char buffer[150];
void skrati(char *string)
{
    if(string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = 0;
}

Element *napraviElement(char *prodavnica, char *proizvod, int cena, int brojProizvoda)
{
    Element *novi = (Element *)calloc(1, sizeof(Element));
    strcpy(novi->prodavnica, prodavnica);
    strcpy(novi->naziv, proizvod);
    novi->cena = cena;
    novi->brojKomada = brojProizvoda;
    //printf("%8s %18s %3d %3d\n", novi->prodavnica, novi->naziv, novi->cena, novi->brojKomada);
    return novi;
}

Element *dodajUListu(Element *glava, Element *novi)
{
    if(glava == NULL)
        return novi;
    if(strcmp(glava->naziv, novi->naziv) > 0 || (strcmp(glava->naziv, novi->naziv) == 0 && glava->brojKomada > novi->brojKomada))
    {
        novi->sledeci = glava;
        return novi;
    }
    Element *temp = glava;
    while(temp->sledeci && strcmp(temp->sledeci->naziv, novi->naziv) < 0)
        temp = temp->sledeci;
    while(temp->sledeci && strcmp(temp->sledeci->naziv, novi->naziv) == 0 && temp->sledeci->brojKomada < novi->brojKomada)
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
        printf("%8s %18s %3d %3d\n", temp->prodavnica, temp->naziv, temp->cena, temp->brojKomada);
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
}

Element *brisanjeIzListe(Element *glava)
{
    printf("Molimo unesite zeljenu cenu:\n");
    int cena;
    scanf("%d", &cena);
    Element *temp = glava;
    while(temp)
    {
        Element *tempPrim = temp;
        int flag = 1;
        while(tempPrim->sledeci && strcmp(tempPrim->sledeci->naziv, temp->naziv) == 0)
        {
            if(tempPrim->cena < cena)
                flag = 0;
            tempPrim = tempPrim->sledeci;
        }
        if(flag)
        {
            //
            Element *tempPrim = temp;
            Element *zaBrisanje = temp;
            while(tempPrim->sledeci && strcmp(tempPrim->sledeci->naziv, temp->naziv) == 0)
            {
                temp->sledeci = tempPrim->sledeci;
                zaBrisanje = tempPrim;
                tempPrim = tempPrim->sledeci;
                free(zaBrisanje);
            }
            printf("Treba izbrisati sve artike %s\n", temp->naziv);
        }
        temp = tempPrim->sledeci;
    }
    return glava;
}

Element *citanjeFajla(Element *glava)
{
    printf("Molimo unesite naziv fajla\n");
    fgets(buffer, 30, stdin);
    skrati(buffer);
    FILE *f = fopen(buffer, "r");
    if(f)
    {
        while(fgets(buffer, 100, f))
        {
            skrati(buffer);
            char *token = strtok(buffer, ",");
            char prodavnica[20] = "";
            strcpy(prodavnica, token);
            token = strtok(NULL, ",");
            char proizvod[30] = "";
            strcpy(proizvod, token);
            token = strtok(NULL, ",");
            int cena = atoi(token);
            token = strtok(NULL, ",");
            int brojProizvoda = atoi(token);
            Element *novi = napraviElement(prodavnica, proizvod, cena, brojProizvoda);
            glava = dodajUListu(glava, novi);
        }
    }
    else
    {
        printf("Uneti fajl nije dostupan, molimo pokusajte ponovo\n");
    }
    fclose(f);
    return glava;
}
int meni()
{
    printf("MENI:\nOpcija 1: Ucitavanje podataka\nOpcija 2: Ispis liste\nOpcija 3: Brisanje unosa\n");
    printf("Opcija 4: Ipis prodavnica sa manjim lagerom\nOpcija 5: Izlaz iz programa i brisanje liste\n");
    int op;
    while(1)
    {
        fgets(buffer, 100, stdin);
        skrati(buffer);
        op = atoi(buffer);
        if(op >= 1 && op <= 5)
            return op;
        printf("Neispravan unos, molimo unesite broj izmedju 1 i 5\n");
    }

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
            break;
        case 2:
            ispisListe(glava);
            break;
        case 3:
            glava = brisanjeIzListe(glava);
            ispisListe(glava);
            break;
        case 4:
            break;
        case 5:
            glava = brisanjeListe(glava);
            if(glava == NULL)
                printf("Lista uspesno obrisana");
            return 0;
        }
    }
    return 0;
}
