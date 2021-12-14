#ifndef MainWindow_H
#define MainWindow_H

#include <Pch.h>

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
	private:
		// Qt Widgets
		QMenuBar* mMenuBar;
		QStatusBar* mStatusBar;
		QWidget* mCentralWidget;
	};
}

#endif // MainWindow_H
