#include <stdint.h>
#include <stdio.h>
unsigned char	reverse_bits(unsigned char octet) {
    
    return __builtin_bitreverse8(octet);
}

int ispower(unsigned int n) {
    return n != 0 && (__builtin_popcount(n) == 1);
}

#include <assert.h>
int main() {
    assert(ispower(4096) > 0);
    assert(ispower(16384));
    assert(ispower(1));
    assert(ispower(2));
    assert(ispower(4));
    assert(ispower(8));
    assert(ispower(16));
    assert(ispower(32));
    assert(ispower(64));

    char a[255] = {0};
    unsigned char c = 0b11001100;
    char b[8];
    int i = 0;
    while (i < 8){
        if (c % 2 == 0)
            b[i] = '0';
        else    
            b[i] = '1';
        c = c>> 1;
        i++;
    }
    i = 7;
    while (i >= 0)
        putchar(b[i--]);

    // 11001100
    // 01100110
    // 00110011
    // 00011001
    // 00001100
    // 00000110
    // 00000011
    // 00000001
    // 01000000
    // 00010000



    // unsigned char c = reverse_bits(0b10101010);
    // unsigned char b = 0b11110000; // 
    // unsigned char l = b >> 4; // 1111
    // unsigned char r = b & 0b1111; // 0000

    // // 00001100
    // // 00001111
    // // 00001111
    // // 00000011

    // unsigned char result = (r << 4) | l;
}
