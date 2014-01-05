#include "Status.h"

Status::Status(const int errorCode)
	: m_errorCode(errorCode)
{

}

bool Status::isValid() const
{
	return m_errorCode < 0;
}
