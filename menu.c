#include <stdio.h>
#include "myHeader.h"
#include <stdlib.h>

void menu(){
    int p;
    printf("\n\n \t\t\t S E L A M A T  D A T A N G \t\t\t \n\n");
    printf("\t\t\t 1. Registrasi \n");
    printf("\t\t\t 2. Login \n");
    printf("\t\t\t 3. Admin \n");
    printf("\t\t\t Pilih (1/2/3/4) \n");
    scanf("%d", &p);
    getchar();
    switch(p){
        case 1:
            system("clear");
            registrasi();
            break;
        case 2:
            system("clear");
            login();
            break;
        case 3:
            system("clear");
            admin();
            break;
        default :
            break;
    }
}

struct data{
    
    char nama[50];
    char nik[50];
    char username[50];
    char password[50];
    int saldo;
}x;
void registrasi(){

    FILE * user;
    user = fopen("user.dat", "a+");

    printf("Nama : ");
    gets(x.nama);
    printf("nik : ");
    gets(x.nik);
    printf("username : ");
    gets(x.username);
    printf("password : ");
    gets(x.password);
    printf("Saldo awal : ");
    scanf("%d",&x.saldo);
    getchar();
    fwrite(&x, sizeof(x), 1, user);
    fclose(user);
}

void dataUser(){

    FILE * user;
    user = fopen("user.dat", "r+");

    while(fread(&x, sizeof(x), 1, user)==1){
        printf("Nama : %s \n", x.nama);
        printf("NIK : %s \n", x.nik);
        printf("username : %s \n", x.username);
        printf("password : %s \n", x.password);
        printf("Saldo : %d\n\n", x.saldo);
    }

    fclose(user);

}

void login(){
    char username[50], password[50];

    printf("USERNAME : ");
    gets(username);
    printf("PASSWORD : ");
    gets(password);

    FILE * user;
    user = fopen("user.dat", "r+");

    while(fread(&x, sizeof(x), 1, user)==1){
        if(strcmp(x.username, username)==0 && strcmp(x.password, password) == 0){
            pesan();
        }
    }
    fclose(user);


}




