#ifndef LISTELER_OGRENCI_LISTESI_H
#define LISTELER_OGRENCI_LISTESI_H

#include "ogrencikayit.h"
#include <stdbool.h>

typedef struct ogrenci_node {

    struct ogrenci_node* prev;
    ogrenci* ogrenci_veri;
    struct ogrenci_node* next;

} ogrenci_node;


int guncel_kayit = -1;
int boyut = 0;



ogrenci_node* OgrenciNode(ogrenci* ogrenci)
{
    ogrenci_node* node_ptr = malloc(sizeof (ogrenci_node));
    node_ptr->ogrenci_veri = ogrenci;
    node_ptr->prev = node_ptr->next = NULL;
    return node_ptr;
}


void ekle(ogrenci_node** head, ogrenci* yeni_ogrenci)
{

    ogrenci_node* yeni_node = OgrenciNode(yeni_ogrenci);
    ogrenci_node* takip_edici = *head;

    if(*head == NULL){
        *head = yeni_node;
        boyut++;
        guncel_kayit++;
        return;
    }

    while (takip_edici->next != NULL)
    {
        takip_edici = takip_edici->next;
    }

    takip_edici->next = yeni_node;

    yeni_node->prev = takip_edici;

    boyut++;
    guncel_kayit++;


}

void kayit_azalt()
{
    if(boyut == 0)
    {
        printf("\n\t\tOgrenci listesinde ogrenci bulunmamaktır. Menu'ye geri donuluyor...\n");
        return;
    } else {
        printf("\n\tOnceki kayida gidildi, guncel ogrenci: \n");
    }

    guncel_kayit--;
    if(guncel_kayit < 0)
    {
        guncel_kayit = 0;
    }

}


void sil(ogrenci_node** head, int index)
{

    if (*head == NULL || guncel_kayit == -1 || index < 0 || index >= boyut)
    {
        return;
    }

    ogrenci_node* takip_edici = *head;

    if (index == 0)
    {
        *head = takip_edici->next;
        kayit_azalt();
        boyut--;
        if(boyut < 0)
        {
            boyut = 0;
        }
        return;
    }

    int position = 0;
    while (takip_edici != NULL && position < index)
    {
        takip_edici = takip_edici->next;
        position++;
    }

    if(takip_edici == NULL)
    {
        return;
    }


    if(takip_edici->next != NULL)
    {
        takip_edici->next->prev = takip_edici->prev;
    }

    if(takip_edici->prev != NULL)
    {
        takip_edici->prev->next = takip_edici->next;
    }



    kayit_azalt();
    boyut--;
    if(boyut < 0)
    {
        boyut = 0;
    }

    free(takip_edici);

}





void onceki_kayida_git()
{
    kayit_azalt();
}

void sonraki_kayida_git()
{
    if(boyut == 0)
    {
        printf("\n\t\tOgrenci listesinde ogrenci bulunmamaktır. Menu'ye geri donuluyor...\n");
        return;
    } else {
        printf("\n\tSonraki kayida gidildi, guncel ogrenci: \n");
    }

    guncel_kayit++;
    if(guncel_kayit >= boyut)
    {
        guncel_kayit = boyut - 1;
    }
}

ogrenci_node* guncel_node_get(ogrenci_node** head)
{

    if(boyut == 0)
    {
        return NULL;
    }

    if(guncel_kayit == 0){
        return *head;
    }



    ogrenci_node* takip_edici = *head;


    int position = 0;
    while (takip_edici->next != NULL && position < guncel_kayit)
    {
        position++;
        takip_edici = takip_edici->next;
    }


    if(position == guncel_kayit)
    {
        return takip_edici;
    } else {
        return NULL;
    }
}

void ogrenci_yazdir(ogrenci_node* node)
{

    printf("\tOgrenci Ad = %s\n", node->ogrenci_veri->ad);
    printf("\tOgrenci Soyad = %s\n", node->ogrenci_veri->soyad);
    printf("\tOgrenci No = %d\n", node->ogrenci_veri->no);
    printf("\tOgrenci Vize = %d\n", node->ogrenci_veri->vize_notu);
    printf("\tOgrenci Final = %d\n\n", node->ogrenci_veri->final_notu);

}

void guncel_ogrenci_yazdir(ogrenci_node** head)
{
    ogrenci_node* guncel_node = guncel_node_get(head);
    if(guncel_node == NULL)
    {
        printf("\n\t\tOgrenci listesinde ogrenci bulunmamaktadir. Menu'ye geri donuluyor...\n");
        return;
    }

    ogrenci_yazdir(guncel_node);

}




void liste_listele(ogrenci_node** head)
{
    ogrenci_node* takip_edici = *head;

    int count = 1;
    while (takip_edici != NULL)
    {
        printf("%d - \n", count);
        ogrenci_yazdir(takip_edici);
        takip_edici = takip_edici->next;
        count++;
    }

    printf("Liste Boyutu: %d\n", boyut);

}

#endif //LISTELER_OGRENCI_LISTESI_H
