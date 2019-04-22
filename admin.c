#include <stdio.h>
#include <string.h>
#include "myHeader.h"

//fungsi untuk admin login
void admin(){
    int i;
    
    char user[50], pass[50];

    char userAdmin[50] = "admin";
    char passAdmin[50] = "admin";

    printf("USERNAME : ");
    gets(user);
    printf("PASSWORD : ");
    gets(pass);

    if(strcmp(user , userAdmin) == 0 && strcmp(pass, passAdmin) == 0){
        system("clear");
        menuAdmin();
    }
    else{
        system("clear");
        admin();
    }    
}

//fungsi untuk menu dari admin
void menuAdmin(){
    int p;
    printf("\t\t\t 1. User \n");
    printf("\t\t\t 2. Input Tiket Kereta \n");
    printf("\t\t\t 3. Input Tiket Pesawat \n");
    printf("\t\t\t 4. Input Tiket Bus \n");
    printf("\t\t\t 5. Exit \n");
    printf("\t\t\t Pilih (1/2/3/4/5) \n");
    scanf("%d", &p);
    getchar();

    switch(p){
        case 1:
            dataUser();
            break;
        case 2:
            tiketKereta();
            break;
        case 3:
            tiketPesawat();
            break;
        case 4:
            tiketBus();
            break;
        case 5:
            system("clear");
            break;
        default :
            break;
    }
}
struct data{
    char nama[50];
    char asal[50];
    char tujuan[50];
    char jenis[50];
    char berangkat[50];
    char tiba[50];
    int harga;

}y;


//fungsi input tiket
//Kereta
void tiketKereta(){

    FILE * tiket;
    tiket = fopen("kereta.dat", "a+");

    printf("Nama Kereta : ");
    gets(y.nama);
    printf("Asal : ");
    gets(y.asal);
    printf("Tujuan : ");
    gets(y.tujuan);
    printf("Jam keberangkata  : ");
    gets(y.berangkat);
    printf("Jam TIba  : ");
    gets(y.tiba);
    printf("Jenis  : ");
    gets(y.jenis);
    printf("Harga  : ");
    scanf("%d", &y.harga);
    getchar();
    fwrite(&y, sizeof(y), 1, tiket);
    fclose(tiket);

    menuAdmin();
    
}

void kereta(){
    FILE * tiket;
    tiket = fopen("kereta.dat", "r+");
    int i = 1;
    while(fread(&y, sizeof(y), 1, tiket)==1){
        printf("ID : %d\n", i);
        printf("Nama Kereta : %s \n", y.nama);
        printf("Keberangkatan  : Statiun %s Pukul %s\n", y.asal, y.berangkat);
        printf("Tiba : Stasiun %s Pukul %s\n", y.tujuan, y.tiba);
        printf("Harga : %d \n\n\n", y.harga);
        i++;
    }

    fclose(tiket);
    
}

//Pesawat
void tiketPesawat(){

    FILE * tiket;
    tiket = fopen("pesawat.dat", "a+");

    printf("Nama Maskapai : ");
    gets(y.nama);
    printf("Asal : ");
    gets(y.asal);
    printf("Tujuan : ");
    gets(y.tujuan);
    printf("Jam keberangkata  : ");
    gets(y.berangkat);
    printf("Jam TIba  : ");
    gets(y.tiba);
    printf("Jenis  : ");
    gets(y.jenis);
    printf("Harga  : ");
    scanf("%d", &y.harga);
    getchar();
    fwrite(&y, sizeof(y), 1, tiket);
    fclose(tiket);

    menuAdmin();
    
}

void pesawat(){
    FILE * tiket;
    tiket = fopen("pesawat.dat", "r+");
    int i = 1;
    while(fread(&y, sizeof(y), 1, tiket)==1){
        printf("ID : %d\n", i);
        printf("Nama Maskapai : %s \n", y.nama);
        printf("Keberangkatan  : Bandara %s Pukul %s\n", y.asal, y.berangkat);
        printf("Tiba : Bandara %s Pukul %s\n", y.tujuan, y.tiba);
        printf("Harga : %d \n\n\n", y.harga);
        i++;
    }

    fclose(tiket);
    
}
//Bus
void tiketBus(){

    FILE * tiket;
    tiket = fopen("bus.dat", "a+");

    printf("Nama PO : ");
    gets(y.nama);
    printf("Asal : ");
    gets(y.asal);
    printf("Tujuan : ");
    gets(y.tujuan);
    printf("Jam keberangkata  : ");
    gets(y.berangkat);
    printf("Jam TIba  : ");
    gets(y.tiba);
    printf("Jenis  : ");
    gets(y.jenis);
    printf("Harga  : ");
    scanf("%d", &y.harga);
    getchar();
    fwrite(&y, sizeof(y), 1, tiket);
    fclose(tiket);

    menuAdmin();
    
}

void bus(){
    FILE * tiket;
    tiket = fopen("bus.dat", "r+");
    int i = 1;
    while(fread(&y, sizeof(y), 1, tiket)==1){
        printf("ID : %d\n", i);
        printf("Nama PO : %s \n", y.nama);
        printf("Keberangkatan  : Bandara %s Pukul %s\n", y.asal, y.berangkat);
        printf("Tiba : Bandara %s Pukul %s\n", y.tujuan, y.tiba);
        printf("Harga : %d \n\n\n", y.harga);
        i++;
    }

    fclose(tiket);
    
}




