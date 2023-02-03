//ISPARTA UYGULAMALI B�L�BLER �N�VERS�TES�   TEKNOLOJ� FAK�LTES�   B�LG�S�YAR M�HEND�SL��� B�L�M�   1. SINIF
//ALGOR�TMA ve PROGRAMLAMAYA G�R�� DERS� PROJE �DEV� 
//�MER SOYD�N�  2012721018 
//D�L KURSU ��RENC� ��LER� OTOMASYONU
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
	
	cout<<"D�L KURSU ��RENC� ��LER� OTOMASYONU"<<endl<<endl;
	
	{ //------------------------------��RENC� KAYIDI YAPMAK------------------------------
	   
	
		ofstream dosya("ogrenci.dat", ios::binary);
	
	    do
	    {
		cout<<"��RENC�N�N ADINI G�R�N�Z:  ";
		cin>>ogrenci.ad;
		
		cout<<endl;
		
		cout<<"��RENC�N�N YA�INI G�R�N�Z:  ";
		cin>>ogrenci.yas;
		
		cout<<endl;
		
		cout<<"�LKOKUL        "<<endl;
		cout<<"ORTAOKUL       "<<endl;
		cout<<"L�SE           "<<endl;
		cout<<"�N�VERS�TE     "<<endl;
		cout<<"MEZUN-�ALI�AN  "<<endl;
		cout<<"��RENC�N�N E��T�M DURUMUNU G�R�N�Z:   ";
		cin>>ogrenci.egitimdurumu;
		
		cout<<endl<<endl;
		
		cout<<"T�RK�E       "<<endl
	        <<"�NG�L�ZCE    "<<endl
	        <<"ALMANCA      "<<endl
	        <<"FRANSIZCA    "<<endl
	        <<"RUS�A        "<<endl
	        <<"�SPANYOLCA   "<<endl
            <<"��NCE        "<<endl
	        <<"PORTEK�ZCE   "<<endl
	        <<"ARAP�A       "<<endl
            <<"H�NT�E       "<<endl;
	    cout<<"��RENC�N�N ANAD�L�N� G�R�N�Z:   ";
		cin>>ogrenci.anadili;
		
		cout<<endl<<endl;
		
		cout<<"T�RK�E       "<<endl
	        <<"�NG�L�ZCE    "<<endl
	        <<"ALMANCA      "<<endl
	        <<"FRANSIZCA    "<<endl
	        <<"RUS�A        "<<endl
	        <<"�SPANYOLCA   "<<endl
            <<"��NCE        "<<endl
	        <<"PORTEK�ZCE   "<<endl
	        <<"ARAP�A       "<<endl
            <<"H�NT�E       "<<endl;
		cout<<"��RENC�N�N DERS ALMAK �STED��� D�L� G�R�N�Z:   ";
		cin>>ogrenci.dersalacagidil;
		
		cout<<endl<<endl;
		
	    cout<<"A1  (Ba�lanc�� seviyesi)  "<<endl
		    <<"A2                        "<<endl
		    <<"B1                        "<<endl
		    <<"B2                        "<<endl
	        <<"C1                        "<<endl
	        <<"C2  (�leri seviye)        "<<endl;
		cout<<"��RENC�N�N DERS ALMAK �STED��� D�L SEV�YES�N� G�R�N�Z:   ";
		cin>>ogrenci.alacagidildekiseviyesi;
	    
		cout<<endl<<endl;
		
		cout<<"SAAT 10:00 daki ders i�in 10   "<<endl
		    <<"SAAT 14:00 daki ders i�in 14   "<<endl
		    <<"SAAT 18:00 daki ders i�in 18   "<<endl;
		cout<<"��RENC�N�N DERS ALMAK �STED��� SAAT� G�R�N�Z :   ";
		cin>>ogrenci.derssaati;
		
		cout<<endl<<endl;
		
		dosya.write(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
		
		cout<<"BA�KA ��RENC� KAYDETMEK �STER M�S�N�Z ? (EVET=E , HAYIR=H)  : ";
		secim=getche();
		
		system("cls");
		
	    }while(secim=='e'||secim=='E');
	    dosya.close();
	}
	  
	cout<<endl<<endl;   
	    
		//------------------------------KAYIT SAYISINI ��RENME------------------------------


        ifstream dosya;
	    dosya.open("ogrenci.dat",ios::binary);

        dosya.seekg(0,ios::end);

        int kayitliogrencisayisi=dosya.tellg()/sizeof(bilgiler);
        
        cout<<"KURSUNUZA KAYITLI ��RENC� SAYISI= "<<kayitliogrencisayisi<<endl<<endl;
        dosya.close();
	
	
	{//------------------------------KAYITLI ��RENC� L�STES�------------------------------
		
	    ifstream dosya;
    	dosya.open("ogrenci.dat",ios::binary);
    	
    	cout<<"KURSUNUZDA TOPLAM "<<kayitliogrencisayisi<<" ADET ��RENC� BULUNMAKTADIR."<<endl<<endl;
    	if(kayitliogrencisayisi>0)
		{
			for(int k=0;k<kayitliogrencisayisi;k++)
			{
				cout<<k+1<<". ��RENC�N�N B�LG�LER�"<<endl;
				dosya.seekg(k*sizeof(ogrenci));
				dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
				cout<<endl<<"ADI:              "<<ogrenci.ad<<endl;
				cout<<"YA�I:             "<<ogrenci.yas<<endl;
				cout<<"E��T�M DURUMU:    "<<ogrenci.egitimdurumu<<endl;
				cout<<"ANAD�L�:          "<<ogrenci.anadili<<endl;
				cout<<"DERS ALACA�I D�L: "<<ogrenci.dersalacagidil<<endl;
				cout<<"D�L SEV�YES�:     "<<ogrenci.alacagidildekiseviyesi<<endl;
				cout<<"DERS SAAT�:       "<<ogrenci.derssaati<<endl<<endl;
			}
    	}
    }
   
    {//------------------------------KAYITTAN ��RENC� BULMA------------------------------
        
	    char isim[20];
		bool kayit;
		
		ifstream dosya;
		dosya.open("ogrenci.dat",ios::binary);
		
		cout<<"KAYDINI BULMAK �STED���N�Z ��RENC�N�N ADINI G�R�N�Z:   ";
		cin>>isim;
		
		for(int k=0;k<kayitliogrencisayisi;k++)
		{
			dosya.seekg(k*sizeof(ogrenci));
			dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
			
			if(strcmp(ogrenci.ad,isim)==0)
			{
				cout<<endl<<"��RENC�N�N B�LG�LER� "<<k+1<<". KAYITTA BULUNMU�TUR..."<<endl;
				kayit=true;
                
				cout<<endl<<"---B�LG�LER�---"<<endl<<endl;
				
				dosya.seekg(k*sizeof(ogrenci));
				dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
				
				cout<<"ADI:              "<<ogrenci.ad<<endl;
				cout<<"YA�I:             "<<ogrenci.yas<<endl;
				cout<<"E��T�M DURUMU:    "<<ogrenci.egitimdurumu<<endl;
				cout<<"ANAD�L�:          "<<ogrenci.anadili<<endl;
				cout<<"DERS ALACA�I D�L: "<<ogrenci.dersalacagidil<<endl;
				cout<<"D�L SEV�YES�:     "<<ogrenci.alacagidildekiseviyesi<<endl;
				cout<<"DERS SAAT�:       "<<ogrenci.derssaati<<endl<<endl;
		    }
		}if((!kayit))
		cout<<isim<<" ADINDA ��RENC� KAYDI BULUNAMAMI�TIR..."<<endl<<endl;
		dosya.close();
	}
	
	{//------------------------------��RENC� KAYDI S�LME------------------------------ 
	
	    char isim[20];
		char secim=' ';
		bool var=false;
		
		ifstream dosya;
		dosya.open("ogrenci.dat",ios::binary);
		
		cout<<"KAYDINI S�LMEK �STED���N�Z ��RENC�N�N ADINI G�R�N�Z:   ";
		cin>>isim;
		
		cout<<endl;
		
		for(int j=0;j<kayitliogrencisayisi;j++)
		{
			dosya.seekg(j*sizeof(ogrenci));
			dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
			if(strcmp(ogrenci.ad,isim)==0)
			{
				cout<<"��RENC�N�N B�LG�LER�"<<endl<<endl;
				
				dosya.seekg(j*sizeof(ogrenci));
				dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
				
				cout<<"ADI:              "<<ogrenci.ad<<endl;
				cout<<"YA�I:             "<<ogrenci.yas<<endl;
				cout<<"E��T�M DURUMU:    "<<ogrenci.egitimdurumu<<endl;
				cout<<"ANAD�L�:          "<<ogrenci.anadili<<endl;
				cout<<"DERS ALACA�I D�L: "<<ogrenci.dersalacagidil<<endl;
				cout<<"D�L SEV�YES�:     "<<ogrenci.alacagidildekiseviyesi<<endl;
				cout<<"DERS SAAT�:       "<<ogrenci.derssaati<<endl;
				
				cout<<"KAYDINI S�LMEK �STED���N�Z ��RENC� BUMU ?[E/H] ";
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
			cout<<isim<<" ADINDAK� ��RENC�N�N KAYDI S�L�NM��T�R...";
	    }
		else
		{
			cout<<endl;
			remove("YEDEK.DAT");
			cout<<isim<<" ADINDA ��RENC� KAYDI BULUNAMAMI�TIR...";
		}
	}
    
    {//------------------------------��RENC� KAYDI D�ZELTME------------------------------
   	
	    cout<<endl<<endl;
		char isim[20];
		char secim;
		bool var=false;
		
		ifstream dosya;
		dosya.open("ogrenci.dat",ios::binary);
		
		cout<<endl;
		cout<<"KAYDINI D�ZELTMEK �STED���N�Z ��RENC�N�Z ADINI G�R�N�Z:   ";
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
				cout<<"YA�I:             "<<ogrenci.yas<<endl;
				cout<<"E��T�M DURUMU:    "<<ogrenci.egitimdurumu<<endl;
				cout<<"ANAD�L�:          "<<ogrenci.anadili<<endl;
				cout<<"DERS ALACA�I D�L: "<<ogrenci.dersalacagidil<<endl;
				cout<<"D�L SEV�YES�:     "<<ogrenci.alacagidildekiseviyesi<<endl;
				cout<<"DERS SAAT�:       "<<ogrenci.derssaati<<endl<<endl;
				
				cout<<"KAYDINI D�ZELTMEK �STED���N�Z ��RENC� BU MU [E/H]?  ";
				secim=getch();
				
				if(secim=='E'||secim=='e')
				{
					ofstream dosya;
					dosya.open("YEDEK.DAT",ios::app|ios::binary);
					
					cout<<endl;
					cout<<"��RENC�N�Z ADINI G�R�N�Z:  ";
					cin>>ogrenci.ad;
		
             	    cout<<endl;
   		
		            cout<<"��RENC�N�N YA�INI G�R�N�Z:  ";
	 	            cin>>ogrenci.yas;
		                      
		            cout<<endl;
		
		            cout<<"�LKOKUL        "<<endl;
		            cout<<"ORTAOKUL       "<<endl;
		            cout<<"L�SE           "<<endl;
		            cout<<"�N�VERS�TE     "<<endl;
		            cout<<"MEZUN-�ALI�AN  "<<endl;
		            cout<<"��RENC�N�N E��T�M DURUMUNU G�R�N�Z:   ";
		            cin>>ogrenci.egitimdurumu;
		
	                cout<<endl<<endl;
		            
					cout<<"T�RK�E       "<<endl
	                    <<"�NG�L�ZCE    "<<endl
	                    <<"ALMANCA      "<<endl
	                    <<"FRANSIZCA    "<<endl
	                    <<"RUS�A        "<<endl
	                    <<"�SPANYOLCA   "<<endl
                        <<"��NCE        "<<endl
	                    <<"PORTEK�ZCE   "<<endl
	                    <<"ARAP�A       "<<endl
                        <<"H�NT�E       "<<endl;
	                cout<<"��RENC�N�N ANAD�L�N� G�R�N�Z:   ";
		            cin>>ogrenci.anadili;
		
	    	        cout<<endl<<endl;
		
		            cout<<"T�RK�E       "<<endl
	                    <<"�NG�L�ZCE    "<<endl
	                    <<"ALMANCA      "<<endl
	                    <<"FRANSIZCA    "<<endl
	                    <<"RUS�A        "<<endl
	                    <<"�SPANYOLCA   "<<endl
                        <<"��NCE        "<<endl
	                    <<"PORTEK�ZCE   "<<endl
	                    <<"ARAP�A       "<<endl
                        <<"H�NT�E       "<<endl;
		            cout<<"��RENC�N�N DERS ALMAK �STED��� D�L� G�R�N�Z:   ";
		            cin>>ogrenci.dersalacagidil;
		
	                cout<<endl<<endl;
	                
            		cout<<"A1  (Ba�lanc�� seviyesi)  "<<endl
		                <<"A2                        "<<endl
		                <<"B1                        "<<endl
		                <<"B2                        "<<endl
	                    <<"C1                        "<<endl
	                    <<"C2  (�leri seviye)        "<<endl;
		            cout<<"��RENC�N�N DERS ALMAK �STED��� D�L SEV�YES�N� G�R�N�Z:   ";
		            cin>>ogrenci.alacagidildekiseviyesi;
	
	                cout<<endl<<endl;
	                
		            cout<<"SAAT 10:00 daki ders i�in 10   "<<endl
		                <<"SAAT 14:00 daki ders i�in 14   "<<endl
		                <<"SAAT 18:00 daki ders i�in 18   "<<endl;
		            cout<<"��RENC�N�N DERS ALMAK �STED��� SAAT� G�R�N�Z :   ";
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
			cout<<"��RENC�N�N KAYIDI D�ZELT�LM��T�R..."<<endl<<endl;
	    }
	    else
		{
			cout<<endl;
			remove("YEDEK.DAT");
			cout<<"\n KAYIT BULUNAMADI..."<<endl;
		}
   }
   
   {//------------------------------G�NCELLENM�� OLAN ��RENC� L�STES�------------------------------
		
	    ifstream dosya;
    	dosya.open("ogrenci.dat",ios::binary);
    	
    	cout<<"G�NCELLENM�� KAYITLARDA "<<kayitliogrencisayisi-1<<" ADET ��RENC� BULUNMAKTADIR."<<endl<<endl;
    	if(kayitliogrencisayisi>0)
		{
			for(int k=0;k<kayitliogrencisayisi-1;k++)
			{
				cout<<k+1<<". ��RENC�N�N B�LG�LER�"<<endl<<endl;
				
				dosya.seekg(k*sizeof(ogrenci));
				dosya.read(reinterpret_cast<char*>(&ogrenci),sizeof(ogrenci));
				
				cout<<"ADI:              "<<ogrenci.ad<<endl;
				cout<<"YA�I:             "<<ogrenci.yas<<endl;
				cout<<"E��T�M DURUMU:    "<<ogrenci.egitimdurumu<<endl;
				cout<<"ANAD�L�:          "<<ogrenci.anadili<<endl;
				cout<<"DERS ALACA�I D�L: "<<ogrenci.dersalacagidil<<endl;
				cout<<"D�L SEV�YES�:     "<<ogrenci.alacagidildekiseviyesi<<endl;
				cout<<"DERS SAAT�:       "<<ogrenci.derssaati<<endl<<endl;
			}
    	}
   }
	getch();
	return 0;
}
