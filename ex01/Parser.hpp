#include <string>
#define RED "\033[1;31m"
#define RESET "\033[0m"

typedef struct user_input_s {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
} user_input_t;

typedef struct prompts_and_inputs {
    std::string prompt;
    std::string *input;
    std::string error_message;
} prompts_and_inputs_t;

class Parser {
  private:
    int number_of_prompts;
	prompts_and_inputs_t prompts_and_inputs[5];

  public:
	Parser();
    void parse_input(user_input_t &perfect_input);
    void read_print_evaluate_loop(prompts_and_inputs_t prompts_and_inputs[]);
};
