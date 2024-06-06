#include <string>
#include "messages.hpp"

class Harl {
  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
	void unexpected(void);
	// initializes an array of function pointers with each function on it's correspondant hashed index
	void init_lookup_table();
	// this is the array of function pointers(the lookup table)
	void (Harl::*funcs[TABLE_SIZE])(void);
	// this function turns the level string into a hash whose range is within the lookup table size
    int index_of(const std::string &level);

  public:
    Harl(void);
    ~Harl(void);
	// calls the correspondant private function based on the hash of the level string
    void complain(std::string level);
};

