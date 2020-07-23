//
// Created by Francisco Piantoni on 16/07/2020.
//

class GameSettings {
    static GameSettings* _instance;
    int _Width;
    int _Height;
    int _isPlayerinMenu;
    const int _MAXDISPAROSRED;
    const int _MAXDISPAROSBLUE;
    GameSettings () : _Width(820), _Height(840), _isPlayerinMenu(1), _MAXDISPAROSRED(4), _MAXDISPAROSBLUE(4) {}

public:
    static GameSettings* getInstance () {
        if (_instance == nullptr )
            _instance = new GameSettings();
        return _instance;
    }

    /* En el caso que lo quereamos setear desde el main como se implemento con el isPlayerinMenu abajo
    void SetWidth (int Width) {_Width = Width;}
    void SetHeight (int Height) {_Height = Height;}
    */
    void SetisPlayerinMenu (int isPlayerinMenu) {_isPlayerinMenu = isPlayerinMenu;}

    int getMAXDISPAROSRED () { return _MAXDISPAROSRED;};
    int getMAXDISPAROSBLUE () { return _MAXDISPAROSBLUE;};
    int getisPlayerinMenu () {return _isPlayerinMenu;};
    int getWidth () {return _Width;};
    int getHeight () {return _Height;};

};

