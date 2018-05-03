#include <cstring>

bool cmp(Player p1, Player p2) {
    if (p1.score == p2.score)
        return (p1.name <= p2.name);
    else
        return p1.score > p2.score;
}

vector<Player> comparator(vector<Player> players) {
    sort(players.begin(), players.end(), cmp);
    return players;
}
