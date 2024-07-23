#include "Base.hpp"
#include "C.hpp"
#include <exception>

bool isC(Base &ref) {
    try {
        C &test = dynamic_cast<C &>(ref);
		static_cast<void>(test);
        return true;
    } catch (std::exception &) {
        return false;
    }
}
