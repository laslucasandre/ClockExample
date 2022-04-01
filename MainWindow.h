#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	
	enum clockStyle
	{
		Basic,
		Circular,
		LCD		
	};
	
	Q_ENUM(clockStyle)
	
	void SetClockStyle(clockStyle clockStyle);

public slots :	
	void SetClockHora(QString newHora);
	void SetClockData(QString newData);
	
protected slots:
    void ButtonClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
