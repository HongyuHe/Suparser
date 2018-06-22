/********************************************************************************
** Form generated from reading UI file 'maininterface.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAININTERFACE_H
#define UI_MAININTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainInterface
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionClose_the_Flie;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionFont;
    QAction *actionDark_Theme;
    QAction *actionLight_Theme;
    QAction *actionClassic_Theme;
    QAction *actionDefult_Theme;
    QAction *actionAbout_SuParser;
    QAction *actionClick_to_Parse_the_Subtile_File;
    QAction *actionChinese;
    QAction *actionEnglish;
    QAction *actionHelp;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QListWidget *listWidget_Catalog;
    QToolBar *toolBar;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuFiles;
    QMenu *menuEdit;
    QMenu *menuSetting;
    QMenu *menuTheme;
    QMenu *menuLanguage_2;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainInterface)
    {
        if (MainInterface->objectName().isEmpty())
            MainInterface->setObjectName(QStringLiteral("MainInterface"));
        MainInterface->resize(1100, 650);
        MainInterface->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/SuParser.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainInterface->setWindowIcon(icon);
        MainInterface->setStyleSheet(QStringLiteral(""));
        actionOpen = new QAction(MainInterface);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/Open4.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainInterface);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/Save2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSave_as = new QAction(MainInterface);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/SaveAs3.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon3);
        actionClose_the_Flie = new QAction(MainInterface);
        actionClose_the_Flie->setObjectName(QStringLiteral("actionClose_the_Flie"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/Close2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose_the_Flie->setIcon(icon4);
        actionUndo = new QAction(MainInterface);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/Undo2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon5);
        actionRedo = new QAction(MainInterface);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icon/Redo2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon6);
        actionPaste = new QAction(MainInterface);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icon/Paste2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon7);
        actionCut = new QAction(MainInterface);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icon/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon8);
        actionCopy = new QAction(MainInterface);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icon/Copy2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon9);
        actionFont = new QAction(MainInterface);
        actionFont->setObjectName(QStringLiteral("actionFont"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icon/Font2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFont->setIcon(icon10);
        actionFont->setVisible(true);
        actionFont->setIconVisibleInMenu(true);
        actionFont->setPriority(QAction::NormalPriority);
        actionDark_Theme = new QAction(MainInterface);
        actionDark_Theme->setObjectName(QStringLiteral("actionDark_Theme"));
        actionLight_Theme = new QAction(MainInterface);
        actionLight_Theme->setObjectName(QStringLiteral("actionLight_Theme"));
        actionClassic_Theme = new QAction(MainInterface);
        actionClassic_Theme->setObjectName(QStringLiteral("actionClassic_Theme"));
        actionClassic_Theme->setIconVisibleInMenu(false);
        actionDefult_Theme = new QAction(MainInterface);
        actionDefult_Theme->setObjectName(QStringLiteral("actionDefult_Theme"));
        actionAbout_SuParser = new QAction(MainInterface);
        actionAbout_SuParser->setObjectName(QStringLiteral("actionAbout_SuParser"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icon/About.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_SuParser->setIcon(icon11);
        actionClick_to_Parse_the_Subtile_File = new QAction(MainInterface);
        actionClick_to_Parse_the_Subtile_File->setObjectName(QStringLiteral("actionClick_to_Parse_the_Subtile_File"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icon/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClick_to_Parse_the_Subtile_File->setIcon(icon12);
        actionChinese = new QAction(MainInterface);
        actionChinese->setObjectName(QStringLiteral("actionChinese"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/pix/214.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChinese->setIcon(icon13);
        actionEnglish = new QAction(MainInterface);
        actionEnglish->setObjectName(QStringLiteral("actionEnglish"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/pix/letter71.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnglish->setIcon(icon14);
        actionHelp = new QAction(MainInterface);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/pix/help8.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon15);
        centralwidget = new QWidget(MainInterface);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMouseTracking(false);
        textEdit->setLayoutDirection(Qt::LeftToRight);
        textEdit->setAutoFillBackground(true);
        textEdit->setStyleSheet(QStringLiteral(""));
        textEdit->setFrameShadow(QFrame::Plain);
        textEdit->setLineWidth(0);

        gridLayout->addWidget(textEdit, 1, 2, 1, 1);

        listWidget_Catalog = new QListWidget(centralwidget);
        listWidget_Catalog->setObjectName(QStringLiteral("listWidget_Catalog"));
        listWidget_Catalog->setLayoutDirection(Qt::LeftToRight);
        listWidget_Catalog->setStyleSheet(QStringLiteral(""));
        listWidget_Catalog->setFrameShadow(QFrame::Plain);
        listWidget_Catalog->setLineWidth(0);

        gridLayout->addWidget(listWidget_Catalog, 1, 0, 1, 2);

        MainInterface->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainInterface);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy1);
        toolBar->setIconSize(QSize(27, 27));
        MainInterface->addToolBar(Qt::LeftToolBarArea, toolBar);
        statusbar = new QStatusBar(MainInterface);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainInterface->setStatusBar(statusbar);
        menubar = new QMenuBar(MainInterface);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1100, 21));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy2);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        menubar->setFont(font);
        menubar->setLayoutDirection(Qt::LeftToRight);
        menubar->setAutoFillBackground(false);
        menubar->setDefaultUp(false);
        menubar->setNativeMenuBar(true);
        menuFiles = new QMenu(menubar);
        menuFiles->setObjectName(QStringLiteral("menuFiles"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/pix/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuFiles->setIcon(icon16);
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/pix/Edit8.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuEdit->setIcon(icon17);
        menuSetting = new QMenu(menubar);
        menuSetting->setObjectName(QStringLiteral("menuSetting"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/pix/Setting8.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuSetting->setIcon(icon18);
        menuTheme = new QMenu(menuSetting);
        menuTheme->setObjectName(QStringLiteral("menuTheme"));
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/icon/Theme3.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon19.addFile(QStringLiteral(":/icon/Theme3.png"), QSize(), QIcon::Normal, QIcon::On);
        menuTheme->setIcon(icon19);
        menuTheme->setToolTipsVisible(true);
        menuLanguage_2 = new QMenu(menuSetting);
        menuLanguage_2->setObjectName(QStringLiteral("menuLanguage_2"));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/pix/accessories-dictionary.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuLanguage_2->setIcon(icon20);
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/pix/home_help.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuHelp->setIcon(icon21);
        MainInterface->setMenuBar(menubar);

        toolBar->addAction(actionOpen);
        toolBar->addAction(actionClick_to_Parse_the_Subtile_File);
        toolBar->addSeparator();
        toolBar->addAction(actionSave);
        toolBar->addAction(actionSave_as);
        toolBar->addAction(actionClose_the_Flie);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addSeparator();
        toolBar->addSeparator();
        menubar->addAction(menuFiles->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuSetting->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFiles->addAction(actionOpen);
        menuFiles->addAction(actionClick_to_Parse_the_Subtile_File);
        menuFiles->addSeparator();
        menuFiles->addAction(actionSave);
        menuFiles->addAction(actionSave_as);
        menuFiles->addSeparator();
        menuFiles->addAction(actionClose_the_Flie);
        menuEdit->addSeparator();
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuSetting->addAction(actionFont);
        menuSetting->addAction(menuTheme->menuAction());
        menuSetting->addAction(menuLanguage_2->menuAction());
        menuTheme->addAction(actionDefult_Theme);
        menuTheme->addAction(actionClassic_Theme);
        menuTheme->addAction(actionDark_Theme);
        menuTheme->addAction(actionLight_Theme);
        menuLanguage_2->addAction(actionChinese);
        menuLanguage_2->addAction(actionEnglish);
        menuHelp->addAction(actionAbout_SuParser);
        menuHelp->addAction(actionHelp);

        retranslateUi(MainInterface);

        QMetaObject::connectSlotsByName(MainInterface);
    } // setupUi

    void retranslateUi(QMainWindow *MainInterface)
    {
        MainInterface->setWindowTitle(QApplication::translate("MainInterface", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainInterface", "Open File", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainInterface", "Open File", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainInterface", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainInterface", "Save", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainInterface", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave_as->setText(QApplication::translate("MainInterface", "Save As...", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave_as->setShortcut(QApplication::translate("MainInterface", "Ctrl+Shift+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionClose_the_Flie->setText(QApplication::translate("MainInterface", "Close the File", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionClose_the_Flie->setToolTip(QApplication::translate("MainInterface", "Close the File", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionClose_the_Flie->setShortcut(QApplication::translate("MainInterface", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("MainInterface", "Undo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainInterface", "Ctrl+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainInterface", "Redo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainInterface", "Ctrl+Y", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainInterface", "Paste", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainInterface", "Ctrl+V", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainInterface", "Cut", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainInterface", "Ctrl+X", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainInterface", "Copy", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainInterface", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionFont->setText(QApplication::translate("MainInterface", "Font", Q_NULLPTR));
        actionDark_Theme->setText(QApplication::translate("MainInterface", "Dark Theme", Q_NULLPTR));
        actionLight_Theme->setText(QApplication::translate("MainInterface", "Light Theme", Q_NULLPTR));
        actionClassic_Theme->setText(QApplication::translate("MainInterface", "Classic Theme", Q_NULLPTR));
        actionDefult_Theme->setText(QApplication::translate("MainInterface", "Defult Theme", Q_NULLPTR));
        actionAbout_SuParser->setText(QApplication::translate("MainInterface", "About SuParser ...", Q_NULLPTR));
        actionClick_to_Parse_the_Subtile_File->setText(QApplication::translate("MainInterface", "Click to Parse the Subtile File", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionClick_to_Parse_the_Subtile_File->setToolTip(QApplication::translate("MainInterface", "Click to Parse the Subtile File", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionClick_to_Parse_the_Subtile_File->setShortcut(QApplication::translate("MainInterface", "Ctrl+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionChinese->setText(QApplication::translate("MainInterface", "Chinese", Q_NULLPTR));
        actionEnglish->setText(QApplication::translate("MainInterface", "English", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("MainInterface", "Help", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainInterface", "toolBar", Q_NULLPTR));
        menuFiles->setTitle(QApplication::translate("MainInterface", "Files", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainInterface", "Edit", Q_NULLPTR));
        menuSetting->setTitle(QApplication::translate("MainInterface", "Setting", Q_NULLPTR));
        menuTheme->setTitle(QApplication::translate("MainInterface", "Theme", Q_NULLPTR));
        menuLanguage_2->setTitle(QApplication::translate("MainInterface", "Language", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainInterface", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainInterface: public Ui_MainInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAININTERFACE_H
