const check_rotation = (s1, s2) => {
    if (typeof s1 != 'string' || typeof s2 != 'string') return false;
    if (s1.length != s2.length || (!s1.length && !s2.length)) return false;
    if (s1 == s2) return true;

    let s1s1 = s1 + s1;
    return s1s1.includes(s2);
}

console.log("waterbottle vs erbottlewat: ", check_rotation("waterbottle", "erbottlewat"));
console.log("waterbottle vs waterbottle: ", check_rotation("waterbottle", "waterbottle"));
console.log("hello vs nollo: ", check_rotation("hello", "nollo"));
console.log("utercomp vs computer: ", check_rotation("utercomp", "computer"));
console.log("butter vs googol: ", check_rotation("butter", "googol"));
