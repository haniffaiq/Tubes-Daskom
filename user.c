#include <stdio.h>
#include <string.h>
#include "myHeader.h"
struct data{
    char nama[50];
    char nik[50];
    char username[50];
    char password[50];
    int saldo;
    int tambah;
}x;
void pesan(){
    int p;
    printf("\t\t\t 1. Tiket Kereta \n");
    printf("\t\t\t 2. Tiket Pesawat \n");
    printf("\t\t\t 3. Tiket Bus \n");
    printf("\t\t\t 4. Saldo \n");
    printf("\t\t\t Pilih (1/2/3/4) \n");
    scanf("%d", &p);
    getchar();

    switch(p){
        case 1:
            system("clear");
            kereta();
            break;
        case 2:
            system("clear");
            pesawat();
            break;
        case 3:
            system("clear");
            bus();
            break;
        case 4:
            saldo();
            break;
        default :
            break;
    }

}

void saldo(){
    int p;
    printf("\t\t\t Saldo anda : %d \n", x.saldo);
    printf("\t\t\t 1.Isi Saldo \n");
    printf("\t\t\t Pilih (1) \n");
    scanf("%d", &p);
    getchar();

    switch(p){
        case 1:
            system("clear");
            isiSaldo();
            break;
        default:
            break;
    }

}

void isiSaldo(){
    // TO DO edit file user untuk menambahkan saldo

    FILE  * user;
    user = fopen("user.dat", "a+");

    char username[50], password[50];

    printf("USERNAME : ");
    gets(username);
    printf("PASSWORD : ");
    gets(password);
    while(fread(&x, sizeof(x), 1, user)==1){
        if(strcmp(x.username, username)==0 && strcmp(x.password, password) == 0){
            printf("Tambah Saldo : ");
            scanf("%d", &x.tambah);
            x.saldo = x.saldo + x.tambah;

            fwrite(&x, sizeof(x), 1, user);
            fclose(user);

        }
    }
        printf("\t\t\t 1.kembali \n");
        printf("\t\t\t 2.isi lagi \n");
        printf("\t\t\t Pilih (1/2) \n");
}
