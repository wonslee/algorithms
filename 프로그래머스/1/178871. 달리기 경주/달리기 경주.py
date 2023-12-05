def solution(players, callings):
    index_dict = { p : i for i, p in enumerate(players)}    # 탐색 시간복잡도 때문에 딕셔너리 사용

    for c in callings:
        idx = index_dict[c] # 호명된 이름의 현재 순서
        index_dict[c] -= 1  # 추월
        index_dict[players[idx-1]] += 1
        players[idx], players[idx-1] = players[idx-1], players[idx] # swap
    return players


# 1트
# def solution(players, callings):
#     for c in callings:
#         idx = players.index(c)
#         players[idx], players[idx-1] = players[idx-1], players[idx]
#     return players