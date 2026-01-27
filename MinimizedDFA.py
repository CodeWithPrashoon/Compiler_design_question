def minimize_dfa(n, symbols, final_states, trans):
    # Step 1: Initial partition (Final & Non-final)
    P = [set(final_states), set(range(n)) - set(final_states)]
    P = [p for p in P if p]

    # Step 2: Partition refinement
    changed = True
    while changed:
        changed = False
        new_P = []

        for group in P:
            blocks = {}
            for state in group:
                key = tuple(
                    next(i for i, g in enumerate(P) if trans[state][s] in g)
                    for s in range(symbols)
                )
                blocks.setdefault(key, set()).add(state)

            if len(blocks) > 1:
                changed = True
                new_P.extend(blocks.values())
            else:
                new_P.append(group)

        P = new_P

    # Step 3: Assign groups
    state_group = {}
    for i, g in enumerate(P):
        for s in g:
            state_group[s] = i

    # Step 4: Build minimized DFA transition table
    min_trans = {}
    for i, g in enumerate(P):
        rep = next(iter(g))
        min_trans[i] = [state_group[trans[rep][s]] for s in range(symbols)]

    return state_group, min_trans


# -------- SAMPLE INPUT --------
n = 5                      # number of states
symbols = 2                # number of input symbols
final_states = [4]         # final state

trans = {
    0: [1, 2],
    1: [1, 3],
    2: [1, 2],
    3: [1, 4],
    4: [1, 2]
}

# -------- PROCESS --------
groups, min_dfa = minimize_dfa(n, symbols, final_states, trans)

# -------- OUTPUT --------
print("\nMinimized DFA State Groups:")
for s in range(n):
    print(f"State {s} -> Group {groups[s]}")

print("\nMinimized DFA Transition Table:")
for g in sorted(min_dfa):
    print(f"Group {g}: {min_dfa[g][0]} {min_dfa[g][1]}")
