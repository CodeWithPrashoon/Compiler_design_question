from collections import deque

# Example NFA
Q = ["q0", "q1", "q2"]
sigma = ["a", "b"]
start = "q0"
final = ["q2"]

delta = {
    "q0": {"a": ["q0", "q1"], "b": ["q2"]},
    "q1": {"a": ["q1"], "b": ["q2"]},
    "q2": {"a": [], "b": []}
}

def nfa_to_dfa():
    dfa_start = frozenset([start])
    q = deque([dfa_start])
    dfa_states = {dfa_start}
    dfa_delta = {}

    while q:
        cur = q.popleft()
        dfa_delta[cur] = {}

        for s in sigma:
            nxt = set()
            for st in cur:
                nxt.update(delta[st][s])
            nxt = frozenset(nxt)
            dfa_delta[cur][s] = nxt

            if nxt not in dfa_states:
                dfa_states.add(nxt)
                q.append(nxt)

    dfa_final = [st for st in dfa_states if any(f in st for f in final)]
    return dfa_states, dfa_delta, dfa_start, dfa_final

# Print NFA Table
print("Output :-\n")
print("NFA Transition Table")
print("State\t\ta\t\tb")
for st in Q:
    print(f"{st}\t\t{delta[st]['a']}\t\t{delta[st]['b']}")

# Convert + Print DFA Table
dfa_states, dfa_delta, dfa_start, dfa_final = nfa_to_dfa()

print("\nDFA Transition Table")
print("DFA State\t\ta\t\tb")
for st in dfa_states:
    print(f"{list(st)}\t\t{list(dfa_delta[st]['a'])}\t\t{list(dfa_delta[st]['b'])}")

print("\nStart State :", list(dfa_start))
print("Final States:", [list(s) for s in dfa_final])
