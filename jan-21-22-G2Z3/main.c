#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element
{
    char ime[20];
    int visina;
    int tezina;
    struct Element* desni, *levi;
}Element;

char buffer[255];

void skrati(char *string)
{
    if(string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = 0;
}

int meni()
{
    printf("MENI:\nOpcija 1: Unos fajla\nOpcija 2: Ispis stabla\nOpcija 3: Ispis najvise i najnize osobe\n");
    printf("Opcija 4: Ispis osoba laksih od odredjene tezine\nOpcija 5: Brisanje stabla i prekid izvrsavanja programa\n");
    fgets(buffer, 5, stdin);
    skrati(buffer);
    int op = atoi(buffer);
    while(1)
    {
        if(op >= 1 && op <= 5)
        {
            return op;
        }
        else
        {
            printf("Neispravan unos\n");
        }
    }

}

Element * napraviNoviElement(char *ime, int visina, int tezina)
{
    Element *novi = (Element *)calloc(1, sizeof(Element));
    strcpy(novi->ime, ime);
    novi->visina = visina;
    novi->tezina = tezina;
    return novi;
}

Element *dodajSortirano(Element *koren, Element *novi)
{
    if(koren == NULL)
        return novi;
    if(strcmp(koren->ime, novi->ime) < 0)
        koren->levi = dodajSortirano(koren->levi, novi);
    else
        koren->desni = dodajSortirano(koren->desni, novi);
    return koren;
}

void nadjiNajviseg(Element *koren, Element **najvisi, Element **najnizi)
{
    /**
    if (koren) {
        if (*najvisi == NULL || (*najvisi)->visina < koren->visina) {
            *najvisi = koren;
        }
        if (*najnizi == NULL || (*najnizi)->visina > koren->visina) {
            *najnizi = koren;
        }
        nadjiNajvisuINajnizuOsobu(koren->levi, najvisi, najnizi);
        nadjiNajvisuINajnizuOsobu(koren->desni, najvisi, najnizi);
    }*/
    if(koren)
    {
        if(*najvisi == NULL || koren->visina > (*najvisi)->visina)
        {
            *najvisi = koren;
        }
        if(*najnizi == NULL || (*najnizi)->visina > koren->visina)
        {
            *najnizi = koren;
        }
        nadjiNajviseg(koren->desni, najvisi, najnizi);
        nadjiNajviseg(koren->levi, najvisi, najnizi);
    }
}

void najvisiINajnizi(Element *koren)
{
    Element *najnizi = NULL;
    Element *najvisi = NULL;
    nadjiNajviseg(koren, &najvisi, &najnizi);
    printf("Najvisi: %12s %5d %5d\n", najvisi->ime, najvisi->visina, najvisi->tezina);
    printf("Najnizi: %12s %5d %5d\n", najnizi->ime, najnizi->visina, najnizi->tezina);
}

void ispisStabla(Element *koren)
{
    if(koren)
    {
        ispisStabla(koren->levi);
        printf("%12s %5d %5d\n", koren->ime, koren->visina, koren->tezina);
        ispisStabla(koren->desni);
    }
}

Element *brisanjeStabla(Element *koren)
{
    if(koren)
    {
        brisanjeStabla(koren->levi);
        brisanjeStabla(koren->desni);
        free(koren);
    }
    return koren;
}

Element *ucitavanjeFajla(Element *koren)
{
    printf("Unesite naziv fajla:\n");
    fgets(buffer, 255, stdin);
    skrati(buffer);
    FILE *f = fopen(buffer, "r");
    if(f == NULL)
    {
        printf("Fajl nije dostupan za citanje");
    }
    else
    {
        while(fgets(buffer, 255, f))
        {
            skrati(buffer);
            char *token = strtok(buffer, ",");
            char ime[20];
            strcpy(ime, token);
            token = strtok(NULL, ",");
            int visina = atoi(token);
            token = strtok(NULL, ",");
            int tezina = atoi(token);
            Element *novi = napraviNoviElement(ime, visina, tezina);
            koren = dodajSortirano(koren, novi);
        }
    }
    fclose(f);
    return koren;
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
            koren = ucitavanjeFajla(koren);
            break;
        case 2:
            ispisStabla(koren);
            break;
        case 3:
            najvisiINajnizi(koren);
            /*Element *najvisi = NULL;
            Element *najnizi = NULL;
            Element *temp = koren;
            nadjiNajviseg(temp, najvisi, najnizi);
            */
            break;
        case 4:
            break;
        case 5:
            ispisStabla(koren);
            koren = brisanjeStabla(koren);
            if(koren == NULL)
                printf("Stablo je uspesno obrisano");
            else
                ispisStabla(koren);
            return 0;
        }
    }
    return 0;
}
