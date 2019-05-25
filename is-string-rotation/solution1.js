const check_rotation = (s1, s2) => {
    if (typeof s1 != 'string' || typeof s2 != 'string') return false;
    if (s1.length != s2.length || (!s1.length && !s2.length)) return false;
    if (s1 == s2) return true;

    let s2_index = s2.length - 1;
    let s1_index = s1.indexOf(s2[s2_index]);
    if (s1_index == -1) return false;

    while (s1_index > 0) {
        --s1_index;
        --s2_index;
        if (s1[s1_index] != s2[s2_index]) return false;
    }
    if (s2_index == 0) return true;
    let cut = s2.substr(0, s2_index);
    return s1.includes(cut);
}

console.log("waterbottle vs erbottlewat: ", check_rotation("waterbottle", "erbottlewat"));
console.log("waterbottle vs waterbottle: ", check_rotation("waterbottle", "waterbottle"));
console.log("hello vs nollo: ", check_rotation("hello", "nollo"));
console.log("utercomp vs computer: ", check_rotation("utercomp", "computer"));
console.log("butter vs googol: ", check_rotation("butter", "googol"));
