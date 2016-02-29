#ifndef NULLEXPRESSIONEXCEPTION_H_INCLUDED
#define NULLEXPRESSIONEXCEPTION_H_INCLUDED

#include <iostream>
#include <sstream>
#include <exception>

using namespace std;

class NullExpressionException : public exception {

	public:

		NullExpressionException(const char *msg, int Line)
		{
			std::ostringstream oss;
			oss << "Erreur ligne " << Line << " : " << msg;
			this->msg = oss.str();
		}

		virtual ~NullExpressionException() throw ()
		{

		}

		virtual const char *what() const throw ()
		{
			return this->msg.c_str();
		}

	private:

		std::string msg;

};

#endif
