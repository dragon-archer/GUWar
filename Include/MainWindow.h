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

		// virtual void keyPressEvent(QKeyEvent* event) override;

	public Q_SLOTS:
		void showFps();

	private:
		// Qt Widgets
		QMenuBar* mMenuBar;
		QStatusBar* mStatusBar;
		QWidget* mCentralWidget;
		QTimer *mTimerFps, *mTimerMain;

		Soldier *mSoldier1, *mSoldier2;

		int mFrameCnt;
	};
}

#endif // _GUWAR_MAINWINDOW_H
