/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>
#include <glview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    glView *openGLWidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QComboBox *Vertex_Settenings;
    QLabel *Projection_2;
    QLabel *Projection;
    QPushButton *Vertex_Color;
    QLabel *label_6;
    QLabel *label_5;
    QScrollBar *Scroll_RotateY;
    QLabel *Projection_5;
    QPushButton *Edges_Color;
    QLabel *label_4;
    QPushButton *Projection_Color;
    QComboBox *Edges_Settenings;
    QScrollBar *Scroll_RotateZ;
    QScrollBar *Scroll_ShiftX;
    QScrollBar *Scroll_RotateX;
    QLabel *Projection_7;
    QLabel *Projection_4;
    QLabel *Projection_6;
    QLabel *label_2;
    QScrollBar *Scroll_ShiftY;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *Projection_3;
    QScrollBar *Scroll_ShiftZ;
    QComboBox *comboBox_4;
    QPushButton *pushButton_3;
    QLabel *Projection_8;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label;
    QLabel *label_8;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QDoubleSpinBox *Shift_X;
    QDoubleSpinBox *Shift_Y;
    QDoubleSpinBox *Shift_Z;
    QScrollBar *Scroll_ShiftSize;
    QDoubleSpinBox *Shift_Size;
    QLabel *label_9;
    QScrollBar *ScrollTimer;
    QDoubleSpinBox *Rotate_X;
    QDoubleSpinBox *Rotate_Y;
    QDoubleSpinBox *Rotate_Z;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(945, 680);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color : #c7ccb9;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        openGLWidget = new glView(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(10, 10, 631, 551));
        openGLWidget->setFocusPolicy(Qt::ClickFocus);
        openGLWidget->setAcceptDrops(false);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 640, 131, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #B0BC98;\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"     font: bold 14px;\n"
"     padding: 6px;\n"
"}"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 600, 631, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(520, 640, 121, 32));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #B0BC98;\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"     font: bold 14px;\n"
"     padding: 6px;\n"
"}"));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(650, 70, 201, 51));
        Vertex_Settenings = new QComboBox(centralwidget);
        Vertex_Settenings->addItem(QString());
        Vertex_Settenings->addItem(QString());
        Vertex_Settenings->setObjectName(QString::fromUtf8("Vertex_Settenings"));
        Vertex_Settenings->setGeometry(QRect(650, 170, 201, 31));
        Vertex_Settenings->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"  color: #364330;\n"
"}"));
        Projection_2 = new QLabel(centralwidget);
        Projection_2->setObjectName(QString::fromUtf8("Projection_2"));
        Projection_2->setGeometry(QRect(660, 130, 251, 31));
        Projection_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid #364330;\n"
"  color: #364330;\n"
"	border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"}\n"
"\n"
"background-color : white;"));
        Projection_2->setAlignment(Qt::AlignCenter);
        Projection = new QLabel(centralwidget);
        Projection->setObjectName(QString::fromUtf8("Projection"));
        Projection->setGeometry(QRect(660, 10, 251, 31));
        Projection->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid #364330;\n"
"  color: #364330;\n"
"	border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"}\n"
"\n"
"background-color : white;"));
        Projection->setAlignment(Qt::AlignCenter);
        Vertex_Color = new QPushButton(centralwidget);
        Vertex_Color->setObjectName(QString::fromUtf8("Vertex_Color"));
        Vertex_Color->setGeometry(QRect(850, 170, 61, 61));
        Vertex_Color->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #B0BC98;\n"
"	color: white;\n"
"	border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"     font: bold 14px;\n"
"     padding: 6px;\n"
"}\n"
""));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(670, 630, 31, 31));
        label_6->setStyleSheet(QString::fromUtf8("QLabel{\n"
"  color: #364330;\n"
"}"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(670, 600, 31, 31));
        label_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"  color: #364330;\n"
"}"));
        Scroll_RotateY = new QScrollBar(centralwidget);
        Scroll_RotateY->setObjectName(QString::fromUtf8("Scroll_RotateY"));
        Scroll_RotateY->setGeometry(QRect(740, 600, 161, 20));
        Scroll_RotateY->setMinimum(-628);
        Scroll_RotateY->setMaximum(628);
        Scroll_RotateY->setOrientation(Qt::Horizontal);
        Projection_5 = new QLabel(centralwidget);
        Projection_5->setObjectName(QString::fromUtf8("Projection_5"));
        Projection_5->setGeometry(QRect(660, 530, 251, 31));
        Projection_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  	qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  	border: 1px solid #364330;\n"
"  	color: #364330;\n"
"	border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"}\n"
"\n"
"background-color : white;"));
        Projection_5->setAlignment(Qt::AlignCenter);
        Edges_Color = new QPushButton(centralwidget);
        Edges_Color->setObjectName(QString::fromUtf8("Edges_Color"));
        Edges_Color->setGeometry(QRect(850, 290, 61, 61));
        Edges_Color->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #B0BC98;\n"
"	color: white;\n"
"	border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"     font: bold 14px;\n"
"     padding: 6px;\n"
"}\n"
""));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(670, 570, 31, 31));
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"  color: #364330;\n"
"}"));
        Projection_Color = new QPushButton(centralwidget);
        Projection_Color->setObjectName(QString::fromUtf8("Projection_Color"));
        Projection_Color->setGeometry(QRect(850, 50, 61, 61));
        Projection_Color->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #B0BC98;\n"
"	color: white;\n"
"	border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"     font: bold 14px;\n"
"     padding: 6px;\n"
"}\n"
"\n"
"QPushButton::Pressed{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        Edges_Settenings = new QComboBox(centralwidget);
        Edges_Settenings->addItem(QString());
        Edges_Settenings->addItem(QString());
        Edges_Settenings->addItem(QString());
        Edges_Settenings->setObjectName(QString::fromUtf8("Edges_Settenings"));
        Edges_Settenings->setGeometry(QRect(660, 290, 201, 31));
        Edges_Settenings->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"  color: #364330;\n"
"}"));
        Scroll_RotateZ = new QScrollBar(centralwidget);
        Scroll_RotateZ->setObjectName(QString::fromUtf8("Scroll_RotateZ"));
        Scroll_RotateZ->setGeometry(QRect(740, 630, 161, 20));
        Scroll_RotateZ->setMinimum(-628);
        Scroll_RotateZ->setMaximum(628);
        Scroll_RotateZ->setOrientation(Qt::Horizontal);
        Scroll_ShiftX = new QScrollBar(centralwidget);
        Scroll_ShiftX->setObjectName(QString::fromUtf8("Scroll_ShiftX"));
        Scroll_ShiftX->setGeometry(QRect(740, 430, 161, 20));
        Scroll_ShiftX->setStyleSheet(QString::fromUtf8(""));
        Scroll_ShiftX->setMinimum(-99);
        Scroll_ShiftX->setOrientation(Qt::Horizontal);
        Scroll_RotateX = new QScrollBar(centralwidget);
        Scroll_RotateX->setObjectName(QString::fromUtf8("Scroll_RotateX"));
        Scroll_RotateX->setGeometry(QRect(740, 570, 161, 20));
        Scroll_RotateX->setStyleSheet(QString::fromUtf8("QScrollBar{\n"
"	background-color: rgba(0, 0, 0, 77);\n"
"\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"      border: none;\n"
"      background: none;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: none;\n"
"      background: none;\n"
"}"));
        Scroll_RotateX->setMinimum(-628);
        Scroll_RotateX->setMaximum(628);
        Scroll_RotateX->setOrientation(Qt::Horizontal);
        Projection_7 = new QLabel(centralwidget);
        Projection_7->setObjectName(QString::fromUtf8("Projection_7"));
        Projection_7->setGeometry(QRect(660, 320, 111, 31));
        Projection_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid #364330;\n"
"  color: #364330;\n"
"	border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"}\n"
"\n"
"background-color : white;"));
        Projection_7->setAlignment(Qt::AlignCenter);
        Projection_4 = new QLabel(centralwidget);
        Projection_4->setObjectName(QString::fromUtf8("Projection_4"));
        Projection_4->setGeometry(QRect(660, 360, 251, 31));
        Projection_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid #364330;\n"
"  color: #364330;\n"
"	border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"}\n"
"\n"
"background-color : white;"));
        Projection_4->setAlignment(Qt::AlignCenter);
        Projection_6 = new QLabel(centralwidget);
        Projection_6->setObjectName(QString::fromUtf8("Projection_6"));
        Projection_6->setGeometry(QRect(660, 200, 111, 31));
        Projection_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid #364330;\n"
"  color: #364330;\n"
"	border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"}\n"
"\n"
"background-color : white;"));
        Projection_6->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(670, 430, 31, 31));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"  color: #364330;\n"
"}"));
        Scroll_ShiftY = new QScrollBar(centralwidget);
        Scroll_ShiftY->setObjectName(QString::fromUtf8("Scroll_ShiftY"));
        Scroll_ShiftY->setGeometry(QRect(740, 460, 161, 20));
        Scroll_ShiftY->setStyleSheet(QString::fromUtf8(""));
        Scroll_ShiftY->setMinimum(-99);
        Scroll_ShiftY->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(670, 460, 31, 31));
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"  color: #364330;\n"
"}"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(670, 490, 31, 31));
        label_7->setStyleSheet(QString::fromUtf8("QLabel{\n"
"  color: #364330;\n"
"}"));
        Projection_3 = new QLabel(centralwidget);
        Projection_3->setObjectName(QString::fromUtf8("Projection_3"));
        Projection_3->setGeometry(QRect(660, 250, 251, 31));
        Projection_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid #364330;\n"
"  color: #364330;\n"
"	border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"}\n"
"\n"
"background-color : white;"));
        Projection_3->setAlignment(Qt::AlignCenter);
        Scroll_ShiftZ = new QScrollBar(centralwidget);
        Scroll_ShiftZ->setObjectName(QString::fromUtf8("Scroll_ShiftZ"));
        Scroll_ShiftZ->setGeometry(QRect(740, 490, 161, 20));
        Scroll_ShiftZ->setStyleSheet(QString::fromUtf8("QScrollBar{\n"
"	background-color: rgba(0, 0, 0, 77);\n"
"\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"      border: none;\n"
"      background: none;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: none;\n"
"      background: none;\n"
"}"));
        Scroll_ShiftZ->setMinimum(-99);
        Scroll_ShiftZ->setOrientation(Qt::Horizontal);
        comboBox_4 = new QComboBox(centralwidget);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(650, 50, 201, 31));
        comboBox_4->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"  color: #364330;\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 640, 121, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #B0BC98;\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"     font: bold 14px;\n"
"     padding: 6px;\n"
"}"));
        Projection_8 = new QLabel(centralwidget);
        Projection_8->setObjectName(QString::fromUtf8("Projection_8"));
        Projection_8->setGeometry(QRect(660, 360, 251, 301));
        Projection_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid #364330;\n"
"  color: #364330;\n"
"	border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: #DBF9B8;\n"
"}\n"
"\n"
"background-color : white;"));
        Projection_8->setAlignment(Qt::AlignCenter);
        doubleSpinBox = new QDoubleSpinBox(centralwidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(780, 200, 61, 31));
        doubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox->setSingleStep(0.100000000000000);
        doubleSpinBox->setValue(0.500000000000000);
        doubleSpinBox_2 = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(780, 320, 61, 31));
        doubleSpinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_2->setSingleStep(0.100000000000000);
        doubleSpinBox_2->setValue(5.000000000000000);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 570, 58, 21));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(210, 570, 58, 21));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 570, 113, 21));
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(270, 570, 113, 21));
        lineEdit_3->setReadOnly(true);
        Shift_X = new QDoubleSpinBox(centralwidget);
        Shift_X->setObjectName(QString::fromUtf8("Shift_X"));
        Shift_X->setGeometry(QRect(690, 431, 41, 21));
        Shift_X->setStyleSheet(QString::fromUtf8("QDoubleSpinBox{\n"
"	background-color : #c7ccb9;\n"
"color:rgb(0, 0, 0);\n"
"}"));
        Shift_X->setFrame(true);
        Shift_X->setReadOnly(false);
        Shift_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Shift_X->setMinimum(-99.000000000000000);
        Shift_X->setSingleStep(0.100000000000000);
        Shift_Y = new QDoubleSpinBox(centralwidget);
        Shift_Y->setObjectName(QString::fromUtf8("Shift_Y"));
        Shift_Y->setGeometry(QRect(690, 460, 41, 21));
        Shift_Y->setStyleSheet(QString::fromUtf8("QDoubleSpinBox{\n"
"	background-color : #c7ccb9;\n"
"color:rgb(0, 0, 0);\n"
"}"));
        Shift_Y->setFrame(true);
        Shift_Y->setReadOnly(false);
        Shift_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Shift_Y->setMinimum(-99.000000000000000);
        Shift_Y->setSingleStep(0.100000000000000);
        Shift_Z = new QDoubleSpinBox(centralwidget);
        Shift_Z->setObjectName(QString::fromUtf8("Shift_Z"));
        Shift_Z->setEnabled(true);
        Shift_Z->setGeometry(QRect(690, 494, 41, 20));
        Shift_Z->setStyleSheet(QString::fromUtf8("QDoubleSpinBox{\n"
"	background-color : #c7ccb9;\n"
"color:rgb(0, 0, 0);\n"
"border:none;\n"
"}"));
        Shift_Z->setFrame(true);
        Shift_Z->setReadOnly(false);
        Shift_Z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Shift_Z->setMinimum(-99.000000000000000);
        Shift_Z->setSingleStep(0.100000000000000);
        Scroll_ShiftSize = new QScrollBar(centralwidget);
        Scroll_ShiftSize->setObjectName(QString::fromUtf8("Scroll_ShiftSize"));
        Scroll_ShiftSize->setGeometry(QRect(740, 400, 161, 20));
        Scroll_ShiftSize->setStyleSheet(QString::fromUtf8(""));
        Scroll_ShiftSize->setMinimum(0);
        Scroll_ShiftSize->setOrientation(Qt::Horizontal);
        Shift_Size = new QDoubleSpinBox(centralwidget);
        Shift_Size->setObjectName(QString::fromUtf8("Shift_Size"));
        Shift_Size->setGeometry(QRect(690, 400, 41, 21));
        Shift_Size->setStyleSheet(QString::fromUtf8("QDoubleSpinBox{\n"
"	background-color : #c7ccb9;\n"
"color:rgb(0, 0, 0);\n"
"}"));
        Shift_Size->setFrame(true);
        Shift_Size->setReadOnly(false);
        Shift_Size->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Shift_Size->setMinimum(0.000000000000000);
        Shift_Size->setSingleStep(0.100000000000000);
        Shift_Size->setValue(1.000000000000000);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(670, 400, 31, 31));
        label_9->setStyleSheet(QString::fromUtf8("QLabel{\n"
"  color: #364330;\n"
"}"));
        ScrollTimer = new QScrollBar(centralwidget);
        ScrollTimer->setObjectName(QString::fromUtf8("ScrollTimer"));
        ScrollTimer->setEnabled(false);
        ScrollTimer->setGeometry(QRect(420, 570, 211, 20));
        ScrollTimer->setStyleSheet(QString::fromUtf8("QScrollBar{\n"
"	background-color: rgba(0, 0, 0, 77);\n"
"\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"      border: none;\n"
"      background: none;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: none;\n"
"      background: none;\n"
"}"));
        ScrollTimer->setMinimum(0);
        ScrollTimer->setMaximum(30);
        ScrollTimer->setOrientation(Qt::Horizontal);
        Rotate_X = new QDoubleSpinBox(centralwidget);
        Rotate_X->setObjectName(QString::fromUtf8("Rotate_X"));
        Rotate_X->setEnabled(true);
        Rotate_X->setGeometry(QRect(690, 570, 41, 20));
        Rotate_X->setStyleSheet(QString::fromUtf8("QDoubleSpinBox{\n"
"	background-color : #c7ccb9;\n"
"color:rgb(0, 0, 0);\n"
"border:none;\n"
"}"));
        Rotate_X->setFrame(true);
        Rotate_X->setReadOnly(false);
        Rotate_X->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Rotate_X->setMinimum(-400.000000000000000);
        Rotate_X->setMaximum(400.000000000000000);
        Rotate_X->setSingleStep(0.100000000000000);
        Rotate_Y = new QDoubleSpinBox(centralwidget);
        Rotate_Y->setObjectName(QString::fromUtf8("Rotate_Y"));
        Rotate_Y->setEnabled(true);
        Rotate_Y->setGeometry(QRect(690, 600, 41, 20));
        Rotate_Y->setStyleSheet(QString::fromUtf8("QDoubleSpinBox{\n"
"	background-color : #c7ccb9;\n"
"color:rgb(0, 0, 0);\n"
"border:none;\n"
"}"));
        Rotate_Y->setFrame(true);
        Rotate_Y->setReadOnly(false);
        Rotate_Y->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Rotate_Y->setMinimum(-400.000000000000000);
        Rotate_Y->setMaximum(400.000000000000000);
        Rotate_Y->setSingleStep(0.100000000000000);
        Rotate_Z = new QDoubleSpinBox(centralwidget);
        Rotate_Z->setObjectName(QString::fromUtf8("Rotate_Z"));
        Rotate_Z->setEnabled(true);
        Rotate_Z->setGeometry(QRect(690, 630, 41, 20));
        Rotate_Z->setStyleSheet(QString::fromUtf8("QDoubleSpinBox{\n"
"	background-color : #c7ccb9;\n"
"color:rgb(0, 0, 0);\n"
"border:none;\n"
"}"));
        Rotate_Z->setFrame(true);
        Rotate_Z->setReadOnly(false);
        Rotate_Z->setButtonSymbols(QAbstractSpinBox::NoButtons);
        Rotate_Z->setMinimum(-400.000000000000000);
        Rotate_Z->setMaximum(400.000000000000000);
        Rotate_Z->setSingleStep(0.100000000000000);
        MainWindow->setCentralWidget(centralwidget);
        Projection_8->raise();
        openGLWidget->raise();
        pushButton->raise();
        lineEdit->raise();
        pushButton_2->raise();
        comboBox->raise();
        Vertex_Settenings->raise();
        Projection_2->raise();
        Projection->raise();
        Vertex_Color->raise();
        label_6->raise();
        label_5->raise();
        Scroll_RotateY->raise();
        Projection_5->raise();
        Edges_Color->raise();
        label_4->raise();
        Edges_Settenings->raise();
        Scroll_RotateZ->raise();
        Scroll_ShiftX->raise();
        Scroll_RotateX->raise();
        Projection_7->raise();
        Projection_4->raise();
        Projection_6->raise();
        label_2->raise();
        Scroll_ShiftY->raise();
        label_3->raise();
        label_7->raise();
        Projection_3->raise();
        Scroll_ShiftZ->raise();
        comboBox_4->raise();
        pushButton_3->raise();
        doubleSpinBox->raise();
        doubleSpinBox_2->raise();
        label->raise();
        label_8->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        Projection_Color->raise();
        Shift_X->raise();
        Shift_Y->raise();
        Shift_Z->raise();
        Scroll_ShiftSize->raise();
        Shift_Size->raise();
        label_9->raise();
        ScrollTimer->raise();
        Rotate_X->raise();
        Rotate_Y->raise();
        Rotate_Z->raise();

        retranslateUi(MainWindow);

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Choose file", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Screen", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Saphire", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "White", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Black", nullptr));

        comboBox->setStyleSheet(QCoreApplication::translate("MainWindow", "QComboBox{\n"
"  color: #364330;\n"
"}", nullptr));
        Vertex_Settenings->setItemText(0, QCoreApplication::translate("MainWindow", "Solid", nullptr));
        Vertex_Settenings->setItemText(1, QCoreApplication::translate("MainWindow", "Dashed", nullptr));

        Projection_2->setText(QCoreApplication::translate("MainWindow", "Vertexes", nullptr));
        Projection->setText(QCoreApplication::translate("MainWindow", "Projection", nullptr));
        Vertex_Color->setText(QCoreApplication::translate("MainWindow", "\302\240color", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Z:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        Projection_5->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        Edges_Color->setText(QCoreApplication::translate("MainWindow", "\302\240color", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        Projection_Color->setText(QCoreApplication::translate("MainWindow", "\302\240color", nullptr));
        Edges_Settenings->setItemText(0, QCoreApplication::translate("MainWindow", "Circle", nullptr));
        Edges_Settenings->setItemText(1, QCoreApplication::translate("MainWindow", "Square", nullptr));
        Edges_Settenings->setItemText(2, QCoreApplication::translate("MainWindow", "None", nullptr));

        Projection_7->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        Projection_4->setText(QCoreApplication::translate("MainWindow", "Shift", nullptr));
        Projection_6->setText(QCoreApplication::translate("MainWindow", "Width", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Z:", nullptr));
        Projection_3->setText(QCoreApplication::translate("MainWindow", "Edges", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "Central", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "Parallel", nullptr));

        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Gif", nullptr));
        Projection_8->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Vectors = ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Surface=", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "S:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
