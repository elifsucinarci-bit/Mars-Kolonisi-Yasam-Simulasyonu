#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Kod bloðu hata verdi diye eklendi.*/
int zarAtVeKontrolEt(int esikDegeri){
	int zar=rand() %100;
	printf("Zar: %d/ Esik: %d ->", zar, esikDegeri);
	
	if(zar< esikDegeri) {
		printf(" BASARÝLÝ\n");
		return 1;
	}
	else {
		printf("BASARÝSÝZ\n");
		return 0;
	}
}

int main () {
 
    /* Rastgelelik durumu için zamana bagli olarak  bir kez baslatiyoruz*/
    srand(time(NULL));

	/* Adim 1: Degiþkenleri tanýmlama. 
	0:Muhurlu degil, 1: Muhurlu
	Gun sayisi 1den baslar
	Tur sayacini gecerli komutlari saymak için kullandýk
	Kum firtinasi tur sayisi zorluguna göre degisecek.*/
	 int saglik =100;
	 int enerji=100;
	 int oksijen=100;
	 int suMiktari=0;
	 int yedekParca=0;
	 int modulHasari=0;
	 int kilitMuhurlu=0;
	 int gunSayisi=1;
	 int turSayaci=0;
	 int firtinaSuresi=0;
	 
	 /* Gecersiz zorluk donguyu kontrol etmek için bayrak*/
	 char zorlukSecimi;
	 int gecersizZorluk=1;
	 
	 
	 /* 3 Adet printfkullanimi giriþ ekranini oyuna hazirlar ve devam için temiz gorunum saglar.*/
	 printf("--\n");
	 printf("MARS KOLONISI YASAM DESTEK SIMILATORUNE HOS GELDINIZ\n");
	 printf("--\n\n");
	 
	 /* Zorluk seviyesi secimi ve do-while kullanýmý*/
	 
	 do{ 
	 printf("Lutfen bir zorluk seviyesi seciniz:\n");
	 printf("[K]- Kolay\n");
	 printf("[N]- Normal\n");
	 printf("[Z]-Zor\n");
	 printf("Seciminiz:");
	 
	 /*Kullanicinin girdiði harfe göre zorluk seviyesi secildi. bastaki bosluk karakteri enter tusuna basildiginda gecici hafizada sahipsiz beklemisini saglar*/
	    scanf(" %c", &zorlukSecimi);
	    
	    /* Zorluk seviyesi için switch-case yapisi*/
	    switch(zorlukSecimi) {
	    	case 'k':
	        case 'K': 
	        
	        /*Hem büyük harfin hem de kücük harfin kabulu için ikiside printf ile yazýldý
			 Kolay seviyede firtina 3 tur surecek 
			 Gecersiz zorluk kýsmýnda 0 ise gecis basarili, donguden cýkýlabilir(butun seviyeler için gecerli).*/
	        printf("\n >>> Kolay mod secildi. Baslangic kaynaklari yuksek.\n\n");
	        suMiktari=50;
	        yedekParca=10;
	        modulHasari=10;
	        firtinaSuresi=3;
	        gecersizZorluk=0;
	        
	        break;
	        
	        case'n':
	       	case'N':
	       		
	       	/*Normal seviyede firtina 5 tur surecek*/
	       	printf("\n>>>  Normal mod secildi. Dengeli baslangic. \n\n");
	       	suMiktari=30;
	       	yedekParca=5;
	       	modulHasari=20;
	       	firtinaSuresi=5;
	       	gecersizZorluk=0;
	       	
	       	break;
	       	
	       	case'z':
	       	case'Z':
	       		
	       	/*Zor seviyede firtina 7 tur surecek
			  Zor seviyede baslangic suyu daha az ve baslangic hasari daha yuksek.*/
	       	printf("\n>>> Zor mod secildi.Kaynaklar kit, tehlike yuksek! \n\n");
	       	suMiktari=15;
	       	yedekParca=2;
	       	modulHasari=40;
	       	firtinaSuresi=7;
	       	gecersizZorluk=0;
	       	
	       	break;
	       	
	       	/*Gecersiz seviye girisinde secim tekrar istenir.*/
	       	default:
	       		
	       	printf("\n[HATA] Gecersiz bir zorluk seviyesi girdiniz! Lutfen tekrar deneyin.\n\n ");
	       	gecersizZorluk=1;
	       	break;
	       }
	      
		   }while(gecersizZorluk==1);
		    /*test amacli kaynak durumunu ekrana basalim*/
		    printf("--Baslangic Durumu--\n");
		    printf("Saglik: %d, Enerji:%d, Oksijen:%d \n", saglik,enerji,oksijen);
		    printf("Su Miktari:%d birim, Yedek Parca:%d adet, Modul Hasari:%%%d \n",suMiktari, yedekParca, modulHasari);
		    printf("Firtina Tur Suresi:%d tur\n", firtinaSuresi);
		    printf("--\n\n");
	  
	  /*Adim1 bitti burada do-while kullanýmý zorluk secimi kisminda kullanýldý ve dongunun devam edip etmeyecegine while dongusu karar verdi. 
	  switch-case yapisi zorluk için girilen harfin kontrolunu yapmakta gorev aldi.*/
	  
	/*Adim 2: Ana komut dongusunu kurma. */
	
	char komut;
	int oyunDevamEdiyor=1;
	
	printf("--SIMILASYON BASLADI! Kurtarma ekibinin gelmesine 15 gun var.-- \n\n");
	do{ 
	/* Her turun basinda oyuncuya secenekler sunulacak þekilde ayarlandý. scanf satýrýnda  buffer hatasýný onlemek için basinda boþluk birakildi.*/
	printf("[G] Kesif [O] Oksijen Uret [T] Tamir  [D] Durum [U] Uyu [K] Kum Firtinasi [H] Hava Kilidi [Q] Cikis \n ");
	printf("Komutunuzu girin: ");
	scanf("%c", &komut);
	
	/*gecersiz komutlarda 0 kalacak gecerli komutlarda 1 olacak.*/
	int turHarcandiMi=0;
	
	/*Komut yonetim sistemi kurma asamasi.*/
	switch(komut) {
		/* case kisminda buyuk ve kucuk harf tanýmlandi.*/
		/*Kesif Blogu*/
		case'g': case'G':
			
		printf("\n>>> Kesif gorevine cikiliyor. \n");
		if(enerji< 15|| oksijen<10){
			printf("[IPTAL] Keske cikmak için yeterli kaynaginiz yok! (Gerekli-> Enerji: 15, Oksijen:10)\n\n");
			turHarcandiMi=0;
			break;
			}
			
		enerji-=15;
		oksijen-=10;
		printf("Kesif Maliyeti: -15 Enerji, -10 Oksijen harcandi.\n");
		
		int suEsikDegeri= (enerji> 40 && oksijen> 30) ? 60:25;
		printf("Su Arama Sonucu->");
		if(zarAtVeKontrolEt(suEsikDegeri)==1){
			printf("[BASARI] Ýstasyon yakinlarinda donus su kaynagi kesfettiniz! +15 Su depolandi.\n");
			suMiktari+=15;
			}
			else {
			printf("Yedek Parca Arama Sonucu->");
		if(zarAtVeKontrolEt(40)==1) {
			
			printf("[BASARI] Eski bir insansiz hava aracinin enkazindan +3 Yedek Parca soktunuz.\n");
			yedekParca+=3;
			}
			else{
				printf("[BASARISIZ] Cevrede kayda deger hicbir kaynak bulunamadi. Eli bos donuyorsunuz. \n");
				}
			}
			int yaralanmaZari= rand() %100;
			printf("Yaralanma Riski Kontrolu-> Zar: %d / Esik:10 veya Modul Hasari>70\n", yaralanmaZari);
			if(yaralanmaZari<10 || modulHasari>70){
				printf("[TEHLIKE] Kesif sirasinda Mars zemininde kaza gecirdiniz ve yaralandiniz! -20 Saglik.\n");
				saglik-=20;
		      	}
		      	else{
		      		printf("[GUVENLI] Kesif gorevi kazasiz tamamlandi.\n");
				  }
				  printf("\n");
		turHarcandiMi=1;
		break; 
	 
		
		/*Oksijen Uretim Blogu*/
		case'o': case'O':
			
		printf("\n>>> Oksijen uretim unitesine giriliyor. \n");
		if(enerji<10) {
			printf("[IPTAL] Enerjiniz yetersiz! Oksijen unitesini calistirmak icin en az 10 Enerji gerekir.\n\n");
			turHarcandiMi=0;
			break;
		}
		int harcanacakSu;
		printf("Donusturmek istediginiz su miktarini girin(Mevcut Su: %d):",suMiktari);
		scanf("%d", &harcanacakSu);
		
		if(harcanacakSu<=0|| harcanacakSu> suMiktari) {
			printf("[IPTAL] Gecersiz veya yetersiz su miktari girdiniz! \n\n");
			turHarcandiMi=0;
			break;
		}
		
		int islenecekSu=harcanacakSu;
		if(harcanacakSu %2!=0) {
			printf("[BILGI] Tek sayida su girdiniz. 1 birim su artakalan olarak depoda kalacak.\n");
			islenecekSu=harcanacakSu - 1;
		}
		if(islenecekSu=00) {
			printf("[IPTAL] Ýslenecek yeterli su miktari olusmadi.\n\n");
			turHarcandiMi=0;
			break;
		}
		int uretilenOksijen= (islenecekSu /2) * 3;
		suMiktari-=islenecekSu;
		oksijen+= uretilenOksijen;
		enerji-=10;
		
		printf("[BASARI] %d birim su harcandi, +%d birim Oksijen uretildi! (-10 Enerji)\n\n", islenecekSu, uretilenOksijen);
	
		turHarcandiMi=1;
		break;
	
		
		/*Tamir Blogu*/
		case't': case'T':
		
		printf("\n>>> Tamir islemleri baslatiliyor. \n");
		if(yedekParca<=0|| modulHasari==0) {
			printf("[IPTAL] Tamir yapilamaz!(Parca yok veya hasar sifir.\n\n");
			turHarcandiMi=0;
			break;
		}
		if(modulHasari<=30) {
			yedekParca-= 1;
			modulHasari-=15;
			printf("Hafif hasar onarildi: 1 Parca harcandi, Hasar 15 azaldi.\n");
		}
		else if(modulHasari<=70) {
			if(yedekParca< 2){ 
			printf("[IPTAL] Orta hasar icin en az 2 parca gerek!\n\n");
			turHarcandiMi=0;
			break;
			}
		
		    yedekParca-=2;
			modulHasari-=30;
			printf("Orta hasar onarildi: 2 Parca harcandi, Hasar 30 azaldi.\n");
			}
			
			else {
				if(yedekParca< 3) {
				printf("[IPTAL] Agir hasar icin en az 3 parca gerek.\n\n");
				turHarcandiMi=0;
				break;
				}
				yedekParca-=3;
				modulHasari-=50;
				printf("Agir hasar onarildi: 3 Parca harcandi, Hasar 50 azaldi.\n");
				}
				
		printf("\n");
		turHarcandiMi=1;
		break;
	
	
	 /*Durum Raporu Blogu (Tur harcamaz.)*/
		case'd': case'D':
		
		printf("\n>>> Durum raporu aliniyor. \n");
	    printf("\n=====\n");
	    printf("     DURUM RAPORU    ");
	    printf("===========\n");
	    printf("Saglik: %d/100 | Enerji: %d/100 | Oksijen: %d/100 \n", saglik,enerji,oksijen);
	    printf("Su: %d | Parca: %d | Hasar: %%%d \n", suMiktari,yedekParca, modulHasari);
	    
	    if(oksijen<25) printf("[UYARI] Oksijen kritik seviyede!\n");
	    if(saglik<30) printf("[UYARI] Saglik kritik seviyede!\n");
	    if(modulHasari>70) printf("[UYARI] Moodul hasari cok yuksek!\n");
	    
	    if(oksijen>=25 && saglik>= 30 && modulHasari<=70) {
	    	printf(">>> TUM SISTEMLER NORMAL <<<\n");
		}
		printf("=====\n\n");
		turHarcandiMi=0;
		break;
	
	
	/*Dinlenme Blogu*/
		case'u': case'U':
			
		printf("\n>>> Karakter dinlenmeye cekiliyor. \n");
		oksijen-=5;
		enerji+=30;
		if(oksijen<20) {
			printf("[TEHLIKE] Oksijen yetersizliginden uyurken bogulma tehlikesi! Can kaybi:-10\n");
			saglik-=10;
		}
		else {
			printf("Huzurlu uyku. +15 Saglik kazanildi.\n");
			saglik+=15;
		}
		printf("\n");
		turHarcandiMi=1;
		break;
	
	
	
		case'k': case'K':
		
		printf("\n>>> Kum Firtinasi Simule Ediliyor! <<<\n");
		/* Firtina ozeti icin cabalar.*/
		int firtinaHasarTurSayisi=0;
		int firtinaKayipSaglik=0;
		int firtinaKayipOksijen=0;
		
	    /*Firtina suresi zorluk derecsine gore belirlenmiþtir.3,5 veya 7 tur.*/
	    int tur;
	    for(tur=1; tur<= firtinaSuresi; tur++) {
	    	printf("\n -----Firtina Turu %d\n----\n", tur);
	    	
	    	/*Cift numarali turlarda rüzgar siddetlenir ve hasar iki katina cikar.*/
	    	int ruzgarKatsayisi=(tur % 2==0) ? 2:1;
	    	if(ruzgarKatsayisi==2) {
	    		printf("[BILGI] Ruzgar siddetlendi! Bu tur hasarlar 2 katina cikacak.\n ");
	    		}
	    		
	    	int firtinaZari= rand() %100;
	    	printf("Firtina Olay Kontrolu->");
	    	
	    	/*Rastgele olay havuzu(0-24: Can Kaybi, 25-49: Oksijen Sizintisi,50-74: Modul Hasari, 75-99: Guvenli)*/
	    	if(firtinaZari< 25) {
	    		int zarar =10* ruzgarKatsayisi;
	    		saglik-= zarar;
	    		firtinaKayipSaglik+=zarar;
	    		firtinaHasarTurSayisi++;
	    		printf("Zar: %d -> [TEHLIKE] Enkaz parcalari carpti! -%d Saglik.\n ", firtinaZari, zarar);
				}
				
			else if(firtinaZari< 50){
				/* Hava kilidi daha once H komutuyla muhurlendiyse sizinti atlanýr.*/
				if (kilitMuhurlu==1) {
					printf("Zar: %d -> [GUVENLI] Hava kilidi muhurlu oldugu icin oksijen sizintisi onlendi!(continue)\n)", firtinaZari);
					continue;
				}
				int sizinti=115* ruzgarKatsayisi;
				oksijen-= sizinti;
				firtinaKayipOksijen+= sizinti;
				firtinaHasarTurSayisi++;
				printf("Zar: %d -> [TEHLIKE] Basic hatti zarar gordu! -%d Oksijen.\n", firtinaZari, sizinti);
				}
				
			else if(firtinaZari < 75) {
				int hasar=15* ruzgarKatsayisi;
				modulHasari+= hasar;
				firtinaHasarTurSayisi++;
				printf("Zar: %d -> [TEHLIKELI] Dis paneller darbe aldi! +%d Modul Hasari.\n", firtinaZari,hasar);
				}
				
			else {
				printf("Zar: %d -> [GUVENLI] Firtina bu tur istisyona zarar vermedi.\n", firtinaZari);
				}
				
		/*Saglik veya oksijen kritik sinira (0) duserse firtina dongusu derhal sonlandirlir.*/
		 if(saglik<=0 || oksijen <=0) {
		 	printf("[KRITIK] Yasamsal fonksiyonlar bitti, firtina dongusunden cikiliyor! (break)\n");
		 	break;
		 }	
		}
		
		/*Dongu sonunda firtina ozeti yazdirilir*/
		printf("\n===== FIRTINA OZETI===\n");
		printf("Hasar Alinan Toplam Tur: %d\n", firtinaHasarTurSayisi);
		printf("Toplam Kaybedilen Saglik: %d\n", firtinaKayipSaglik);
		printf("Toplam Kaybedilen Oksijen: %d\n", firtinaKayipOksijen);
		printf("============\n\n");
		turHarcandiMi=1;
		break;
		
		case'h': case'H':
		
		printf("\n>>> Hava kilidi sifre paneli aciliyor. \n");
		
	/* Sifre o anki gun sayisindan aritmetik olarak turetilir.*/
	char dogruSifre= 'A' + (gunSayisi % 26);
	char tahmin;
	int denemeHakki=3;
	int basariliMi=0;
	
	   printf("[IPUCU] Sifre, alfabede A harfinden bugunun gun sayisi (%d) kadar ilerdeki harftir.\n", gunSayisi);
	   
	   /* do-while dongusu ile sinirli denemede sifre dogrulama*/
	   do{
	   	  printf("Sifre tahmininizi girin (%d hakkiniz kaldi):", denemeHakki);
	   	  scanf("%c", &tahmin);
	   	  
	   	  /*Kücük harf girildiyse büyük harfe donusturulur.*/
	   	  if(tahmin>='a' && tahmin<='z'){
	   	  	tahmin=tahmin-'a'+'A';
			 } 
		  if(tahmin==dogruSifre){
		  	printf("[BASARILI] Sifre dogru! Hava kilidi tamamen muhurlendi.\n\n");
		  	kilitMuhurlu=1;
		  	basariliMi=1;
		  }
		  else{
		  	  denemeHakki--;
		  	  enerji-=5;
		  	  printf("[HATALI] Yanlis sifre! -5 Enerji gitti.");
		  	  
		  	  /*Girilen harf sifreden onceyse ileri,sonraysa geri git ipucu verilir.*/
		  	  if(tahmin<dogruSifre) {
		  	  	printf("(Ipucu: Alfabede daha ILERÝ gitmelisiniz.)\n");
				}
			else{
				printf("(Ipucu: Alfabede daha GERÝ gitmelisiniz.)\n");
			}
		  }
		 /*Kosul: Hem sifre yanlýs olmalý(basariliMi==0) hem de deneme hakký bitmemis olmalý*/
		  }
		  while(basariliMi==0 && denemeHakki> 0);
		  
		  /* 3 deneme de basarisiz olursa modul hasari 20 artar.*/
		  if(basariliMi==0) {
		  	modulHasari+=20;
		  	printf("[BASARISIZ] Tum haklariniz bitti! Sistem bloke oldu ve dýs kapak sarsildi. +20 Modul Hasari.\n\n");
		  	 }
		turHarcandiMi=1;
		break;
		
		case'q': case'Q':
		
		printf("\n>>> Simulasyondan cikis yapiliyor. Elveda muhendis. \n");
		/*Dongunun bitmesini saglar.*/
		oyunDevamEdiyor=0;
		turHarcandiMi=0;
		break;
		
		/*Tanim hissi veren gecersiz komut durumunda default blagu calisir.*/
		default:
		printf("\n [UYARI] Tanimlamayan veya gecersiz bir komut girdiniz! Tur harcanmadi.\n\n");
		/*Tanimlanmamis ya da gecersiz komut alindigi zaman tur harcanmaz.*/
		turHarcandiMi=0;
		break;
	}
	
	/*Zaman Akýsý ve Tur Yonetimi*/
	if(turHarcandiMi==1){
		/*Gecerli komut tur sayacini 1 arttirir.*/
	   turSayaci++;
	   
	   /*Her 3 turda bir yeni bir gun baslar.*/
	   if(turSayaci %3==0) {
	   	gunSayisi++;
	   	printf("\n=====\n");
	   	printf("!!! YENI BIR GUN BASLADI! bugun %d. Gun!!!\n",gunSayisi);
	   	
	   	/*Gun basinda oksijen 8 azalir.*/
	   	oksijen-= 8;
	   	printf("Gunluk oksijen tuketimi: -8 Oksijen\n");
	   	
	   	/*Modul hasari 70'in uzerindeyse ek olarak 5 saglik kaybedilir.*/
	   	if(modulHasari> 70){
	   		saglik-=5;
	   		printf("[KRITIK TEHLIKE] Yuksek modul hasari yuzunden 5 Saglik kaybettiniz!\n ");
	   		 }
	   		 printf("======\n\n");
	
	   }
	}
	
	/* Sinirlandirma
	Degerlerin hiçbir zaman 0'in altina duþmemesi ve 100'u asmamasý için sinirler belitilecek.*/
	if(saglik<0) saglik=0;
	if(saglik>100) saglik=100;
	if(enerji<0) enerji=0;
	if(enerji>100) enerji=100;
	if(oksijen<0) oksijen=0;
	if(oksijen>100) oksijen=100;
	if(modulHasari<0) modulHasari=0;
	if(modulHasari>100) modulHasari=100;
	
	/* Oyun sonu sinirlarin konrtolu:*/
	if(saglik<=0) {
		printf("\n[OYUN BITTI!] Saglik degeriniz tukendi. Mars'ta hayatini kaybettin.\n");
		oyunDevamEdiyor=0;
	}
	
	else if(oksijen<=0){
		printf("\n[OYUN BITTI!] Oksijeniniz tukendi. Bogularak can verdiniz.\n");
		oyunDevamEdiyor=0;
	}
	/*15. gun tamamlaninca kurtarma ekibi gelir.*/
	else if(gunSayisi>15) {
	printf("\n[TEBRIKLER-OYUN KAZANILDI] 15 gun boyunca hayatta kalmayi basardiniz. Kurtarma ekibi ulasti.\n ");
		oyunDevamEdiyor=0;
	}
	
	}while (oyunDevamEdiyor==1);
	
/*Oyun Sonu Sonuc Raporu ve Puanlama*/
/*Oyun donguden ciktiginda buradaki kodlar calisacak.*/

int puan = (gunSayisi*100)+ saglik+oksijen-modulHasari;
printf("\n=====\n");
printf(" SONUC RAPORU \n");
printf("=========\n");
printf("Hayatta Kalinan Gun: %d\n", gunSayisi);
printf("Toplam Yapilan Hamle(Tur): %d\n",turSayaci);
printf("Son Durum-> Saglik:%d | Oksijen: %d | Enerji: %d | Hasar:%%%d\n",saglik,oksijen,enerji,modulHasari);
printf("------\n");
printf("TOPLAM SKORUNUZ: %d Puan\n",puan);
printf("===========\n");

/*Adim 3: Rastgelelik (zar) fonksiyonu yazma.
 Bu fonksiyon uretilen zari ekrana basar.
 Eger zar esik degerinden KUCUKSE olayýn gerceklestirgini(1 /Basarili) bildirir.
 Eger zar esik degerini ESÝT veya BUYUKSE (0/ Basarisiz) bildirir.*/
 
 int zarAtVeKontrolEt(int esikDegeri) {
 	/* 0-99 arasýnda rastgele bir sayi uretiyoruz(rand()% 100) */
 	int zar= rand() %100;
 	
 	/*Odev dokumanýnda istenen zorunlu formatta ekrana yazdýrýyoruz.*/
 	printf("Zar: :%d ->", zar,esikDegeri);
 	
 	if(zar< esikDegeri){
 		/*Burada 1 donerse eylem basarili gerceklesti demektir.*/
 		printf("BASARÝLÝ\n");
 		return 1;
	 }
	 /* Burada 0 donerse eylem basarýsýz gerceklesmedi demektir.*/
	 else{
	 	printf("BASARÝSÝZ\n");
	 	return 0;
	 		 }
 	
 }
	
	
		return 0;
}
