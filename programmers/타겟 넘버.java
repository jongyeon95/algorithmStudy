class Solution {
    public int target;
    public int size;
    public int answer;

    public void dfs(int cnt, int num, int[] numbers) {
        if (cnt == size) {
            if (num == target) {
                answer++;
            }
            return;
        }
        dfs(cnt + 1, num + numbers[cnt], numbers);
        dfs(cnt + 1, num - numbers[cnt], numbers);
    }


    public int solution(int[] numbers, int target) {
        this.answer = 0;
        this.target = target;
        this.size = numbers.length;
        dfs(0, 0, numbers);
        return this.answer;
    }
}