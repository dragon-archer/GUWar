#ifndef _GUWAR_MAINWINDOW_H
#define _GUWAR_MAINWINDOW_H

#include <Pch.h>
#include <Soldier.h>

namespace GU
{
	class MainWindow : public QMainWindow
	{
		Q_OBJECT

	public:
		MainWindow(QWidget *parent = nullptr);
		~MainWindow();

		void setupUi();
		void retranslateUi();

		void keyPressEvent(QKeyEvent* event);
	private:
		// Qt Widgets
		QMenuBar* mMenuBar;
		QStatusBar* mStatusBar;
		QWidget* mCentralWidget;

		Soldier* mSoldier;
	};
}

#endif // _GUWAR_MAINWINDOW_H
