
function solution(strings, n) {
    let answer = [];
    const arr = strings.slice();
    const swap = (a, b) => {
        return [b, a];
    }
    
    for(let i=0;i<arr.length;i++) {
        for(let j=0;j<arr.length;j++) {
            if(i === j) continue;
            if(arr[i][n] < arr[j][n]) {
                const tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            else if(arr[i][n] === arr[j][n]) {
                if(arr[i] < arr[j]) {
                    const tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }
    
    answer = arr.slice();
    
    return answer;
}
