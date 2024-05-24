#include "test.h"
#include <criterion/criterion.h>
#include <unistd.h>

#include <semaphore.h>
#include <fcntl.h>

sem_t *sem = sem_open("/test_semaphore", O_CREAT, 0644, 1);

// add eight contacts
#define scenario1                                                                                                      \
    CYAN "\nGiven phonebook = PhoneBook()\
\nWhen eight contacts are added\
\nThen the contacts are as expected" RESET

Test(testPhoneBook, add_eight_contacts, .description = scenario1) {
    PhoneBook phonebook = PhoneBook();
    std::string names[] = {"one", "two", "three", "four", "five", "six", "seven", "eight"};
    std::string numbers[] = {"11111111", "22222222", "33333333", "44444444",
                             "55555555", "66666666", "77777777", "88888888"};

    for (int i = 0; i < 8; i++) {
        phonebook.add_contact(names[i], numbers[i], "", "", "");
    }
	sem_wait(sem);
    phonebook.display_contacts();
	sem_post(sem);
}

// add a ninth contact
#define scenario2                                                                                                      \
    CYAN "\nGiven phonebook = PhoneBook()\
\nWhen a ninth contact is added\
\nThen the contacts are as expected" RESET

Test(testPhoneBook, add_ninth_contact, .description = scenario2) {
    PhoneBook phonebook = PhoneBook();
    std::string names[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string numbers[] = {"11111111", "22222222", "33333333", "44444444", "55555555",
                             "66666666", "77777777", "88888888", "99999999"};

    for (int i = 0; i < 9; i++) {
        phonebook.add_contact(names[i], numbers[i], "", "", "");
    }
	sem_wait(sem);
    phonebook.display_contacts();
	sem_post(sem);
}

// add a tenth contact
#define scenario3                                                                                                      \
    CYAN "\nGiven phonebook = PhoneBook()\
\nWhen a tenth contact is added\
\nThen the contacts are as expected" RESET

Test(testPhoneBook, add_tenth_contact, .description = scenario3) {
    PhoneBook phonebook = PhoneBook();
    std::string names[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    std::string numbers[] = {"11111111", "22222222", "33333333", "44444444", "55555555",
                             "66666666", "77777777", "88888888", "99999999", "10101010"};

    for (int i = 0; i < 10; i++) {
        phonebook.add_contact(names[i], numbers[i], "", "", "");
    }
    sem_wait(sem);
    phonebook.display_contacts();
	sem_post(sem);
}

// sixteen total contacts
#define scenario4                                                                                                      \
    CYAN "\nGiven phonebook = PhoneBook()\
\nWhen sixteen contacts are added\
\nThen the contacts are as expected" RESET

Test(testPhoneBook, add_sixteen_contacts, .description = scenario4) {
    PhoneBook phonebook = PhoneBook();
    std::string names[] = {"one",  "two", "three",  "four",   "five",     "six",      "seven",   "eight",
                           "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen"};
    std::string numbers[] = {"11111111", "22222222", "33333333", "44444444", "55555555",    "66666666",
                             "77777777", "88888888", "99999999", "10101010", "11,11,11,11", "12121212",
                             "13131313", "14141414", "15151515", "16161616"};

    for (int i = 0; i < 16; i++) {
        phonebook.add_contact(names[i], numbers[i], "", "", "");
    }
    sem_wait(sem);
    phonebook.display_contacts();
	sem_post(sem);
}


// sixteen total contacts
#define scenario5                                                                                                      \
    CYAN "\nGiven phonebook = PhoneBook()\
\nWhen seventeen contacts are added\
\nThen the contacts are as expected" RESET

Test(testPhoneBook, add_seventeen_contacts, .description = scenario5) {
    PhoneBook phonebook = PhoneBook();
    std::string names[] = {"one", "two",    "three",  "four",     "five",     "six",     "seven",   "eight",    "nine",
                           "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen"};
    std::string numbers[] = {"11111111", "22222222", "33333333", "44444444", "55555555",    "66666666",
                             "77777777", "88888888", "99999999", "10101010", "11,11,11,11", "12121212",
                             "13131313", "14141414", "15151515", "16161616", "17171717"};

    for (int i = 0; i < 17; i++) {
        phonebook.add_contact(names[i], numbers[i], "", "", "");
    }
    sem_wait(sem);
    phonebook.display_contacts();
    sem_post(sem);
}
