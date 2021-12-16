#include <MainWindow.h>
#include <Soldier.h>

using namespace GU;
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QTranslator translator;
	if(translator.load(":/Language/GUWar_zh_CN")) {
		app.installTranslator(&translator);
	}
	MainWindow window;
	window.show();
	// qDebug() << sizeof(QObject) << sizeof(QWidget) << sizeof(QPainter) << sizeof(QPaintDevice) << sizeof(QApplication) << sizeof(QMainWindow);
	return app.exec();
}
