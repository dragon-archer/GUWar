#include <MainWindow.h>

namespace GU
{
	MainWindow::MainWindow(QWidget* parent)
		: QMainWindow(parent)
	{
		setParent(parent);
		setupUi();
		grabKeyboard();
		mTimerMain = new QTimer(this);
		mTimerMain->setInterval(1000ms);
		connect(mTimerMain, QTimer::timeout, mSoldier1, Soldier::attack);
		connect(mTimerMain, QTimer::timeout, mSoldier2, Soldier::attack);
		mTimerMain->start();
		// mTimerFps = new QTimer(this);
		// mTimerFps->setInterval(1000ms);
		// connect(mTimerFps, QTimer::timeout, this, MainWindow::showFps);
		// mFrameCnt = 0;
		// mTimerFps->start();
	}

	MainWindow::~MainWindow()
	{ }

	void MainWindow::setupUi()
	{
		if(objectName().isEmpty()) {
			setObjectName("MainWindow");
		}
		resize(1280, 720);
		setFixedSize(1280, 720);
		QFont qf;
		qf.setPointSize(12);
		setFont(qf);
		mCentralWidget = new QWidget(this);
		mCentralWidget->setGeometry(0, 32, 1280, 660);
		setCentralWidget(mCentralWidget);
		mMenuBar = new QMenuBar(this);
		mMenuBar->setObjectName("mMenuBar");
		mMenuBar->setGeometry(0, 0, 1280, 32);
		setMenuBar(mMenuBar);
		mStatusBar = new QStatusBar(this);
		mStatusBar->setObjectName("mStatusBar");
		mStatusBar->setGeometry(0, 692, 1280, 28);
		setStatusBar(mStatusBar);
		mSoldier1 = new Soldier(mCentralWidget);
		mSoldier1->setPosition({600, 400});
		mSoldier1->setObjectName("mSoldier1");
		mSoldier1->setTeam(0);
		mSoldier2 = new Soldier(mCentralWidget);
		mSoldier2->setPosition({800, 300});
		mSoldier2->setObjectName("mSoldier2");
		mSoldier2->setTeam(1);

		retranslateUi();
	}

	void MainWindow::retranslateUi()
	{
		this->setWindowTitle(QCoreApplication::translate("MainWindow", "GUWar"));
	}

	// void MainWindow::keyPressEvent(QKeyEvent* event)
	// {
	// 	QVector2D dir;
	// 	switch(event->key()) {
	// 		case Qt::Key_Up:
	// 		case Qt::Key_W:
	// 			dir = {0, -1};
	// 			break;
	// 		case Qt::Key_S:
	// 		case Qt::Key_Down:
	// 			dir = {0, 1};
	// 			break;
	// 		case Qt::Key_A:
	// 		case Qt::Key_Left:
	// 			dir = {-1, 0};
	// 			break;
	// 		case Qt::Key_D:
	// 		case Qt::Key_Right:
	// 			dir = {1, 0};
	// 			break;
	// 		default:
	// 			QWidget::keyPressEvent(event);
	// 			break;
	// 	}
	// 	for(auto s : Soldier::getSoldierList(mCentralWidget)) {
	// 		s->move(dir);
	// 		s->update();
	// 	}
	// 	++mFrameCnt;
	// }

	void MainWindow::showFps()
	{
		static int lastFrameCnt = 0;
		qDebug() << "Fps: " << mFrameCnt - lastFrameCnt;
		lastFrameCnt = mFrameCnt;
	}
}
