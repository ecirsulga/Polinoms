#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct polinom
{

 int katsayi;  
 int us;  
 struct polinom *sonraki; 
}polinom;

polinom *p3=NULL,*g3;
polinom* polinom_topla(polinom *g1,polinom *g2)//fonksiyonumuz recursive fonksiyondur
{	

	if(g1->sonraki==NULL && g2->sonraki==NULL)return g3;//fonksiyonun döngüden çýkma þartý her iki polinomunda bitmesidir
	if(g1->sonraki==NULL)//eðer bir polinom bitip diðer polinom bitmemiþse bitmeyen polinomun kalan deðerlerini toplam polinomuna ekler
	{
		while(g2->sonraki!=NULL)
		{
			p3->katsayi=g2->katsayi;
			p3->us=g2->us;
			g2=g2->sonraki;
			p3->sonraki=(polinom*)malloc(sizeof(polinom));
			p3=p3->sonraki;
			p3->sonraki=NULL;
		}
		return g3;
	}
	if(g2->sonraki==NULL)//eðer bir polinom bitip diðer polinom bitmemiþse bitmeyen polinomun kalan deðerlerini toplam polinomuna ekler
	{
		while(g1->sonraki!=NULL)
		{
			p3->katsayi=g1->katsayi;
			p3->us=g1->us;
			g1=g1->sonraki;
			p3->sonraki=(polinom*)malloc(sizeof(polinom));
			p3=p3->sonraki;
			p3->sonraki=NULL;
		}
		return g3;
	}
	if(g1->us>g2->us)//büyük olan polinom deðerini toplam polinomuna polinomun sonraki elemanýný fonksiyona tekrar yollar.Küçük olan polinomda deðiþme olmaz.
	{	if(p3==NULL)//bu if þartý baðý listenin ilk elemanýnýn oluþturulup oluþturulmadýðýný kontrol eder oluþturulmadýysa yer ayýrýr
		{
			p3=(polinom*)malloc(sizeof(polinom));
			g3=p3;
		}
		p3->katsayi=g1->katsayi;
		p3->us=g1->us;	
		p3->sonraki=(polinom*)malloc(sizeof(polinom));
		p3=p3->sonraki;
		p3->sonraki=NULL;
		polinom_topla(g1->sonraki,g2);	
	}
	else {
		if(g1->us<g2->us)//büyük olan polinom deðerini toplam polinomuna polinomun sonraki elemanýný fonksiyona tekrar yollar.Küçük olan polinomda deðiþme olmaz.
		{
			if(p3==NULL)
		{
			p3=(polinom*)malloc(sizeof(polinom));
			g3=p3;
		}
			p3->katsayi=g2->katsayi;
			p3->us=g2->us;
			p3->sonraki=(polinom*)malloc(sizeof(polinom));
			p3=p3->sonraki;
			p3->sonraki=NULL;
			polinom_topla(g1,g2->sonraki);	
		}
		else 
		{
			if(p3==NULL)//polinomlardaki üsler ayný ise 2 polinom deðerinin katsayýlarýný toplayarak toplam polinomunun yenir elemanýna ekler
		{
			p3=(polinom*)malloc(sizeof(polinom));
			g3=p3;
		}
			p3->katsayi=g1->katsayi+g2->katsayi;
			p3->us=g1->us;
			p3->sonraki=(polinom*)malloc(sizeof(polinom));
			p3=p3->sonraki;
			p3->sonraki=NULL;
			polinom_topla(g1->sonraki,g2->sonraki);	
		}
	}
}


int main (){
	polinom *gecici;
	polinom *p1,*p2;
	FILE *dosya1,*dosya2,*dosya3;
	dosya1=fopen("polinom1.txt","r");//polinomlarý almak için polinom1.txt ve polinom2.txtyi read modunda toplamlarý yazdýrmak içinde polinom3.txt yi write modunda açtýk 
	dosya2=fopen("polinom2.txt","r");
	dosya3=fopen("polinom3.txt","w");
	p1=(polinom*)malloc(sizeof(polinom));
	p2=(polinom*)malloc(sizeof(polinom));
	gecici=p1;
	while(!feof(dosya1))//p1 in ilk elemanýný tutan baðýl listemizi içine polinom1.txtden gelen verileri ekleyerek oluþturduk
	{	
		
		fscanf(dosya1,"%dx%d",&gecici->katsayi,&gecici->us);
		gecici->sonraki=(polinom*)malloc(sizeof(polinom));
		gecici=gecici->sonraki;
		gecici->sonraki=NULL;
		
	}
	
	gecici=p2;
	while(!feof(dosya2))//p2 içinde polinom2.txt verilerini okuyup ekledik
	{
		fscanf(dosya2,"%dx%d",&gecici->katsayi,&gecici->us);
		gecici->sonraki=(polinom*)malloc(sizeof(polinom));
		gecici=gecici->sonraki;
		gecici->sonraki=NULL;
	}
	p3=polinom_topla(p1,p2);//yeni toplam polinomu oluþturmak için fonksiyona yolladýk
	gecici=p3;
	while(gecici->sonraki!=NULL)//toplam baðýl listemizin son elemanýna kadar polinom3.txt ye deðerleri yazdýrdýk
	{	
		fprintf(dosya3,"%dx%d+",gecici->katsayi,gecici->us);
		gecici=gecici->sonraki;
	}
	
	fclose(dosya1);
	fclose(dosya2);
	fclose(dosya3);//dosyalarý kapattýk
	return 0;
}
