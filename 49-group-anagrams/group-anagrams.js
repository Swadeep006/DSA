/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
    const sol = [];
    const temp = [];
    for (let i = 0; i < strs.length; i++) {
        if (strs[i] === "") {
            temp.push("");
        }
    }
    if (temp.length > 0) sol.push(temp);
    for (let i = 0; i <= strs.length - 1; i++) {
        if (strs[i].length === 0) {
            continue;
        }
        const sub_arr = [];
        sub_arr.push(strs[i]);
        for (let j = i + 1; j <= strs.length - 1; j++) {
            if (helper(strs[i], strs[j])) {
                sub_arr.push(strs[j]);
                strs[j] = "";
            }
        }
        sol.push(sub_arr);
    }
    return sol;
};
 
 
 
 
function helper(s, t){
    if (s.length !== t.length) return false;
    const arr = new Array(26).fill(0);
    for (let i = 0; i < s.length; i++) {
        arr[s.charCodeAt(i) - 97]++;
        arr[t.charCodeAt(i) - 97]--;
    }
    for (let i = 0; i < 26; i++) {
        if (arr[i] !== 0) return false;
    }
    return true;
}
 
 
 
 