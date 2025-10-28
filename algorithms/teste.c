#include <stdio.h>

int main()
{
    printf("É só um teste de novo\n");

    /* Aqui começa meus testes*/
   char name[100];

   printf("Enter a name:\n");
   fgets(name, sizeof(name), stdin);

   printf("\n");
   printf("Welcome: ");
   printf("%s", name);


}