#ifndef SUBTITLEPARSER_H
#define SUBTITLEPARSER_H

#include <QWidget>

class QTimer;

namespace Ui {
class SubtitleParser;
}

class SubtitleParser : public QWidget
{
    Q_OBJECT

public:
    explicit SubtitleParser(QWidget *parent = 0);
    ~SubtitleParser();

signals:
    void signalShowMainInterface ();

private slots:
    void slotTimeout ();

private:
    Ui::SubtitleParser *ui;

    QTimer *welcomeTimer;
};

#endif // SUBTITLEPARSER_H
