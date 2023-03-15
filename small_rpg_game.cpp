#include <iostream>
#include <vector>

using namespace std;

class Karakter
{
public:
    int id;
    int para;
    int aclik;
    int susuzluk;
    bool uyuyorMu;

    Karakter(int id, int para, int aclik, int susuzluk)
    {
        this->id = id;
        this->para = para;
        this->aclik = aclik;
        this->susuzluk = susuzluk;
        this->uyuyorMu = true;
    }

    void yuru()
    {
        if (uyuyorMu == false)
        {
            cout << "Yon gir (w/a/s/d): ";
            char yon;
            cin >> yon;
            cout <<"-----------------------------------"<<endl
                 << "Karakter " << id << " " << yon << " yonunde yurudu " << endl
                 <<"-----------------------------------"<< endl;
        }
        else
        {
            cout <<"-----------------------------------"<< endl
                 << "Once Karakteri Uyandirmaniz Gerek" << endl
                 <<"-----------------------------------"<< endl;
        }
    }

    void yemekeYe()
    {
        if (uyuyorMu == false)
        {
            if (aclik + 10 < 100)
            {
                aclik += 10;
                cout<<"-----------------------------------"<< endl
                    <<"Yemek yiyor" << endl
                    <<"-----------------------------------"<< endl; 
            }
            else
            {
                cout <<"-----------------------------------"<< endl
                     << "Henuz tam olarak acikmadiniz, aclik seviyeniz 90'in altina indiginde yemek yiyebilirsiniz" << endl
                     <<"-----------------------------------"<< endl;
            }
        }
        else
        {
            cout <<"-----------------------------------"<< endl
                 << "Once Karakteri Uyandirmaniz Gerek" << endl
                 <<"-----------------------------------"<< endl;
        }
    }

    void suIc()
    {
        if (uyuyorMu == false)
        {
            if (susuzluk + 10 < 100)
            {
                susuzluk += 10;
                cout<<"-----------------------------------"<< endl
                    << "Su iciyor" << endl
                    <<"-----------------------------------"<< endl;
            }
            else
            {
                cout <<"-----------------------------------"<< endl
                     << "Henuz tam olarak susamadiniz, susuzluk seviyeniz 90'in altina indiginde su icebilirsiniz" << endl
                     <<"-----------------------------------"<< endl;
            }
        }
        else
        {
            cout <<"-----------------------------------"<< endl
                 << "Once Karakteri Uyandirmaniz Gerek" << endl
                 <<"-----------------------------------"<< endl;
        }
    }

    void uyu()
    {
        uyuyorMu = true;
        cout <<"-----------------------------------"<< endl
             << "Uyudu" << endl
             <<"-----------------------------------"<< endl;
    }

    void uyan()
    {
        uyuyorMu = false;
        cout <<"-----------------------------------"<< endl
             << "Uyaniyor" << endl
             <<"-----------------------------------"<< endl;
    }

    void paraGondeer(Karakter &digerKarakter, int miktar)
    {
        if (miktar > 0 && miktar <= para)
        {
            digerKarakter.para += miktar;
            para -= miktar;
            cout << endl
                 << miktar << " TL ID: " << digerKarakter.id << "'e gonderildi" << endl
                 << endl;
        }
        else
        {
            cout << endl
                 << "Gecersiz miktar" << endl
                 << endl;
        }
    }

    void durumGoster()
    {
        cout << "ID: " << id << "  ";
        cout << "Para: " << para << "  ";
        cout << "Aclik: " << aclik << "  ";
        cout << "Susuzluk: " << susuzluk << "  ";
        if (uyuyorMu == 1)
        {
            cout << "Uyuyor" << endl;
        }
        else
        {
            cout << "Uyanik" << endl;
        }
    }

    void aclikAzalt()
    {
        if (aclik > 0)
        {
            aclik--;
        }
        else
        {
            cout << "Karakter " << id << " cok acikti" << endl;
        }
    }

    void susuzlukAzalt()
    {
        if (susuzluk > 0)
        {
            susuzluk--;
        }
        else
        {
            cout << "Karakter " << id << " cok susadi" << endl;
        }
    }
};

int main()
{
    vector<Karakter> karakterler;
    int karakterIdsayici = 0;
    while (true)
    {
        cout << "Birini sec (a: karakter ekle, c: karakter sec, q: quit): ";
        char secenek;
        cin >> secenek;
        cout << endl;
        if (secenek == 'a')
        {
            Karakter karakter(++karakterIdsayici, 100, 100, 100);
            karakterler.push_back(karakter);
            cout << "Karakter " << karakter.id << " nolu ID ile eklendi" << endl;
        }
        else if (secenek == 'c')
        {
            cout << "Karakterin ID'sini gir: ";
            int id;
            cin >> id;
            bool found = false;
            for (int i = 0; i < karakterler.size(); i++)
            {
                if (karakterler[i].id == id)
                {
                    found = true;
                    cout << "Birini sec (m: yuru, e: yemek ye, d: su ic, s: uyu, w: uyan, t: para gonder): ";
                    char secenek;
                    cin >> secenek;
                    if (secenek == 'm')
                    {
                        karakterler[i].yuru();
                    }
                    else if (secenek == 'e')
                    {
                        karakterler[i].yemekeYe();
                    }
                    else if (secenek == 'd')
                    {
                        karakterler[i].suIc();
                    }
                    else if (secenek == 's')
                    {
                        karakterler[i].uyu();
                    }
                    else if (secenek == 'w')
                    {
                        karakterler[i].uyan();
                    }
                    else if (secenek == 't')
                    {
                        cout << "Para gondermek istediginiz karakterin ID'sini giriniz: ";
                        int id;
                        cin >> id;
                        cout << "Kac para gondereceksiniz: ";
                        int miktar;
                        cin >> miktar;
                        for (int j = 0; j < karakterler.size(); j++)
                        {
                            if (karakterler[j].id == id)
                            {
                                karakterler[i].paraGondeer(karakterler[j], miktar);
                                break;
                            }
                        }
                    }
                    else
                    {
                        cout << "Gecersiz eylem" << endl;
                    }

                    cout << "Aktif olan karakterin bilgileri" << endl;
                    karakterler[i].durumGoster();
                    cout << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "gecersiz ID" << endl;
            }
        }
        else if (secenek == 'q')
        {
            cout << "Metaverse evreninden cikiliyor..." << endl;
            break;
        }
        else
        {
            cout << "Gecersiz eylem" << endl;
        }
        cout << "Tum karakterlerin bilgileri" << endl;
        for (int i = 0; i < karakterler.size(); i++)
        {
            karakterler[i].aclikAzalt();
            karakterler[i].susuzlukAzalt();
            karakterler[i].durumGoster();
        }
        cout << endl;
    }
    return 0;
}





























