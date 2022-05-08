function solution(id_list, report, k) {
    var answer = [];
    var reportingId = {};
    var reportedNum = {};
    // 초기화
    for (let i = 0 ; i < id_list.length; i++){
        reportingId[id_list[i]] = {};
        reportedNum[id_list[i]] = 0;
        answer.push(0);
    }
    // 신고한 사람 정리, 신고당한 횟수 정리
    for (let i = 0; i < report.length; i++) {
        r = report[i].split(' ');
        if(!(r[1] in reportingId[r[0]]))
            reportedNum[r[1]]++;
        reportingId[r[0]][r[1]] = true;
    }
    // 답 구하기
    for (let i = 0 ; i < id_list.length; i++) {
        const ids =  Object.keys(reportingId[id_list[i]]);
        for (let j = 0; j < ids.length; j++) {
            if (reportedNum[ids[j]] >= k){
                answer[i]++;
            }
        }
    }
    return answer;
}

function cleanSolution(id_list, report, k) {
    let reports = [...new Set(report)].map(a=>{return a.split(' ')});
    let counts = new Map();
    for (const bad of reports){
        counts.set(bad[1],counts.get(bad[1])+1||1)
    }
    let good = new Map();
    for(const report of reports){
        if(counts.get(report[1])>=k){
            good.set(report[0],good.get(report[0])+1||1)
        }
    }
    let answer = id_list.map(a=>good.get(a)||0)
    return answer;
}

console.log(cleanSolution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"], 2))
console.log(solution(["con", "ryan"], ["ryan con", "ryan con", "ryan con", "ryan con"], 3));