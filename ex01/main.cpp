#include "PhoneBook.hpp"
int main () {
	PhoneBook pb;
	pb.display_contacts();
	pb.add_contact("vinni", "11993471802");
	pb.display_contacts();
}
