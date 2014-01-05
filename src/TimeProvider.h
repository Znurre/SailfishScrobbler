#ifndef TIMEPROVIDER_H
#define TIMEPROVIDER_H

#include <QDateTime>

class TimeProvider
{
	public:
		operator unsigned int() const
		{
			const QDateTime &now = QDateTime::currentDateTime();

			return now.toTime_t();
		}
};

const TimeProvider TIME_NOW;

#endif // TIMEPROVIDER_H
