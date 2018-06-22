#include "maininterface.h"
#include "ui_maininterface.h"

#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QCloseEvent>
#include <QMessageBox>
#include <QGuiApplication>
#include <QTextEdit>
#include <QTextBrowser>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QAction>
#include <QRegExp>
#include <QTimer>
#include <QWidget>
#include <QPixmap>
#include <QRect>
#include <QTranslator>
#include <QSettings>
#include <QFont>

MainInterface::MainInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainInterface)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/icon/SuParser.png"));
    ui->listWidget_Catalog->clear();
    ui->menuLanguage_2->setIcon(QIcon(":/pix/accessories-dictionary.png"));
    ui->actionChinese->setIcon(QIcon(":/pix/214.png"));
    ui->actionEnglish->setIcon(QIcon(":/pix/letter-e.png"));

    m_fileName.clear();
    m_content.clear();
    m_subtxt.clear();
    m_catalogMap.clear();
    m_nameList.clear();
    m_isTextchanged = false;
    m_index = 0;

    /*处理标题位置*/
    title_timer = new QTimer(this);
    title_timer->setInterval(10);
    QObject::connect( title_timer, SIGNAL(timeout ()),      //此处也可用简易singleshot：
                                 this, SLOT(slotTimeout ()) );          //QTimer::singleShot(600000, &app, SLOT(quit()));
    title_timer->start();


///*初始化listWidget_Catalog*/
    ui->listWidget_Catalog->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(203, 255, 254);"));
//    ui->listWidget_Catalog->adjustSize();
//    ui->listWidget_Catalog->setGeometry(QRect(328, 240, 329, 27*4));
    ui->listWidget_Catalog->setWordWrap(true);

///*初始化用户翻译文件*/
    m_translator = new QTranslator;
    m_translator->load(":/En2Ch.qm");

 ///*初始化用户配置文件*/
     QFont initfont("Bahnschrift Light", 16);
     m_font = initfont;
     m_theme = DARK;
     m_language = EN;
     m_config = new QSettings("./../config.ini", QSettings::IniFormat);
     initConfiguration();
}

MainInterface::~MainInterface()
{
    delete ui;
}

/////////////////////////////////// Configeration //////////////////////////////////////
   ///*初始化用户配置文件*/
void  MainInterface::initConfiguration()
{
//    QFile conf(conf_file);

    QString confFont;
    QString confTheme;
    QString confLanguage;

    confFont.clear();
    confTheme.clear();
    confLanguage.clear();

    readInit(QString("Font"), "font", confFont);
    readInit(QString("Theme"), "theme", confTheme);
    readInit(QString("Language"), "language", confLanguage);
//    if (conf.open(QIODevice::ReadOnly))
//    {
//        QTextStream data(&conf);
//        QString configure = data.readAll();
//        if (!configure.isEmpty())
//        {
//             QStringList confList = configure.split(" || ");
//             confFont = confList.at(0);
//             confTheme = confList.at(1).toInt();
//             conLanguage = confList.at(2).toInt();
//        }
//    }
//    qDebug() << "#Font:" << confFont <<"#Theme:" << confTheme
//                     << "#Language:" << conLanguage;

///初始化字体///；
    QFont initfont("Bahnschrift Light", 16);
    if (m_font != initfont)
    {
        m_font = (QFont)confFont;
        ui->textEdit->setFont(m_font);
        qDebug() << "Init Font:" << m_font;
    }


///初始化主题///；
qDebug() << "confTheme" << confTheme;
    qDebug() << "confTheme.toInt()" << confTheme.toInt();
    if ( (!confTheme.isEmpty()) && (confTheme.toInt() != 0) )
    {
        m_theme = confTheme.toInt();
        qDebug() << "Init Theme:" << m_theme;
    }

    switch (m_theme) {
    case DARK:
        MainInterface::setTheme(":/darkTheme.css");
        break;
    case LIGHT:
        MainInterface::setTheme(":/lightTheme.css");
        break;
    case CLASSIC:
        MainInterface::setTheme(":/defaultTheme.css");
        break;
    case DEFAULT:
        MainInterface::setTheme(":/defaultTheme2.css");
        break;
    default:
        break;
    }
//    conf.close();

///初始化语言///；
    qDebug() << "confLanguage" << confLanguage;
    qDebug() << "confLanguage.toInt()" << confLanguage.toInt();
    if (!confLanguage.isEmpty() && confLanguage.toInt() != 0)
    {
        m_language = confLanguage.toInt();
        qDebug() << "Init Language:" << m_language;
    }

    switch (m_language) {
    case CH:
        qApp->installTranslator(m_translator);
        ui->retranslateUi(this);
        break;
    case EN:
        qApp->removeTranslator(m_translator);
        ui->retranslateUi(this);
    default:
        break;
    }
}

    /*保存用户配置文件*/
void MainInterface::setConfiguration ()
{
    QString confFont = m_font.toString();
    QString confTheme = QString::number(m_theme);
    QString confLanguage = QString::number(m_language);

    writeInit(QString("Font"), "font", confFont);
    writeInit(QString("Theme"), "theme", confTheme);
    writeInit(QString("Language"), "language", confLanguage);

//    QFile conf(conf_file);  //关闭App时将用户最后的设置写入配置文件；

//    if (conf.open(QIODevice::WriteOnly))
//    {
//        QTextStream configure(&conf);
//        QString content = QString("%1 || %2 || %3").arg(m_font.toString()).
//                                                                            arg(m_theme).arg(m_language);
//        configure << content;
//        qDebug() << "Configure:" << content;
//        flush(configure);
//        conf.close();
//    }else
//    {
//        qFatal("Could Not Open the Configeration !");
//    }
}

bool MainInterface::writeInit (QString group, QString key, QString &value)
{
    if (group.isEmpty() || key.isEmpty())
    {
        return 0;
    }else
    {
        m_config->beginGroup(group);
        m_config->setValue(key, value);
        m_config->endGroup();

        return true;
    }
}

bool MainInterface::readInit(QString group, QString key, QString& value)
{
    value.clear();
    if(group.isEmpty() || key.isEmpty())
    {
        return false;
    }
    else
    {
        //读取用户配置信息
        value = m_config->value(group + "/" + key).toString();
        qDebug() << value;

        return true;
    }
}

void MainInterface::slotShowMainInterface ()
{
    this->show();
}

/*设置随窗口大小改变位置的标题*/
void MainInterface::slotTimeout()
{
     QString title = "SuParser 2.l";
     int pos = width() / 2 - sizeof(title);

     QString strTitle;
     strTitle.clear();
     for (int i = 0; i < pos / 4; i++)  //13寸屏幕5.7、1100X650
     {
         strTitle.append(" ");
     }
     strTitle.append(title);
//     qDebug() << strTitle;

     this->setWindowTitle(strTitle);
}

///////////////////////////////////////////////////// File Action ///////////////////////////////////////////////////////////////////
void MainInterface::on_actionOpen_triggered()
{
//    setToolTip("Open");
    m_fileName = QFileDialog::getOpenFileName(
                this, tr("Choose your file..."),
                "/", tr(     "All types(*.*)"
                                ";;Subtilte files(*.ass *.srt *.ssa *.srt)"
                               ";;Normal text file (*.txt)"
                                ";;Flash ActionScript file (*.as;*.mx);;Ada file (*.ada;*.ads;*.adb)"
                                ";;Assembly language source file (*.asm)"
                                ";;Abstract Syntax Notation One file (*.mib)"
                                ";;Active Server Pages script file (*.asp;*.asp);;AutoIt  (*.au3)"
                                ";;AviSynth scripts files (*.avs;*.avsi);;BaanC file (*.bc;*.cln)"
                                ";;Unix script file (*.bash;*.sh;*.bsh;*.csh;*.bash_ profile;*.bashrc;*.profile);;Batch file (*.bat;*.cmd;*.nt);;BlitzBasic file (*.bb)"
                                ";;C source file (*.c;*.lex)"
                                ";;Categorical Abstract Machine Language (*.ml;*.mli;*.sml;*.thy);;CMake file (*.cmake;*.cmake)"
                                ";;COmmon Business Oriented Language (*.cbl;*.cbd;*.cdb;*.cdc;*.cob);;Csound file (*.orc;*.sco;*.csd)"
                                ";;CoffeeScript file (*.coffee;*.litcoffee)"
                                ";;C++ source file (k. h;*.hpp;*.hxx;*.cpp;k. cxx;*k. cc;k. ino)"
                                ";;C# source file (*.cs)"
                                ";;Cascade Style Sheets file (*.css);;D programming language (*.d);;Diff file (*.diff;*.patch);;Erlang file (*.erl;*.hrl);;ESCRIPT file (*.src;*.em);;Forth file (*.forth)"
                                ";;Fortran free form source file (*.f;*.for;*.f9O;*.f95;*.f2k;*.f23);;Fortran fixed form source file (*.f77);;FreeBasic file (*.bas;*.bi);;Haskell (*.hs;*.lhs;*.las)"
                                ";;Hyper Text Markup Language file  (*.html;*.htm;*.shtml;*.shtm;*.xhtml;*.xht;*.hta);;MS ini file (*.ini;*.inf;*.url;*.wer);;Inno Setup script (*.iss)"
                                ";;Intel HEX binary data (*.hex);;Java source file (*.java)"
                                ";;JavaScript file (*.js;*.jsm;*.jsx;*.ts;*.tsx);;JSON file (*.json)"
                                ";;JavaServer Pages script file (*.jsp);;KiXtart file (*.kix)"
                                ";;List Processing language file (*.lsp;*.lisp);;LaTeX file (*.tex;*.sty);;Lua source File (*.lua)Makefile (*.mak)"
                                ";;MATrix LABoratory (*.m);;MMIXAL file (*.mms);;Nimrod file (*.nim)"
                                ";;extended crontab file (*.tab;*.spf);;MSDOS Style/ASCII Art (*.nfo)"
                                ";;Nullsoft Scriptable Install System script file (*.nsi;*.nsh);;OScript source file (*.osx)"
                                ";;ObjectiveC source  file (*.mm)"
                                ";;Pascal source file (*.pas;*.pp;*.p;*.inc;*.lpr);;Perl source file (*.pl;*.pm;*.plx)"
                                ";;PHP Hypertext Preprocessor file (*.php;*.php3;*.php4;*.php5;*.phps;*.phpt;*.phtml);;PostScript file (*.ps)"
                                ";;Windows PowerShell (*.psl;*.psml);;Properties file (*.properties);;PureBasic file (*.pb);;Python_ file_ (*.py;*.pyw)"
                                ";;R programming l anguage (Nk. r;*k. s;nk. splus)"
                                ";;REBOL file  (k. r;*.reb);;registry file (*k. reg)"
                                ";;Windows Resource file (*.rc);;Ruby file  (*k. rb;*.rbw);;Rust file  (*.rs)"
                                ";;Scheme file  (*.scm;*.smd;*.ss);;Smalltalk file (*.st)"
                                ";;a spice file  (C+. scp;k. out)"
                                ";;Structured Query Language file  (*.sql)"
                                ";;Motorola SRecord binary data  (+. mot;*.srec);;Swift file  (*.swift)"
                                ";;Tool Command Language file (*.tcl)"
                                ";;Tektronix extended HEX binary data (*.tek);;TeX file  (*.tex)"
                                ";;Visual Basic file (k. vb;*.vbs);;txt2tags file (*.t2t)"
                                ";;Verilog file (*.v;*.sv;*.vh;*.svh)"
                                ";;VHSIC Hardware Description Language file (*.vhd;*.vhdl);;Visual Prolog file  (*.pro;*.cl;*.i;*.pack;*.ph)"
                                ";;eXtensible Markup Language file (<. xml;k. xaml;*.xsl;*.xslt;*.xsd;*.xul;*.kml;*.svg;[ YAML_ Ain t Markup Language  (k. yml;*.yaml)"

                                 ));    //双引号提供打开或保存文件格式的选项；

    QFile subFile(m_fileName);

    if (m_fileName.isEmpty())
    {
        qDebug() << "Did not open any flie !";      //此处很重要！不然未打开文件会报错；
    }else if (!subFile.open(QIODevice::ReadOnly))
    {
        qFatal("Could Not Open the File !");
    }else
    {
        qDebug() << m_fileName;
        QStringList tmpList = m_fileName.split("/");
        QStringList nameList = m_fileName.split(".");
            qDebug() << nameList.last();

        QTextStream data(&subFile);
        m_content = data.readAll();

        qDebug() << "A";
        m_nameList << m_fileName;       //将打开文件的名字插入链表；
        m_catalogMap.insert(m_fileName, m_content);   //在Map中插入文件名和内容；
        ui->listWidget_Catalog->addItem(tmpList.last());//在listWedget中插入简化的文件名；

        if( ( !QString::compare(nameList.last() , "ass")) || (!QString::compare(nameList.last() , "ass") ) )
        {
            subtitleHandle_Ass (m_content);
        }else if ( !QString::compare(nameList.last() , "srt"))
        {
            subtitleHandle_Srt (m_content);
        }else
        {
            subtitleHandle_Other(m_content);
        }
        subFile.close();
    }
}

void MainInterface::on_actionClick_to_Parse_the_Subtile_File_triggered()
{
    QString originalName;
    if (!m_nameList.isEmpty())      //必须先判断是否有打开的文件；
    {
        originalName = m_nameList.at(m_index);
    }

    if (!originalName.isEmpty())
    {
        QMap<QString, QString>::const_iterator i =
                   m_catalogMap.find(originalName.append("@SuP"));

        if (i != m_catalogMap.end())        //如果找不到，则说明不是字幕文件，则什么都不做；
        {
            ui->textEdit->setPlainText(i.value());
        }
    }
}

void MainInterface::on_actionSave_triggered()
{
    if (!m_fileName.isEmpty())
    {
        QFile subFile(m_fileName);

        if (!subFile.open(QIODevice::WriteOnly))
        {
            qFatal("Could Not Open the File !");
        }else
        {
            QTextStream data(&subFile);
            QString content = ui->textEdit->toPlainText();
            data << content;

            subFile.close();
        }
    }else
    {
        on_actionSave_as_triggered ();
    }
}

void MainInterface::on_actionSave_as_triggered()
{
    QString saveRout = QFileDialog::getSaveFileName(
                this, tr("Save your file..."),
                "/", tr("Normal text file (*.txt)"
                            ";;All types(*.*)"
                                 ";;Subtilte files(*.ass *.srt *.ssa *.srt)"
                                 ";;Flash ActionScript file (* as;*.mx);;Ada file (*.ada;*.ads;*.adb)"
                                 ";;Assembly language source file (*.asm)"
                                 ";;Abstract Syntax Notation One file (*.mib)"
                                 ";;Active Server Pages script file (*.asp;*.asp);;AutoIt  (*.au3)"
                                 ";;AviSynth scripts files (*.avs;*.avsi);;BaanC file (*.bc;*.cln)"
                                 ";;Unix script file (*.bash;*.sh;*.bsh;*.csh;*.bash_ profile;*.bashrc;*.profile);;Batch file (*.bat;*.cmd;*.nt);;BlitzBasic file (*.bb)"
                                 ";;C source file (*.c;*.lex)"
                                 ";;Categorical Abstract Machine Language (*.ml;*.mli;*.sml;*.thy);;CMake file (*.cmake;*.cmake)"
                                 ";;COmmon Business Oriented Language (*.cbl;*.cbd;*.cdb;*.cdc;*.cob);;Csound file (*.orc;*.sco;*.csd)"
                                 ";;CoffeeScript file (*.coffee;*.litcoffee)"
                                 ";;C++ source file (k.h;*.hpp;*.hxx;*.cpp;k.cxx;*k.cc;k.ino)"
                                 ";;C# source file (*.cs)"
                                 ";;Cascade Style Sheets file (*.css);;D programming language (*.d);;Diff file (*.diff;*.patch);;Erlang file (*.erl;*.hrl);;ESCRIPT file (*.src;*.em);;Forth file (*.forth)"
                                 ";;Fortran free form source file (*.f;*.for;*.f9O;*.f95;*.f2k;*.f23);;Fortran fixed form source file (*.f77);;FreeBasic file (*.bas;*.bi);;Haskell (*.hs;*.lhs;*.las)"
                                 ";;Hyper Text Markup Language file  (*.html;*.htm;*.shtml;*.shtm;*.xhtml;*.xht;*.hta);;MS ini file (*.ini;*.inf;*.url;*.wer);;Inno Setup script (*.iss)"
                                 ";;Intel HEX binary data (*.hex);;Java source file (*.java)"
                                 ";;JavaScript file (*.js;*.jsm;*.jsx;*.ts;*.tsx);;JSON file (*.json)"
                                 ";;JavaServer Pages script file (*.jsp);;KiXtart file (*.kix)"
                                 ";;List Processing language file (*.lsp;*.lisp);;LaTeX file (*.tex;*.sty);;Lua source File (*.lua)Makefile (*.mak)"
                                 ";;MATrix LABoratory (*.m);;MMIXAL file (*.mms);;Nimrod file (*.nim)"
                                 ";;extended crontab file (*.tab;*.spf);;MSDOS Style/ASCII Art (*.nfo)"
                                 ";;Nullsoft Scriptable Install System script file (*.nsi;*.nsh);;OScript source file (*.osx)"
                                 ";;ObjectiveC source  file (*.mm)"
                                 ";;Pascal source file (*.pas;*.pp;*.p;*.inc;*.lpr);;Perl source file (*.pl;*.pm;*.plx)"
                                 ";;PHP Hypertext Preprocessor file (*.php;*.php3;*.php4;*.php5;*.phps;*.phpt;*.phtml);;PostScript file (*.ps)"
                                 ";;Windows PowerShell (*.psl;*.psml);;Properties file (*.properties);;PureBasic file (*.pb);;Python_ file_ (*.py;*.pyw)"
                                 ";;R programming l anguage (Nk. r;*k. s;nk. splus)"
                                 ";;REBOL file  (k. r;*.reb);;registry file (*k. reg)"
                                 ";;Windows Resource file (*.rc);;Ruby file  (*k. rb;*.rbw);;Rust file  (*.rs)"
                                 ";;Scheme file  (*.scm;*.smd;*.ss);;Smalltalk file (*.st)"
                                 ";;a spice file  (C+. scp;k. out)"
                                 ";;Structured Query Language file  (*.sql)"
                                 ";;Motorola SRecord binary data  (+. mot;*.srec);;Swift file  (*.swift)"
                                 ";;Tool Command Language file (*.tcl)"
                                 ";;Tektronix extended HEX binary data (*.tek);;TeX file  (*.tex)"
                                 ";;Visual Basic file (k. vb;*.vbs);;txt2tags file (*.t2t)"
                                 ";;Verilog file (*.v;*.sv;*.vh;*.svh)"
                                 ";;VHSIC Hardware Description Language file (*.vhd;*.vhdl);;Visual Prolog file  (*.pro;*.cl;*.i;*.pack;*.ph)"
                                 ";;eXtensible Markup Language file (<. xml;k. xaml;*.xsl;*.xslt;*.xsd;*.xul;*.kml;*.svg;[ YAML_ Ain t Markup Language  (k. yml;*.yaml)"

                                  ));    //双引号提供打开或保存文件格式的选项；
    qDebug() << saveRout;

    QFile subFile(saveRout);

    if (saveRout.isEmpty())
    {
        qDebug() << "Did not open any flie !";      //此处很重要！不然未打开文件会报错；
    }else if (!subFile.open(QIODevice::WriteOnly))
    {
        qFatal("Could Not Open the File !");
    }else
    {
        QTextStream data(&subFile);
        QString content = ui->textEdit->toPlainText();
        data << content;

        subFile.close();
    }
}

/*关于*/
void MainInterface::on_actionAbout_SuParser_triggered()
{
    QMessageBox msgBox;
    QPixmap icon = QPixmap(":/icon/SuParser.png");

    msgBox.setWindowTitle(tr("About SuParser 2.1"));
    msgBox.setWindowIcon(QIcon(":/icon/SuParser.png"));
//    msgBox.setMinimumSize(400, 300);
//    msgBox.setFixedSize(1000,300);
//    msgBox.setStyleSheet("font: 25 Microsoft JhengHei UI Light;");
    msgBox.setTextInteractionFlags(Qt::TextSelectableByMouse);
    //支持HTML格式文本：
    msgBox.setText( "<h1><font size='16' color= 'green';>SuParser 2.1</font></h1><hr/>" );
    msgBox.setInformativeText( tr(/*"<h1>☺SuParser是以解析.ass .srt字幕文件为主的PC端文本小工具。</h1><hr/>"*/
//                                                     "<font size='13'><sub>Technical support:<br></sub>"
//                                                     "<b><span><font face='Monotype Corsiva'>MorningStar </span>"
//                                                     "<span>工作室</font></span></b><br><hr/>"
                                                     "<font size='11'>【作者】</font>"
                                                     "<strong><font face='隶书' size='14'>贺鸿宇</font></strong>"
                                                     "(<font face='MV Boli'>Ray</font>)<hr/>"
                                                     "<font size='16'>【建议和Bug反馈】</font>"
                                                    "<div><span><font size='11'>GitHub：</font></span><a href=https://github.com/HongyuHe style='color:lightGreen'>github.com/HongyuHe</a></div>"
                                                     "<div><font size='9'>      FaceBook：HongyuHe</font></div>"
                                                     "<div><font size='11'>      QQ：229064282</font></div>"
                                                     "<div><font size='11'>      WeiChat：hhy19980819</font></div>"

                                                     "<div><font size='11'>      Email：hongyu.he@hotmail.com</font></div>"
                                                     ) );
    msgBox.setIconPixmap(icon);

    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();        //exec()返回对应按键的键值；

    switch (ret) {
      case QMessageBox::Ok:
          break;
      default:
          // should never be reached
          break;
    }
}


void MainInterface::on_actionHelp_triggered()
{
    QMessageBox msgBox;
//    QPixmap icon = QPixmap(":/icon/SuParser.png");

    msgBox.setWindowTitle(tr("SuParser Helping page"));
//    msgBox.setWindowIcon(QIcon(":/icon/SuParser.png"));
//    msgBox.setMinimumSize(400, 300);
//    msgBox.setFixedSize(1000,300);
//    msgBox.setStyleSheet("font: 25 Microsoft JhengHei UI Light;");
    //支持HTML格式文本：

    msgBox.setText( tr("<h1>☺《SuParser》是以解析.ass .srt .ssa .sup字幕文件为主的PC端文本小工具。</h1><hr/>" ));
    msgBox.setInformativeText( tr("<h2><font size='6'><b>【主要功能】</b></font></h2>"
                                                     "<div>1、 一键解析.ass .srt .ssa .sup字幕文件，并能够以可读的文本形式显示和保存；</div>"
                                  "<div><span><font size='3'>（免费字幕资源网：</font></span><a href=http://subhd.com/ style='color:lightGreen'>Sub HD字幕站</a>）</div><br>"
                                                     "<div>2、支持C,C++,Java,pascal,C#,XML,SQL,Ada,HTML,PHP,ASP, AutoIt, 汇编, DOS批处理, Caml, COBOL, Cmake, CSS,D, Diff, ActionScript, Fortran, Gui4Cli, Haskell, INNO, JSP, KIXtart, LISP, Lua, Make处理(Makefile), Matlab, INI文件, MS-DOS Style, NSIS, Normal text, Objective-C, Pascal,Python, Javascript,Verilog,Haskell,InnoSetup,CMake,VHDL,Matlab文件的基本编辑和保存功能；<br></div>"
                                                    "<div>3.、支持打开文件目录的显示与操作；<br></div>"
                                                    "<div>4、 提供中文汉化包，可以随时切换语言；<br></div>"
                                                     "<div>5、支持用户自定义字体和主题(2.1版本提供四款主题)，并保存用户配置。<br></div>"
                                                                                       "<h2><font size='6'><b>【使用说明】</b></font></h2>"
                                                                                       "<div>1、点击[Open File]打开文件；<br></div>"
                                                                                      "<div>2、当您打开的是.ass .srt 字母文件时，点击[Click to Parse the Subtile File]可以解析并显示可读字幕内容；<br></div>"
                                                                                      "<div>3、点击[Save] [Save As …]保存当前文件；<br></div>"
                                                                                       "<div>4、点击[Close the File]关闭当前文件，并从文件列表中删除；<br></div>"
                                  /*"<span>Studio</font></span></b><br><hr/>"
                                                     "<sub>Author:</sub>"
                                                     "<strong><font face='隶书' size='13'>贺鸿宇</font></strong>"
                                                     "<i>(<font face='MV Boli'>Ray</font>)</i><hr/>"*/) );
    msgBox.resize(500, 500);
//    msgBox.setIconPixmap(icon);

    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();        //exec()返回对应按键的键值；

    switch (ret) {
      case QMessageBox::Ok:
          break;
      default:
          // should never be reached
          break;
    }
}
//////////////////////////////////// Event //////////////////////////////////////
void MainInterface::closeEvent (QCloseEvent *ev)
{
  /*保存用户配置文件*/
    setConfiguration();

    if (m_isTextchanged)    //给出保存提示框；
    {
        QMessageBox msgBox;
        msgBox.setText( tr("The document has been modified.") );
        msgBox.setInformativeText( tr("Do you want to save your changes?") );
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();        //exec()返回对应按键的键值；

        switch (ret) {
          case QMessageBox::Save:
              if (!m_fileName.isEmpty())
              {
                  on_actionSave_triggered();
              }else
              {
                  on_actionSave_as_triggered();
              }
              break;
          case QMessageBox::Discard:   // Do nothing!
              break;
          case QMessageBox::Cancel:
              ev->ignore();
              break;
          default:
              // should never be reached
              break;
        }
    }
}

///显示点击目录的文件
void MainInterface::on_listWidget_Catalog_doubleClicked(const QModelIndex &index)
{
    m_index = index.row();          //将m__index 和 m_flieName均设为当前值，
    m_fileName = m_nameList.at(m_index);    //确保从m_catalogMap和m_nameList中删除的时当前项；
    QMap<QString, QString>::const_iterator i = m_catalogMap.find(m_fileName);

    ui->textEdit->setPlainText(i.value());
    ui->listWidget_Catalog->setCurrentIndex(index);
}

void MainInterface::on_listWidget_Catalog_clicked(const QModelIndex &index)
{
    m_index = index.row();          //将m__index 和 m_flieName均设为当前值，
    m_fileName = m_nameList.at(m_index);    //确保从m_catalogMap和m_nameList中删除的是当前浏览项；
    QMap<QString, QString>::const_iterator i = m_catalogMap.find(m_fileName);

    ui->textEdit->setPlainText(i.value());
    ui->listWidget_Catalog->setCurrentIndex(index);
}

void MainInterface::on_textEdit_textChanged()
{
    m_isTextchanged = true;
}


//////////////////////////////////// Subtitle Handle ////////////////////////////////////////////////
void MainInterface::subtitleHandle_Ass (QString content)
{
    ui->textEdit->setPlainText(content);

    QStringList allScripts = content.split("[Events]");
    QStringList allSubtitles = allScripts.at(1).split("Dialogue: ");
    QStringList subtitle;
    QStringList body1;
    QStringList body2;
    QString Ch;
    QString En;
    QString text;
    QString margin = "              ";
    text.clear();

    for (int i = 1; i < allSubtitles.size(); i++)
    {
        subtitle.clear();
        body1.clear();
        body2.clear();
        Ch.clear();
        En.clear();

        subtitle = allSubtitles.at(i).split("0,,");
        if (  (!subtitle.at(1).contains( QRegExp("[\\x4e00-\\x9fa5]+") ))    //通过检查是否有中文、“pos”、“”fad“、 ”move“-
             || (subtitle.at(1).contains("pos")) || (subtitle.at(1).contains("fad")) || (subtitle.at(1).contains("move")) || (subtitle.at(1).contains("Comment")) ) //去除无用部分；
        {
            continue;
        }else if ( subtitle.at(1).contains("\\N", Qt::CaseInsensitive) )
        {
            body1 = subtitle.at(1).split("\\N");    //小心“|”导致的Escap Sequence；
            body2 = body1.at(1).split("}");

            Ch = body1.at(0);
            En = body2.last();
        }else
        {
            Ch = subtitle.at(1);
        }

        text.append(margin).append(Ch).append('\n');
        if (!En.isEmpty())
        {
            text.append(margin).append(En).append('\n');
        }
    }  
    m_subtxt = text;       //j将解析后的字母文件存入m_content等待解析；
    m_catalogMap.insert(m_fileName.append("@SuP"), m_subtxt);   //将解析后的内容也插入Map；
    ///字幕文件在QMap中有两份内容，一份是解析前的(key=m_fileName)，另一份是解析后的(key=m_fileName+@SuP)；
}

void  MainInterface::subtitleHandle_Srt (QString content)
{
    ui->textEdit->setPlainText(content);

    QStringList allScripts = content.split(" --> ");
    QString text;
    QString margin = "              ";
    text.clear();

    for (int i = 1; i < allScripts.size(); i++)
    {
        int len = allScripts.at(i).size();
        text.append(margin).append(allScripts.at(i).mid(12, len - 32)).append('\n');
    }
//    m_content.clear();
    m_subtxt = text;       //j将解析后的字母文件存入m_content等待解析；
    m_catalogMap.insert(m_fileName.append("@SuP"), m_subtxt);   //将解析后的内容也插入Map；
}

void MainInterface::subtitleHandle_Other (QString content)
{
    ui->textEdit->setPlainText(content);
}

///////////////////////////////////////////////// Edit Action ///////////////////////////////////////////////
void MainInterface::on_actionUndo_triggered()
{
//    QTextBrowser::backward();
    ui->textEdit->undo();
}

void MainInterface::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainInterface::on_actionClose_the_Flie_triggered()
{
    ui->listWidget_Catalog->removeItemWidget(ui->listWidget_Catalog->currentItem());//从列表中删除内容；
    ui->listWidget_Catalog->takeItem(ui->listWidget_Catalog->currentIndex().row()); //从UI中删除内容；
    m_nameList.removeOne(m_fileName);   //从m_catalogMap和m_nameList中删除的是当前浏览项；
    m_catalogMap.remove(m_fileName);

    ui->textEdit->clear();
}

void MainInterface::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainInterface::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainInterface::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

//////////////////////////////////////////// Setting Action ///////////////////////////////////////////////////
void MainInterface::on_actionFont_triggered()
{
    bool ok;
    m_font = QFontDialog::getFont(&ok, QFont("Times", 14), this);
    if (ok)
    {
        // font is set to the font the user selected
        ui->textEdit->setFont(m_font);
    } else
    {
        // the user canceled the dialog; font is set to the initial
        // value, in this case Times, 12.
       ///*Do nothing!*/
    }
}

void MainInterface::setTheme(const QString &route)
{
    QFile css(route);

    if (!css.open(QIODevice::ReadOnly))
    {
        qFatal("Could Not Open the theme !");
    }else
    {
        QTextStream data(&css);    //将文件与文本流绑定；
        QString theme = data.readAll();       //从文件中读取数据存入content；

        css.close();
        qApp->setStyleSheet(theme);
    }
}

/*主题*/
void MainInterface::on_actionDark_Theme_triggered()
{
    MainInterface::setTheme(":/darkTheme.css");
    m_theme = DARK;
}

void MainInterface::on_actionLight_Theme_triggered()
{
    MainInterface::setTheme(":/lightTheme.css");
    m_theme = LIGHT;
}

void MainInterface::on_actionClassic_Theme_triggered()
{
    MainInterface::setTheme(":/defaultTheme.css");
    m_theme = CLASSIC;
}

void MainInterface::on_actionDefult_Theme_triggered()
{
    MainInterface::setTheme(":/defaultTheme2.css");
    m_theme = DEFAULT;
}

/*翻译*/
void MainInterface::on_actionChinese_triggered()
{
    qApp->installTranslator(m_translator);    //加载翻译文件；
    ui->retranslateUi(this);    //UI界面进行翻译文本替换；
    m_language = CH;
}

void MainInterface::on_actionEnglish_triggered()
{
    qApp->removeTranslator(m_translator);    //加载翻译文件；
    ui->retranslateUi(this);    //UI界面进行翻译文本替换；
    m_language = EN;
}



//void MainInterface::saveAll ()
//{
//    for (int i = 0; i < m_nameList.length(); i++)
//    {
//        if (!m_nameList.at(i).isEmpty())
//        {
//            QFile subFile(m_nameList.at(i));

//            if (!subFile.open(QIODevice::WriteOnly))
//            {
//                qFatal("Could Not Open the File !");
//            }else
//            {
//                QTextStream data(&subFile);
//                QString content = ui->textEdit->toPlainText();
//                data << content;

//                subFile.close();
//            }
//        }
//    }
//}










