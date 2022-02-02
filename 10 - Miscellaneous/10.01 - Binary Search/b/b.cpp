#include <bits/stdc++.h>

using namespace std;

long a, c, s;
int n;
vector<long> st;
constexpr long p = 0x7FFFFFFF;

void compute_st()
{
    st = {s};

    for (int i = 1; i < n; i++)
        st.push_back(((long long)a * st[i - 1] + c) & p);

    // sort st from low to high
    sort(st.begin(), st.end());
}

void solve()
{
    long u;
    cin >> u;

    // so far computed st
    unsigned long b_st = 0;

    // initially consider all st
    int lower_bnd = 0;
    int upper_bnd = st.size() - 1;

    // find best st by going from high to low
    for (int i = 31; i >= 0; i--)
    {
        int lb = lower_bnd;
        int ub = upper_bnd;

        // only one st remaining
        if (lower_bnd == upper_bnd)
            break;

        if ((u >> i) & 1)
        {
            // next b_st bit should be 0

            // reduce current st space by filtering sts that have
            // this bit 1 (lowering upper bound)

            unsigned long bigger_b_st = b_st + (1 << i);

            int upper_lower_bnd = lower_bnd;
            int upper_upper_bnd = upper_bnd;

            while (upper_lower_bnd < upper_upper_bnd)
            {
                int m = (upper_upper_bnd - upper_lower_bnd) / 2 + upper_lower_bnd;

                if (st[m] >= bigger_b_st)
                    // still to big
                    upper_upper_bnd = m;
                else
                    // small enough but maybe skipped some
                    upper_lower_bnd = m + 1;
            }

            // update upper bound filtering out to high sts
            upper_bnd = upper_lower_bnd;

            // check if we're on the higher side of the expected new upper bound
            if (st[upper_bnd] >= bigger_b_st)
                upper_bnd--;
        }
        else
        {
            // next b_st bit should be 1

            // reduce current st space by filtering sts that have
            // this bit 0 (raising lower bound)

            b_st += (1 << i);

            int lower_lower_bnd = lower_bnd;
            int lower_upper_bnd = upper_bnd;

            while (lower_lower_bnd < lower_upper_bnd)
            {
                int m = (lower_upper_bnd - lower_lower_bnd) / 2 + lower_lower_bnd;

                if (st[m] < b_st)
                    // still to small
                    lower_lower_bnd = m + 1;
                else
                    // big enough but maybe skipped some
                    lower_upper_bnd = m;
            }

            // update lower bound filtering out to small sts
            lower_bnd = lower_lower_bnd;

            // check if we're on the smaller side of the expected new lower bound
            if (st[lower_bnd] < b_st)
                lower_bnd++;
        }

        // check if our remaining st space is not empty
        if (lower_bnd > upper_bnd)
        {
            // remaining st space is empty
            // this happens if none of our sts had the needed bit
            // revert st space changes and go to next bit

            lower_bnd = lb;
            upper_bnd = ub;

            b_st = ((b_st >> i) ^ 1) << i;
        }
    }

    cout << st[lower_bnd] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(numeric_limits<double>::max_digits10);

    cin >> a >> c >> s >> n;

    compute_st();

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}