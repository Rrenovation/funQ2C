#ifndef _FUNDEVICE_H
#define _FUNDEVICE_H

#pragma execution_character_set("utf-8")

#include <QAxFactory>
#include <QPixmap>
#include "../functionQ/scrcpy/device.h"
#include "../functionQ/scrcpy/controller/action.h"

//定义相应的bmp数据头结构体
#pragma pack(1)
typedef struct
{
    long imageSize;
    long blank;
    long startPosition;
} BmpHead;

typedef struct
{
    long Length;
    long width;
    long height;
    unsigned short colorPlane;
    unsigned short bitColor;
    long zipFormat;
    long realSize;
    long xPels;
    long yPels;
    long colorUse;
    long colorImportant;
} InfoHead;
#pragma pack()

typedef void (__stdcall *FUNC)();


class FunDevice : public Device
{
    Q_OBJECT
    Q_CLASSINFO("ClassID", "{DF16845C-92CD-4AAB-A982-EB9840E74667}")
    Q_CLASSINFO("InterfaceID", "{616F620B-91C5-4410-A74E-6B81C76FFFE7}")
    Q_CLASSINFO("EventsID", "{E1816BBA-BF5D-4A31-9855-D6BA432055F7}")
public:
    explicit FunDevice(QObject *parent = nullptr);
    ~FunDevice();
private:
    Action *action = Q_NULLPTR;
    void *bmpBuff = Q_NULLPTR;
    FUNC callBackFun;
    uint8_t *data =Q_NULLPTR;
    int width ;
    int height;
public slots:
    virtual void consumeFrame();
    int getFrameData();
    int getBmpPic();
    int getBmpPicSize();
    int getWidth();
    int getHeight();
    void callBack(int callback);

    void setName(QString deviceName);
    QString getName();

    void home();
    void copy();
    void back();
    void menu();
    void appSwitch();
    void power();
    void clear(int num = 1);

    void keyCode(int code);
    void keyCodeHold(int code);
    void keyCodeRelease(int code);
    void click(int x1, int x2,  int id = 0);
    void clickHold(int x1, int x2,  int id = 0);
    void clickRelease(int x1, int x2,  int id = 0);
    void move(int x1, int x2,  int id = 0);


    void sendText(QString text);
    void sendtextEx(QString text);
};

#endif