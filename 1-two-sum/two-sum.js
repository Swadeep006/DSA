/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const map = new Map();
    for(let i=0;i<nums.length;i++){
        const flag = target-nums[i];
        if(map.has(flag)){
            return [i,map.get(flag)];
        }
        map.set(nums[i],i);
    }
    return null;
};