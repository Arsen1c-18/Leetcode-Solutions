int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    
    // rook captures in same row
    if (a == e) {
        if (!(c == a && ((d > b && d < f) || (d < b && d > f))))
            return 1;
    }

    // rook captures in same column
    if (b == f) {
        if (!(d == b && ((c > a && c < e) || (c < a && c > e))))
            return 1;
    }

    // bishop captures diagonally
    if (abs(c - e) == abs(d - f)) {
        if (!(abs(a - e) == abs(b - f) &&
            ((a > c && a < e) || (a < c && a > e)) &&
            ((b > d && b < f) || (b < d && b > f))))
            return 1;
    }

    return 2;
}