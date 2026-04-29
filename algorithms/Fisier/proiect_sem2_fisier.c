#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FISIER_BINAR "stocuri.dat"
#define RAPORT_COMPLET "raport_complet.txt"
#define RAPORT_PARTIAL "raport_partial.txt"

typedef struct {
    int id;
    char denumire[50];
    char categorie[30];
    float pret;
    int cantitate;
    int activ; // 1 = activ, 0 = sters logic
} Articol;

void golesteBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void citesteSir(char mesaj[], char sir[], int dimensiune) {
    printf("%s", mesaj);
    fgets(sir, dimensiune, stdin);
    sir[strcspn(sir, "\n")] = '\0';
}

void afiseazaArticol(Articol a) {
    printf("\nID: %d", a.id);
    printf("\nDenumire: %s", a.denumire);
    printf("\nCategorie: %s", a.categorie);
    printf("\nPret: %.2f lei", a.pret);
    printf("\nCantitate: %d bucati", a.cantitate);
    printf("\nValoare stoc: %.2f lei\n", a.pret * a.cantitate);
}

int existaID(int id) {
    FILE *f = fopen(FISIER_BINAR, "rb");
    Articol a;

    if (f == NULL) {
        return 0;
    }

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1 && a.id == id) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}

Articol citireArticol() {
    Articol a;

    do {
        printf("ID articol: ");
        scanf("%d", &a.id);
        golesteBuffer();

        if (a.id <= 0) {
            printf("ID-ul trebuie sa fie pozitiv.\n");
        } else if (existaID(a.id)) {
            printf("Exista deja un articol cu acest ID.\n");
            a.id = -1;
        }

    } while (a.id <= 0);

    citesteSir("Denumire articol: ", a.denumire, 50);
    citesteSir("Categorie articol: ", a.categorie, 30);

    do {
        printf("Pret: ");
        scanf("%f", &a.pret);
        golesteBuffer();

        if (a.pret <= 0) {
            printf("Pretul trebuie sa fie pozitiv.\n");
        }
    } while (a.pret <= 0);

    do {
        printf("Cantitate: ");
        scanf("%d", &a.cantitate);
        golesteBuffer();

        if (a.cantitate < 0) {
            printf("Cantitatea nu poate fi negativa.\n");
        }
    } while (a.cantitate < 0);

    a.activ = 1;
    return a;
}

void creareFisier() {
    FILE *f = fopen(FISIER_BINAR, "wb");

    if (f == NULL) {
        printf("Eroare la crearea fisierului binar.\n");
        return;
    }

    Articol v[] = {
        {1, "Laptop Lenovo", "Electronice", 3200.00f, 10, 1},
        {2, "Mouse Logitech", "Electronice", 120.00f, 35, 1},
        {3, "Caiet A4", "Papetarie", 8.50f, 100, 1},
        {4, "Pix albastru", "Papetarie", 2.50f, 200, 1},
        {5, "Apa plata", "Alimente", 3.20f, 150, 1},
        {6, "Cafea", "Alimente", 28.90f, 45, 1}
    };

    int n = sizeof(v) / sizeof(v[0]);

    for (int i = 0; i < n; i++) {
        fwrite(&v[i], sizeof(Articol), 1, f);
    }

    fclose(f);

    printf("Fisierul binar a fost creat si populat cu articole initiale.\n");
}

void adaugareArticole() {
    FILE *f = fopen(FISIER_BINAR, "ab");

    if (f == NULL) {
        printf("Fisierul nu exista. Alegeti mai intai optiunea 1.\n");
        return;
    }

    char raspuns;

    do {
        Articol a = citireArticol();
        fwrite(&a, sizeof(Articol), 1, f);

        printf("Articol adaugat cu succes.\n");
        printf("Doriti sa mai adaugati un articol? (d/n): ");
        scanf(" %c", &raspuns);
        golesteBuffer();

    } while (raspuns == 'd' || raspuns == 'D');

    fclose(f);
}

void actualizareArticolUnic() {
    FILE *f = fopen(FISIER_BINAR, "rb+");

    if (f == NULL) {
        printf("Fisierul nu exista.\n");
        return;
    }

    int idCautat, gasit = 0;
    Articol a;

    printf("Introduceti ID-ul articolului de modificat: ");
    scanf("%d", &idCautat);
    golesteBuffer();

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1 && a.id == idCautat) {
            gasit = 1;

            printf("Articol gasit:");
            afiseazaArticol(a);

            printf("\nIntroduceti noile date:\n");

            citesteSir("Noua denumire: ", a.denumire, 50);
            citesteSir("Noua categorie: ", a.categorie, 30);

            printf("Noul pret: ");
            scanf("%f", &a.pret);
            golesteBuffer();

            printf("Noua cantitate: ");
            scanf("%d", &a.cantitate);
            golesteBuffer();

            fseek(f, -sizeof(Articol), SEEK_CUR);
            fwrite(&a, sizeof(Articol), 1, f);

            printf("Articolul a fost actualizat cu succes.\n");
            break;
        }
    }

    if (!gasit) {
        printf("Nu exista articol activ cu ID-ul %d.\n", idCautat);
    }

    fclose(f);
}

void actualizareGrupArticole() {
    FILE *f = fopen(FISIER_BINAR, "rb+");

    if (f == NULL) {
        printf("Fisierul nu exista.\n");
        return;
    }

    char categorie[30];
    float procent;
    int nrActualizate = 0;
    Articol a;

    citesteSir("Introduceti categoria pentru actualizare: ", categorie, 30);

    printf("Introduceti procentul de modificare a pretului: ");
    printf("\nExemplu: 10 pentru scumpire cu 10%%, -5 pentru reducere cu 5%%\n");
    printf("Procent: ");
    scanf("%f", &procent);
    golesteBuffer();

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1 && strcmp(a.categorie, categorie) == 0) {
            a.pret = a.pret + a.pret * procent / 100;

            fseek(f, -sizeof(Articol), SEEK_CUR);
            fwrite(&a, sizeof(Articol), 1, f);
            fflush(f);

            nrActualizate++;

            fseek(f, 0, SEEK_CUR);
        }
    }

    printf("Au fost actualizate %d articole.\n", nrActualizate);

    fclose(f);
}

void stergereArticol() {
    FILE *f = fopen(FISIER_BINAR, "rb+");

    if (f == NULL) {
        printf("Fisierul nu exista.\n");
        return;
    }

    int idCautat, gasit = 0;
    Articol a;

    printf("Introduceti ID-ul articolului de sters: ");
    scanf("%d", &idCautat);
    golesteBuffer();

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1 && a.id == idCautat) {
            a.activ = 0;

            fseek(f, -sizeof(Articol), SEEK_CUR);
            fwrite(&a, sizeof(Articol), 1, f);

            gasit = 1;
            printf("Articolul a fost sters logic.\n");
            break;
        }
    }

    if (!gasit) {
        printf("Articolul nu a fost gasit.\n");
    }

    fclose(f);
}

void raportComplet() {
    FILE *f = fopen(FISIER_BINAR, "rb");
    FILE *r = fopen(RAPORT_COMPLET, "w");

    if (f == NULL || r == NULL) {
        printf("Eroare la deschiderea fisierelor.\n");
        return;
    }

    Articol a;
    float valoareTotala = 0;

    fprintf(r, "RAPORT COMPLET - GESTIUNEA STOCURILOR\n\n");

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1) {
            fprintf(r, "ID: %d\n", a.id);
            fprintf(r, "Denumire: %s\n", a.denumire);
            fprintf(r, "Categorie: %s\n", a.categorie);
            fprintf(r, "Pret: %.2f lei\n", a.pret);
            fprintf(r, "Cantitate: %d\n", a.cantitate);
            fprintf(r, "Valoare stoc: %.2f lei\n", a.pret * a.cantitate);
            fprintf(r, "-----------------------------\n");

            valoareTotala += a.pret * a.cantitate;
        }
    }

    fprintf(r, "\nValoarea totala a stocului: %.2f lei\n", valoareTotala);

    fclose(f);
    fclose(r);

    printf("Raportul complet a fost generat in fisierul %s.\n", RAPORT_COMPLET);
}

void raportPartial() {
    FILE *f = fopen(FISIER_BINAR, "rb");
    FILE *r = fopen(RAPORT_PARTIAL, "w");

    if (f == NULL || r == NULL) {
        printf("Eroare la deschiderea fisierelor.\n");
        return;
    }

    char categorie[30];
    int cantitateMinima;
    Articol a;
    int gasite = 0;

    citesteSir("Introduceti categoria cautata: ", categorie, 30);

    printf("Introduceti cantitatea minima: ");
    scanf("%d", &cantitateMinima);
    golesteBuffer();

    fprintf(r, "RAPORT PARTIAL\n");
    fprintf(r, "Criterii: categorie = %s si cantitate >= %d\n\n", categorie, cantitateMinima);

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1 &&
            strcmp(a.categorie, categorie) == 0 &&
            a.cantitate >= cantitateMinima) {

            fprintf(r, "ID: %d\n", a.id);
            fprintf(r, "Denumire: %s\n", a.denumire);
            fprintf(r, "Pret: %.2f lei\n", a.pret);
            fprintf(r, "Cantitate: %d\n", a.cantitate);
            fprintf(r, "Valoare stoc: %.2f lei\n", a.pret * a.cantitate);
            fprintf(r, "-----------------------------\n");

            gasite++;
        }
    }

    fprintf(r, "\nNumar articole gasite: %d\n", gasite);

    fclose(f);
    fclose(r);

    printf("Raportul partial a fost generat in fisierul %s.\n", RAPORT_PARTIAL);
}

void afisareArticolUnic() {
    FILE *f = fopen(FISIER_BINAR, "rb");

    if (f == NULL) {
        printf("Fisierul nu exista.\n");
        return;
    }

    int idCautat, gasit = 0;
    Articol a;

    printf("Introduceti ID-ul articolului cautat: ");
    scanf("%d", &idCautat);
    golesteBuffer();

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1 && a.id == idCautat) {
            printf("Articolul cautat este:");
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

void afisareToateArticolele() {
    FILE *f = fopen(FISIER_BINAR, "rb");

    if (f == NULL) {
        printf("Fisierul nu exista.\n");
        return;
    }

    Articol a;
    int nr = 0;

    printf("\nLISTA ARTICOLE ACTIVE\n");

    while (fread(&a, sizeof(Articol), 1, f) == 1) {
        if (a.activ == 1) {
            afiseazaArticol(a);
            nr++;
        }
    }

    if (nr == 0) {
        printf("Nu exista articole active.\n");
    }

    fclose(f);
}

void meniu() {
    printf("\n========== MENIU PROIECT ==========\n");
    printf("1. Creare fisier binar si populare cu articole\n");
    printf("2. Adaugare articol in fisierul binar\n");
    printf("3. Actualizare articol identificat unic\n");
    printf("4. Actualizare grup de articole\n");
    printf("5. Stergere articol identificat unic\n");
    printf("6. Generare raport complet in fisier text\n");
    printf("7. Generare raport partial dupa criterii\n");
    printf("8. Afisare articol unic pe ecran\n");
    printf("9. Afisare toate articolele active pe ecran\n");
    printf("0. Iesire\n");
    printf("Alegeti optiunea: ");
}

int main() {
    int optiune;

    do {
        meniu();
        scanf("%d", &optiune);
        golesteBuffer();

        switch (optiune) {
            case 1:
                creareFisier();
                break;
            case 2:
                adaugareArticole();
                break;
            case 3:
                actualizareArticolUnic();
                break;
            case 4:
                actualizareGrupArticole();
                break;
            case 5:
                stergereArticol();
                break;
            case 6:
                raportComplet();
                break;
            case 7:
                raportPartial();
                break;
            case 8:
                afisareArticolUnic();
                break;
            case 9:
                afisareToateArticolele();
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