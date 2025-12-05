#include<stdio.h>
int funcOne(int a){
    printf("Function One: %d\n",a);
    return a;
}
int funcTwo(int b){
    printf("Function Two: %d\n",b);
    return b;
}
int funcThree(int c){
    printf("Function Three: %d\n",c);
    return c;
}

int main(){
    int opt;
        printf("Select an option:\n1. Option One\n2. Option Two\n3. Option Three\n0. Exit\n");
        scanf("%d",&opt);
        do
        {
           switch (opt)
           {
           case 1:
            funcOne(10);
            break;
            case 2:
            funcTwo(20);    
            break;
            case 3:
            funcThree(30);
            break;
           
           default:
            break;
           }
        } while (opt!=0);
    return 0;
        
}