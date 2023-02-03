//ISPARTA UYGULAMALI BILIMLER UNIVERSITESI   
//ALGORITMA VE PROGRAMLAMAYA GIRIS DERSI ODEVI
//ÖMER SOYDİNÇ   
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
	
	cout<<"DİL KURSU ÖĞRENCİ İŞLERİ OTOMASYONU"<<endl<<endl;
	
	{ //------------------------------OGRENCI KAYIDI YAPMAK------------------------------
	   
	
		ofstream dosya("ogrenci.dat", ios::binary);
	
	    do
	    {
		cout<<"OGRENCININ ADINI GIRINIZ:  ";
		cin>>ogrenci.ad;
		
		cout<<endl;
		
		cout<<"OGRENCININ YASINI GIRINIZ:  ";
		cin>>ogrenci.yas;
		
		cout<<endl;
		
		cout<<"ILKOKUL        "<<endl;
		cout<<"ORTAOKUL       "<<endl;
		cout<<"LISE           "<<endl;
		cout<<"UNIVERSITE     "<<endl;
		cout<<"MEZUN-ÇALISAN  "<<endl;
		cout<<"OGRENCININ EGITIM DURUMUNU GIRINIZ:   ";
		cin>>ogrenci.egitimdurumu;
		
		cout<<endl<<endl;
		
		cout<<"TURKCE       "<<endl
	            <<"INGILIZCE    "<<endl
	            <<"ALMANCA      "<<endl
	            <<"FRANSIZCA    "<<endl
	            <<"RUSCA        "<<endl
	            <<"ISPANYOLCA   "<<endl
                    <<"CINCE        "<<endl
	            <<"PORTEKIZCE   "<<endl
	            <<"ARAPÇA       "<<endl
                    <<"HINTÇE       "<<endl;
	    cout<<"OGRENCININ ANADILINI GIRINIZ:   ";
		cin>>ogrenci.anadili;
		
		cout<<endl<<endl;
		
		cout<<"TURKCE       "<<endl
	            <<"INGILIZCE    "<<endl
	            <<"ALMANCA      "<<endl
	            <<"FRANSIZCA    "<<endl
	            <<"RUSCA        "<<endl
	            <<"ISPANYOLCA   "<<endl
                    <<"CINCE        "<<endl
	            <<"PORTEKIZCE   "<<endl
	            <<"ARAPÇA       "<<endl
                    <<"HINTÇE       "<<endl;
		cout<<"ORENCININ DERS ALMAK ISTEDIGI DILI GIRINIZ:   ";
		cin>>ogrenci.dersalacagidil;
		
		cout<<endl<<endl;
		
	    cout<< "A1  (Baslangic Seviyesi)  "<<endl
		<<" A2                        "<<endl
		<<" B1                        "<<endl
	    	<<" B2                        "<<endl
	        <<" C1                        "<<endl
	        <<" C2  (Ileri seviye)        "<<endl;
		cout<<"OGRENCININ DERS ALMAK ISTEDIGI DIL SEVIYESINI GIRINIZ:   ";
		cin>>ogrenci.alacagidildekiseviyesi;
	    
		cout<<endl<<endl;
		
		cout<<" SAAT 10:00 daki ders için 10   "<<endl
		    <<" SAAT 14:00 daki ders için 14   "<<endl
		    <<" SAAT 18:00 daki ders için 18   "<<endl;
		cout<<"OGRENCININ DERS ALMAK ISTEDIGI SAATI GIRINIZ :   ";
		cin>>ogrenci.derssaati;
		
		cout<<endl<<endl;
		
		dosya.write(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
		
		cout<<"BASKA OGRENCI KAYDETMEK ISTER MISINIZ ? (EVET=E , HAYIR=H)  : ";
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
        
        cout<<"KURSUNUZA KAYITLI OGRENCI SAYISI= "<<kayitliogrencisayisi<<endl<<endl;
        dosya.close();
	
	
	{//------------------------------KAYITLI ÖÐRENCÝ LÝSTESÝ------------------------------
		
	    ifstream dosya;
    	dosya.open("ogrenci.dat",ios::binary);
    	
    	cout<<"KURSUNUZDA TOPLAM "<<kayitliogrencisayisi<<" ADET OGRENCI BULUNMAKTADIR."<<endl<<endl;
    	if(kayitliogrencisayisi>0)
		{
			for(int k=0;k<kayitliogrencisayisi;k++)
			{
				cout<<k+1<<". OGRENCININ BILGILER"<<endl;
				dosya.seekg(k*sizeof(ogrenci));
				dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
				cout<<endl<<  "ADI:              "<<ogrenci.ad<<endl;
					cout<<"YASI:             "<<ogrenci.yas<<endl;
					cout<<"EGITIM DURUMU:    "<<ogrenci.egitimdurumu<<endl;
					cout<<"ANADILI:          "<<ogrenci.anadili<<endl;
					cout<<"DERS ALACAGI DIL: "<<ogrenci.dersalacagidil<<endl;
					cout<<"DIL SEVIYESI:     "<<ogrenci.alacagidildekiseviyesi<<endl;
					cout<<"DERS SAATI:       "<<ogrenci.derssaati<<endl<<endl;
			}
    	}
    }
   
    {//------------------------------KAYITTAN OGRENCI BULMA------------------------------
        
	    char isim[20];
		bool kayit;
		
		ifstream dosya;
		dosya.open("ogrenci.dat",ios::binary);
		
		cout<<"KAYDINI BULMAK ISTEDIGINIZ OGRENCININ ADINI GIRINIZ:   ";
		cin>>isim;
		
		for(int k=0;k<kayitliogrencisayisi;k++)
		{
			dosya.seekg(k*sizeof(ogrenci));
			dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
			
			if(strcmp(ogrenci.ad,isim)==0)
			{
				cout<<endl<<"OGRENCININ BILGILERI "<<k+1<<". KAYITTA BULUNMUSTUR..."<<endl;
				kayit=true;
                
				cout<<endl<<"---BILGILERI---"<<endl<<endl;
				
				dosya.seekg(k*sizeof(ogrenci));
				dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
				
				cout<<"ADI:              "<<ogrenci.ad<<endl;
				cout<<"YASI:             "<<ogrenci.yas<<endl;
				cout<<"EGITIM DURUMU:    "<<ogrenci.egitimdurumu<<endl;
				cout<<"ANADILI:          "<<ogrenci.anadili<<endl;
				cout<<"DERS ALACAGI DIL: "<<ogrenci.dersalacagidil<<endl;
				cout<<"DIL SEVIYESI:     "<<ogrenci.alacagidildekiseviyesi<<endl;
				cout<<"DERS SAATI:       "<<ogrenci.derssaati<<endl<<endl;
		    }
		}if((!kayit))
		cout<<isim<<" ADINDA OGRENCI KAYDI BULUNAMAMISTIR..."<<endl<<endl;
		dosya.close();
	}
	
	{//------------------------------OGRENCI KAYDI SILME------------------------------ 
	
	    char isim[20];
		char secim=' ';
		bool var=false;
		
		ifstream dosya;
		dosya.open("ogrenci.dat",ios::binary);
		
		cout<<"KAYDINI SILMEK ISTEDIGINIZ OGRENCININ ADINI GIRINIZ:   ";
		cin>>isim;
		
		cout<<endl;
		
		for(int j=0;j<kayitliogrencisayisi;j++)
		{
			dosya.seekg(j*sizeof(ogrenci));
			dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
			if(strcmp(ogrenci.ad,isim)==0)
			{
				cout<<"OGRENCININ BILGILERI"<<endl<<endl;
				
				dosya.seekg(j*sizeof(ogrenci));
				dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
				
				cout<<"ADI:              "<<ogrenci.ad<<endl;
				cout<<"YASI:             "<<ogrenci.yas<<endl;
				cout<<"EGITIM DURUMU:    "<<ogrenci.egitimdurumu<<endl;
				cout<<"ANADILI:          "<<ogrenci.anadili<<endl;
				cout<<"DERS ALACAGI DIL: "<<ogrenci.dersalacagidil<<endl;
				cout<<"DIL SEVIYESI:     "<<ogrenci.alacagidildekiseviyesi<<endl;
				cout<<"DERS SAATI:       "<<ogrenci.derssaati<<endl;
				
				cout<<"KAYDINI SILMEK ISTEDIGINIZ OGRENCI BUMU ?[E/H] ";
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
			cout<<isim<<" ADINDAKI OGRENCININ KAYDI SILINMISTIR...";
	    }
		else
		{
			cout<<endl;
			remove("YEDEK.DAT");
			cout<<isim<<" ADINDA OGRENCI KAYDI BULUNAMAMISTIR...";
		}
	}
    
    {//------------------------------OGRENCI KAYDI DÜZELTME------------------------------
   	
	    cout<<endl<<endl;
		char isim[20];
		char secim;
		bool var=false;
		
		ifstream dosya;
		dosya.open("ogrenci.dat",ios::binary);
		
		cout<<endl;
		cout<<"KAYDINI DÜZELTMEK ISTEDIGINIZ OGRENCININ ADINI GIRINIZ:   ";
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
					cout<<"YASI:             "<<ogrenci.yas<<endl;
					cout<<"EGITIM DURUMU:    "<<ogrenci.egitimdurumu<<endl;
					cout<<"ANADILI:          "<<ogrenci.anadili<<endl;
					cout<<"DERS ALACAGI DIL: "<<ogrenci.dersalacagidil<<endl;
					cout<<"DIL SEVIYESI:     "<<ogrenci.alacagidildekiseviyesi<<endl;
					cout<<"DERS SAATI:       "<<ogrenci.derssaati<<endl<<endl;
				
				cout<<"KAYDINI DÜZELTMEK ISTEDIGINIZ OGRENCI BU MU [E/H]?  ";
				secim=getch();
				
				if(secim=='E'||secim=='e')
				{
					ofstream dosya;
					dosya.open("YEDEK.DAT",ios::app|ios::binary);
					
					cout<<endl;
					cout<<"OGRENCININ ADINI GIRINIZ:  ";
					cin>>ogrenci.ad;
		
             	    cout<<endl;
   		
		            cout<<"OGRENCININ YASINI GIRINIZ:  ";
	 	            cin>>ogrenci.yas;
		                      
		            cout<<endl;
		
		            cout<<"ILKOKUL        "<<endl;
		            cout<<"ORTAOKUL       "<<endl;
		            cout<<"LISE           "<<endl;
		            cout<<"ÜNIVERSITE     "<<endl;
		            cout<<"MEZUN-ÇALISAN  "<<endl;
		            cout<<"OGRENCININ EGITIM DURUMUNU GIRINIZ:   ";
		            cin>>ogrenci.egitimdurumu;
		
	                cout<<endl<<endl;
		            
			    cout<<"TURKCE       "<<endl
	                    	<<"INGILIZCE    "<<endl
	                    	<<"ALMANCA      "<<endl
	                    	<<"FRANSIZCA    "<<endl
	                    	<<"RUSCA        "<<endl
	                    	<<"ISPANYOLCA   "<<endl
                    	        <<"CINCE        "<<endl
	                    	<<"PORTEKIZCE   "<<endl
	                    	<<"ARAPCA       "<<endl
                        	<<"HINTCE       "<<endl;
	                cout<<"OGRENCININ ANADILINI GIRINIZ:   ";
		            cin>>ogrenci.anadili;
		
	    	        cout<<endl<<endl;
		
		            cout<<"TURKCE       "<<endl
	                    	<<"INGILIZCE    "<<endl
	                    	<<"ALMANCA      "<<endl
	                    	<<"FRANSIZCA    "<<endl
	                    	<<"RUSCA        "<<endl
	                    	<<"ISPANYOLCA   "<<endl
                    	        <<"CINCE        "<<endl
	                    	<<"PORTEKIZCE   "<<endl
	                    	<<"ARAPCA       "<<endl
                        	<<"HINTCE       "<<endl;
		            cout<<"OGRENCININ DERS ALMAK ISTEDIGI DILI GIRINIZ:   ";
		            cin>>ogrenci.dersalacagidil;
		
	                cout<<endl<<endl;
	                
            		cout<<"A1  (Baslangic seviyesi)  "<<endl
		            <<"A2                        "<<endl
		            <<"B1                        "<<endl
		            <<"B2                        "<<endl
	                    <<"C1                        "<<endl
	                    <<"C2  (Ileri seviye)        "<<endl;
		            cout<<"OGRENCININ DERS ALMAK ISTEDIGI DIL SEVIYESINI GIRINIZ:   ";
		            cin>>ogrenci.alacagidildekiseviyesi;
	
	                cout<<endl<<endl;
	                
		            cout<<"SAAT 10:00 daki ders için 10   "<<endl
		                <<"SAAT 14:00 daki ders için 14   "<<endl
		                <<"SAAT 18:00 daki ders için 18   "<<endl;
		            cout<<"OGRENCININ DERS ALMAK ISTEDIGI SAATI GIRINIZ :   ";
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
			cout<<"OGRENCININ KAYIDI DUZENLENMISTIR..."<<endl<<endl;
	    }
	    else
		{
			cout<<endl;
			remove("YEDEK.DAT");
			cout<<"\n KAYIT BULUNAMADI..."<<endl;
		}
   }
   
   {//------------------------------GUNCELLENMIS OLAN OGRENCI LISTESI------------------------------
		
	    ifstream dosya;
    	dosya.open("ogrenci.dat",ios::binary);
    	
    	cout<<"GUNCELLENMIS KAYITLARDA "<<kayitliogrencisayisi-1<<" ADET OGRENCI BULUNMAKTADIR."<<endl<<endl;
    	if(kayitliogrencisayisi>0)
		{
			for(int k=0;k<kayitliogrencisayisi-1;k++)
			{
				cout<<k+1<<". OGRENCININ BILGILERI"<<endl<<endl;
				
				dosya.seekg(k*sizeof(ogrenci));
				dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
				
				cout<<"ADI:              "<<ogrenci.ad<<endl;
				cout<<"YASI:             "<<ogrenci.yas<<endl;
				cout<<"EGITIM DURUMU:    "<<ogrenci.egitimdurumu<<endl;
				cout<<"ANADILI:          "<<ogrenci.anadili<<endl;
				cout<<"DERS ALACAGI DIL: "<<ogrenci.dersalacagidil<<endl;
				cout<<"DIL SEVIYESI:     "<<ogrenci.alacagidildekiseviyesi<<endl;
				cout<<"DERS SAATI:       "<<ogrenci.derssaati<<endl<<endl;
			}
    	}
   }
	getch();
	return 0;
}
