#pragma once

#include <QThread>
#include <QTimer>
#include <QDateTime>

// clock/clockthread.h
class ClockThread : public QThread
{
	Q_OBJECT
signals :
    void sendHora(QString hora);
	void sendData(QString data);
private:
	void run();
	QString m_lastHora;
	QString m_lastData;
	private slots :
	    void timerHit();

};