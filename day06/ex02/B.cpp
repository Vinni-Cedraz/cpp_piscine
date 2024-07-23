#include "B.hpp"
#include "Base.hpp"
#include <exception>

bool isB(Base &ref) {
    try {
        B &test = dynamic_cast<B &>(ref);
		static_cast<void>(test);
        return true;
    } catch (std::exception &) {
        return false;
    }
}
