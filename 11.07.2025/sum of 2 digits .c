int sumOfSquares(int n) {
    int result = 0;
    while (n != 0) {
        int digit = n % 10;
        result += digit * digit;
        n /= 10;
    }
    return result;
}
