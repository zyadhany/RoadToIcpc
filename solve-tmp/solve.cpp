#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n, c, p;
        cin >> n >> c >> p;
        vector<string> nouns, tverb, iverb, conj;
        for (int i = 0; i < n; i++) {
            string w, t;
            cin >> w >> t;

            if (t == "noun") nouns.push_back(w);
            else if (t == "transitive-verb") tverb.push_back(w);
            else if (t == "intransitive-verb") iverb.push_back(w);
            else conj.push_back(w);
        }

        int ans = 0;
        // vars that track info related to the answer
        int t1, t2, combine, tack_end;
        for (int type_1 = 0; type_1 <= sz(iverb); type_1++) {
            int noun_cnt = sz(nouns), conj_cnt = sz(conj);
            int period = p, comma = c;
            int cur_words = 0;

            // let's make type 1 sentences yay
            cur_words += 2 * type_1;
            noun_cnt -= type_1;
            if (noun_cnt < 0) continue;

            // now let's make the most basic type of type 2 sentences
            int type_2 = min({sz(tverb), noun_cnt / 2, min(conj_cnt, period) * 2 + max(0, period - conj_cnt)});
            cur_words += 3 * type_2;
            noun_cnt -= 2 * type_2;

            // try to combine as much sentences with conj as possible
            int total = type_1 + type_2;
            int connections = type_1 + type_2 - 1;
            int can_combine = min((connections + 1) / 2, conj_cnt);
            cur_words += can_combine;
            // whatever we cannot combine, fill with periods
            period -= total - can_combine;
            if (period < 0) continue;

            // tack extra nouns we have at the end with commas
            // at the end of the last type 2 sentence
            int tack = 0;
            if (type_2 > 0) {
                tack = min(noun_cnt, comma);
                cur_words += tack;
            }
            if (cur_words > ans) {
                ans = cur_words;
                t1 = type_1;
                t2 = type_2;
                combine = can_combine;
                tack_end = tack;
            }
        }
        cout << ans << endl;

        if (ans == 0) {
            cout << endl;
            continue;
        }

        vector<vector<string>> sentences;
        // construct type 1 sentences
        for (int i = 0; i < t1; i++) {
            sentences.push_back({nouns.back(), iverb.back()});
            nouns.pop_back();
            iverb.pop_back();
        }
        // construct type 2 sentences
        for (int i = 0; i < t2; i++) {
            sentences.push_back({nouns.back(), tverb.back()});
            nouns.pop_back();
            tverb.pop_back();
            sentences.back().push_back(nouns.back());
            nouns.pop_back();
        }
        string output;
        for (int i = 0; i < sz(sentences); i++) {
            for (string j : sentences[i]) { output += j + " "; }
            if (i % 2 == 0 && combine) {
                combine--;
                // ADD A CONJUNCTION
                output += conj.back() + " ";
                conj.pop_back();
            } else {
                // remove the last whitespace and add a period
                output.pop_back();
                output += ". ";
            }
        }
        // remove the last whitespace
        output.pop_back();
        if (tack_end > 0) {
            // remove the last period
            output.pop_back();
            // and add a series of commas and nouns
            for (int i = 0; i < tack_end; i++) {
                output += ", " + nouns.back();
                nouns.pop_back();
            }
            // add back the last period
            output += ".";
        }
        cout << output << endl;
    }
}