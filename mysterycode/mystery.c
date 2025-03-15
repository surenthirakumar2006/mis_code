#include <stdio.h>
#include <string.h>

int main(void) {
    char input[64];
    printf("Enter the secret key: ");
    fflush(stdout);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // remove newline

    int sum = 0;
    // For each character, perform an obfuscated transformation.
    for (int i = 0; i < strlen(input); i++) {
        unsigned char ch = input[i];
        // Example transformation: subtract 0x23, then XOR with (0xAA rotated by (i mod 8)),
        // then add 0x10.
        unsigned char transformed = ((ch - 0x23) ^ (0xAA >> (i % 8))) + 0x10;
        sum += transformed;
    }
    
    // The secret target value is embedded in the binary.
    if (sum == 0x3F7) {  // 0x3F7 is an example target value.
        FILE *file;
        file = fopen("flag", "r");
        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }
        char flag[64];
        if (fgets(flag, sizeof(flag), file) == NULL) {
            perror("Error reading file");
            return 1;
        }
        printf("Access Granted! Flag: %s\n", flag);
        fclose(file);
    } else {
        printf("Wrong key. Try again.\n");
    }
    return 0;
}
