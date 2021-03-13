#include <stdio.h>
#include <stdlib.h>

void printDizi(int dizi[],int N){//dizimizi ekrana bastýran fonksiyon.Geri donus degeri yok.
	int i;
	for(i=0;i<N;i++){//dizi boyutu kadar git
		printf("\t%d",dizi[i]);//her elemani bastir.
	}
}

int *bruteForce(int dizi[],int n){
	int i,j;//dongu degiskenlerinin tanimi.
	int minDistance = abs(dizi[0]-dizi[1]);//minimum aralik icin farklarinin mutlak degeri kontrolu.
	int minPoints[] = {dizi[0],dizi[1]};//ilk olarak minimum bir noktanin belirlenmesi.
	for (i=0;i<n-1;i++){//ana dongumuze giris.
		for(j=i+1;j<n;j++){//bir ilersinden sonuna kadar devam eden ic dongu.
			if(abs(dizi[i] - dizi[j]) < minDistance){//ikili elemanlarin farklarinin mutlak degeri karsilastirma blogu.
			//sart saglandýgý taktirde yeni aralik ve yeni minimum degerlerin atanmasi.
				minDistance = abs(dizi[i] - dizi[j]);
				minPoints[0] = dizi[i];
				minPoints[1] = dizi[j];
			}
		}
	}
	return minPoints;//islemler sonucu olusan minimum noktalarý tutan dizinin adresi dondurulur.
}

int main(){
	
	int N;//Eleman sayýsýný tutacak degisken.
	printf("Dizideki eleman adetini girin=");//dizinin eleman sayýsý alýndý ve dizinin boyutu atanarak tanýmlandý.
	scanf("%d",&N);
	int dizi[N];
	
	int i;
	for(i=0;i<N;i++){//diziye eleman girisleri alýndý.
		printf("\n%d. elemani giriniz : ",i);
		scanf("%d",&dizi[i]);
	}
	printf("\nOlusan Dizimiz=");//islem öncesinde olusan dizimizi ilgili fonksiyonumuza göndererek ekrana bastýrýyoruz.
	printDizi(dizi,N);
	
	if(N<=2){//dizideki eleman sayisi 2 veya 2den kücük ise siralama islemi yapýlmaz.
		printf("\nDizideki eleman sayisina gore dizi siralanabilir durumda degil.");
	}
	else{//degilse islemlerin yapilacagi kod blogu calisir.
		int *mins = bruteForce(dizi,N);//bizden istenen yaklasým ile islem yapýlacak fonksiyona dizimizi ve eleman sayisini atýyoruz.
		//dönüs degeri,birbirine en yakýn 2 degeri tutan minPoints isimli dizinin baslangýc adresini döndürmektedir.
		printf("\n\nBirbirine en yakin iki eleman : %d ve %d",*mins,*(mins+1));//birbirine en yakýn degerler ekrana bastýrýlýr.1. deger adresin ilk gosterdigi yer,2.deger bir ilersi(2.eleman).
	
	}
	
	return 0;
}
