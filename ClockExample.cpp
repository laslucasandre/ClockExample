#include "MainWindow.h"
#include "clockthread.h"
#include <QApplication>
#include <QDebug>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication clockApplication(argc, argv);
	qDebug() << "main thread ID: " << clockApplication.thread()->currentThreadId();
	
	QString newHora = QDateTime::currentDateTime().toString("hh:mm:ss");
	QString newData = QDateTime::currentDateTime().toString("dd/MM/yy");
	
	qDebug() << "newHora: " << newHora;
	qDebug() << "newData: " << newData;
	
	MainWindow windowMain;
	windowMain.show();
	
	windowMain.SetClockData(newData);
	windowMain.SetClockHora(newHora);
	
	windowMain.SetClockStyle(MainWindow::Basic);
	
	//instantiate thread object
	ClockThread clockThread;
	QObject::connect(&clockThread, SIGNAL(sendHora(QString)), &windowMain, SLOT(SetClockHora(QString)), Qt::QueuedConnection);	
	QObject::connect(&clockThread, SIGNAL(sendData(QString)), &windowMain, SLOT(SetClockData(QString)), Qt::QueuedConnection);	
	
	clockThread.start();
	
	clockApplication.exec();
	clockThread.quit();
	clockThread.wait();	
	
	return 0;
}
