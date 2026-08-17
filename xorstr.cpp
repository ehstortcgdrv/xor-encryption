#include "xorstr.h"

int main() {
    std::string password = ("visible_password");
    std::string username = xorstr_("hidden_username");
    std::cout << username << " | " << password;
    std::cin.get();
    return 0;
}
