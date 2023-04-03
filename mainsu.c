#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int *argc, char argv[]) {

     int dizi[]={0,1,0,2,1,0,1,3,2,1,2,1}; // olu�turulan dizi her bir �ubu�un y�lsekli�ini temsil eder.

        int size = sizeof(dizi) / sizeof(dizi[0]); // dizinin toplam boyutunu ilk eleman�n boyutuna b�lerek dizinin boyutunu bulduk.
        int maxleft[size]; // dizi boyutunda mevcut �ubu�un solundaki �ubuklar�n maksimum y�ksekli�ini tutacak olan maxleft ad�nda dir dizi olu�turduk. 
        int maxright[size]; //dizi boyutunda mevcut �ubu�un sa��ndaki �ubuklar�n maksimum y�ksekli�ini tutacak olan maxright ad�nda dir dizi olu�turduk. 
        int leftmax=0,rightmax=0,cukur=0,toplam=0; //Bu diziler, mevcut �ubu�un solundaki ve sa��ndaki �ubuklar�n maksimum y�ksekliklerini ge�ici olarak tutan (yani tuttu�u elemanlar� maxright ve maxleft dizisine yazan)
        //leftmax ve rightmax de�i�kenleri olu�turduk.
		// ve �ubuklar aras�nda s�k��abilecek su miktar�n� hesaplamak  i�in cukur ve toplam de�i�kenleri olu�turduk.

        int i;

        for( i=0;i<size; i++){ 
        
        //s�ras�yla yukar�da verilen dizin elemanlar�n�n solundaki �ubuklar�n maksimum y�ksekli�ini hesaplayan  ve bunu maxleft dizisinde saklayan bir if-else d�ng�s� olu�turduk.

            if(leftmax==0){ 
                leftmax=dizi[i]; 
                maxleft[i]=leftmax; 
            }
            else{
                if(leftmax<dizi[i]){ 
                    leftmax=dizi[i]; 
                    maxleft[i]=leftmax;

                }
                else{
                    maxleft[i]=leftmax; 
                }
            }

            printf("MaxL :%d \n", maxleft[i]); //maxleft dizisini ekrana yazd�rd�k.
        }
        
		//sondan ba�layarak s�ras�yla yukar�da verilen dizin elemanlar�n�n sa��ndaki �ubuklar�n maksimum y�ksekli�ini hesaplayan  ve bunu maxright dizisinde saklayan bir if-else d�ng�s� olu�turduk.
        
		for( i = size -1; i>=0;i--){

            if(rightmax==0){
                rightmax=dizi[i];
                maxright[i]=rightmax;
            }
            else{
                if(rightmax<dizi[i]){
                    rightmax=dizi[i];
                    maxright[i]=rightmax;
                }
                else{
                    maxright[i]=rightmax;
                }
            }

            printf("MaxR :%d \n", maxright[i]); // maxright dizisini ekrana yazd�rd�k.
        }

        for(i = 0; i<size;i++){

            if(maxright[i]>maxleft[i]){ //maxright ve maxleft dizilerinin elemanlar�n� s�ras�yla kar��la�t�rd�k maxright b�y�k ise if d�ng�s�ne girdi.
                cukur=maxleft[i]-dizi[i]; // Tutulabilecek su miktar�n� hesaplamak i�in aradaki �ukura ve �ukurun sa��ndaki ve solundaki y�ksekliklerden en k���k olana ihtiya� vard�r. ��nk� o miktar kadar su tutabilir.
                //maxleft daha k���k oldu�u i�in ondan siyah y�kseklikleri ��kard�k.
                toplam=toplam+cukur; // �ukura, burada ��kan sonu� kadar su dolabilece�i i�in ��kan sonucu toplam de�i�kenine atad�k.
                
                
            }
            else{ 
               cukur=maxright[i]-dizi[i]; //di�er olas�klarda ise maxrightdan siyah y�kseklileri ��kard�k.
               toplam=toplam+cukur; // ve bu sonucu yine toplam de�i�kenine atad�k.
              
            }
        }

        printf("toplam su miktari:%d\n",toplam); // toplam biriken suyu ekrana yazd�rd�k.

        return 0;
    }


