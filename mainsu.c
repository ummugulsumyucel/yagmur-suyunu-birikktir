#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int *argc, char argv[]) {

     int dizi[]={0,1,0,2,1,0,1,3,2,1,2,1}; // oluþturulan dizi her bir çubuðun yülsekliðini temsil eder.

        int size = sizeof(dizi) / sizeof(dizi[0]); // dizinin toplam boyutunu ilk elemanýn boyutuna bölerek dizinin boyutunu bulduk.
        int maxleft[size]; // dizi boyutunda mevcut çubuðun solundaki çubuklarýn maksimum yüksekliðini tutacak olan maxleft adýnda dir dizi oluþturduk. 
        int maxright[size]; //dizi boyutunda mevcut çubuðun saðýndaki çubuklarýn maksimum yüksekliðini tutacak olan maxright adýnda dir dizi oluþturduk. 
        int leftmax=0,rightmax=0,cukur=0,toplam=0; //Bu diziler, mevcut çubuðun solundaki ve saðýndaki çubuklarýn maksimum yüksekliklerini geçici olarak tutan (yani tuttuðu elemanlarý maxright ve maxleft dizisine yazan)
        //leftmax ve rightmax deðiþkenleri oluþturduk.
		// ve çubuklar arasýnda sýkýþabilecek su miktarýný hesaplamak  için cukur ve toplam deðiþkenleri oluþturduk.

        int i;

        for( i=0;i<size; i++){ 
        
        //sýrasýyla yukarýda verilen dizin elemanlarýnýn solundaki çubuklarýn maksimum yüksekliðini hesaplayan  ve bunu maxleft dizisinde saklayan bir if-else döngüsü oluþturduk.

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

            printf("MaxL :%d \n", maxleft[i]); //maxleft dizisini ekrana yazdýrdýk.
        }
        
		//sondan baþlayarak sýrasýyla yukarýda verilen dizin elemanlarýnýn saðýndaki çubuklarýn maksimum yüksekliðini hesaplayan  ve bunu maxright dizisinde saklayan bir if-else döngüsü oluþturduk.
        
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

            printf("MaxR :%d \n", maxright[i]); // maxright dizisini ekrana yazdýrdýk.
        }

        for(i = 0; i<size;i++){

            if(maxright[i]>maxleft[i]){ //maxright ve maxleft dizilerinin elemanlarýný sýrasýyla karþýlaþtýrdýk maxright büyük ise if döngüsüne girdi.
                cukur=maxleft[i]-dizi[i]; // Tutulabilecek su miktarýný hesaplamak için aradaki çukura ve çukurun saðýndaki ve solundaki yüksekliklerden en küçük olana ihtiyaç vardýr. Çünkü o miktar kadar su tutabilir.
                //maxleft daha küçük olduðu için ondan siyah yükseklikleri çýkardýk.
                toplam=toplam+cukur; // çukura, burada çýkan sonuç kadar su dolabileceði için çýkan sonucu toplam deðiþkenine atadýk.
                
                
            }
            else{ 
               cukur=maxright[i]-dizi[i]; //diðer olasýklarda ise maxrightdan siyah yükseklileri çýkardýk.
               toplam=toplam+cukur; // ve bu sonucu yine toplam deðiþkenine atadýk.
              
            }
        }

        printf("toplam su miktari:%d\n",toplam); // toplam biriken suyu ekrana yazdýrdýk.

        return 0;
    }


