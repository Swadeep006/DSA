/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    const seen = new Map();

    for (let i = 0; i < nums.length; i++) {
        if (seen.has(nums[i])) {
            return true;
        } else {
            seen.set(nums[i]);
        }
    }

    return false;
};