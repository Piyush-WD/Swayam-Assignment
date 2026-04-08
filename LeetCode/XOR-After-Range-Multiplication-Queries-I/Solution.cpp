const xorAfterQueries = (A, q) => {
    for (const [l, r, k, v] of q)
        for (let i = l; i <= r; i += k)
            A[i] = (A[i] * v) % (1e9 + 7);

    return A.reduce((a, c) => a ^ c, 0);
};