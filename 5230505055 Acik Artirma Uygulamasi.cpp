#include <stdio.h>
#include <stdlib.h>

#define MAX_KATILIMCI_SAYISI 10


struct Katilimci { // Katilimci struct'i
    char isim[50]; // Katilimcinin ismini aldim
    double teklif; // Teklifleri aldim
};

int main() {
    int katilimciSayisi;
    int turSayisi;

    
    printf("Acik artirmaya kac katilimci katilacak ? (Maksimum %d): ", MAX_KATILIMCI_SAYISI); // Katilimci sayisini aldim
    scanf("%d", &katilimciSayisi);

    
    if (katilimciSayisi > MAX_KATILIMCI_SAYISI || katilimciSayisi < 1) { // Katilimci sayisini kontrol ettim
        printf("Gecersiz katilimci sayisi. Program sonlandiriliyor.\n"); // Ekrana "Gecersiz katilimci sayisi. Program sonlandiriliyor." yazdirdim
        return 1;
    }

    
    printf("Acik artirma kac tur surecek ? : "); // Kulanicidan tur sayisini aldim
    scanf("%d", &turSayisi);

    
    struct Katilimci katilimcilar[MAX_KATILIMCI_SAYISI]; // Katilimcilari tanimladim

   
    for (int i = 0; i < katilimciSayisi; ++i) { // Katilimcilarin isimlerini aldim
        printf("\nKatilimci %d icin isim giriniz: ", i + 1);
        scanf("%s", katilimcilar[i].isim);
    }

    
    for (int tur = 1; tur <= turSayisi; ++tur) {
        printf("\n\n----- Acik Artirma Turu %d -----\n", tur); // Acik artirma turlari sayisini ekrana yazdirdim

        
        double enYuksekTeklif = katilimcilar[0].teklif; // En yuksek teklifi buldum
        for (int i = 1; i < katilimciSayisi; ++i) {
            if (katilimcilar[i].teklif > enYuksekTeklif) {
                enYuksekTeklif = katilimcilar[i].teklif;
            }
        }

        
for (int i = 0; i < katilimciSayisi; ++i) { // Her katilimcinin yeni teklifi ile birlikte son teklifini guncelledim
    double yeniTeklif;

    
    do {
        printf("\n%s, %d. tur icin yeni teklifinizi giriniz (en yuksek teklif: %.2f): ", // Katilimcilardan tekliflerini aldim
               katilimcilar[i].isim, tur, enYuksekTeklif);
        scanf("%lf", &yeniTeklif);

        
        if (yeniTeklif < katilimcilar[i].teklif) {
            printf("Gecersiz teklif! Onceki teklifinizden dusuk bir teklif giremezsiniz.\n"); //Katilimcilarin kendi teklifinden daha dusuk teklif vermesini engelledim
        } else if (yeniTeklif < 0) {
            printf("Gecersiz teklif! Pozitif bir teklif giriniz.\n"); //Katilimcilarin negatif teklif girmesini engelledim
        } else {
            // Diger katilimcilarin ayni teklifi verip vermedigini kontrol ettim
            int ayniTeklifVar = 0;
            for (int j = 0; j < katilimciSayisi; ++j) {
                if (j != i && yeniTeklif == katilimcilar[j].teklif) {
                    ayniTeklifVar = 1;
                    printf("Gecersiz teklif! Baska bir katilimci zaten ayni teklifi vermistir. Tekrar deneyiniz.\n"); // Ekrana "Gecersiz teklif! Baska bir katilimci zaten ayni teklifi vermistir. Tekrar deneyiniz." yazdirdim
                    break;
                }
            }
            // Ayni teklifin olmamasi durumunda islemleri devam ettirdim
            if (!ayniTeklifVar) {
                break;
            }
        }
    } while (1);

    printf("%s'nin teklifi guncellendi. Eski teklif: %.2f, Yeni teklif: %.2f\n", // Ekrana "'nin teklifi guncellendi. Eski teklif: %.2f, Yeni teklif:" yazdirdim
           katilimcilar[i].isim, katilimcilar[i].teklif, yeniTeklif);
    katilimcilar[i].teklif = yeniTeklif;

    
    if (yeniTeklif > enYuksekTeklif) { // En yuksek teklifi guncelledim
        enYuksekTeklif = yeniTeklif;
    }
}


        printf("\nEn yuksek teklif: %.2f\n", enYuksekTeklif); // Ekrana "En yuksek teklif:" yazdirdim
    }

    // En yuksek teklifi buldum
    double enYuksekTeklif = katilimcilar[0].teklif;
    int enYuksekTeklifIndex = 0;
    for (int i = 1; i < katilimciSayisi; ++i) {
        if (katilimcilar[i].teklif > enYuksekTeklif) {
            enYuksekTeklif = katilimcilar[i].teklif;
            enYuksekTeklifIndex = i;
        }
    }

    // Sonuclari ekranda gosterdim
    printf("\n----- Acik Artirma Sonuclari -----\n"); // Ekrana "----- Acik Artirma Sonuclari -----" yazdirdim
    printf("'%s' en yuksek teklifi veren katilimcidir ve acik artirmayi kazanmistir. Teklifi: %.2f\n", // Ekrana "en yuksek teklifi veren katilimcidir ve acik artirmayi kazanmistir. Teklifi:" yazdirdim
           katilimcilar[enYuksekTeklifIndex].isim, enYuksekTeklif);

    return 0;
}


