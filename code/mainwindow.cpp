#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, &MainWindow::algo_signal, this, &MainWindow::algo_slot);
    connect(this, &MainWindow::write_signal, this, &MainWindow::write_bmp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::algo_slot(QImage * img)
{
    int width = img->width();
    int height = img->height();
    int depth = img->depth();

    if(isGray){

        if(depth==16)
            img->convertToFormat(QImage::Format_Grayscale16);
        else if(depth<16)
            img->convertToFormat(QImage::Format_Grayscale8);

        QVector<QVector<int>> imgMat;

        for(int i=0; i<height; i++){
            QVector<int> newvec;
            for(int j=0; j<width; j++){
                newvec.append(QColor(img->pixel(j,i)).value());
            }
            imgMat.append(newvec);
        }

        /*
         *
         * user code
         *
         */

        QImage * imgOut = new QImage(width,height,QImage::Format_RGB32);

        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                QColor rgb(imgMat[i][j],imgMat[i][j],imgMat[i][j]);
                imgOut->setPixelColor(j,i,rgb);
            }
        }

        imgOut->convertToFormat(img->format());
        emit write_signal(imgOut);

    }
    else{

        QVector<QVector<int>> imgMatR;
        QVector<QVector<int>> imgMatG;
        QVector<QVector<int>> imgMatB;

        for(int i=0; i<height; i++){
            QVector<int> newvecR;
            QVector<int> newvecG;
            QVector<int> newvecB;
            for(int j=0; j<width; j++){
                newvecR.append(QColor(img->pixel(j,i)).red());
                newvecG.append(QColor(img->pixel(j,i)).green());
                newvecB.append(QColor(img->pixel(j,i)).blue());
            }
            imgMatR.append(newvecR);
            imgMatG.append(newvecG);
            imgMatB.append(newvecB);
        }

        /*
         *
         * user code
         *
         */

        QImage * imgOut = new QImage(width,height,img->format());

        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                QColor rgb(imgMatR[i][j],imgMatG[i][j],imgMatB[i][j]);
                imgOut->setPixelColor(j,i,rgb);
            }
        }

        emit write_signal(imgOut);

    }
}

void MainWindow::read_bmp(QString filePath)
{
    QImage * imgIn = new QImage;
    imgIn->load(filePath);

    emit algo_signal(imgIn);
}

void MainWindow::write_bmp(QImage * img)
{
    QString filePath = "imgOut.bmp";
    filePath = QDir::currentPath() + "/image/" + filePath;

    img->save(filePath,"bmp");
}

void MainWindow::on_algoBtn_clicked()
{
    if(!isFile){
        QString filePath = ui->fileInEdit->text();
        filePath = QDir::currentPath() + "/image/" + filePath;
        read_bmp(filePath);
    }
}

//导入
void MainWindow::on_fileinBtn_clicked()
{
    if(isFile){
        QString imgPath = "imgOut.bmp";
        QString filePath = QDir::currentPath() + "/image/" + imgPath;
        QImage * imgIn = new QImage;

        if(isGray){

            //读取txt
            int width;
            int height;
            QVector<QString> str;
            QVector<QVector<int>> imgMat;
            bool ok;

            //优先hex
            if(ui->checkBox_16->isChecked()){
                //gray
                QString filePath = QDir::currentPath() + "/image/imgHexIn.txt";
                QFile file(filePath);

                if(!file.open(QIODevice::ReadOnly))
                    return;

                QTextStream stream(&file);
                while(!stream.atEnd()){
                    QString line = stream.readLine();
                    str.push_back(line);
                }
                file.close();

                width = str.at(0).toInt(&ok,16);
                height = str.at(1).toInt(&ok,16);

                //写入img
                for(int i=0; i<height; i++){
                    QVector<int> newvec;
                    for(int j=0; j<width; j++){
                        newvec.append(str.at(i*width+j+2).toInt(&ok,16));
                    }
                    imgMat.append(newvec);
                }

                QImage * imgOut = new QImage(width,height,QImage::Format_RGB32);

                for(int i=0; i<height; i++){
                    for(int j=0; j<width; j++){
                        QColor rgb(imgMat[i][j],imgMat[i][j],imgMat[i][j]);
                        imgOut->setPixelColor(j,i,rgb);
                    }
                }

                imgOut->convertToFormat(QImage::Format_Grayscale8);
                filePath = QDir::currentPath() + "/image/imgOut.bmp";
                imgOut->save(filePath);
            }
            else if(ui->checkBox_10->isChecked()){
                //gray
                QString filePath = QDir::currentPath() + "/image/imgDecIn.txt";
                QFile file(filePath);

                if(!file.open(QIODevice::ReadOnly))
                    return;

                QTextStream stream(&file);
                while(!stream.atEnd()){
                    QString line = stream.readLine();
                    str.push_back(line);
                }
                file.close();

                width = str.at(0).toInt(&ok,10);
                height = str.at(1).toInt(&ok,10);

                //写入img
                for(int i=0; i<height; i++){
                    QVector<int> newvec;
                    for(int j=0; j<width; j++){
                        newvec.append(str.at(i*width+j+2).toInt(&ok,10));
                    }
                    imgMat.append(newvec);
                }

                QImage * imgOut = new QImage(width,height,QImage::Format_RGB32);

                for(int i=0; i<height; i++){
                    for(int j=0; j<width; j++){
                        QColor rgb(imgMat[i][j],imgMat[i][j],imgMat[i][j]);
                        imgOut->setPixelColor(j,i,rgb);
                    }
                }

                imgOut->convertToFormat(QImage::Format_Grayscale8);
                filePath = QDir::currentPath() + "/image/imgOut.bmp";
                imgOut->save(filePath);
            }

        }
        else{

            //读取txt
            int width;
            int height;
            QVector<QString> strR;
            QVector<QString> strG;
            QVector<QString> strB;
            QVector<QVector<int>> imgMatR;
            QVector<QVector<int>> imgMatG;
            QVector<QVector<int>> imgMatB;
            bool ok;

            //优先hex
            if(ui->checkBox_16->isChecked()){
                //R
                QString filePathR = QDir::currentPath() + "/image/imgHexInR.txt";
                QFile fileR(filePathR);

                if(!fileR.open(QIODevice::ReadOnly))
                    return;

                QTextStream streamR(&fileR);
                while(!streamR.atEnd()){
                    QString line = streamR.readLine();
                    strR.push_back(line);
                }
                fileR.close();

                //G
                QString filePathG = QDir::currentPath() + "/image/imgHexInG.txt";
                QFile fileG(filePathG);

                if(!fileG.open(QIODevice::ReadOnly))
                    return;

                QTextStream streamG(&fileG);
                while(!streamG.atEnd()){
                    QString line = streamG.readLine();
                    strG.push_back(line);
                }
                fileG.close();

                //B
                QString filePathB = QDir::currentPath() + "/image/imgHexInB.txt";
                QFile fileB(filePathB);

                if(!fileB.open(QIODevice::ReadOnly))
                    return;

                QTextStream streamB(&fileB);
                while(!streamB.atEnd()){
                    QString line = streamB.readLine();
                    strB.push_back(line);
                }
                fileB.close();

                width = strR.at(0).toInt(&ok,16);
                height = strR.at(1).toInt(&ok,16);

                //写入img
                for(int i=0; i<height; i++){
                    QVector<int> newvecR;
                    QVector<int> newvecG;
                    QVector<int> newvecB;
                    for(int j=0; j<width; j++){
                        newvecR.append(strR.at(i*width+j+2).toInt(&ok,16));
                        newvecG.append(strG.at(i*width+j+2).toInt(&ok,16));
                        newvecB.append(strB.at(i*width+j+2).toInt(&ok,16));
                    }
                    imgMatR.append(newvecR);
                    imgMatG.append(newvecG);
                    imgMatB.append(newvecB);
                }

                QImage * imgOut = new QImage(width,height,QImage::Format_RGB32);

                for(int i=0; i<height; i++){
                    for(int j=0; j<width; j++){
                        QColor rgb(imgMatR[i][j],imgMatG[i][j],imgMatB[i][j]);
                        imgOut->setPixelColor(j,i,rgb);
                    }
                }

                imgOut->save(filePath);
            }
            else if(ui->checkBox_10->isChecked()){
                //R
                QString filePathR = QDir::currentPath() + "/image/imgDecInR.txt";
                QFile fileR(filePathR);

                if(!fileR.open(QIODevice::ReadOnly))
                    return;

                QTextStream streamR(&fileR);
                while(!streamR.atEnd()){
                    QString line = streamR.readLine();
                    strR.push_back(line);
                }
                fileR.close();

                //G
                QString filePathG = QDir::currentPath() + "/image/imgDecInG.txt";
                QFile fileG(filePathG);

                if(!fileG.open(QIODevice::ReadOnly))
                    return;

                QTextStream streamG(&fileG);
                while(!streamG.atEnd()){
                    QString line = streamG.readLine();
                    strG.push_back(line);
                }
                fileG.close();

                //B
                QString filePathB = QDir::currentPath() + "/image/imgDecInB.txt";
                QFile fileB(filePathB);

                if(!fileB.open(QIODevice::ReadOnly))
                    return;

                QTextStream streamB(&fileB);
                while(!streamB.atEnd()){
                    QString line = streamB.readLine();
                    strB.push_back(line);
                }
                fileB.close();

                width = strR.at(0).toInt(&ok,10);
                height = strR.at(1).toInt(&ok,10);

                //写入img
                for(int i=0; i<height; i++){
                    QVector<int> newvecR;
                    QVector<int> newvecG;
                    QVector<int> newvecB;
                    for(int j=0; j<width; j++){
                        newvecR.append(strR.at(i*width+j+2).toInt(&ok,10));
                        newvecG.append(strG.at(i*width+j+2).toInt(&ok,10));
                        newvecB.append(strB.at(i*width+j+2).toInt(&ok,10));
                    }
                    imgMatR.append(newvecR);
                    imgMatG.append(newvecG);
                    imgMatB.append(newvecB);
                }

                QImage * imgOut = new QImage(width,height,QImage::Format_RGB32);

                for(int i=0; i<height; i++){
                    for(int j=0; j<width; j++){
                        QColor rgb(imgMatR[i][j],imgMatG[i][j],imgMatB[i][j]);
                        imgOut->setPixelColor(j,i,rgb);
                    }
                }

                imgOut->save(filePath);
            }
        }
    }
}

//导出
void MainWindow::on_fileoutBtn_clicked()
{
    if(isFile){
        QString imgPath = ui->fileInEdit->text();
        QString filePath = QDir::currentPath() + "/image/" + imgPath;
        QImage * imgIn = new QImage;
        imgIn->load(filePath);

        int width = imgIn->width();
        int height = imgIn->height();
        int depth = imgIn->depth();

        if(isGray){

            if(depth==16)
                imgIn->convertToFormat(QImage::Format_Grayscale16);
            else if(depth<16)
                imgIn->convertToFormat(QImage::Format_Grayscale8);

            //读取图片
            QVector<QVector<int>> imgMat;

            for(int i=0; i<height; i++){
                QVector<int> newvec;
                for(int j=0; j<width; j++){
                    newvec.append(QColor(imgIn->pixel(j,i)).value());
                }
                imgMat.append(newvec);
            }

            //写入txt
            if(ui->checkBox_16->isChecked()){
                QString filePath = QDir::currentPath() + "/image/imgHexOut.txt";
                QFile file(filePath);

                if(!file.open(QIODevice::WriteOnly))
                    return;

                QTextStream stream(&file);
                stream << QString("%1").arg(width,4,16,QChar('0')) << "\n"
                       << QString("%1").arg(height,4,16,QChar('0')) << "\n";

                for(int i=0; i<height; i++)
                    for(int j=0; j<width; j++){
                        if(depth==16)
                            stream << QString("%1").arg(imgMat[i][j],4,16,QChar('0')) << "\n";
                        else if(depth < 16)
                            stream << QString("%1").arg(imgMat[i][j],2,16,QChar('0')) << "\n";
                    }

                file.close();
            }
            if(ui->checkBox_10->isChecked()){
                QString filePath = QDir::currentPath() + "/image/imgDecOut.txt";
                QFile file(filePath);

                if(!file.open(QIODevice::WriteOnly))
                    return;

                QTextStream stream(&file);
                stream << width << "\n" << height << "\n";

                for(int i=0; i<height; i++)
                    for(int j=0; j<width; j++){
                        stream << imgMat[i][j] << "\n";
                    }

                file.close();
            }

        }
        else{

            //读取图片
            QVector<QVector<int>> imgMatR;
            QVector<QVector<int>> imgMatG;
            QVector<QVector<int>> imgMatB;

            for(int i=0; i<height; i++){
                QVector<int> newvecR;
                QVector<int> newvecG;
                QVector<int> newvecB;
                for(int j=0; j<width; j++){
                    newvecR.append(QColor(imgIn->pixel(j,i)).red());
                    newvecG.append(QColor(imgIn->pixel(j,i)).green());
                    newvecB.append(QColor(imgIn->pixel(j,i)).blue());
                }
                imgMatR.append(newvecR);
                imgMatG.append(newvecG);
                imgMatB.append(newvecB);
            }

            //写入txt
            if(ui->checkBox_16->isChecked()){
                QString filePathR = QDir::currentPath() + "/image/imgHexOutR.txt";
                QFile fileR(filePathR);
                QString filePathG = QDir::currentPath() + "/image/imgHexOutG.txt";
                QFile fileG(filePathG);
                QString filePathB = QDir::currentPath() + "/image/imgHexOutB.txt";
                QFile fileB(filePathB);

                if(!fileR.open(QIODevice::WriteOnly))
                    return;
                if(!fileG.open(QIODevice::WriteOnly))
                    return;
                if(!fileB.open(QIODevice::WriteOnly))
                    return;

                QTextStream streamR(&fileR);
                QTextStream streamG(&fileG);
                QTextStream streamB(&fileB);
                streamR << QString("%1").arg(width,4,16,QChar('0')) << "\n"
                        << QString("%1").arg(height,4,16,QChar('0')) << "\n";
                streamG << QString("%1").arg(width,4,16,QChar('0')) << "\n"
                        << QString("%1").arg(height,4,16,QChar('0')) << "\n";
                streamB << QString("%1").arg(width,4,16,QChar('0')) << "\n"
                        << QString("%1").arg(height,4,16,QChar('0')) << "\n";

                for(int i=0; i<height; i++)
                    for(int j=0; j<width; j++){
                        streamR << QString("%1").arg(imgMatR[i][j],2,16,QChar('0')) << "\n";
                        streamG << QString("%1").arg(imgMatG[i][j],2,16,QChar('0')) << "\n";
                        streamB << QString("%1").arg(imgMatB[i][j],2,16,QChar('0')) << "\n";
                    }

                fileR.close();
                fileG.close();
                fileB.close();
            }
            if(ui->checkBox_10->isChecked()){
                QString filePathR = QDir::currentPath() + "/image/imgDecOutR.txt";
                QFile fileR(filePathR);
                QString filePathG = QDir::currentPath() + "/image/imgDecOutG.txt";
                QFile fileG(filePathG);
                QString filePathB = QDir::currentPath() + "/image/imgDecOutB.txt";
                QFile fileB(filePathB);

                if(!fileR.open(QIODevice::WriteOnly))
                    return;
                if(!fileG.open(QIODevice::WriteOnly))
                    return;
                if(!fileB.open(QIODevice::WriteOnly))
                    return;

                QTextStream streamR(&fileR);
                QTextStream streamG(&fileG);
                QTextStream streamB(&fileB);
                streamR << width << "\n" << height << "\n";
                streamG << width << "\n" << height << "\n";
                streamB << width << "\n" << height << "\n";

                for(int i=0; i<height; i++)
                    for(int j=0; j<width; j++){
                        streamR << imgMatR[i][j] << "\n";
                        streamG << imgMatG[i][j] << "\n";
                        streamB << imgMatB[i][j] << "\n";
                    }

                fileR.close();
                fileG.close();
                fileB.close();
            }

        }
    }
}

void MainWindow::on_fileRadioBtn_clicked()
{
    if(ui->fileRadioBtn->isChecked()){
        ui->algoRadioBtn->setChecked(false);
        isFile = 1;
    }
    else{
        ui->algoRadioBtn->setChecked(true);
        isFile = 0;
    }
}

void MainWindow::on_algoRadioBtn_clicked()
{
    if(ui->algoRadioBtn->isChecked()){
        ui->fileRadioBtn->setChecked(false);
        isFile = 0;
    }
    else{
        ui->fileRadioBtn->setChecked(true);
        isFile = 1;
    }
}

void MainWindow::on_rgbCheckBox_stateChanged(int arg1)
{
    if(ui->rgbCheckBox->isChecked())
        ui->grayCheckBox->setChecked(false);
    else
        ui->grayCheckBox->setChecked(true);
    isGray = 0;
}

void MainWindow::on_grayCheckBox_stateChanged(int arg1)
{
    if(ui->grayCheckBox->isChecked())
        ui->rgbCheckBox->setChecked(false);
    else
        ui->rgbCheckBox->setChecked(true);
    isGray = 1;
}
