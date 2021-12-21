#include <Soldier.h>
#include <Common.h>

namespace GU
{
	SoldierData Soldier::defaultData = {.health = 100, .attackDamage = 10, .attackRange = 50, .moveSpeed = 5, .attackCd = 2};
	Soldier::Soldier(QWidget* parent)
		: QWidget(parent)
	{
		setParent(parent);
		mData = new SoldierData(defaultData);
		setGeometry(parent->geometry());
	}

	Soldier::~Soldier()
	{
	}

	void Soldier::move(const QVector2D& direction)
	{
		mPosition += (direction / direction.length() * mData->moveSpeed).toPoint();
		update();
	}

	void Soldier::attack()
	{
		qDebug() << mTeam << mPosition;
		auto l = getSoldierList(parent());
		// qDebug() << l.size();
		Soldier* n = nullptr;
		double minDist = 1e9;
		for(auto i : l) {
			// qDebug() << i->team() << i->position() << minDist;
			if(i->team() == mTeam) continue;
			if(dist(i->position(), mPosition) < minDist) {
				n = i;
				minDist = dist(i->position(), mPosition);
			}
		}
		// qDebug() << n->team() << n->position() << minDist;
		if(minDist < mData->attackRange) {
			n->data()->health -= mData->attackDamage;
			if(n->data()->health <= 0) {
				qDebug() << n->team();
				// n->destroy();
				delete n;
			}
		}
		else {
			move(QVector2D{n->position() - mPosition});
		}
	}

	void Soldier::paintEvent(QPaintEvent* event)
	{
		QPainter painter(this);
		painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
		painter.setPen(QPen(Qt::blue, 2));
		painter.setBrush(Qt::blue);
		painter.drawEllipse(mPosition, 20, 20);
	}

	QList<Soldier*> Soldier::getSoldierList(QObject* parent)
	{
		auto l = parent->children();
		QList<Soldier*> a;
		for(auto i : l) {
			if(i->objectName().contains("Soldier")) {
				a.push_back(dynamic_cast<Soldier*>(i));
			}
		}
		return a;
	}
}
