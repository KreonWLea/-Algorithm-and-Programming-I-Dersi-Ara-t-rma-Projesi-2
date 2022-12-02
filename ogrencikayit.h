#ifndef LISTELER_OGRENCIKAYIT_H
#define LISTELER_OGRENCIKAYIT_H

#include <stdio.h>
#include <malloc.h>

typedef struct ogrenci_kayit{

    int no;
    char* ad;
    char* soyad;
    int vize_notu;
    int final_notu;

} ogrenci;

ogrenci* OgrenciKayit(int no, char* ad, char* soyad, int vize_notu, int final_notu)
{
    ogrenci* ogrenci_ptr = malloc(sizeof (ogrenci));
    ogrenci_ptr->ad = ad;
    ogrenci_ptr->soyad = soyad;
    ogrenci_ptr->no = no;
    ogrenci_ptr->vize_notu = vize_notu;
    ogrenci_ptr->final_notu = final_notu;
    return ogrenci_ptr;
}

#endif //LISTELER_OGRENCIKAYIT_H
