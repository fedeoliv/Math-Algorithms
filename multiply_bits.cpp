# include<stdio.h>

/*  Efficient method to multiply number using bitwise operator. */

/*  Multiply by 2: n<<1
    By 3: (n<<1)+n
    By 4: (n<<2)
    By 5: (n<<2)+n
    By 6: (n<<2)+(n<<1)
    By 7: (n<<3)-n
    By 8: (n<<3)
    By 9: (n<<3)+n
    By 10: (n<<3)+(n<<1) */

int multiplyBySeven(unsigned int n) {
    return ((n<<3) - n);
}

int main() {
    unsigned int n = 4;
    printf("%u", multiplyBySeven(n));

    return 0;
}
