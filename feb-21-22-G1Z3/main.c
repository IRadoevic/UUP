#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element
{
    char opstina[20];
    char teretana[20];
    int sprave;
    int kardio;
    struct Element *desni, *levi;
}Element;

Element *napraviNoviElement(char *opstina, char *teretana, int sprave, int kardio)
{
    Element *novi = (Element *)calloc(1, sizeof(Element));
    strcpy(novi->opstina, opstina);
    strcpy(novi->teretana, teretana);
    novi->sprave = sprave;
    novi->kardio = kardio;
    return novi;
}

Element *dodajSortirano(Element *koren, Element *novi)
{
    if(koren == NULL)
        return novi;
    if(strcmp(koren->opstina, novi->opstina) < 0)
    {
        koren->desni = dodajSortirano(koren->desni, novi);
    }
    else
    {
        koren->levi = dodajSortirano(koren->levi, novi);
    }
    return koren;
}

void ispisStabla(Element *koren)
{
    if(koren)
    {
        ispisStabla(koren->desni);
        printf("%16s %20s %5d %5d\n", koren->opstina, koren->teretana, koren->sprave, koren->kardio);
        ispisStabla(koren->levi);
    }
}

void ispisTeretana(Element *koren, int broj)
{
    if(koren)
    {
        if((koren->sprave - koren->kardio) > broj)
            printf("%20s %5d\n", koren->teretana, koren->sprave);
        ispisTeretana(koren->levi, broj);
        ispisTeretana(koren->desni, broj);
    }
    return;
}

void ispisOpstina(Element *koren, char *string)
{
    if(koren)
    {
        int pozicija = strlen(koren->opstina) - strlen(string);
        if(strcmp(koren->opstina + pozicija, string) == 0)
            printf("%16s %20s %5d %5d\n", koren->opstina, koren->teretana, koren->sprave, koren->kardio);
        ispisOpstina(koren->levi, string);
        ispisOpstina(koren->desni, string);
    }
}

Element *brisanjeStabla(Element *koren)
{
    if(koren)
    {
        brisanjeStabla(koren->desni);
        brisanjeStabla(koren->levi);
        free(koren);
    }
    return NULL;
}

char buffer[200];

void skrati(char *string)
{
    if(string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = 0;
}

int meni()
{
    printf("MENI:\nOpcija 1: Ucitavanje podataka\nOpcija 2: Ispis podataka\nOpcija 3: Ispis teretana koje ispunjavaju kriterijum\n");
    printf("Opcija 4: Ispis sprava u odredjenoj opstini\nOpcija 5:Brisanje stabla i zavrsetak programa\n");
    while(1)
    {
        fgets(buffer, 200, stdin);
        skrati(buffer);
        int op = atoi(buffer);
        if(op >= 1 && op <= 5)
            return op;
        else
            printf("Neispravan unos, molimo unesite broj od 1 do 5\n");
    }
}

Element *citanjeFajla(Element *koren)
{
    char fajl[] = "fajl.txt";
    FILE *f = fopen(fajl, "r");
    if(f)
    {
        while(fgets(buffer, 250, f))
        {
            skrati(buffer);
            char *token = strtok(buffer, "-");
            char opstina[20];
            strcpy(opstina, token);
            token = strtok(NULL, "-");
            char teretana[20];
            strcpy(teretana, token);
            token = strtok(NULL, "-");
            int sprave = atoi(token);
            token = strtok(NULL, "-");
            int kardio = atoi(token);
            Element *novi = napraviNoviElement(opstina, teretana, sprave, kardio);
            koren = dodajSortirano(koren, novi);
        }
        fclose(f);
        return koren;
    }
    else
    {
        printf("Uneti fajl nije dostupan");
        fclose(f);
        return NULL;
    }
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
            ispisStabla(koren);
            break;
        case 3:
            printf("Unesite broj sprava:\n");
            int brojSprava;
            scanf("%d", &brojSprava);
            Element *temp = koren;
            ispisTeretana(temp, brojSprava);
            break;
        case 4:
            printf("Unesite string:\n");
            char string[20];
            fgets(string, 20, stdin);
            skrati(string);
            ispisOpstina(koren, string);
            break;
        case 5:
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
