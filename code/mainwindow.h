#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QDir>
#include <QPixmap>
#include <QImage>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool isFile=0;
    bool isGray=0;

signals:
    void algo_signal(QImage * img);
    void write_signal(QImage * img);

public slots:
    void read_bmp(QString filePath);
    void write_bmp(QImage * img);
    void algo_slot(QImage * img);

private slots:
    void on_algoBtn_clicked();

    void on_fileinBtn_clicked();

    void on_fileoutBtn_clicked();

    void on_fileRadioBtn_clicked();

    void on_algoRadioBtn_clicked();

    void on_rgbCheckBox_stateChanged(int arg1);

    void on_grayCheckBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
