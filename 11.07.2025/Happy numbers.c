void checkHappyNumber(int sqdnumber, int *finalNumber, int *cycle_no) {
    int num = sqdnumber;
    for (int i = 1; i <= 10; i++) {
        num = sumOfSquares(num);
        if (num == 1) {
            *finalNumber = 1;
            *cycle_no = i;
            return;
        }
    }
    *finalNumber = num;
    *cycle_no = 10;
}
