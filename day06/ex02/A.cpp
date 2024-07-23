#include "A.hpp"
#include "Base.hpp"
#include <exception>

bool isA(Base &ref) {
    try {
        A &test = dynamic_cast<A &>(ref);
		static_cast<void>(test);
        return true;
    } catch (std::exception &) {
        return false;
    }
}
