
function solution(n) {
    let answer = 0;
    const num = Math.sqrt(n);
    
    if(Math.floor(num) === num) {
        answer = (num+1)**2;
    }
    else {
        answer = -1;
    }

    return answer;
}
