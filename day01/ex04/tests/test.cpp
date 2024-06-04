#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <sys/stat.h>
#define GREEN(text) "\033[32m" text "\033[0m"

#define scenario1                                                                                                      \
    "\nTEST1:\n\
	WHEN not_sed receives like_a_rolling_stone\n\
	AND laugh\n\
	AND cry\n\
	THEN like_a_rolling_stone.replace exists\n\
	AND like_a_rolling_stone.replace contains the phrase \"You used to cry about\"\n"
#define scenario2                                                                                                      \
    "\nTEST2:\nWHEN not_sed receives like_a_rolling_stone\n\
	AND used\n\
	AND apple\n\
	THEN like_a_rolling_stone.replace contains \"You apple to laugh about\"\n\
	AND \"But you know you only apple to get juiced in it\"\n\
	AND \"And now you're gonna have to get apple to it\"\n\
	AND \"You apple to ride on a chrome horse with your diplomat\"\n\
	AND \"You apple to ride on a chrome horse with your diplomat\"\n\
	AND \"You apple to be so amused\"\n\
	AND \"At Napoleon in rags and the language that he apple\"\n"

bool fileExists(const std::string &filename) {
    struct stat buffer;
    return (stat(filename.c_str(), &buffer) == 0);
}

int main() {
    std::cout << scenario1;
    {
        system("./not_sed like_a_rolling_stone laugh cry");
        assert(fileExists("like_a_rolling_stone.replace"));
        std::cout << GREEN("PASSED: ") << "like_a_rolling_stone.replace exists" << std::endl;

        std::ostringstream oss;
        std::ifstream file("like_a_rolling_stone.replace");
        std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(),
                  std::ostream_iterator<std::string>(oss, " "));
        std::string allines = oss.str();
        assert(allines.find("You used to cry about") != std::string::npos);
        std::cout << GREEN("PASSED: ") << "like_a_rolling_stone.replace contains the phrase \"You used to cry about\""
                  << std::endl;
    }
    std::cout << scenario2;
    {
        system("./not_sed like_a_rolling_stone used apple");
        std::ifstream file("like_a_rolling_stone.replace");
        std::ostringstream oss;
        std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(),
                  std::ostream_iterator<std::string>(oss, " "));
        std::string allines = oss.str();
        char test_strings[5][100] = {
			"But you know you only apple to get juiced in it",
            "And now you're gonna have to get apple to it",
            "You apple to ride on a chrome horse with your diplomat",
            "You apple to be so amused",
		    "At Napoleon in rags and the language that he apple"
		};
        assert(allines.find(test_strings[0]) != std::string::npos);
		std::cout << GREEN("PASSED: ") << "like_a_rolling_stone.replace contains \"But you know you only apple to get juiced in it\"" << std::endl;
        assert(allines.find(test_strings[1]) != std::string::npos);
		std::cout << GREEN("PASSED: ") << "like_a_rolling_stone.replace contains \"And now you're gonna have to get apple to it\"" << std::endl;
        assert(allines.find(test_strings[2]) != std::string::npos);
		std::cout << GREEN("PASSED: ") << "like_a_rolling_stone.replace contains \"You apple to ride on a chrome horse with your diplomat\"" << std::endl;
        assert(allines.find(test_strings[3]) != std::string::npos);
		std::cout << GREEN("PASSED: ") << "like_a_rolling_stone.replace contains \"You apple to be so amused\"" << std::endl;
		assert(allines.find(test_strings[4]) != std::string::npos);
		std::cout << GREEN("PASSED: ") << "like_a_rolling_stone.replace contains \"At Napoleon in rags and the language that he apple\"" << std::endl;
    }
}
