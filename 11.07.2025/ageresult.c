int getAgeResult(int age) {
    if (age < 0 || age > 101) return -1;
    if (age <= 5) return 0;
    if (age <= 12) return 1;
    if (age <= 19) return 2;
    if (age <= 50) return 3;
    if (age <= 60) return 4;
    return 5;
}
