#include "subtitleparser.h"
#include "maininterface.h"

#include <QApplication>
#include <QTextStream>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication::addLibraryPath("./plugins");
    QApplication a(argc, argv);

    SubtitleParser welcomePage;
    MainInterface mainInterface;

//    QFile css(":/darkTheme.css");
//    if (css.open(QFile::ReadOnly))
//    {
//        QTextStream  styleSheet(&css);
//        mainInterface.setStyleSheet(styleSheet.readAll());
//    }

    QObject::connect(&welcomePage, SIGNAL(signalShowMainInterface ()),
                                 &mainInterface, SLOT(slotShowMainInterface ()));

    welcomePage.show();

    return a.exec();
}
