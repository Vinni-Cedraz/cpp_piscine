#include <string>

class Harl {
  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);


  private:
	void init_funcs();
	void (Harl::*funcs[40])(void);
    int index_of(const std::string &level);

  public:
    Harl(void);
    ~Harl(void);
    void complain(std::string level);
};

