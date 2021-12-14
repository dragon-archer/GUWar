#include <MainWindow.h>

namespace GU
{
	MainWindow::MainWindow(QWidget* parent)
		: QMainWindow(parent)
	{
		this->setParent(parent);
		this->setupUi();
	}

	MainWindow::~MainWindow()
	{ }

	void MainWindow::setupUi()
	{
		if(this->objectName().isEmpty()) {
			this->setObjectName("MainWindow");
		}
		this->resize(1280, 720);
		QFont qf;
		qf.setPointSize(12);
		this->setFont(qf);
		mCentralWidget = new QWidget(this);
		this->setCentralWidget(mCentralWidget);
		mMenuBar = new QMenuBar(this);
		mMenuBar->setObjectName("mMenuBar");
		mMenuBar->setGeometry(0, 0, 1280, 32);
		this->setMenuBar(mMenuBar);
		mStatusBar = new QStatusBar(this);
		mStatusBar->setObjectName("mStatusBar");
		mStatusBar->setGeometry(0, 692, 1280, 28);
		this->setStatusBar(mStatusBar);

		this->retranslateUi();
	}

	void MainWindow::retranslateUi()
	{
		this->setWindowTitle(QCoreApplication::translate("MainWindow", "GUWar"));
	}
}
