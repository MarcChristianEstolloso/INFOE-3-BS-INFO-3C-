#include <iostream>
#include <cstring>

int main() {
    // These are stored sequentially in memory
    char secret_key[16] = "TOP_SECRET_123";
    char password_buffer[8]; // This 'bucket' only holds 8 characters

    std::cout << "--- Login ---" << std::endl;
    std::cout << "Enter 4-digit PIN: ";

    // VULNERABILITY: cin >> does not check if the input fits in the buffer!
    // This is a classic 'Bounds Control' failure.
    std::cin >> password_buffer; 

    if (strcmp(password_buffer, "1234") == 0) {
        std::cout << "Access Granted! Secret Key: " << secret_key << std::endl;
    } else {
        std::cout << "Access Denied." << std::endl;
        // In a real attack, the overflow has already happened here
        std::cout << "Current Memory State of Secret: " << secret_key << std::endl;
    }

    return 0;
}