/**
 * @param {number} k
 * @param {number} n
 * @return {number[][]}
 */

var getCombination = (numbers, selectNumber, n) => {
    let result = [];
    if (selectNumber === 1){
        return numbers.map((el) => [el]);
    }
    numbers.forEach((fixed, index, origin) => {
        const rest = origin.slice(index + 1);
        const combinations = getCombination(rest, selectNumber - 1, n);
        const attached = combinations.map((combination) => {
            if (combination && combination.reduce((acc, cur) => acc + cur, 0) <= n)
                return [fixed, ...combination];
        });
        result.push(...attached);
    });
    return result;
}

var combinationSum3 = function(k, n) {
    const numbers = [1,2,3,4,5,6,7,8,9];
    const combinations = getCombination(numbers, k, n);
    let result = [];
    combinations.forEach((el) => {
        if (el && el.reduce((acc, cur) => acc+cur, 0) === n){
            result.push(el);
        }
    })
    return result;
};

console.log(combinationSum3(3, 7));