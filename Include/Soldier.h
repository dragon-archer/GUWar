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

		Soldier(QWidget* parent = nullptr);
		~Soldier();

		inline QPoint position() const
			{ return mPosition; }
		inline void setPosition(const QPoint& position)
			{ mPosition = position; }
		inline SoldierData* data() const
			{ return mData; }
		inline void setData(SoldierData* data)
			{ if(mData != data) mData = new(mData) SoldierData(*data); }
		inline uint team() const
			{ return mTeam; }
		inline void setTeam(uint team)
			{ mTeam = team; }

		void move(const QVector2D& direction);
		void attack();

		void paintEvent(QPaintEvent* event);

		static SoldierData defaultData;
		static QList<Soldier*> getSoldierList(QObject* parent);
	protected:
		SoldierData* mData;
		QPoint mPosition;
		uint mTeam;
	};
}

#endif /* _GUWAR_SOLDIER_H */
