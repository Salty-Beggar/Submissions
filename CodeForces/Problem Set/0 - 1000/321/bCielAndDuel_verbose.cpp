
#include <iostream>
#include <vector>
#include <algorithm>
#include <span>
#include <string>
#include <utility>
using namespace std;

const long long MAX_NM = 100;
long long n, m, ciel_cards[MAX_NM], cards_between[MAX_NM],
attack_strength_total;
bool card_is_attack[MAX_NM];
vector<long long> attack_cards, defense_cards;
vector<pair<long long, bool>> cards;

int main() {
    cin >> n >> m;
    m = max(n, m);
    for (long long i = 0; i < n; i++) {
        string command;
        long long strength;
        cin >> command >> strength;
        if (command == "ATK") {
            cards.push_back({strength, true});
            attack_cards.push_back(strength);
            attack_strength_total += strength;
        }else {
            cards.push_back({strength+1, false});
            defense_cards.push_back(strength+1);
        }
    }
    sort(attack_cards.begin(), attack_cards.end());
    sort(defense_cards.begin(), defense_cards.end());
    sort(cards.begin(), cards.end());
    long long card_index = 0;
    for (auto card : cards) {
        card_is_attack[card_index++] = card.second;
    }
    for (auto &card : span(ciel_cards).subspan(0, m)) {
        cin >> card;
        long long index = upper_bound(cards.begin(), cards.end(), make_pair(card, false))-cards.begin()-1;
        
        if (index != -1) cards_between[index]++;
    }
    sort(ciel_cards, ciel_cards+m);

    long long max_points = 0;
    long long cur_card_defeats = 0;
    long long cur_attack_cards = 0;
    long long cur_attack_sub = 0;
    long long cur_ciel_attack = 0;
    long long cur_ciel_card = m-1;
    for (long long i = n-1; i >= 0; i--) {
        long long cur_between = cards_between[i];
        cur_card_defeats += cur_between;
        if (cards[i].second) {
            cur_attack_cards++;
        }else continue;

        if (cur_attack_cards > cur_card_defeats) {
            max_points = 0;
            cur_attack_cards = cur_card_defeats;
            cur_attack_sub += cards[i].first;
            continue;
        
        }
        cur_ciel_attack += ciel_cards[cur_ciel_card--];
        max_points = max(cur_ciel_attack - (attack_strength_total - cur_attack_sub), max_points);
        cur_attack_sub += cards[i].first;
    }

    cout << max_points;

    return 0;
}
