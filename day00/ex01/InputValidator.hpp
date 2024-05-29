#include <string>
#define RED "\033[1;31m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

typedef struct user_input_s {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
} user_input_t;

typedef struct prompts {
    std::string prompt;
    std::string *input;
    std::string error_message;
} prompts_t;

class InputValidator {
  private:
    int number_of_prompts;
    prompts_t prompts[5];

  public:
    InputValidator();
    void parse_input(user_input_t &perfect_input);
    bool doesntHaveLetters(std::string phone_number);
    void read_print_evaluate_loop(prompts_t prompts[]);
    void removeConsecutiveSpaces(std::string &data);
    void removeOuterSpaces(std::string &data);
    void cleanContactData(std::string &str);
};
