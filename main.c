#include <memory.h>
#include <string.h>
#include "ogrenci_listesi.h"

int main() {

    printf("\t\tBAGIL LISTE IMPLEMENTASYONU");

    ogrenci_node* liste = NULL;

    while(true)
    {
        printf("\n\n\t1- Ogrenci Ekleme\n");
        printf("\t2- Ogrenci Cikarma\n");
        printf("\t3- Guncel Ogrenciyi Listele\n");
        printf("\t4- Onceki Kayida Git\n");
        printf("\t5- Sonraki Kayida Git\n");
        printf("\t6- Tum Kayitlari Listele\n");
        printf("\t7- Cikis\n");
        printf("\tLutfen menuden bir secenegi tam sayi olarak giriniz. Girdiginiz secenekteki islem gerceklestirilecektir.\n");
        printf("\tEK NOT: Guncel ogrenci, Ogrenci Ekleme secenegi secildigi"
               "zaman, en son eklenen ogrenci olarak listelenecektir.\n\tBunun haricinde 4. ve 5. menu secenegi kullanarak kayidi degistirebilirsiniz.\n");
        
        int input;
        scanf("%d", &input);

        while (input < 1 || input > 7)
        {
            printf("\tSecenegi tekrar giriniz: (1-7): ");
            scanf("%d", &input);
        }


        if(input == 1)
        {
            char ad_kopya[30], soyad_kopya[30];
            char* ad = (char*) malloc(strlen(ad_kopya));
            char* soyad = (char*) malloc(strlen(soyad_kopya));

            printf("\t Ogrenci Adi: ");
            scanf("%s", &ad_kopya);
            strcpy (ad, ad_kopya);



            printf("\t Ogrenci Soyad: ");
            scanf("%s", &soyad_kopya);
            strcpy (soyad, soyad_kopya);

            int no = 0;

            printf("\t Ogrenci No: ");
            scanf("%d", &no);

            int vize = 0;
            printf("\t Ogrenci Vize Notu: ");
            scanf("%d", &vize);

            while (vize < 0 || vize > 100)
            {
                printf("\t Ogrenci Vize Notu Tekar Giriniz: ");
                scanf("%d", &vize);
            }


            int final = 0;
            printf("\t Ogrenci Final Notu: ");
            scanf("%d", &final);

            while (final < 0 || final > 100)
            {
                printf("\t Ogrenci Final Notu Tekar Giriniz: ");
                scanf("%d", &final);
            }


            ogrenci* ogrenci = OgrenciKayit(no, ad, soyad, vize, final);
            ekle(&liste, ogrenci);

            printf("\n\t\t %s %s adli ogrenci basariyla eklendi ! \n", ad, soyad);

            continue;
        }

        if(input == 2)
        {

            if(liste == NULL)
            {
                printf("\n\t\tOgrenci listesinde ogrenci bulunmamaktadir. Menu'ye geri donuluyor...\n");
                continue;
            }

            liste_listele(&liste);

            printf("\n\tCikarilmak istenen ogrencinin sira no'sunu giriniz: (1 - %d)", boyut);

            int index;
            scanf("%d", &index);

            if(boyut == 1 && index == 1)
            {
                sil(&liste, index - 1);

                printf("\n\t\t Silme islemi basarili ! Listede ogrenci kalmamistir. \n");
                printf("\t\t Guncel Liste Boyutu: %d\n", boyut);
                continue;
            }

            while (index < 1 || input > boyut)
            {
                printf("\n\tHATA. Cikarilmak istenen ogrencinin sira no'sunu tekrar giriniz: (1 - %d)", boyut);
                scanf("%d", &index);
            }

            sil(&liste, index - 1);

            printf("\n\t\t Silme islemi basarili ! \n");
            printf("\t\t Guncel Liste Boyutu: %d\n", boyut);

            continue;
        }


        if(input == 3)
        {
            guncel_ogrenci_yazdir(&liste);
            continue;
        }

        if(input == 4)
        {
            onceki_kayida_git();
            guncel_ogrenci_yazdir(&liste);
            continue;
        }

        if(input == 5)
        {
            sonraki_kayida_git();
            guncel_ogrenci_yazdir(&liste);
            continue;
        }

        if(input == 6)
        {
            liste_listele(&liste);
            printf("\n\n");
            continue;
        }

        if(input == 7)
        {
            printf("\nCikis yapiliyor....");
            break;
        }

    }


    return 0;
}
