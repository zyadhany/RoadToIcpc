// bool take 1 byte not 1 bit
// we can make 1 byte intiger and make it work for 8 bits as bool.
uint8_t G[13][5005][(5005 + 7) / 8];
inline void set_bit(int i, int j, int k, bool val) {
    if (val)
        G[i][j][k / 8] |= (1 << (k % 8));
    else
        G[i][j][k / 8] &= ~(1 << (k % 8));
}
inline bool get_bit(int i, int j, int k) {
    return (G[i][j][k / 8] >> (k % 8)) & 1;
}
