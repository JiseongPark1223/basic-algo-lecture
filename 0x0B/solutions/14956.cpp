// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/bb5866b211a7402f81f4654196240b41
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
using ll = long long;
using PLL = pair<ll, ll>;
// 변의 길이, 걸어간 거리로 x, y좌표값을 재귀적으로 계산
PLL philo(ll side, ll walk) {
  // Base case: 변의 길이가 2^1인 경우
  if (side == 2) {
    switch (walk) {
      case 1:
        return {1, 1};
      case 2:
        return {1, 2};
      case 3:
        return {2, 2};
      case 4:
        return {2, 1};
    }
  }
  ll half = side / 2, section = half * half;
  // walk가 속하는 범위에 따라 계산
  if (walk <= section) {
    PLL rv = philo(half, walk);
    return {rv.Y, rv.X};
  } else if (walk <= 2 * section) {
    PLL rv = philo(half, walk - section);
    return {rv.X, half + rv.Y};
  } else if (walk <= 3 * section) {
    PLL rv = philo(half, walk - 2 * section);
    return {half + rv.X, half + rv.Y};
  } else {
    PLL rv = philo(half, walk - 3 * section);
    return {2 * half - rv.Y + 1, half - rv.X + 1};
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll side, walk;
  cin >> side >> walk;
  PLL ans = philo(side, walk);
  cout << ans.X << " " << ans.Y;
}
/*
Programming land의 범위를 4개의 범위로 나누어
walk를 바탕으로 현재 철학자가 어느 사분면에 존재하는지 파악한 후,
적절한 계산을 통해 사각형을 축소시키며 좌표값을 계산합니다.
*/
