int solve(int l, int r, int score) {
    if (l >= left_g.size() || r >= right_g.size())  //카드를 다 쓴 경우
        return score;
    
    if (left_g[l] > right_g[r]) {       //오른쪽이 더 작은 경우
        score += solve(l, r + 1, score) + right_g[r];
        return score;
    } else {                            //아닌 경우
        int temp1 = solve(l + 1, r + 1, score);
        int temp2 = solve(l + 1, r, score);

        score += temp1 >= temp2 ? temp1 : temp2;    //둘다 끝까지 가보고 비교
        return score;
    }
}
