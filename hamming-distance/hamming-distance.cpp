class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR=x^y;
        int bits=0;
        while(XOR) {
            XOR=XOR&(XOR-1);
            bits++;
        }
        return bits;
    }
};