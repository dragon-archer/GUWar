#include <Soldier.h>

namespace GU
{
	SoldierData Soldier::defaultData = {.health = 100, .attackDamage = 10, .attackRange = 10, .moveSpeed = 5, .attackCd = 2};
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

	QPoint Soldier::position() const
	{
		return mPosition;
	}

	void Soldier::setPosition(const QPoint& position)
	{
		mPosition = position;
		update();
	}

	SoldierData* Soldier::data() const
	{
		return mData;
	}

	void Soldier::setData(SoldierData* data)
	{
		if(mData != data) {
			mData = new(mData) SoldierData(*data);
		}
	}

	uint Soldier::team() const
	{
		return mTeam;
	}

	void Soldier::setTeam(uint team)
	{
		mTeam = team;
	}

	void Soldier::move(const QVector2D& direction)
	{
		mPosition += (direction / direction.length() * mData->moveSpeed).toPoint();
		update();
	}

	void Soldier::paintEvent(QPaintEvent* event)
	{
		QPainter painter(this);
		painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
		painter.setPen(QPen(Qt::blue, 2));
		painter.setBrush(Qt::blue);
		painter.drawEllipse(mPosition, 20, 20);
	}
}
