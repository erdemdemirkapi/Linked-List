#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int deger;
    struct Dugum *sonraki;
};

void listeyi_yaz(struct Dugum *baslangic) {
	struct Dugum *e;
	for (e = baslangic ; e != NULL ; e = e->sonraki) {
		printf("%d ", e->deger);
	}
	printf("\n");
}

int main()
{
    struct Dugum *yeni;
    struct Dugum *bas;
    struct Dugum *son;

    /**Sona ekleme*/
    yeni = malloc(sizeof(struct Dugum));
    yeni -> deger = 10;
    yeni -> sonraki = NULL;
    bas = son = yeni;
    listeyi_yaz(bas);

    yeni = malloc(sizeof(struct Dugum));
    yeni -> deger = 20;
    yeni -> sonraki = NULL;
    son -> sonraki = yeni;
    son = yeni;
    listeyi_yaz(bas);

    yeni = malloc(sizeof(struct Dugum));
    yeni -> deger = 30;
    yeni -> sonraki = NULL;
    son -> sonraki = yeni;
    son = yeni;
    listeyi_yaz(bas);

    /**Başa ekleme*/
    yeni = malloc(sizeof(struct Dugum));
    yeni -> deger = 111;
    yeni -> sonraki = bas;
    bas = yeni;
    listeyi_yaz(bas);

    yeni = malloc(sizeof(struct Dugum));
    yeni -> deger = 222;
    yeni -> sonraki = bas;
    bas = yeni;
    listeyi_yaz(bas);

    ///Bastan silme!!!
    struct Dugum *silinecek = bas;
    bas = bas -> sonraki;
    free(silinecek);
    listeyi_yaz(bas);

    struct Dugum *sil2 = bas;
    bas = bas -> sonraki;
    free(sil2);
    listeyi_yaz(bas);

    ///Sondan silme!!!
    struct Dugum *e = bas;
    while(e -> sonraki != son){
        e = e -> sonraki;
    }
    free(e -> sonraki);
    e -> sonraki = NULL;
    son = e;
    listeyi_yaz(bas);

    return 0;
}
