#include <stdio.h>
#include <stdlib.h>

void printDizi(int dizi[],int N){//dizimizi ekrana bast�ran fonksiyon.Geri donus degeri yok.
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
			//sart sagland�g� taktirde yeni aralik ve yeni minimum degerlerin atanmasi.
				minDistance = abs(dizi[i] - dizi[j]);
				minPoints[0] = dizi[i];
				minPoints[1] = dizi[j];
			}
		}
	}
	return minPoints;//islemler sonucu olusan minimum noktalar� tutan dizinin adresi dondurulur.
}

int main(){
	
	int N;//Eleman say�s�n� tutacak degisken.
	printf("Dizideki eleman adetini girin=");//dizinin eleman say�s� al�nd� ve dizinin boyutu atanarak tan�mland�.
	scanf("%d",&N);
	int dizi[N];
	
	int i;
	for(i=0;i<N;i++){//diziye eleman girisleri al�nd�.
		printf("\n%d. elemani giriniz : ",i);
		scanf("%d",&dizi[i]);
	}
	printf("\nOlusan Dizimiz=");//islem �ncesinde olusan dizimizi ilgili fonksiyonumuza g�ndererek ekrana bast�r�yoruz.
	printDizi(dizi,N);
	
	if(N<=2){//dizideki eleman sayisi 2 veya 2den k�c�k ise siralama islemi yap�lmaz.
		printf("\nDizideki eleman sayisina gore dizi siralanabilir durumda degil.");
	}
	else{//degilse islemlerin yapilacagi kod blogu calisir.
		int *mins = bruteForce(dizi,N);//bizden istenen yaklas�m ile islem yap�lacak fonksiyona dizimizi ve eleman sayisini at�yoruz.
		//d�n�s degeri,birbirine en yak�n 2 degeri tutan minPoints isimli dizinin baslang�c adresini d�nd�rmektedir.
		printf("\n\nBirbirine en yakin iki eleman : %d ve %d",*mins,*(mins+1));//birbirine en yak�n degerler ekrana bast�r�l�r.1. deger adresin ilk gosterdigi yer,2.deger bir ilersi(2.eleman).
	
	}
	
	return 0;
}
