const is_permutation = (str) => {
    if (typeof str != 'string') return false;
    if (!str.length) {
        return true;
    }
    let count = new Map();
    str = str.toLowerCase();
    for (let ch of str) {
        if (ch != ' ') {
            count.set(ch, ((count.get(ch) || 0) + 1));
        }
    }
    let odd_exists = false;
    for (let [ch, cnt] of count) {
        if (cnt % 2 != 0) {
            if (odd_exists) return false;
            odd_exists = true;
        }
    }
    return true;
}

console.log("Tact Coa: ", is_permutation("Tact Coa"));
console.log("Tact Coap: ", is_permutation("Tact Coap"));
