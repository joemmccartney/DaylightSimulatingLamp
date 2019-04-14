
#include "homemenu.h"
#include "settingmenu.h"
#include "heartmenu.h"

int main(int argc, char **argv){
    //int w,h;
    QApplication app(argc, argv);

    //QPalette palMain = app.palette();
    //palMain.setColor(QPalette::Window,Qt::black);
    //palMain.setColor(QPalette::WindowText,Qt::green);
    //app.setPalette(palMain);

    HomeMenu window;
    window.show();

    return app.exec();
}
