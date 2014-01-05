#ifndef STATUS_H
#define STATUS_H

class Status
{
	public:
		Status(const int errorCode);

		bool isValid() const;

	private:
		int m_errorCode;
};

#endif // STATUS_H
