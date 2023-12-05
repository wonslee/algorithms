def solution(players, callings):
    for c in callings:
        idx = players.index(c)
        players[idx], players[idx-1] = players[idx-1], players[idx]
    print(players)
    return players