/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QRadioButton *algoRadioBtn;
    QLabel *label_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *fileinBtn;
    QPushButton *fileoutBtn;
    QPushButton *algoBtn;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *fileRadioBtn;
    QCheckBox *checkBox_16;
    QCheckBox *checkBox_10;
    QLineEdit *fileInEdit;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *rgbCheckBox;
    QCheckBox *grayCheckBox;
    QFrame *line;
    QLabel *label;
    QFrame *line_2;
    QFrame *line_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(346, 272);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        algoRadioBtn = new QRadioButton(centralwidget);
        algoRadioBtn->setObjectName(QString::fromUtf8("algoRadioBtn"));
        algoRadioBtn->setChecked(true);

        gridLayout->addWidget(algoRadioBtn, 6, 1, 1, 2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 5, 0, 2, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fileinBtn = new QPushButton(centralwidget);
        fileinBtn->setObjectName(QString::fromUtf8("fileinBtn"));

        horizontalLayout->addWidget(fileinBtn);

        fileoutBtn = new QPushButton(centralwidget);
        fileoutBtn->setObjectName(QString::fromUtf8("fileoutBtn"));

        horizontalLayout->addWidget(fileoutBtn);

        algoBtn = new QPushButton(centralwidget);
        algoBtn->setObjectName(QString::fromUtf8("algoBtn"));

        horizontalLayout->addWidget(algoBtn);


        gridLayout->addLayout(horizontalLayout, 8, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        fileRadioBtn = new QRadioButton(centralwidget);
        fileRadioBtn->setObjectName(QString::fromUtf8("fileRadioBtn"));

        horizontalLayout_2->addWidget(fileRadioBtn);

        checkBox_16 = new QCheckBox(centralwidget);
        checkBox_16->setObjectName(QString::fromUtf8("checkBox_16"));
        checkBox_16->setChecked(true);

        horizontalLayout_2->addWidget(checkBox_16);

        checkBox_10 = new QCheckBox(centralwidget);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));

        horizontalLayout_2->addWidget(checkBox_10);


        gridLayout->addLayout(horizontalLayout_2, 5, 1, 1, 2);

        fileInEdit = new QLineEdit(centralwidget);
        fileInEdit->setObjectName(QString::fromUtf8("fileInEdit"));

        gridLayout->addWidget(fileInEdit, 0, 1, 2, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        rgbCheckBox = new QCheckBox(centralwidget);
        rgbCheckBox->setObjectName(QString::fromUtf8("rgbCheckBox"));
        rgbCheckBox->setChecked(true);

        horizontalLayout_3->addWidget(rgbCheckBox);

        grayCheckBox = new QCheckBox(centralwidget);
        grayCheckBox->setObjectName(QString::fromUtf8("grayCheckBox"));

        horizontalLayout_3->addWidget(grayCheckBox);


        gridLayout->addLayout(horizontalLayout_3, 3, 1, 1, 2);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 4, 0, 1, 3);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 2, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 2, 0, 1, 3);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 7, 0, 1, 3);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        algoRadioBtn->setText(QCoreApplication::translate("MainWindow", "\347\256\227\346\263\225\346\250\241\345\274\217", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\240\274\345\274\217\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\250\241\345\274\217\357\274\232", nullptr));
        fileinBtn->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\345\233\276\347\211\207", nullptr));
        fileoutBtn->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272\345\233\276\347\211\207", nullptr));
        algoBtn->setText(QCoreApplication::translate("MainWindow", "\345\244\204\347\220\206\345\233\276\345\203\217", nullptr));
        fileRadioBtn->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\346\250\241\345\274\217", nullptr));
        checkBox_16->setText(QCoreApplication::translate("MainWindow", "16\350\277\233\345\210\266", nullptr));
        checkBox_10->setText(QCoreApplication::translate("MainWindow", "10\350\277\233\345\210\266", nullptr));
        fileInEdit->setText(QCoreApplication::translate("MainWindow", "lena.bmp", nullptr));
        rgbCheckBox->setText(QCoreApplication::translate("MainWindow", "RGB\345\233\276", nullptr));
        grayCheckBox->setText(QCoreApplication::translate("MainWindow", "\345\215\225\350\211\262\351\201\223\345\233\276", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
