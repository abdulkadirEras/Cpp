#include <cstdlib>
#include <iostream>
#include <string>
#include <filesystem>
#include <windows.h>
#include <Shlobj.h>  // SHGetFolderPath için gerekli
#include <chrono>
#include <thread>
#include <conio.h> // _kbhit ve _getch için gerekli


#define hedefAy 9
#define hedefGun 6

using namespace std;
namespace fs = filesystem;

class DurumMakinesi
{
private:
 
    chrono::steady_clock::time_point sonGuncellemeZamani;
    const int zamanlayiciAraligi = 1000; // 1 saniye
    int sayac = 0; 

public:
    void guncelle() 
    {
        auto suankiZaman = chrono::steady_clock::now();
        auto gecenSure = chrono::duration_cast<chrono::milliseconds>(suankiZaman - sonGuncellemeZamani).count();

        
        
        if (gecenSure >= zamanlayiciAraligi) 
        {
            
            sayac++;
            //cout << "Gecen sure: " << sayac << " saniye" << endl;
            
            
            if (sayac % 5 == 0) 
            {
                //cout << "5 saniye gecti!" << endl;
                yapilacakIslem();
            }

          
            sonGuncellemeZamani = suankiZaman;
        }
    }
    
 
};

void yapilacakIslem();
void baslatmaPrograminaEkle();


int main() 
{
    DurumMakinesi durumMakinesi;
    bool programiBaslat = false; // Programın başlangıçta çalışması için true yapıldı
    time_t suankiZaman = time(nullptr);
    tm* suankiTarih = localtime(&suankiZaman);


    //system("cls");
    // Programın başlangıçta çalışması için kısayol oluştur
    baslatmaPrograminaEkle();

    cout<<"suankiTarih->tm_mon +1: "<< suankiTarih->tm_mon +1 << endl;
    cout<<"suankiTarih->tm_mday: "<< suankiTarih->tm_mday << endl;

    if (suankiTarih->tm_mon +1 >= hedefAy && suankiTarih->tm_mday >= hedefGun ) 
    {
        cout << "Hedef zaman geldi!" << endl;
       
        programiBaslat = true;
    } 
    else 
    {
        programiBaslat = false;
    }


    if(programiBaslat)
    {
        bool devamEt = true;
        while (devamEt)
        {
            durumMakinesi.guncelle();

            // Klavyeden tuş girişi kontrolü
            if (_kbhit()) {
                int tus = _getch();
                if (tus == 'q' || tus == 'Q') {
                    devamEt = false;
                    cout << "Program sonlandiriliyor..." << endl;
                    break;
                }
            }
        }

    }
    else
        cout << "Program baslatilmiyor. Hedef zaman gelmedi." << endl;

    
    
    return 0;
}

void yapilacakIslem()
{
    // Yapılacak işlemler burada tanımlanır
    cout << "Yapilacak islem gerceklestiriliyor..." << endl;
    cout << "Mevcut dizin: " << fs::current_path() << endl;

    cout << "dosyaadi.txt dosyasi aciliyor..." << endl;

    //system("start test.txt");
}



void baslatmaPrograminaEkle() 
{
    // Programın tam yolunu al
    char exeYolu[MAX_PATH];
    GetModuleFileName(NULL, exeYolu, MAX_PATH);
    
    // Başlangıç klasörünün yolunu al
    char baslangicYolu[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_STARTUP, NULL, SHGFP_TYPE_CURRENT, baslangicYolu);
    
    // Kısayol oluştur
    string linkPath = string(baslangicYolu) + "\\program.lnk";
    string command = "powershell -command \"$WS = New-Object -ComObject WScript.Shell; $SC = $WS.CreateShortcut('" + 
                    linkPath + "'); $SC.TargetPath = '" + string(exeYolu) + "'; $SC.Save()\"";
    
    system(command.c_str());

}
