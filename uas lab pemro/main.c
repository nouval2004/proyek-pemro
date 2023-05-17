#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void soal();
typedef struct registration
{
    char nama[20];
    char pekerjaan[20];
    char alamat[50];
    char umur[20];
    char universitas[50];
    char jurusan[20];
    char username[20];
    char password[20];
} regis;


int main(int manyArgument, char *argument[])
{
    if(manyArgument == 1){
        regis reg;
        printf("\n");
        printf("*************************************************************\n");
        printf("*************************************************************\n");
        printf("*************************************************************\n");
        printf("*************************************************************\n");
        printf("*************************************************************\n");
        printf("*****\t\tWellcome to our game quizz\t\t*****\n");
        printf("*************************************************************\n");
        printf("*************************************************************\n");
        printf("*************************************************************\n");
        printf("*************************************************************\n");
        printf("*************************************************************\n");
        printf("Silahkan registrasi terlebih dahulu sebelum memulai game quiz <3\n");
        printf("Nama\t\t: "); gets(reg.nama);
        printf("Pekerjaan\t: "); gets(reg.pekerjaan);
        printf("alamat\t\t: "); gets(reg.alamat);
        printf("umur\t\t: "); gets(reg.umur);
        printf("universitas (optional)\t: "); gets(reg.universitas);
        printf("jurusan (optional\t\t: "); gets(reg.jurusan);
        printf("\n");
        printf("\tLets create your account <3\n");
        printf("Username\t: "); gets(reg.username);
        printf("Password\t: "); gets(reg.password);
        printf("\nCreate account success !\n");
        printf("Lets login and enjoy the game <3 !\n");
        printf("Note cara login : ./FileProgramUtama Username Password (perhatikan huruf besar dan kecil ya <3!)\n\n");
        
        FILE *fpw = fopen("database/login.bin", "wb");

        char insl[3] = "#";
        strcat(reg.username, insl);
        strcat(reg.username, reg.password);

        fwrite(reg.username, sizeof(char), sizeof(reg.username)/sizeof(char), fpw);

        fclose(fpw);
    }

    if(manyArgument == 2){
        regis reg;
        FILE *fpr = fopen("database/login.bin", "rb");

        char add[3] = "#";
        strcat(reg.username, add);
        strcat(reg.username, reg.password);

        fread(reg.username, sizeof(char), sizeof(reg.username)/sizeof(char), fpr);

        fclose(fpr);
        
        char acc[0];
        printf("\nFail to login !\n");
        printf("Anda belum memasukkan password !\n");
        printf("See your account? (y/n) "); gets(acc);
        if (acc[0] == 'y')
        {
            fgets(reg.username, sizeof(reg.username), fpr);
            printf("Your account : %s\n", reg.username);
        }
        printf("Note cara login : ./FileProgramUtama Username Password (harap perhatikan huruf besar dan kecil ya <3!)\n\n");
    }

    if(manyArgument == 3){
        regis reg;

        char usernameInput[10], passwordInput[10];
        strcpy(usernameInput, argument[1]);
        strcpy(passwordInput, argument[2]);
        
        FILE *fpr = fopen("database/login.bin", "rb");

        fread(reg.username, sizeof(char), sizeof(reg.username)/sizeof(char), fpr);

        fclose(fpr);

        char *string[3];
        char username[20], password[20];
        int ctrl = 0;

        string[0] = strtok(reg.username, "#");
        while (string[ctrl++] != NULL){
            string[ctrl] = strtok(NULL, "#");
        }

        strcpy(username, string[0]);
        strcpy(password, string[1]);

        if( (strcmp(usernameInput, username) != 0 ) && (strcmp(passwordInput, password) != 0)) {
            printf("Anda Gagal login !\n");
            exit(1);
        } 
        else{
            printf("Login berhasil!");
            soal();
        }

    }
    return 0;
    }
void soal()
{
  char start[20], jawab[20];
  int benar = 0, salah = 0, uang = 0;

  printf("\n\t\t\t\t++-----------------------------++");
  printf("\n\t\t\t\t||----------------------------|");
  printf("\n\t\t\t\t||  want to be a millioner!  ||");
  printf("\n\t\t\t\t||---------------------------||");
  printf("\n\t\t\t\t++---------------------------++");
  printf("\n\nselamat datang di game 'want to be a millioner'\n");
  printf("dalam game ini kami akan memberikan 5 soal bertentangan dengan indonesia\n");
  printf("\n\t RULES : - pilihlah pilihan choice dengan menggunakan huruf besar (capslock)");
  printf("\nTekan Enter untuk memulai game...");
  fgets(start, sizeof(start), stdin);

    system("cls");
    printf("jika berhasil menjawab pertanyaan ini,total hadiah anda = Rp50.000");
    printf("\nUang yang telah anda kumpulkan = Rp%d", uang);
    printf("\n\n1. siapa yang menjahit bendera indonesia...?");
    printf("\n\tA. fatmawati\n");
    printf("\tB. soekarnoe\n");
    printf("\tC. gusdur\n");
    printf("Jawaban anda (A/B/C) : ");
    gets(jawab);
    fflush(stdin);

    if (jawab[0] == 'A')
    {
      printf("selamat jawaban anda benar\n\n");
      uang = +50000;
      printf("Rp.%d", uang);
      system("cls");
    }
    else
    {
      printf("jawaban anda salah, uang yang anda bawa Rp.%d", uang);
      exit(1);
    }

    printf("jika berhasil menjawab pertanyaan ini,total hadiah anda = Rp100.000");
    printf("\nUang yang telah anda kumpulkan = Rp%d", uang);
    printf("\n\n2. kapan indonesia merdeka ?");
    printf("\n\tA. 2003\n");
    printf("\tB. 1999\n");
    printf("\tC. 1945\n");
    printf("Jawaban anda (A/B/C) : ");
    gets(jawab);
    fflush(stdin);

    if (jawab[0] == 'C')
    {
      printf("selamat jawaban anda benar");
      uang = +100000;
      printf("Rp.%d", uang);
      system("cls");
    }
    else
    {
      printf("\njawaban anda salah ,uang yang anda bawa pulang Rp.%u uang\n", uang);

      exit(1);
    }

    printf("jika berhasil menjawab pertanyaan ini,total hadiah anda = Rp150.000");
    printf("\nUang yang telah anda kumpulkan = Rp%d", uang);
    printf("\n\n3. siapa presiden pertama indonesia ?");
    printf("\n\tA. soekarnoe\n");
    printf("\tB. megachan\n");
    printf("\tC. prabowo\n");
    printf("Jawaban anda (A/B/C) : ");
    gets(jawab);
    fflush(stdin);

    if (jawab[0] == 'A')
    {
      printf("selamat jawaban anda benar");
      uang = +150000;
      printf("Rp.%d", uang);
      system("cls");
    }
    else
    {
      printf("\njawaban anda salah ,uang yang anda bawa pulang Rp.%uuang\n", uang);

      exit(1);
    }
  printf("jika berhasil menjawab pertanyaan ini,total hadiah anda = Rp200.000");
    printf("\nUang yang telah anda kumpulkan = Rp%d", uang);
    printf("\n\n4.kapan terjadinya hari sumpah pemuda?");
    printf("\n\tA. 28 oktober\n");
    printf("\tB. 20 oktober\n");
    printf("\tC. 12 juni\n");
    printf("Jawaban anda (A/B/C) : ");
    gets(jawab);
    fflush(stdin);

    if (jawab[0] == 'A')
    {
      printf("selamat jawaban anda benar");
      uang = +200000;
      printf("Rp.%d", uang);
      system("cls");
    }
    else
    {
      printf("\njawaban anda salah ,uang yang anda bawa pulang Rp.%uuang\n", uang);

      exit(1);
    }  
  printf("jika berhasil menjawab pertanyaan ini,total hadiah anda = Rp250.000");
    printf("\nUang yang telah anda kumpulkan = Rp%d", uang);
    printf("\n\n5.siapa saja yang pernah menjajah indonesia?");
    printf("\n\tA. belanda,chile,malaysia\n");
    printf("\tB. belanda,jepang,portugis\n");
    printf("\tC. inggris,denmark,arab saudi\n");
    printf("Jawaban anda (A/B/C) : ");
    gets(jawab);
    fflush(stdin);

    if (jawab[0] == 'B')
    {
      printf("selamat jawaban anda benar semua");
      uang = +250000;
      printf("Rp.%d", uang);
      printf("\ntotal hadiah yang anda dapatkan adalah Rp.%d",uang);
      printf("\n\t`GAME SELESAI1");
    }
    else
    {
      printf("\njawaban anda salah ,uang yang anda bawa pulang Rp.%u\n", uang);

      exit(1);
    }  
  }
