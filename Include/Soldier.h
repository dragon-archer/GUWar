#ifndef _GUWAR_SOLDIER_H
#define _GUWAR_SOLDIER_H

#include <Pch.h>

namespace GU
{
	class SoldierData
	{
	public:
		SoldierData() = default;
		~SoldierData() = default;
		uint health;        // point
		uint attackDamage;  // point
		double attackRange; // pixel
		double moveSpeed;   // pixel per second
		double attackCd;    // second
	};

	class Soldier : public QWidget
	{
		Q_OBJECT
	public:
		Q_PROPERTY(QPoint mPosition READ position WRITE setPosition)

		Soldier(QWidget* parent = nullptr);
		~Soldier();

		QPoint position() const;
		void setPosition(const QPoint& position);
		SoldierData* data() const;
		void setData(SoldierData* data);
		uint team() const;
		void setTeam(uint team);

		void move(const QVector2D& direction);

		void paintEvent(QPaintEvent* event);

		static SoldierData defaultData;
	protected:
		SoldierData* mData;
		QPoint mPosition;
		uint mTeam;
	};
}

#endif /* _GUWAR_SOLDIER_H */
