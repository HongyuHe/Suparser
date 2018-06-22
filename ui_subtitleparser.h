/********************************************************************************
** Form generated from reading UI file 'subtitleparser.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBTITLEPARSER_H
#define UI_SUBTITLEPARSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubtitleParser
{
public:
    QFrame *frameBackground;
    QLabel *labelLoading;

    void setupUi(QWidget *SubtitleParser)
    {
        if (SubtitleParser->objectName().isEmpty())
            SubtitleParser->setObjectName(QStringLiteral("SubtitleParser"));
        SubtitleParser->resize(1000, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/SuParser.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SubtitleParser->setWindowIcon(icon);
        SubtitleParser->setStyleSheet(QLatin1String("QFrame{\n"
"	/*background-image: url(:/welcome/background.jpg);*/\n"
"	border-image: url(:/welcome/background.jpg);\n"
"}\n"
"QLabel{\n"
"	background-color: rgb(20, 20, 20);\n"
"	\n"
"	\n"
"	background-image: url(:/welcome/black.jpg);\n"
"	color: white;\n"
"	border-style:hidden;\n"
"	/*border-color: rgb(148, 254, 255);*/\n"
"    border: 2px solid transparent;\n"
"    border-radius: 6px;\n"
"}\n"
""));
        frameBackground = new QFrame(SubtitleParser);
        frameBackground->setObjectName(QStringLiteral("frameBackground"));
        frameBackground->setGeometry(QRect(0, 0, 1000, 600));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameBackground->sizePolicy().hasHeightForWidth());
        frameBackground->setSizePolicy(sizePolicy);
        frameBackground->setStyleSheet(QStringLiteral(""));
        frameBackground->setFrameShape(QFrame::StyledPanel);
        frameBackground->setFrameShadow(QFrame::Raised);
        labelLoading = new QLabel(frameBackground);
        labelLoading->setObjectName(QStringLiteral("labelLoading"));
        labelLoading->setGeometry(QRect(440, 500, 130, 25));
        labelLoading->setAutoFillBackground(false);
        labelLoading->setStyleSheet(QStringLiteral("border-image: url();"));

        retranslateUi(SubtitleParser);

        QMetaObject::connectSlotsByName(SubtitleParser);
    } // setupUi

    void retranslateUi(QWidget *SubtitleParser)
    {
        SubtitleParser->setWindowTitle(QApplication::translate("SubtitleParser", "SubtitleParser", Q_NULLPTR));
        labelLoading->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SubtitleParser: public Ui_SubtitleParser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBTITLEPARSER_H
