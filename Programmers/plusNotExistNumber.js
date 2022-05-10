function solution(numbers) {
    var answer = 45;
    numbers.forEach(number => {
        answer -= number;
    });
    return answer;
}

function bestSolution(numbers) {
    return 45 - numbers.reduce((acc, cur) => acc + cur, 0)
}

console.log(solution([1,2,3,4,6,7,8,0]));