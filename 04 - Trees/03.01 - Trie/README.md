# 03.01 - Trie
Data Structure used to efficiently store and maintain a set of strings.

- Root node represents empty string
- Each outgoing edge associated with a label (e.g. letter)
- Path from root to node represents prefix of a word defined by labels along the path
- All descendants of a node have same prefix
- Nodes at which a word ends are marked

## Implementation Optimizations
Store tree in Hashtable for large alphabets: `(source node, symbol) -> target node`

## Operations
### lookup(s)
- Start at root node and traverse edges by letters in `s`
- If no suitable edge found `s` not contained in trie
- If whole word processed, check if current node is marked

### insert(s)
- Start at root node and traverse edges by letters in `s`
- Add non-existing edges along the way
- Mark last node