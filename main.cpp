#include <iostream>
#include <fstream>

using namespace std;

void change(int choix)
{
    string ligne_1, ligne_2, ligne_3, ligne_4, emplacement("C:/Riot Games/League of Legends/RADS/system/"), langue_cfg("locale=fr_fr"), locale_cfg(emplacement + "locale.cfg"), region_cfg(emplacement + "system.cfg"), launcher_cfg(emplacement + "launcher.cfg");

    ofstream langue(locale_cfg.c_str());
    if (langue)
        langue << langue_cfg;
    else
        cout << "Foirage locale" << endl;

    ifstream region(region_cfg.c_str());
    if (region)
    {
        getline(region, ligne_1);
        getline(region, ligne_2);
        ofstream region(region_cfg.c_str());
        region << ligne_1 << endl;
        region << ligne_2 << endl;
        if (choix==1)
            region << "Region = EUW";
        else
            region << "Region = TR";
    }
    else
        cout << "Foirage region" << endl;

    ifstream launcher(launcher_cfg.c_str());
    if (launcher)
    {
        getline(launcher, ligne_1);
        getline(launcher, ligne_2);
        getline(launcher, ligne_3);
        getline(launcher, ligne_4);
        ofstream launcher(launcher_cfg.c_str());
        if (choix==1)
            launcher << "airConfigProject = lol_air_client_config_euw" << endl;
        else
            launcher << "airConfigProject = lol_air_client_config_tr" << endl;
        launcher << ligne_2 << endl;
        launcher << ligne_3 << endl;
        launcher << ligne_4;
    }
    else
        cout << "Foirage launcher" << endl;
}

int main()
{
    int menu(0);
    while (menu<1 || menu>3)
    {
        cout << "Region Changer V2\n" << endl;
        cout << "1) Euw" << endl;
        cout << "2) Tr" << endl;
        cout << "3) Credits" << endl;
        cin >> menu;
    }
    switch (menu)
    {
    case 1:
        change(1);
        break;
    case 2:
        change(2);
        break;
    case 3:
        cout << "Fait avec <3 par Salzem" << endl;
        break;
    }
    cout << "Au revoir" << endl;
    return 0;
}
