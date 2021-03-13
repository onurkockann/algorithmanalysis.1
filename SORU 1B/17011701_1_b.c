#include <stdio.h>
#include <stdlib.h>

void printDizi(int dizi[],int N){//dizimizi ekrana bastýran fonksiyon.Geri donus degeri yok.
	int i;
	for(i=0;i<N;i++){//dizi boyutu kadar git
		printf("\t%d",dizi[i]);//her elemani bastir.
	}
}

void merge(int arr[],int l,int m,int r){
    int n1=m-l+1,n2=r-m,a1[n1],a2[n2];//gecici diziler ve gerekli baslangic degerlerinin tanimlamalari.
    int i;
    for(i=0;i<n1;i++)//gecici diziye degerlerin atanmasi yapilir.
        a1[i]=arr[l+i];
    for(i=0;i<n2;i++)//gecici diziye degerlerin atanmasi yapilir.
        a2[i]=arr[m+i+1];
    
    //gecidi diziler birlestirilir ve ilk indisi k degiskenine atilir.Indis degerleri icin i ve j degiskenlerine atama yapilir.
	int k=l,j=0;
	i=0;    
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            arr[k]=a1[i];
            i++;
        }
        else{
            arr[k]=a2[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)//geriye kalan degerler kopyalanir.
    {
        arr[k] = a1[i];
        i++;
        k++;
    }
 
    while (j < n2)//geriye kalan degerler kopyalanir.
    {
        arr[k] = a2[j];
        j++;
        k++;
    }
        
}

void mergeSort(int a[],int l,int r){//dizi siralamasini yapan fonksiyondur.Sol deger icin=l,sagdaki deger icin=r
    if (l < r)
    {
        int m=(l+r)/2;//ortasi alinir ve siralama islemine sokulur/devam edilir.
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        
        merge(a,l,m,r);
    }
    
}

int *findPoints(int dizi[],int n){//birbirine en yakin cifti bulan fonksiyonumuz.
	int i,temp,values[2];//gerekli degiskenlerimizin tanimi.
	temp = abs(dizi[0]-dizi[1]);//baslangic icin ilk 2 degerin farkinin mutlak degeri tutuluyor.
	//noktalarin ilgili degiskenlere aktarimi.
	values[0] = dizi[0];
	values[1] = dizi[1]; 
	for(i=0;i<n;i++){
		if(temp > (abs(dizi[i]-dizi[i+1]))){//ilgili degerlerin farki kontrol edilir.Tempdeki deger buyuk ise;
			temp = abs(dizi[i]-dizi[i+1]);//temp yeni degerini bulunan indislerdeki degerlerin farkini alýr.
			//mevcut noktalar tekrar ilgili degiskenlere atilir.
			values[0] = dizi[i];
			values[1] = dizi[i+1]; 
		}
	}
	return values;//2 degeri tutan dizimiz dondurulur.
}


int main(){
	
	int N;//Dizinin eleman sayisini tutan degisken.
	printf("Dizideki eleman adetini giriniz=");//dizinin eleman sayisi kullanicidan istenir ve N degiskenine atanir.
	scanf("%d",&N);
	int dizi[N];//bu N degiskeni ile dizimizin boyutunu belirliyerek dizimizi olusturuyoruz.
	
	int i;
	for(i=0;i<N;i++){//diziye eleman girisleri alýndý.
		printf("\n%d. elemani giriniz=",i);
		scanf("%d",&dizi[i]);
	}
	
	printf("\nOlusturdugumuz dizimiz=");//ilk once dizimizin orjinal halini ekrana bastiriyoruz.
	printDizi(dizi,N);
	mergeSort(dizi,0,N-1);//merge sort islemini gerceklestiren fonksiyona dizimizi atiyoruz.
	
	int *mins = findPoints(dizi,N);//birbirine yakin minimum 2 degerin tutuldugu fonksiyondan donen dizi mins adli pointer degiskenine atiliyor.
	printf("\n\nEn yakin iki deger=%d , %d",*mins,*(mins+1));//minimum degerler sirasiyla pointer dizisinin tuttugu adresler vasitasiyla ekrana bastiriliyor.

	
	
	return 0;
}
