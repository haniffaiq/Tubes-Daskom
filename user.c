#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myHeader.h"
struct data{
    char nama[50];
    char nik[50];
    char username[50];
    char password[50];
    int saldo;
    int tambah;
    

}x;

struct data2{
    char nama[50];
    char asal[50];
    char tujuan[50];
    char jenis[50];
    char berangkat[50];
    char tiba[50];
    int harga;

}y;

struct data3{
    char pemilik[50];
    char nama[50];
    char asal[50];
    char tujuan[50];
    char jenis[50];
    char berangkat[50];
    char tiba[50];
    int harga;

}z;

//fungsi untuk menu dari user ketika selesai login
void pesan(){
    int p;
    printf("\t\t\t 1. Tiket Kereta \n");
    printf("\t\t\t 2. Tiket Pesawat \n");
    printf("\t\t\t 3. Tiket Bus \n");
    printf("\t\t\t 4. Saldo \n");
    printf("\t\t\t 5. Tiket Anda\n");
    printf("\t\t\t Pilih (1/2/3/4) \n");
    scanf("%d", &p);
    getchar();

    switch(p){
        case 1:
            system("clear");
            kereta();
            pemesanan();
            break;
        case 2:
            system("clear");
            pesawat();
            pemesanan();
            break;
        case 3:
            system("clear");
            bus();
            pemesanan();
            break;
        case 4:
            //dataUser();
            uang();
            break;
        case 5:
            yourTicket();
            break;
        default :
            break;
    }

}

//menu saldo user
void uang(){
    FILE * user;
    user = fopen("user.dat", "r+");
    int p;
    char username[50], password[50];
    printf("USERNAME : ");
    gets(username);
    printf("PASSWORD : ");
    gets(password);
    while(fread(&x, sizeof(x), 1, user)){
        printf("Nama : %s \n", x.nama);
        printf("NIK : %s \n", x.nik);
        printf("username : %s \n", x.username);
        printf("password : %s \n", x.password);
        printf("Saldo : %d\n\n", x.saldo);
        
        if(strcmp(username, x.username)==0){
            
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
        
    }

    fclose(user);

    /**/
    
}

//fungsi pengisian saldo

void isiSaldo(){

    FILE  * user;
    user = fopen("user.dat", "r+");

    char username[50], password[50];

    printf("USERNAME : ");
    gets(username);
    printf("PASSWORD : ");
    gets(password);
    while(fread(&x, sizeof(x), 1, user)){
        if(strcmp(x.username, username)==0 && strcmp(x.username, username)==0){
            printf("Tambah Saldo : ");
            int tambah, saldo;
            scanf("%d", &tambah);
            saldo = x.saldo;
            saldo = saldo + tambah;
            fseek(user, -sizeof(x), SEEK_CUR);
            x.saldo = saldo;
            fwrite(&x, sizeof(x), 1, user);
            fclose(user);
            printf("\t\t\t 1.kembali \n");
            printf("\t\t\t 2.isi lagi \n");
            printf("\t\t\t Pilih (1/2) \n");

            int p;
            switch(p){
                case 1:
                    break;
                case 2:
                    isiSaldo();
                    break;
                default:
                    break;
            }

        }
    }
        
}


//fungsi pemesanan tiket
void pemesanan(){
    char tujuan[50];
    char username[50];
    char password[50];



    printf("Masukkan Tujuan anda : ");
    gets(tujuan);
    FILE * user;
    FILE * tiket;
    FILE * pesawat;
    FILE * kereta;
    FILE * bus;
    user = fopen("user.dat", "r+");
    tiket = fopen("tiket.dat", "a+");
    pesawat = fopen("pesawat.dat", "r+");
    kereta = fopen("kereta.dat", "r+");
    bus = fopen("bus.dat", "r+");

    //pesawat
    while(fread(&y, sizeof(y), 1, pesawat)){
        if(strcmp(y.tujuan, tujuan)==0){
            printf("Nama Maskapai : %s \n", y.nama);
            printf("Keberangkatan  : Bandara %s Pukul %s\n", y.asal, y.berangkat);
            printf("Tiba : Bandara %s Pukul %s\n", y.tujuan, y.tiba);
            printf("Harga : %d \n\n\n", y.harga);

            int b;
            printf("Mau ? (1/2)");
            scanf("%d", &b);
            getchar();
            switch(b){
                case 1:
                    printf("USERNAME : ");
                    gets(username);
                    printf("PASSWORD : ");
                    gets(password);
                    while(fread(&x, sizeof(x), 1, user)){
                        /*strcpy(z.nama, y.nama);
                        strcpy(z.tujuan,y.tujuan);                            
                        strcpy(z.asal,y.asal);
                        strcpy(z.berangkat,y.berangkat);
                        strcpy(z.tiba,y.tiba);
                        z.harga = y.harga;
                        strcpy(z.jenis,y.jenis);
                        strcpy(z.pemilik,username);
                        fwrite(&z, sizeof(z),1, tiket);*/
                        if(strcmp(x.username, username) == 0){
                            if(x.saldo >= y.harga){
                                
                                strcpy(z.nama, y.nama);
                                strcpy(z.tujuan,y.tujuan);                            
                                strcpy(z.asal,y.asal);
                                strcpy(z.berangkat,y.berangkat);
                                strcpy(z.tiba,y.tiba);
                                z.harga = y.harga;
                                strcpy(z.jenis,y.jenis);
                                strcpy(z.pemilik,username);
                                fwrite(&z, sizeof(z),1, tiket);
                                int saldo, kurang;
                                saldo = x.saldo;
                                kurang = y.harga;
                                
                                saldo = saldo - kurang;
                                fseek(user, -sizeof(x), SEEK_CUR);
                                x.saldo = saldo;
                                fwrite(&x, sizeof(x), 1, user);
                                
                                
                    
                            }
                            else{
                                printf("saldo anda tidak cukup");
                            }
                            
                        }
                    }
                        
                   
                    break;
                case 2:
                    break;
                default :
                    break;
            }
            
        }
        else{
            printf("\n");
        }
    }

    //kereta
    while(fread(&y, sizeof(y), 1, kereta)){
        if(strcmp(y.tujuan, tujuan)==0){
            printf("Nama Kereta : %s \n", y.nama);
            printf("Keberangkatan  : Stasiun %s Pukul %s\n", y.asal, y.berangkat);
            printf("Tiba : Stasiun %s Pukul %s\n", y.tujuan, y.tiba);
            printf("Harga : %d \n\n\n", y.harga);

            int b;
            printf("Mau ? (1/2)");
            scanf("%d", &b);
            getchar();
            switch(b){
                case 1:
                    printf("USERNAME : ");
                    gets(username);
                    printf("PASSWORD : ");
                    gets(password);
                    if(strcmp(x.username, username) == 0){
                            if(x.saldo >= y.harga){
                                
                                strcpy(z.nama, y.nama);
                                strcpy(z.tujuan,y.tujuan);                            
                                strcpy(z.asal,y.asal);
                                strcpy(z.berangkat,y.berangkat);
                                strcpy(z.tiba,y.tiba);
                                z.harga = y.harga;
                                strcpy(z.jenis,y.jenis);
                                strcpy(z.pemilik,username);
                                fwrite(&z, sizeof(z),1, tiket);
                                int saldo, kurang;
                                saldo = x.saldo;
                                kurang = y.harga;
                                
                                saldo = saldo - kurang;
                                fseek(user, -sizeof(x), SEEK_CUR);
                                x.saldo = saldo;
                                fwrite(&x, sizeof(x), 1, user);
                                
                                
                    
                            }
                            else{
                                printf("saldo anda tidak cukup");
                            }
                            
                        }
                    break;
                case 2:
                    break;
                default :
                    break;
            }
        }
        else{
            printf("\n");
        }
    }

    //bus
    while(fread(&y, sizeof(y), 1, bus)){
        if(strcmp(y.tujuan, tujuan)==0){
            printf("Nama PO : %s \n", y.nama);
            printf("Keberangkatan  : Terminal %s Pukul %s\n", y.asal, y.berangkat);
            printf("Tiba : Terminal %s Pukul %s\n", y.tujuan, y.tiba);
            printf("Harga : %d \n\n\n", y.harga);

            int b;
            printf("Mau ? (1/2)");
            scanf("%d", &b);
            getchar();
            switch(b){
                case 1:
                    printf("USERNAME : ");
                    gets(username);
                    printf("PASSWORD : ");
                    gets(password);
                    if(strcmp(x.username, username) == 0){
                            if(x.saldo >= y.harga){
                                
                                strcpy(z.nama, y.nama);
                                strcpy(z.tujuan,y.tujuan);                            
                                strcpy(z.asal,y.asal);
                                strcpy(z.berangkat,y.berangkat);
                                strcpy(z.tiba,y.tiba);
                                z.harga = y.harga;
                                strcpy(z.jenis,y.jenis);
                                strcpy(z.pemilik,username);
                                fwrite(&z, sizeof(z),1, tiket);
                                int saldo, kurang;
                                saldo = x.saldo;
                                kurang = y.harga;
                                
                                saldo = saldo - kurang;
                                fseek(user, -sizeof(x), SEEK_CUR);
                                x.saldo = saldo;
                                fwrite(&x, sizeof(x), 1, user);
                                
                                
                    
                            }
                            else{
                                printf("saldo anda tidak cukup");
                            }
                            
                        }
                    break;
                case 2:
                    break;
                default :
                    break;
            }
        }
        else{
            printf("\n");
        }
    }




}


//fungsi untuk melihat tiket yang di miliki user tertentu
void yourTicket(){
    char username[50];
    char password[50];
    system("clear");
    printf("USERNAME : ");
    gets(username);
    printf("PASSWORD : ");
    gets(password);
    FILE * tiket;
    tiket = fopen("tiket.dat", "r+");

    while(fread(&z, sizeof(z), 1, tiket)==1){
        if(strcmp(username, z.pemilik)==0){
            printf("Nama : %s \n", z.nama);
            printf("Keberangkatan  :  %s Pukul %s\n", z.asal, z.berangkat);
            printf("Tiba :  %s Pukul %s\n", z.tujuan, z.tiba);
            printf("Harga : %d \n\n\n", z.harga);
        }
        
    }

    fclose(tiket);
}
