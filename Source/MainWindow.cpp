#include <MainWindow.h>

namespace GU
{
	MainWindow::MainWindow(QWidget* parent)
		: QMainWindow(parent)
	{
		setParent(parent);
		setupUi();
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
		mSoldier = new Soldier(mCentralWidget);
		mSoldier->setPosition({600, 400});
		mSoldier->setObjectName("mSoldier");

		grabKeyboard();
		retranslateUi();
	}

	void MainWindow::retranslateUi()
	{
		this->setWindowTitle(QCoreApplication::translate("MainWindow", "GUWar"));
	}

	void MainWindow::keyPressEvent(QKeyEvent* event)
	{
		auto c = mCentralWidget->children();
		// QPoint qp;
		QVector2D dir;
		switch(event->key()) {
			case Qt::Key_Up:
			case Qt::Key_W:
				dir = {0, -1};
				break;
			case Qt::Key_S:
			case Qt::Key_Down:
				dir = {0, 1};
				break;
			case Qt::Key_A:
			case Qt::Key_Left:
				dir = {-1, 0};
				break;
			case Qt::Key_D:
			case Qt::Key_Right:
				dir = {1, 0};
				break;
			default:
				QWidget::keyPressEvent(event);
				break;
		}
		for(auto i : c) {
			if(i->objectName().contains("Soldier")) {
				auto s = dynamic_cast<Soldier*>(i);
				s->move(dir);
			}
		}
	}
}
