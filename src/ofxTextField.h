#pragma once
///--------------------------------------------------------------------------
///--------------------------------------------------------------------------
///TEXTBOX FOR OF add the following code inside ofSystemUtils.h
///--------------------------------------------------------------------------
///--------------------------------------------------------------------------




#include "ofMain.h"

#ifdef TARGET_WIN32

#include <winuser.h>
#include <commdlg.h>
#define _WIN32_DCOM

#include <windows.h>
#include <shlobj.h>
#include <tchar.h>
#include <stdio.h>
enum ofxTextField_Allingment{
    ofxTextField_Alling_LEFT=0,
    ofxTextField_Alling_RIGHT=2,
    ofxTextField_Alling_CENTER=1
};
#endif
#ifdef TARGET_OSX
enum ofxTextField_Allingment{
    ofxTextField_Alling_LEFT=0,
    ofxTextField_Alling_RIGHT=1,
    ofxTextField_Alling_CENTER=2
};
class obj_ofT_;
extern int quantity_ofBoxes;
#endif




class ofxTextField{
    string text,question, standardAppName;
    bool isCreated,isMultiline,isPassword,isHiding,isDrawing,isCentered;
    void create(int x, int y,int w,int h);
#ifdef TARGET_WIN32
    
    HWND hEdit;
    HWND MainWindow;
    WNDCLASSEXW wc;
	MSG Msg;
#endif
#ifdef TARGET_OSX
    CGRect appWindow;
    obj_ofT_ * pointer;
    void *pointerToWindow;
#endif
    
    int winPosx,winPosy;
	int posX,posY,width,height;
	bool showingScrolBar;
    ofxTextField_Allingment TextDirection_;
public:
    bool activeApp();
    bool isActive();
    ofxTextField();
    ~ofxTextField();
    void draw(int x, int y,int w,int h);
    string getText();
    bool showScrollBar(bool showing = true);
    bool setPassWordMode(bool passwrdmd = true);
    bool setMultiline(bool multiln=true);
    void hide();
    void show();
    bool getIsHiding();
    void hideIfNotDrawing();
    void setText(string dtext="");
    void setTextDir(ofxTextField_Allingment direction= ofxTextField_Alling_CENTER);
};