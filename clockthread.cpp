#include "clockthread.h"

#include <QDebug>

// clock/clockthread.cpp
void ClockThread::run()
{
	QTimer timer;
	connect(&timer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection);
	timer.setInterval(10);
	timer.start(); // puts one event in the threads event queue
	exec();
	timer.stop();
}

void ClockThread::timerHit()
{
	QString newHora = QDateTime::currentDateTime().toString("hh:mm:ss");
	QString newData = QDateTime::currentDateTime().toString("dd/MM/yy");
	if (m_lastHora != newHora) {
		qDebug() << "timerHit newHora: " << newHora;
		m_lastHora = newHora;
		emit sendHora(newHora);
	}
	if (m_lastData != newData) {
		qDebug() << "timerHit newData: " << newData;
		m_lastData = newData;
		emit sendData(newData);
	}	
}

