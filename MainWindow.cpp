#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <iostream>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetClockHora(QString newHora)
{
//	QString newHora;
//	newHora = "15:13:01";
	qDebug() << "SetClockHora: " << newHora;
	
	QPalette newColorHora = ui->labelHora->palette();
	
	newColorHora.setColor(ui->labelHora->backgroundRole(), Qt::red);
	newColorHora.setColor(ui->labelHora->foregroundRole(), Qt::yellow);
	
	ui->labelHora->setText(newHora);
	ui->labelHora->setPalette(newColorHora);
		
}


void MainWindow::SetClockData(QString newData)
{
//	QString newData;
//	newData = "01/04/22";
	qDebug() << "SetClockData: " << newData;
	
	QPalette newColorData = ui->labelData->palette();
	
	newColorData.setColor(ui->labelHora->backgroundRole(), Qt::red);
	newColorData.setColor(ui->labelHora->foregroundRole(), Qt::green);
	
	ui->labelData->setText(newData);
	ui->labelData->setPalette(newColorData);	
	
	//ui->labelData->setVisible(false);
	
}

void MainWindow::SetClockStyle(clockStyle clockStyleSelected)
{
	qDebug() << "clockStyleSelected: " << QVariant::fromValue(clockStyleSelected).toString();
	
	switch (clockStyleSelected)
	{
		case clockStyle::Basic:
			qDebug() << "clockStyleSelected Basic ";
			ui->widgetTextClock->setVisible(true);
		break;
		case clockStyle::Circular:
			qDebug() << "clockStyleSelected Circular ";
			ui->widgetTextClock->setVisible(false);
		break;
		case clockStyle::LCD:
			qDebug() << "clockStyleSelected LCD ";
			ui->widgetTextClock->setVisible(false);
		break;
	default:
		qDebug() << "clockStyleSelected default ";
		ui->widgetTextClock->setVisible(true);
		break;
	}
}

void MainWindow::ButtonClicked()
{
    QMessageBox msgBox;
    msgBox.setText("Hello, World!");
    msgBox.setWindowTitle("VisualGDB Qt Demo");
    msgBox.exec();
}
