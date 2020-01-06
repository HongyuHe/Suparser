#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QMainWindow>
#include <QStringList>
#include <QString>
#include <QFont>
#include <QMap>
class QTimer;
class QTranslator;


#define DARK 1
#define LIGHT 2
#define CLASSIC 3
#define DEFAULT 4

#define CH 11
#define EN 12

class QSettings;

namespace Ui {
class MainInterface;
}

class MainInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainInterface(QWidget *parent = 0);
    ~MainInterface();

    void subtitleHandle_Ass (QString content);
    void subtitleHandle_Srt (QString content);
    void subtitleHandle_Other (QString content);
    void initConfiguration ();
    void setConfiguration ();

    bool writeInit (QString group, QString key, QString &value);    ///此处引用至关重要；
    bool readInit (QString group, QString key, QString &value);///因为要进行传值！！！
//    void saveAll ();

    static void setTheme (const QString &theme);

protected:
    void closeEvent(QCloseEvent *ev);

private slots:
    void slotShowMainInterface ();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_textEdit_textChanged();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionClose_the_Flie_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionFont_triggered();

    void on_actionDark_Theme_triggered();

    void on_actionLight_Theme_triggered();

    void on_actionClassic_Theme_triggered();

private slots:
    void slotTimeout ();

    void on_actionDefult_Theme_triggered();

    void on_actionAbout_SuParser_triggered();

    void on_actionClick_to_Parse_the_Subtile_File_triggered();

    void on_listWidget_Catalog_doubleClicked(const QModelIndex &index);

    void on_actionChinese_triggered();

    void on_actionEnglish_triggered();

    void on_actionHelp_triggered();

    void on_listWidget_Catalog_clicked(const QModelIndex &index);

private:
    Ui::MainInterface *ui;

///初始化打开文件的信息
    QString m_fileName;
    QString m_content;
    QString m_subtxt;
    QMap<QString, QString> m_catalogMap;
    QStringList m_nameList;
    int m_index;
//    QString conf_file;
///初始化配置文件
    QSettings *m_config;
    int m_theme;
    int m_language;
    QFont m_font;

///其它
    QTimer *title_timer;
    bool  m_isTextchanged;
    QTranslator *m_translator;
};

#endif // MAININTERFACE_H
