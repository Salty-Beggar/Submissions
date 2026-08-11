
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

const long long MAX_NM = 100;
long long n, m, attack_n, defense_n, between_cards[MAX_NM];
vector<long long> defense_cards, attack_cards, ciel_cards;

int main() {
    cin >> n >> m;

    long long attack_sum = 0;
    for (long long i = 0; i < n; i++) {
        string position;
        long long strength;
        cin >> position >> strength;
        if (position == "ATK") {
            attack_cards.push_back(strength);
            attack_sum += strength;
        }else {
            defense_cards.push_back(strength+1);
        }
    }
    attack_n = attack_cards.size();
    defense_n = defense_cards.size();

    for (long long i = 0; i < m; i++) {
        long long strength;
        cin >> strength;
        ciel_cards.push_back(strength);
        long long between_index = upper_bound(
            attack_cards.begin(),
            attack_cards.end(),
            strength
        ) - attack_cards.begin() - 1;
        if (between_index != -1) between_cards[between_index]++;

    }

    sort(attack_cards.begin(), attack_cards.end());
    sort(defense_cards.begin(), defense_cards.end());
    sort(ciel_cards.begin(), ciel_cards.end());

    long long ciel_sum = 0;
    for (long long i = 0; i < min(attack_n, m); i++) {
        ciel_sum += ciel_cards[m-i-1];
    }

    long long extra_ciels = 0;
    long long ciel_index = max(0ll, m - attack_n);
    long long max_attack_points = 0;
    for (long long i = attack_n-1; i >= 0; i--) {
        extra_ciels += between_cards[i];
        if (extra_ciels == 0) {
            max_attack_points = 0;
        }else {
            extra_ciels--;
            max_attack_points = max(max_attack_points, ciel_sum - attack_sum);
        }
        // cout << ciel_sum << " " << attack_sum << "\n";
        ciel_sum -= ciel_cards[ciel_index];
        ciel_index++;
        attack_sum -= attack_cards[i];
        if (ciel_index == m) break;
    }

    ciel_sum = 0;
    multiset<long long> ciel_card_set;
    for (long long i = 0; i < m; i++) {
        ciel_sum += ciel_cards[i];
        ciel_card_set.insert(ciel_cards[i]);
    }
    attack_sum = 0;
    for (long long i = 0; i < attack_n; i++) {
        attack_sum += attack_cards[i];
    }

    bool defense_possible = true;
    for (long long i = 0; i < defense_n; i++) {
        long long cur_defense = defense_cards[defense_n-1-i];
        auto ciel_use_it = ciel_card_set.lower_bound(cur_defense);
        if (ciel_use_it == ciel_card_set.end()) {
            defense_possible = false;
            break;
        }
        long long ciel_use_strength = *ciel_use_it;
        ciel_card_set.erase(ciel_use_it);
        ciel_sum -= ciel_use_strength;
        long long attack_use_index = upper_bound(
            attack_cards.begin(),
            attack_cards.end(),
            ciel_use_strength
        ) - attack_cards.begin() - 1;
        if (attack_use_index != -1) {
            between_cards[attack_use_index]--;
        }
    }

    extra_ciels = 0;
    for (long long i = attack_n-1; i >= 0; i--) {
        extra_ciels += between_cards[i];
        if (extra_ciels <= 0) {
            defense_possible = false;
            break;
        }else {
            extra_ciels--;
        }
    }

    cout << max(max_attack_points, (defense_possible) ? (ciel_sum - attack_sum) : 0);
}