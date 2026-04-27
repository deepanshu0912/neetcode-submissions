class MedianFinder {
public:
    vector<double> mf;

    MedianFinder() {
    }

    void addNum(int num) {
        mf.push_back(num);
        sort(mf.begin(), mf.end());
    }

    double findMedian() {
        int n = mf.size();

        if (n % 2 == 0) {
            double a = mf[n/2 - 1];
            double b = mf[n/2];
            return (a + b) / 2.0;
        }
        else {
            return mf[n/2];
        }
    }
};