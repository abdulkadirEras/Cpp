#include <iostream>
using namespace std;
 
class ornek1
{
    public://public (genel): bu etiket altında tanımlanan üyelere programın her yerinden erişilebilir.
        int i;//veri tipinde üye
        void yaz()//fonksiyon tipinde üye
        {
            cout<<"ornek1 sinifi"<<endl;
            cout<<"i= "<<i<<endl;
        }
};

class ornek2
{
    public:
        int i;
        void yaz()
        {
            cout<<"ornek2 sinifi"<<endl;
            cout<<"i= "<<i<<endl;
            cout<<"y= "<<y<<endl;
            cout<<"z= "<<z<<endl;
        }
    private://private (özel): bu etiket altında tanımlanan üyelere sadece sınıf içerisinden erişilebilir.
     // sadece sınıf içinde erişilebilen üyeler
        float y=1.1;
        int z=9;
};

class S
{
    public:
        int a;
};

/*
->İkili Kapsam Çözme Operatörü
Sınıfın dışında tanımlanan fonksiyonun hangi sınıfın üye fonksiyonu olduğunu belirtmek amacıyla 
ikili kapsam çözme operatörü (::) ( binary scope resolution operator ) kullanılır.
Kullanımı:

döndürülenVeriTipi SınıfAdı :: fonksiyonAdı(parametre listesi)
{
    ……..
}
*/

class Sayi
{
    int n;
    public:
        void sakla(int a);
        int al();
};

void Sayi::sakla(int x) // Değiştirici fonksiyon tanımı
{
    n = x;
}

int Sayi::al()
{
    return n;
}



/*

    Değiştirici Fonksiyon
Bir sınıf üyesinin değerini değiştiren fonksiyonlara değiştirici fonksiyon (mutator function ) adı verilir.
Sınıf üyesini değiştirmeyen, sadece bu üyeleri döndüren 
fonksiyonlara erişimici fonksiyon (accessor function ) ismi verilir.
*/
class Ogrenci  
 {
 
  int no,vize,final; //private üyeleri
   public:  // erişimci fonksiyonlar
    int noAl(){return no;}
    int vizeAl(){return vize;}
    int finalAl(){return final;}
 
                 // Değiştirici Fonksiyonlar
       void noAta(int  _no){no=_no;}
       void vizeAta(int  _vize)){vize=_vize;}
       void finalAta(int   _final){final=_final;}
      };

int main()
{

    /*ORNEK1 SINIFI İŞLEMLERİ*/
    ornek1 nesne1;//ornek1 sınıfı tipinde nesne1 nesnesi tanımlanır.

    /*Yapılarda olduğu gibi bir nesnenin veri veya fonksiyon üyelereine erişmek için aşağıda görüldüğü gibi nokta (.) operatörünü kullanırız.*/
    nesne1.i=5;//nesnesinin i üyesine 5 atanır
    nesne1.yaz();//x nesnesinin yaz fonksiyonu çağrılır.

    /*ORNEK2 SINIFI İŞLEMLERİ*/
    ornek2 nesne2; //Ornek2 Sınıfı tipinde nesne2 isimli nesne tanımı
    nesne2.i=23;// nesne2 nesnesin i üyesine 23 atanır; 
    //nesne2.z = 5;        // private olarak tanımlanmış y üyesine erişilemez
    //nesne2.y = 5.2 ;       //private olarak tanımlanmış z üyesine erişilemez
    nesne2.yaz();//// nesne2 nesnesin i üyesine 5 atanır; 
   

   //S SINIFI İŞLEMLERİ
   S m,n;// S tipinde m ve n isminde iki nesne tanımlanır
   
   n.a=8;
   cout<<"n nesnesinin a uyesi: "<<n.a<<endl;

    m=n;//m nesnesine a üyesi eklenir
    cout<<"m nesnesinin a üyesi: "<<m.a<<endl;

    S &ref=n; // n nesnesini gösteren referans değişkeni tanımlanır
    cout<<"ref referansının a üyesi: "<<ref.a<<endl;

    ref.a=7;//ref’in referans olduğu nesnenin a üyesi 7 atanır. yani n nin a üyesine 7 atandı
    cout << "ref referansinin a uyesi: " << ref.a << endl;

    S dizi[3];// S tipinde 3 nesneyi içeren bir dizi tanımlanır
    dizi[2].a = 6; // dizi dizisinin 2. indeksli nesnesinin a uyesine 6 atanır
    cout << "kere dizisinin 2. nesnesinin a uyesi: " << dizi[2].a << endl;


    //SAYI SINIFI İŞLEMLERİ
    Sayi no;
    cout<<"sayi sınıfının işlemleri"<<endl;
    no.sakla(3);
    cout << "n= " << no.al() << endl;
    no.sakla(10);
    cout << "n= " << no.al() << endl;

    return 0;
}