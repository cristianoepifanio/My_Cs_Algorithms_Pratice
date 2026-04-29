#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FISIER_BINAR "articole.dat"
#define RAPORT_COMPLET "raport_complet.txt"
#define RAPORT_PARTIAL "raport_partial.txt"

typedef struct {
    int id;
    char denumire[50];
    char categorie[30];
    float pret;
    int cantitate;
    int activ;   // 1 = activ, 0 = sters logic
} Articol;

/* ---------------------------------------------------
   Functii ajutatoare
--------------------------------------------------- */

void citesteSir(char *mesaj, char *sir, int dim) {
    printf("%s", mesaj);
    fgets(sir, dim, stdin);
    sir[strcspn(sir, "\n")] = '\0';
}

void afiseazaArticol(Articol a) {
    printf("\n-----------------------------\n");
    printf("ID         : %d\n", a.id);
    printf("Denumire   : %s\n", a.denumire);
    printf("Categorie  : %s\n", a.categorie);
    printf("Pret       : %.2f\n", a.pret);
    printf("Cantitate  : %d\n", a.cantitate);
    printf("-----------------------------\n");
}

int existaID(const char *numeFisier, int idCautat) {
    FILE *f = fopen(numeFisier, "rb");
    Articol a;

    if (f == NULL) {
        return 0;
    }

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1 && a.id == idCautat) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}

Articol citesteArticolDeLaTastatura() {
    Articol a;

    do {
        printf("ID: ");
        scanf("%d", &a.id);
        getchar();

        if (a.id <= 0) {
            printf("ID-ul trebuie sa fie pozitiv.\n");
        } else if (existaID(FISIER_BINAR, a.id)) {
            printf("Exista deja un articol cu acest ID. Introdu alt ID.\n");
            a.id = -1;
        }
    } while (a.id <= 0);

    citesteSir("Denumire: ", a.denumire, sizeof(a.denumire));
    citesteSir("Categorie: ", a.categorie, sizeof(a.categorie));

    printf("Pret: ");
    scanf("%f", &a.pret);

    printf("Cantitate: ");
    scanf("%d", &a.cantitate);
    getchar();

    a.activ = 1;

    return a;
}

/* ---------------------------------------------------
   1. Creare fisier binar + populare initiala
--------------------------------------------------- */

void creareSiPopulareFisier() {
    FILE *f = fopen(FISIER_BINAR, "wb");
    if (f == NULL) {
        printf("Eroare la crearea fisierului binar.\n");
        return;
    }

    Articol articoleInitiale[] = {
        {1, "Lapte", "Alimente", 7.50f, 40, 1},
        {2, "Paine", "Alimente", 3.20f, 60, 1},
        {3, "Ulei", "Alimente", 11.99f, 25, 1},
        {4, "Caiet", "Papetarie", 8.75f, 100, 1},
        {5, "Pix", "Papetarie", 2.50f, 150, 1}
    };

    int n = sizeof(articoleInitiale) / sizeof(articoleInitiale[0]);

    for (int i = 0; i < n; i++) {
        fwrite(&articoleInitiale[i], sizeof(Articol), 1, f);
    }

    fclose(f);
    printf("Fisierul binar a fost creat si populat cu articole initiale.\n");
}

/* ---------------------------------------------------
   2. Adaugare articol cu posibilitate de repetare
--------------------------------------------------- */

void adaugaArticole() {
    FILE *f = fopen(FISIER_BINAR, "ab");
    if (f == NULL) {
        printf("Fisierul binar nu exista. Creeaza-l mai intai.\n");
        return;
    }

    char raspuns;
    do {
        Articol a = citesteArticolDeLaTastatura();
        fwrite(&a, sizeof(Articol), 1, f);
        printf("Articol adaugat cu succes.\n");

        printf("Mai adaugi un articol? (d/n): ");
        scanf(" %c", &raspuns);
        getchar();
    } while (raspuns == 'd' || raspuns == 'D');

    fclose(f);
}

/* ---------------------------------------------------
   3. Actualizare articol identificat unic
--------------------------------------------------- */

void actualizeazaArticolUnic() {
    FILE *f = fopen(FISIER_BINAR, "rb+");
    if (f == NULL) {
        printf("Fisierul binar nu exista.\n");
        return;
    }

    int idCautat, gasit = 0;
    Articol a;

    printf("Introdu ID-ul articolului de actualizat: ");
    scanf("%d", &idCautat);
    getchar();

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1 && a.id == idCautat) {
            gasit = 1;

            printf("Articol gasit:\n");
            afiseazaArticol(a);

            printf("\nIntrodu noile valori:\n");
            citesteSir("Denumire noua: ", a.denumire, sizeof(a.denumire));
            citesteSir("Categorie noua: ", a.categorie, sizeof(a.categorie));

            printf("Pret nou: ");
            scanf("%f", &a.pret);

            printf("Cantitate noua: ");
            scanf("%d", &a.cantitate);
            getchar();

            fseek(f, -((long)sizeof(Articol)), SEEK_CUR);
            fwrite(&a, sizeof(Articol), 1, f);

            printf("Articol actualizat cu succes.\n");
            break;
        }
    }

    if (!gasit) {
        printf("Articolul cu ID %d nu a fost gasit.\n", idCautat);
    }

    fclose(f);
}

/* ---------------------------------------------------
   4. Actualizare grup de articole
   Exemplu: toate articolele dintr-o categorie
--------------------------------------------------- */

void actualizeazaGrupArticole() {
    FILE *f = fopen(FISIER_BINAR, "rb+");
    if (f == NULL) {
        printf("Fisierul binar nu exista.\n");
        return;
    }

    char categorieCautata[30];
    float procent;
    int gasite = 0;
    Articol a;

    citesteSir("Introdu categoria pentru actualizare grup: ", categorieCautata, sizeof(categorieCautata));
    printf("Introdu procentul de modificare a pretului (ex: 10 pentru +10%%, -5 pentru -5%%): ");
    scanf("%f", &procent);
    getchar();

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1 && strcmp(a.categorie, categorieCautata) == 0) {
            a.pret = a.pret + a.pret * procent / 100.0f;

            fseek(f, -((long)sizeof(Articol)), SEEK_CUR);
            fwrite(&a, sizeof(Articol), 1, f);
            fflush(f);

            gasite++;
            fseek(f, 0, SEEK_CUR);
        }
    }

    if (gasite > 0) {
        printf("Au fost actualizate %d articole din categoria '%s'.\n", gasite, categorieCautata);
    } else {
        printf("Nu exista articole active in categoria '%s'.\n", categorieCautata);
    }

    fclose(f);
}

/* ---------------------------------------------------
   5. Stergere articol identificat unic
   Varianta: stergere logica
--------------------------------------------------- */

void stergeArticol() {
    FILE *f = fopen(FISIER_BINAR, "rb+");
    if (f == NULL) {
        printf("Fisierul binar nu exista.\n");
        return;
    }

    int idCautat, gasit = 0;
    Articol a;

    printf("Introdu ID-ul articolului de sters: ");
    scanf("%d", &idCautat);
    getchar();

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1 && a.id == idCautat) {
            a.activ = 0;

            fseek(f, -((long)sizeof(Articol)), SEEK_CUR);
            fwrite(&a, sizeof(Articol), 1, f);

            gasit = 1;
            printf("Articolul a fost sters logic.\n");
            break;
        }
    }

    if (!gasit) {
        printf("Articolul cu ID %d nu a fost gasit.\n", idCautat);
    }

    fclose(f);
}

/* ---------------------------------------------------
   6. Raport complet in fisier text
--------------------------------------------------- */

void raportComplet() {
    FILE *fbin = fopen(FISIER_BINAR, "rb");
    if (fbin == NULL) {
        printf("Fisierul binar nu exista.\n");
        return;
    }

    FILE *ftxt = fopen(RAPORT_COMPLET, "w");
    if (ftxt == NULL) {
        printf("Eroare la crearea raportului text.\n");
        fclose(fbin);
        return;
    }

    Articol a;
    fprintf(ftxt, "RAPORT COMPLET - TOATE ARTICOLELE ACTIVE\n\n");

    while (fread(&a, sizeof(Articol), 1, fbin) == 1) {
        if (a.activ == 1) {
            fprintf(ftxt, "ID: %d\n", a.id);
            fprintf(ftxt, "Denumire: %s\n", a.denumire);
            fprintf(ftxt, "Categorie: %s\n", a.categorie);
            fprintf(ftxt, "Pret: %.2f\n", a.pret);
            fprintf(ftxt, "Cantitate: %d\n", a.cantitate);
            fprintf(ftxt, "-----------------------------\n");
        }
    }

    fclose(fbin);
    fclose(ftxt);

    printf("Raportul complet a fost generat in fisierul %s\n", RAPORT_COMPLET);
}

/* ---------------------------------------------------
   7. Raport partial dupa 1-2 criterii
   Exemplu: categorie + pret maxim
--------------------------------------------------- */

void raportPartial() {
    FILE *fbin = fopen(FISIER_BINAR, "rb");
    if (fbin == NULL) {
        printf("Fisierul binar nu exista.\n");
        return;
    }

    FILE *ftxt = fopen(RAPORT_PARTIAL, "w");
    if (ftxt == NULL) {
        printf("Eroare la crearea raportului partial.\n");
        fclose(fbin);
        return;
    }

    char categorieCautata[30];
    float pretMaxim;
    Articol a;
    int gasite = 0;

    citesteSir("Introdu categoria: ", categorieCautata, sizeof(categorieCautata));
    printf("Introdu pretul maxim: ");
    scanf("%f", &pretMaxim);
    getchar();

    fprintf(ftxt, "RAPORT PARTIAL\n");
    fprintf(ftxt, "Criterii: categorie = %s, pret <= %.2f\n\n", categorieCautata, pretMaxim);

    while (fread(&a, sizeof(Articol), 1, fbin) == 1) {
        if (a.activ == 1 &&
            strcmp(a.categorie, categorieCautata) == 0 &&
            a.pret <= pretMaxim) {

            fprintf(ftxt, "ID: %d\n", a.id);
            fprintf(ftxt, "Denumire: %s\n", a.denumire);
            fprintf(ftxt, "Categorie: %s\n", a.categorie);
            fprintf(ftxt, "Pret: %.2f\n", a.pret);
            fprintf(ftxt, "Cantitate: %d\n", a.cantitate);
            fprintf(ftxt, "-----------------------------\n");

            gasite++;
        }
    }

    fclose(fbin);
    fclose(ftxt);

    if (gasite > 0) {
        printf("Raportul partial a fost generat in fisierul %s\n", RAPORT_PARTIAL);
    } else {
        printf("Nu exista articole care respecta criteriile. Raportul a fost generat, dar este gol.\n");
    }
}

/* ---------------------------------------------------
   8. Afisare articol unic care indeplineste o conditie
   Exemplu: cautare dupa ID
--------------------------------------------------- */

void afiseazaArticolDupaID() {
    FILE *f = fopen(FISIER_BINAR, "rb");
    if (f == NULL) {
        printf("Fisierul binar nu exista.\n");
        return;
    }

    int idCautat, gasit = 0;
    Articol a;

    printf("Introdu ID-ul articolului cautat: ");
    scanf("%d", &idCautat);
    getchar();

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1 && a.id == idCautat) {
            printf("Articolul gasit este:\n");
            afiseazaArticol(a);
            gasit = 1;
            break;
        }
    }

    if (!gasit) {
        printf("Nu exista articol activ cu ID-ul %d.\n", idCautat);
    }

    fclose(f);
}

/* ---------------------------------------------------
   Optiune suplimentara utila pentru testare
--------------------------------------------------- */

void afiseazaToateArticolelePeEcran() {
    FILE *f = fopen(FISIER_BINAR, "rb");
    if (f == NULL) {
        printf("Fisierul binar nu exista.\n");
        return;
    }

    Articol a;
    int gasite = 0;

    printf("\n=== TOATE ARTICOLELE ACTIVE ===\n");

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1) {
            afiseazaArticol(a);
            gasite++;
        }
    }

    if (gasite == 0) {
        printf("Nu exista articole active.\n");
    }

    fclose(f);
}

/* ---------------------------------------------------
   Meniu principal
--------------------------------------------------- */

void meniu() {
    printf("\n========== MENIU PROIECT ==========\n");
    printf("1. Creare fisier binar si populare initiala\n");
    printf("2. Adaugare articol\n");
    printf("3. Actualizare articol identificat unic\n");
    printf("4. Actualizare grup de articole\n");
    printf("5. Stergere articol identificat unic\n");
    printf("6. Generare raport complet in fisier text\n");
    printf("7. Generare raport partial in fisier text\n");
    printf("8. Afisare articol unic pe ecran\n");
    printf("9. Afisare toate articolele active pe ecran\n");
    printf("0. Iesire\n");
    printf("Alege optiunea: ");
}

int main() {
    int optiune;

    do {
        meniu();
        scanf("%d", &optiune);
        getchar();

        switch (optiune) {
            case 1:
                creareSiPopulareFisier();
                break;
            case 2:
                adaugaArticole();
                break;
            case 3:
                actualizeazaArticolUnic();
                break;
            case 4:
                actualizeazaGrupArticole();
                break;
            case 5:
                stergeArticol();
                break;
            case 6:
                raportComplet();
                break;
            case 7:
                raportPartial();
                break;
            case 8:
                afiseazaArticolDupaID();
                break;
            case 9:
                afiseazaToateArticolelePeEcran();
                break;
            case 0:
                printf("Program inchis.\n");
                break;
            default:
                printf("Optiune invalida.\n");
        }

    } while (optiune != 0);

    return 0;
}