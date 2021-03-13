#include <stdio.h>
#include <stdlib.h>

int bCount[250]={0};//bu dizi ile elde edilen siyah adetlerin say�m� yap�l�r.Initiate de�er olarak 0 verilmi�tir.


void createArrayWithZeros(int **array,int arrayLenght){
	int i,j;
	for(i=0;i<arrayLenght;i++){
		for(j=0;j<arrayLenght;j++){//matrisimizin t�m elemanlar�n� 0lar ile dolduruyoruz.
			array[i][j]=0;
		}
	}
}

void fillArrayWithOnes(int **array,int arrayLenght,int N){
	int i,j;
	for(i=0;i<arrayLenght;i++){
		for(j=0;j<arrayLenght;j++){
			if(abs(i-N-1)+abs(j-N-1)<=N){//gerekli kontrol yap�l�yor.�art sa�lan�yor ise;
				array[i][j]=1;//ilgili h�crenin de�eri 1leniyor.
				bCount[i]++;//o satira ait sayac�n de�eri 1 artt�r�l�yor.
			}
		}
	}
	
}

void showArray(int **array,int arrayLenght,int N){
	int i,j;
	for(i=0;i<arrayLenght;i++){//basit �ekilde arrayimizi print etti�imiz kod blo�u.
		for(j=0;j<arrayLenght;j++){
			printf("%d	",array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<arrayLenght;i++){//sat�r say�s� kadar,sat�rlarda ka� siyah(1) adeti bilgisini ekrana bast�r�yoruz.
		printf("Satir NO=%d	<->	Siyah kare adeti=%d \n",i,bCount[i]);
	}
	
	printf("Toplam siyah kare adeti=%d",(2*N*(N+1))+1);//toplam siyah kare adetinide �dev d�k�mantasyonunda refere edilen kaynaktaki form�le g�re olu�turup ekrana bast�r�yoruz.
}

int main(int argc, char *argv[]) {
	int N,arrayLenght,**array;//gerekli degisken tan�mlamalar�m�z.
	
	printf("N degerini girin:");//N degeri kullan�c�dan istenilir ve degiskene atilir.
	scanf("%d",&N);
	
	arrayLenght=(2*N)+3;//verilen N degiskenine g�re dizinin boyutunu belirleyecek formul ile dizinin boyutu belirlenir.
	//�dev d�k�man�ndaki �rne�i baz al�rsak.N=0 i�in 3x3,N=1 i�in 5x5 vs... sa�l�yordur.
	array=(int**)calloc(arrayLenght,sizeof(int*));//dizi i�in bellekte alan istenmesi.(4*diziBoyutu) Byte
	int i,j;
	for(i=0;i<arrayLenght;i++){
		array[i]=(int*)calloc(arrayLenght,sizeof(int));
	}

	createArrayWithZeros(array,arrayLenght);//0lar ile doldurarak matrisi olu�turacag�m�z fonksiyon.
	fillArrayWithOnes(array,arrayLenght,N);//gerekli yerleri tespit edip 1 de�erlerini verecek fonksiyon.
	showArray(array,arrayLenght,N);//arrayimizi g�stericek fonksiyon.
	free(array);//b�t�n i�lemler sonunda array�m�z� bellekten freeliyoruz.
	
	return 0;
}
