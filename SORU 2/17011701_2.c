#include <stdio.h>
#include <stdlib.h>

int bCount[250]={0};//bu dizi ile elde edilen siyah adetlerin sayýmý yapýlýr.Initiate deðer olarak 0 verilmiþtir.


void createArrayWithZeros(int **array,int arrayLenght){
	int i,j;
	for(i=0;i<arrayLenght;i++){
		for(j=0;j<arrayLenght;j++){//matrisimizin tüm elemanlarýný 0lar ile dolduruyoruz.
			array[i][j]=0;
		}
	}
}

void fillArrayWithOnes(int **array,int arrayLenght,int N){
	int i,j;
	for(i=0;i<arrayLenght;i++){
		for(j=0;j<arrayLenght;j++){
			if(abs(i-N-1)+abs(j-N-1)<=N){//gerekli kontrol yapýlýyor.Þart saðlanýyor ise;
				array[i][j]=1;//ilgili hücrenin deðeri 1leniyor.
				bCount[i]++;//o satira ait sayacýn deðeri 1 arttýrýlýyor.
			}
		}
	}
	
}

void showArray(int **array,int arrayLenght,int N){
	int i,j;
	for(i=0;i<arrayLenght;i++){//basit þekilde arrayimizi print ettiðimiz kod bloðu.
		for(j=0;j<arrayLenght;j++){
			printf("%d	",array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<arrayLenght;i++){//satýr sayýsý kadar,satýrlarda kaç siyah(1) adeti bilgisini ekrana bastýrýyoruz.
		printf("Satir NO=%d	<->	Siyah kare adeti=%d \n",i,bCount[i]);
	}
	
	printf("Toplam siyah kare adeti=%d",(2*N*(N+1))+1);//toplam siyah kare adetinide ödev dökümantasyonunda refere edilen kaynaktaki formüle göre oluþturup ekrana bastýrýyoruz.
}

int main(int argc, char *argv[]) {
	int N,arrayLenght,**array;//gerekli degisken tanýmlamalarýmýz.
	
	printf("N degerini girin:");//N degeri kullanýcýdan istenilir ve degiskene atilir.
	scanf("%d",&N);
	
	arrayLenght=(2*N)+3;//verilen N degiskenine göre dizinin boyutunu belirleyecek formul ile dizinin boyutu belirlenir.
	//ödev dökümanýndaki örneði baz alýrsak.N=0 için 3x3,N=1 için 5x5 vs... saðlýyordur.
	array=(int**)calloc(arrayLenght,sizeof(int*));//dizi için bellekte alan istenmesi.(4*diziBoyutu) Byte
	int i,j;
	for(i=0;i<arrayLenght;i++){
		array[i]=(int*)calloc(arrayLenght,sizeof(int));
	}

	createArrayWithZeros(array,arrayLenght);//0lar ile doldurarak matrisi oluþturacagýmýz fonksiyon.
	fillArrayWithOnes(array,arrayLenght,N);//gerekli yerleri tespit edip 1 deðerlerini verecek fonksiyon.
	showArray(array,arrayLenght,N);//arrayimizi göstericek fonksiyon.
	free(array);//bütün iþlemler sonunda arrayýmýzý bellekten freeliyoruz.
	
	return 0;
}
