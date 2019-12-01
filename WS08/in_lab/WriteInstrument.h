// WriteInstrument.h
#ifndef NAMRSPACE_WHITEINSTRUMENT_H
#define NAMRSPACE_WHITEINSTRUMENT_H
#include<iostream>
namespace sdds {
	class WriteInstrument {
	public:
		virtual ~WriteInstrument() {};
		virtual void write(const char*) = 0;
		virtual void refill(int) = 0;
		virtual bool filled() const = 0;
		virtual std::ostream& display(std::ostream& os) const = 0;

	};
}
#endif // !NAMESPACE_WHITEINSTRUMENT_H