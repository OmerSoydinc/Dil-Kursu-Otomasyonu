//ISPARTA UYGULAMALI BÝLÝBLER ÜNÝVERSÝTESÝ   TEKNOLOJÝ FAKÜLTESÝ   BÝLGÝSÝYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ   1. SINIF
//ALGORÝTMA ve PROGRAMLAMAYA GÝRÝÞ DERSÝ PROJE ÖDEVÝ 
//ÖMER SOYDÝNÇ  2012721018 
//DÝL KURSU ÖÐRENCÝ ÝÞLERÝ OTOMASYONU
#include<iostream>
#include<locale.h>
#include<iomanip>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<fstream>

using namespace std;

struct bilgiler
{
	char ad[50];
	int  yas;
	char egitimdurumu[20];
	char anadili[20];
	char dersalacagidil[20];
	char derssaati[20];
	char alacagidildekiseviyesi[2];
	
};
int main()
{   setlocale(LC_ALL,"Turkish");
	bilgiler ogrenci;
	char secim;
	
	cout<<"DÝL KURSU ÖÐRENCÝ ÝÞLERÝ OTOMASYONU"<<endl<<endl;
	
	{ //------------------------------ÖÐRENCÝ KAYIDI YAPMAK------------------------------
	   
	
		ofstream dosya("ogrenci.dat", ios::binary);
	
	    do
	    {
		cout<<"ÖÐRENCÝNÝN ADINI GÝRÝNÝZ:  ";
		cin>>ogrenci.ad;
		
		cout<<endl;
		
		cout<<"ÖÐRENCÝNÝN YAÞINI GÝRÝNÝZ:  ";
		cin>>ogrenci.yas;
		
		cout<<endl;
		
		cout<<"ÝLKOKUL        "<<endl;
		cout<<"ORTAOKUL       "<<endl;
		cout<<"LÝSE           "<<endl;
		cout<<"ÜNÝVERSÝTE     "<<endl;
		cout<<"MEZUN-ÇALIÞAN  "<<endl;
		cout<<"ÖÐRENCÝNÝN EÐÝTÝM DURUMUNU GÝRÝNÝZ:   ";
		cin>>ogrenci.egitimdurumu;
		
		cout<<endl<<endl;
		
		cout<<"TÜRKÇE       "<<endl
	        <<"ÝNGÝLÝZCE    "<<endl
	        <<"ALMANCA      "<<endl
	        <<"FRANSIZCA    "<<endl
	        <<"RUSÇA        "<<endl
	        <<"ÝSPANYOLCA   "<<endl
            <<"ÇÝNCE        "<<endl
	        <<"PORTEKÝZCE   "<<endl
	        <<"ARAPÇA       "<<endl
            <<"HÝNTÇE       "<<endl;
	    cout<<"ÖÐRENCÝNÝN ANADÝLÝNÝ GÝRÝNÝZ:   ";
		cin>>ogrenci.anadili;
		
		cout<<endl<<endl;
		
		cout<<"TÜRKÇE       "<<endl
	        <<"ÝNGÝLÝZCE    "<<endl
	        <<"ALMANCA      "<<endl
	        <<"FRANSIZCA    "<<endl
	        <<"RUSÇA        "<<endl
	        <<"ÝSPANYOLCA   "<<endl
            <<"ÇÝNCE        "<<endl
	        <<"PORTEKÝZCE   "<<endl
	        <<"ARAPÇA       "<<endl
            <<"HÝNTÇE       "<<endl;
		cout<<"ÖÐRENCÝNÝN DERS ALMAK ÝSTEDÝÐÝ DÝLÝ GÝRÝNÝZ:   ";
		cin>>ogrenci.dersalacagidil;
		
		cout<<endl<<endl;
		
	    cout<<"A1  (Baþlancýç seviyesi)  "<<endl
		    <<"A2                        "<<endl
		    <<"B1                        "<<endl
		    <<"B2                        "<<endl
	        <<"C1                        "<<endl
	        <<"C2  (Ýleri seviye)        "<<endl;
		cout<<"ÖÐRENCÝNÝN DERS ALMAK ÝSTEDÝÐÝ DÝL SEVÝYESÝNÝ GÝRÝNÝZ:   ";
		cin>>ogrenci.alacagidildekiseviyesi;
	    
		cout<<endl<<endl;
		
		cout<<"SAAT 10:00 daki ders için 10   "<<endl
		    <<"SAAT 14:00 daki ders için 14   "<<endl
		    <<"SAAT 18:00 daki ders için 18   "<<endl;
		cout<<"ÖÐRENCÝNÝN DERS ALMAK ÝSTEDÝÐÝ SAATÝ GÝRÝNÝZ :   ";
		cin>>ogrenci.derssaati;
		
		cout<<endl<<endl;
		
		dosya.write(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
		
		cout<<"BAÞKA ÖÐRENCÝ KAYDETMEK ÝSTER MÝSÝNÝZ ? (EVET=E , HAYIR=H)  : ";
		secim=getche();
		
		system("cls");
		
	    }while(secim=='e'||secim=='E');
	    dosya.close();
	}
	  
	cout<<endl<<endl;   
	    
		//------------------------------KAYIT SAYISINI ÖÐRENME------------------------------


        ifstream dosya;
	    dosya.open("ogrenci.dat",ios::binary);

        dosya.seekg(0,ios::end);

        int kayitliogrencisayisi=dosya.tellg()/sizeof(bilgiler);
        
        cout<<"KURSUNUZA KAYITLI ÖÐRENCÝ SAYISI= "<<kayitliogrencisayisi<<endl<<endl;
        dosya.close();
	
	
	{//------------------------------KAYITLI ÖÐRENCÝ LÝSTESÝ------------------------------
		
	    ifstream dosya;
    	dosya.open("ogrenci.dat",ios::binary);
    	
    	cout<<"KURSUNUZDA TOPLAM "<<kayitliogrencisayisi<<" ADET ÖÐRENCÝ BULUNMAKTADIR."<<endl<<endl;
    	if(kayitliogrencisayisi>0)
		{
			for(int k=0;k<kayitliogrencisayisi;k++)
			{
				cout<<k+1<<". ÖÐRENCÝNÝN BÝLGÝLERÝ"<<endl;
				dosya.seekg(k*sizeof(ogrenci));
				dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
				cout<<endl<<"ADI:              "<<ogrenci.ad<<endl;
				cout<<"YAÞI:             "<<ogrenci.yas<<endl;
				cout<<"EÐÝTÝM DURUMU:    "<<ogrenci.egitimdurumu<<endl;
				cout<<"ANADÝLÝ:          "<<ogrenci.anadili<<endl;
				cout<<"DERS ALACAÐI DÝL: "<<ogrenci.dersalacagidil<<endl;
				cout<<"DÝL SEVÝYESÝ:     "<<ogrenci.alacagidildekiseviyesi<<endl;
				cout<<"DERS SAATÝ:       "<<ogrenci.derssaati<<endl<<endl;
			}
    	}
    }
   
    {//------------------------------KAYITTAN ÖÐRENCÝ BULMA------------------------------
        
	    char isim[20];
		bool kayit;
		
		ifstream dosya;
		dosya.open("ogrenci.dat",ios::binary);
		
		cout<<"KAYDINI BULMAK ÝSTEDÝÐÝNÝZ ÖÐRENCÝNÝN ADINI GÝRÝNÝZ:   ";
		cin>>isim;
		
		for(int k=0;k<kayitliogrencisayisi;k++)
		{
			dosya.seekg(k*sizeof(ogrenci));
			dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
			
			if(strcmp(ogrenci.ad,isim)==0)
			{
				cout<<endl<<"ÖÐRENCÝNÝN BÝLGÝLERÝ "<<k+1<<". KAYITTA BULUNMUÞTUR..."<<endl;
				kayit=true;
                
				cout<<endl<<"---BÝLGÝLERÝ---"<<endl<<endl;
				
				dosya.seekg(k*sizeof(ogrenci));
				dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
				
				cout<<"ADI:              "<<ogrenci.ad<<endl;
				cout<<"YAÞI:             "<<ogrenci.yas<<endl;
				cout<<"EÐÝTÝM DURUMU:    "<<ogrenci.egitimdurumu<<endl;
				cout<<"ANADÝLÝ:          "<<ogrenci.anadili<<endl;
				cout<<"DERS ALACAÐI DÝL: "<<ogrenci.dersalacagidil<<endl;
				cout<<"DÝL SEVÝYESÝ:     "<<ogrenci.alacagidildekiseviyesi<<endl;
				cout<<"DERS SAATÝ:       "<<ogrenci.derssaati<<endl<<endl;
		    }
		}if((!kayit))
		cout<<isim<<" ADINDA ÖÐRENCÝ KAYDI BULUNAMAMIÞTIR..."<<endl<<endl;
		dosya.close();
	}
	
	{//------------------------------ÖÐRENCÝ KAYDI SÝLME------------------------------ 
	
	    char isim[20];
		char secim=' ';
		bool var=false;
		
		ifstream dosya;
		dosya.open("ogrenci.dat",ios::binary);
		
		cout<<"KAYDINI SÝLMEK ÝSTEDÝÐÝNÝZ ÖÐRENCÝNÝN ADINI GÝRÝNÝZ:   ";
		cin>>isim;
		
		cout<<endl;
		
		for(int j=0;j<kayitliogrencisayisi;j++)
		{
			dosya.seekg(j*sizeof(ogrenci));
			dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
			if(strcmp(ogrenci.ad,isim)==0)
			{
				cout<<"ÖÐRENCÝNÝN BÝLGÝLERÝ"<<endl<<endl;
				
				dosya.seekg(j*sizeof(ogrenci));
				dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
				
				cout<<"ADI:              "<<ogrenci.ad<<endl;
				cout<<"YAÞI:             "<<ogrenci.yas<<endl;
				cout<<"EÐÝTÝM DURUMU:    "<<ogrenci.egitimdurumu<<endl;
				cout<<"ANADÝLÝ:          "<<ogrenci.anadili<<endl;
				cout<<"DERS ALACAÐI DÝL: "<<ogrenci.dersalacagidil<<endl;
				cout<<"DÝL SEVÝYESÝ:     "<<ogrenci.alacagidildekiseviyesi<<endl;
				cout<<"DERS SAATÝ:       "<<ogrenci.derssaati<<endl;
				
				cout<<"KAYDINI SÝLMEK ÝSTEDÝÐÝNÝZ ÖÐRENCÝ BUMU ?[E/H] ";
			    secim=getche();
			    if(secim=='H'||secim=='h')
			    {
			    	bilgiler y_ogrenci;
			    	ofstream y_dosya;
			    	y_dosya.open("YEDEK.DAT",ios::binary);
			    	
			    	strcpy( y_ogrenci.ad,ogrenci.ad);
			    	y_ogrenci.yas=ogrenci.yas;
			    	y_ogrenci.egitimdurumu==ogrenci.egitimdurumu;
			    	y_ogrenci.anadili==ogrenci.anadili;
			    	y_ogrenci.dersalacagidil==ogrenci.dersalacagidil;
			    	y_ogrenci.alacagidildekiseviyesi==ogrenci.alacagidildekiseviyesi;
			    	y_ogrenci.derssaati==ogrenci.derssaati;
			    	
			    	y_dosya.write(reinterpret_cast<char*>(&ogrenci),sizeof(y_ogrenci));
			    	y_dosya.close();
			    }
			    if(secim=='E'||secim=='e')
			    {
				    var=true;
			    }
			}
			else
		    {
				bilgiler y_ogrenci;
		        ofstream y_dosya;
		        y_dosya.open("YEDEK.DAT",ios::app|ios::binary);
                         				
				strcpy(y_ogrenci.ad,ogrenci.ad);
			    y_ogrenci.yas=ogrenci.yas;
			    y_ogrenci.egitimdurumu==ogrenci.egitimdurumu;
			    y_ogrenci.anadili==ogrenci.anadili;
			    y_ogrenci.dersalacagidil==ogrenci.dersalacagidil;
			    y_ogrenci.alacagidildekiseviyesi==ogrenci.alacagidildekiseviyesi;
			    y_ogrenci.derssaati==ogrenci.derssaati;
		       
			    y_dosya.write(reinterpret_cast<char*>(&ogrenci),sizeof(y_ogrenci));
			    y_dosya.close();
	        }
	    }dosya.close();
	    if(var)
		{
			cout<<endl;
			remove("ogrenci.dat");
			rename("YEDEK.DAT","ogrenci.dat");
			cout<<isim<<" ADINDAKÝ ÖÐRENCÝNÝN KAYDI SÝLÝNMÝÞTÝR...";
	    }
		else
		{
			cout<<endl;
			remove("YEDEK.DAT");
			cout<<isim<<" ADINDA ÖÐRENCÝ KAYDI BULUNAMAMIÞTIR...";
		}
	}
    
    {//------------------------------ÖÐRENCÝ KAYDI DÜZELTME------------------------------
   	
	    cout<<endl<<endl;
		char isim[20];
		char secim;
		bool var=false;
		
		ifstream dosya;
		dosya.open("ogrenci.dat",ios::binary);
		
		cout<<endl;
		cout<<"KAYDINI DÜZELTMEK ÝSTEDÝÐÝNÝZ ÖÐRENCÝNÝZ ADINI GÝRÝNÝZ:   ";
		cin>>isim;
		
		for(int j=0;j<kayitliogrencisayisi;j++)
		{
			dosya.seekg(j*sizeof(ogrenci));
			dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
			
			if(strcmp(ogrenci.ad,isim)==0)
			{
				var=true;
				cout<<endl;
				cout<<endl<<"ADI:              "<<ogrenci.ad<<endl;
				cout<<"YAÞI:             "<<ogrenci.yas<<endl;
				cout<<"EÐÝTÝM DURUMU:    "<<ogrenci.egitimdurumu<<endl;
				cout<<"ANADÝLÝ:          "<<ogrenci.anadili<<endl;
				cout<<"DERS ALACAÐI DÝL: "<<ogrenci.dersalacagidil<<endl;
				cout<<"DÝL SEVÝYESÝ:     "<<ogrenci.alacagidildekiseviyesi<<endl;
				cout<<"DERS SAATÝ:       "<<ogrenci.derssaati<<endl<<endl;
				
				cout<<"KAYDINI DÜZELTMEK ÝSTEDÝÐÝNÝZ ÖÐRENCÝ BU MU [E/H]?  ";
				secim=getch();
				
				if(secim=='E'||secim=='e')
				{
					ofstream dosya;
					dosya.open("YEDEK.DAT",ios::app|ios::binary);
					
					cout<<endl;
					cout<<"ÖÐRENCÝNÝZ ADINI GÝRÝNÝZ:  ";
					cin>>ogrenci.ad;
		
             	    cout<<endl;
   		
		            cout<<"ÖÐRENCÝNÝN YAÞINI GÝRÝNÝZ:  ";
	 	            cin>>ogrenci.yas;
		                      
		            cout<<endl;
		
		            cout<<"ÝLKOKUL        "<<endl;
		            cout<<"ORTAOKUL       "<<endl;
		            cout<<"LÝSE           "<<endl;
		            cout<<"ÜNÝVERSÝTE     "<<endl;
		            cout<<"MEZUN-ÇALIÞAN  "<<endl;
		            cout<<"ÖÐRENCÝNÝN EÐÝTÝM DURUMUNU GÝRÝNÝZ:   ";
		            cin>>ogrenci.egitimdurumu;
		
	                cout<<endl<<endl;
		            
					cout<<"TÜRKÇE       "<<endl
	                    <<"ÝNGÝLÝZCE    "<<endl
	                    <<"ALMANCA      "<<endl
	                    <<"FRANSIZCA    "<<endl
	                    <<"RUSÇA        "<<endl
	                    <<"ÝSPANYOLCA   "<<endl
                        <<"ÇÝNCE        "<<endl
	                    <<"PORTEKÝZCE   "<<endl
	                    <<"ARAPÇA       "<<endl
                        <<"HÝNTÇE       "<<endl;
	                cout<<"ÖÐRENCÝNÝN ANADÝLÝNÝ GÝRÝNÝZ:   ";
		            cin>>ogrenci.anadili;
		
	    	        cout<<endl<<endl;
		
		            cout<<"TÜRKÇE       "<<endl
	                    <<"ÝNGÝLÝZCE    "<<endl
	                    <<"ALMANCA      "<<endl
	                    <<"FRANSIZCA    "<<endl
	                    <<"RUSÇA        "<<endl
	                    <<"ÝSPANYOLCA   "<<endl
                        <<"ÇÝNCE        "<<endl
	                    <<"PORTEKÝZCE   "<<endl
	                    <<"ARAPÇA       "<<endl
                        <<"HÝNTÇE       "<<endl;
		            cout<<"ÖÐRENCÝNÝN DERS ALMAK ÝSTEDÝÐÝ DÝLÝ GÝRÝNÝZ:   ";
		            cin>>ogrenci.dersalacagidil;
		
	                cout<<endl<<endl;
	                
            		cout<<"A1  (Baþlancýç seviyesi)  "<<endl
		                <<"A2                        "<<endl
		                <<"B1                        "<<endl
		                <<"B2                        "<<endl
	                    <<"C1                        "<<endl
	                    <<"C2  (Ýleri seviye)        "<<endl;
		            cout<<"ÖÐRENCÝNÝN DERS ALMAK ÝSTEDÝÐÝ DÝL SEVÝYESÝNÝ GÝRÝNÝZ:   ";
		            cin>>ogrenci.alacagidildekiseviyesi;
	
	                cout<<endl<<endl;
	                
		            cout<<"SAAT 10:00 daki ders için 10   "<<endl
		                <<"SAAT 14:00 daki ders için 14   "<<endl
		                <<"SAAT 18:00 daki ders için 18   "<<endl;
		            cout<<"ÖÐRENCÝNÝN DERS ALMAK ÝSTEDÝÐÝ SAATÝ GÝRÝNÝZ :   ";
		            cin>>ogrenci.derssaati;
		
					dosya.write(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
					dosya.close();
				}else
				if(secim=='H'||secim=='h')
				{
					bilgiler y_ogrenci;
					ofstream y_dosya;
					y_dosya.open("YEDEK.DAT",ios::app|ios::binary);
				
					
					strcpy(y_ogrenci.ad,ogrenci.ad);
			        y_ogrenci.yas=ogrenci.yas;
			        y_ogrenci.egitimdurumu==ogrenci.egitimdurumu;
			        y_ogrenci.anadili==ogrenci.anadili;
			        y_ogrenci.dersalacagidil==ogrenci.dersalacagidil;
			        y_ogrenci.alacagidildekiseviyesi==ogrenci.alacagidildekiseviyesi;
			        y_ogrenci.derssaati==ogrenci.derssaati;
		           
			        y_dosya.write(reinterpret_cast<char*>(&ogrenci),sizeof(y_ogrenci));
			        y_dosya.close();
				}
			}
		    else
		    {
		    
				bilgiler y_ogrenci;
			    ofstream y_dosya;
				y_dosya.open("YEDEK.DAT",ios::app|ios::binary);
	  		
				strcpy(y_ogrenci.ad,ogrenci.ad);
			    y_ogrenci.yas=ogrenci.yas;
			    y_ogrenci.egitimdurumu==ogrenci.egitimdurumu;
			    y_ogrenci.anadili==ogrenci.anadili;
			    y_ogrenci.dersalacagidil==ogrenci.dersalacagidil;
			    y_ogrenci.alacagidildekiseviyesi==ogrenci.alacagidildekiseviyesi;
			    y_ogrenci.derssaati==ogrenci.derssaati;
		          
			    y_dosya.write(reinterpret_cast<char*>(&ogrenci),sizeof(y_ogrenci));
			    y_dosya.close();
		    }
		}
		
		dosya.close();
		
		if(var)
		{
			cout<<endl;
			remove("ogrenci.dat");
			rename("YEDEK.DAT","ogrenci.dat");
			cout<<"ÖÐRENCÝNÝN KAYIDI DÜZELTÝLMÝÞTÝR..."<<endl<<endl;
	    }
	    else
		{
			cout<<endl;
			remove("YEDEK.DAT");
			cout<<"\n KAYIT BULUNAMADI..."<<endl;
		}
   }
   
   {//------------------------------GÜNCELLENMÝÞ OLAN ÖÐRENCÝ LÝSTESÝ------------------------------
		
	    ifstream dosya;
    	dosya.open("ogrenci.dat",ios::binary);
    	
    	cout<<"GÜNCELLENMÝÞ KAYITLARDA "<<kayitliogrencisayisi-1<<" ADET ÖÐRENCÝ BULUNMAKTADIR."<<endl<<endl;
    	if(kayitliogrencisayisi>0)
		{
			for(int k=0;k<kayitliogrencisayisi-1;k++)
			{
				cout<<k+1<<". ÖÐRENCÝNÝN BÝLGÝLERÝ"<<endl<<endl;
				
				dosya.seekg(k*sizeof(ogrenci));
				dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
				
				cout<<"ADI:              "<<ogrenci.ad<<endl;
				cout<<"YAÞI:             "<<ogrenci.yas<<endl;
				cout<<"EÐÝTÝM DURUMU:    "<<ogrenci.egitimdurumu<<endl;
				cout<<"ANADÝLÝ:          "<<ogrenci.anadili<<endl;
				cout<<"DERS ALACAÐI DÝL: "<<ogrenci.dersalacagidil<<endl;
				cout<<"DÝL SEVÝYESÝ:     "<<ogrenci.alacagidildekiseviyesi<<endl;
				cout<<"DERS SAATÝ:       "<<ogrenci.derssaati<<endl<<endl;
			}
    	}
   }
	getch();
	return 0;
}
